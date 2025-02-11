#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "discord.h"
#include "discord-internal.h"

#include "orka-utils.h"

#define BASE_API_URL "https://discord.com/api/v8"


struct _ratelimit_cxt {
  struct discord_adapter *adapter;
  struct discord_bucket *bucket;
  char *endpoint;
};

void
discord_adapter_init(struct discord_adapter *adapter, struct logconf *config, struct sized_buffer *token)
{
  adapter->ua = ua_init(BASE_API_URL, config);
  logconf_add_id(config, adapter->ua, "DISCORD_HTTP");

  if (STRNEQ("YOUR-BOT-TOKEN", token->start, token->size)) {
    token->start = NULL;
  }
  ASSERT_S(NULL != token->start, "Missing bot token");

  char auth[128];
  int ret = snprintf(auth, sizeof(auth), "Bot %.*s", (int)token->size, token->start);
  ASSERT_S(ret < sizeof(auth), "Out of bounds write attempt");

  ua_reqheader_add(adapter->ua, "Authorization", auth);

  if (pthread_mutex_init(&adapter->ratelimit.lock, NULL))
    ERR("Couldn't initialize pthread mutex");

  discord_buckets_init(adapter);
}

void
discord_adapter_cleanup(struct discord_adapter *adapter)
{
  ua_cleanup(adapter->ua);
  pthread_mutex_destroy(&adapter->ratelimit.lock);
  discord_buckets_cleanup(adapter);
}

static int
bucket_tryget_cb(void *p_cxt)
{
  struct _ratelimit_cxt *cxt = p_cxt;
  pthread_mutex_lock(&cxt->adapter->ratelimit.lock);
  cxt->bucket = discord_bucket_try_get(cxt->adapter, cxt->endpoint);
  pthread_mutex_unlock(&cxt->adapter->ratelimit.lock);
  return 1;
}

static void
bucket_trycooldown_cb(void *p_cxt)
{
  struct _ratelimit_cxt *cxt = p_cxt;
  discord_bucket_try_cooldown(cxt->bucket);
}

static void
bucket_trybuild_cb(void *p_cxt, struct ua_conn *conn)
{
  struct _ratelimit_cxt *cxt = p_cxt;
  pthread_mutex_lock(&cxt->adapter->ratelimit.lock);
  discord_bucket_build(cxt->adapter, cxt->bucket, cxt->endpoint, conn);
  pthread_mutex_unlock(&cxt->adapter->ratelimit.lock);
}

static ua_status_t
on_success_cb(void *p_cxt, int httpcode, struct ua_conn *conn) {
  return UA_SUCCESS;
}

static ua_status_t
on_failure_cb(void *p_cxt, int httpcode, struct ua_conn *conn)
{
  struct _ratelimit_cxt *cxt = p_cxt;

  if (httpcode >= 500) { // server related error, retry
    ua_block_ms(cxt->adapter->ua, 5000); // wait for 5 seconds
    return UA_RETRY;
  }

  switch (httpcode) {
  case HTTP_FORBIDDEN:
  case HTTP_NOT_FOUND:
  case HTTP_BAD_REQUEST:
      return UA_FAILURE;
  case HTTP_UNAUTHORIZED:
  case HTTP_METHOD_NOT_ALLOWED:
  default:
      return UA_ABORT;
  case HTTP_TOO_MANY_REQUESTS:
   {
      char message[256]="";
      double retry_after=-1; // seconds

      struct sized_buffer body = ua_conn_get_resp_body(conn);
      json_extract(body.start, body.size,
                  "(message):s (retry_after):lf",
                  message, &retry_after);

      if (retry_after != -1) { // retry after attribute received
        log_warn("%s (wait: %.2lf s)", message, retry_after);

        ua_block_ms(cxt->adapter->ua, (uint64_t)(1000*retry_after));

        return UA_RETRY;
      }
      
      // no retry after included, we should abort
      log_fatal("%s", message);
      return UA_ABORT;
   }
  }
}

static void
json_error_cb(char *str, size_t len, void *p_err)
{
  /* JSON ERROR CODES
  https://discord.com/developers/docs/topics/opcodes-and-status-codes#json-json-error-codes */
  int code = 0; //last error code received
  char message[256] = {0}; //meaning of the error received
  json_extract(str, len, \
      "(message):.*s (code):d", sizeof(message), message, &code);
  log_error(ANSICOLOR("(JSON Error %d) %s", ANSI_BG_RED)
            " - See Discord's JSON Error Codes\n\t\t%.*s", 
            code, message, (int)len, str);
}

/* template function for performing requests */
void
discord_adapter_run(
  struct discord_adapter *adapter, 
  struct ua_resp_handle *resp_handle,
  struct sized_buffer *req_body,
  enum http_method http_method, char endpoint[], ...)
{
  va_list args;
  va_start(args, endpoint);

  struct _ratelimit_cxt cxt = {
    .adapter = adapter, 
    .endpoint = endpoint
  };

  struct ua_callbacks cbs = {
    .data = &cxt,
    .on_startup = &bucket_tryget_cb,
    .on_iter_start = &bucket_trycooldown_cb,
    .on_iter_end = &bucket_trybuild_cb,
    .on_1xx = NULL,
    .on_2xx = &on_success_cb,
    .on_3xx = &on_success_cb,
    .on_4xx = &on_failure_cb,
    .on_5xx = &on_failure_cb,
  };

  /* IF UNSET, SET TO DEFAULT ERROR HANDLING CALLBACKS */
  if (resp_handle && !resp_handle->err_cb) {
    resp_handle->err_cb = &json_error_cb;
    resp_handle->err_obj = NULL;
  }

  ua_vrun(
    adapter->ua,
    resp_handle,
    req_body,
    &cbs,
    http_method, endpoint, args);

  va_end(args);
}
