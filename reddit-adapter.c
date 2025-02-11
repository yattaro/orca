#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "reddit.h"
#include "reddit-internal.h"
#include "orka-utils.h"

#define BASE_API_URL "https://www.reddit.com"

static void
curl_setopt_cb(CURL *ehandle, void *p_client)
{
  struct reddit *client = p_client;

  int ret; // check return length
  char client_id[512], client_secret[512];
  ret = snprintf(client_id, sizeof(client_id), "%.*s", (int)client->client_id.size, client->client_id.start);
  ASSERT_S(ret < sizeof(client_id), "Out of bounds write attempt");
  ret = snprintf(client_secret, sizeof(client_secret), "%.*s", (int)client->client_secret.size, client->client_secret.start);
  ASSERT_S(ret < sizeof(client_secret), "Out of bounds write attempt");

  CURLcode ecode;
  ecode = curl_easy_setopt(ehandle, CURLOPT_USERNAME, client_id);
  ASSERT_S(CURLE_OK == ecode, curl_easy_strerror(ecode));
  ecode = curl_easy_setopt(ehandle, CURLOPT_PASSWORD, client_secret);
  ASSERT_S(CURLE_OK == ecode, curl_easy_strerror(ecode));
}

void
reddit_adapter_init(struct reddit_adapter *adapter, struct logconf *config)
{
  adapter->ua = ua_init(BASE_API_URL, config);
  logconf_add_id(config, adapter->ua, "REDDIT_HTTP");

  ua_easy_setopt(adapter->ua, adapter->p_client, &curl_setopt_cb);
}

void
reddit_adapter_cleanup(struct reddit_adapter *adapter) {
  ua_cleanup(adapter->ua);
}

/* template function for performing requests */
void
reddit_adapter_run(
  struct reddit_adapter *adapter, 
  struct ua_resp_handle *resp_handle,
  struct sized_buffer *req_body,
  enum http_method http_method, char endpoint[], ...)
{
  va_list args;
  va_start(args, endpoint);

  ua_vrun(
    adapter->ua,
    resp_handle,
    req_body,
    NULL,
    http_method, endpoint, args);

  va_end(args);
}
