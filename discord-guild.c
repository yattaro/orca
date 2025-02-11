#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "discord.h"
#include "discord-internal.h"
#include "orka-utils.h"


void
discord_get_guild(struct discord *client, const u64_snowflake_t guild_id, struct discord_guild *p_guild)
{
  if (!guild_id) {
    log_error("Missing 'guild_id'");
    return;
  }

  struct ua_resp_handle resp_handle =
    { .ok_cb = &discord_guild_from_json_v, .ok_obj = (void*)p_guild};

  discord_adapter_run( 
    &client->adapter,
    &resp_handle,
    NULL,
    HTTP_GET, 
    "/guilds/%"PRIu64, guild_id);
}

void 
discord_create_guild_channel(
  struct discord *client, 
  const u64_snowflake_t guild_id, 
  struct discord_create_guild_channel_params *params, 
  struct discord_channel *p_channel)
{
  if (!guild_id) {
    log_error("Missing 'guild_id");
    return;
  }
  if (IS_EMPTY_STRING(params->name)) {
    log_error("Missing channel name (params.name)");
    return;
  }
  if (!orka_str_bounds_check(params->topic, 1024)) {
    log_error("'params.topic' exceeds threshold of 1024");
    return;
  }

  char payload[MAX_PAYLOAD_LEN];
  discord_create_guild_channel_params_to_json(payload, sizeof(payload), params);

  struct ua_resp_handle resp_handle = {
    .ok_cb = p_channel ? &discord_channel_from_json_v : NULL,
    .ok_obj = p_channel,
  };

  struct sized_buffer req_body = {payload, strlen(payload)};

  discord_adapter_run( 
    &client->adapter,
    &resp_handle,
    &req_body,
    HTTP_POST, 
    "/guilds/%"PRIu64"/channels", guild_id);
}
void
discord_get_guild_channels(
  struct discord *client, 
  const u64_snowflake_t guild_id, 
  NTL_T(struct discord_channel) *p_channels)
{
  if (!guild_id) {
    log_error("Missing 'guild_id'");
    return;
  }

  struct ua_resp_handle resp_handle = 
    { .ok_cb = &discord_channel_list_from_json_v, .ok_obj = (void*)p_channels};

  discord_adapter_run( 
    &client->adapter,
    &resp_handle,
    NULL,
    HTTP_GET, 
    "/guilds/%"PRIu64"/channels", guild_id);
}

void 
discord_get_guild_member(struct discord *client, u64_snowflake_t guild_id, u64_snowflake_t user_id, struct discord_guild_member *p_member) 
{
  if (!guild_id) {
    log_error("Missing 'guild_id'");
    return;
  }
  if (!user_id) {
    log_error("Missing 'user_id'");
    return;
  }

  struct ua_resp_handle resp_handle = {
    .ok_cb = discord_guild_member_from_json_v, .ok_obj = p_member
  };

  discord_adapter_run(
    &client->adapter,
    &resp_handle,
    NULL,
    HTTP_GET, 
    "/guilds/%"PRIu64"/members/%"PRIu64, guild_id, user_id);
}

void
discord_list_guild_members(
  struct discord *client, 
  const u64_snowflake_t guild_id, 
  struct discord_list_guild_members_params *params, 
  NTL_T(struct discord_guild_member) *p_members)
{
  if (!guild_id) {
    log_error("Missing 'guild_id'");
    return;
  }
  if (params->limit < 1 || params->limit > 1000) {
    log_error("'limit' value should be in an interval of (1-1000)");
    return;
  }

  char limit_query[64];
  snprintf(limit_query, sizeof(limit_query),
      "?limit=%d", params->limit);

  char after_query[64] = "";
  if (params->after) {
    snprintf(after_query, sizeof(after_query),
        "&after=%" PRIu64 , params->after);
  }

  struct ua_resp_handle resp_handle =
    { .ok_cb = &discord_guild_member_list_from_json_v, .ok_obj = (void*)p_members};
  
  discord_adapter_run( 
    &client->adapter,
    &resp_handle,
    NULL,
    HTTP_GET,
    "/guilds/%"PRIu64"/members%s%s", guild_id, limit_query, after_query);
}

void 
discord_remove_guild_member(
  struct discord *client, 
  const u64_snowflake_t guild_id, 
  const u64_snowflake_t user_id)
{
  if (!guild_id) {
    log_error("Missing 'guild_id'");
    return;
  }
  if (!user_id) {
    log_error("Missing 'user_id'");
    return;
  }

  discord_adapter_run(
    &client->adapter,
    NULL,
    NULL,
    HTTP_DELETE,
    "/guilds/%"PRIu64"/members/%"PRIu64, guild_id, user_id);
}
void 
discord_modify_guild_member(
  struct discord *client, 
  const u64_snowflake_t guild_id, 
  const u64_snowflake_t user_id, 
  struct discord_modify_guild_member_params *params, 
  struct discord_guild_member *p_member)
{
  if (!guild_id) {
    log_error("Missing 'guild_id'");
    return;
  }
  if (!user_id) {
    log_error("Missing 'user_id'");
    return;
  }

  char payload[MAX_PAYLOAD_LEN];
  discord_modify_guild_member_params_to_json(payload, sizeof(payload), params);

  struct ua_resp_handle resp_handle = {
    .ok_cb = p_member ? &discord_guild_member_from_json_v : NULL,
    .ok_obj = p_member,
  };

  struct sized_buffer req_body = {payload, strlen(payload)};

  discord_adapter_run( 
    &client->adapter,
    &resp_handle,
    &req_body,
    HTTP_PATCH, 
    "/guilds/%"PRIu64"/members/%"PRIu64, guild_id, user_id);
}

void
discord_get_guild_ban(
  struct discord *client, 
  const u64_snowflake_t guild_id, 
  const u64_snowflake_t user_id, 
  struct discord_guild_ban *p_ban)
{
  if (!guild_id) {
    log_error("Missing 'guild_id'");
    return;
  }
  if (!user_id) {
    log_error("Missing 'user_id'");
    return;
  }

  struct ua_resp_handle resp_handle =
    { .ok_cb = &discord_guild_ban_from_json_v, .ok_obj = (void*)p_ban};

  discord_adapter_run( 
    &client->adapter,
    &resp_handle,
    NULL,
    HTTP_GET, 
    "/guilds/%"PRIu64"/bans/%"PRIu64, guild_id, user_id);
}
void
discord_get_guild_bans(
  struct discord *client, 
  const u64_snowflake_t guild_id, 
  NTL_T(struct discord_guild_ban) *p_bans)
{
  if (!guild_id) {
    log_error("Missing 'guild_id'");
    return;
  }

  struct ua_resp_handle resp_handle =
    { .ok_cb = &discord_guild_ban_list_from_json_v, .ok_obj = (void*)p_bans};

  discord_adapter_run( 
    &client->adapter,
    &resp_handle,
    NULL,
    HTTP_GET, 
    "/guilds/%"PRIu64"/bans", guild_id);
}

void
discord_create_guild_ban(
  struct discord *client, 
  const u64_snowflake_t guild_id, 
  const u64_snowflake_t user_id, 
  int delete_message_days, 
  const char reason[])
{
  const int MAX_DELETE_MESSAGE_DAYS = 7;
  if (!guild_id) {
    log_error("Missing 'guild_id'");
    return;
  }
  if (!user_id) {
    log_error("Missing 'user_id'");
    return;
  }
  if (reason && strlen(reason) > MAX_REASON_LEN) {
    log_error("Reason length exceeds %u characters threshold (%zu)",
        MAX_REASON_LEN, strlen(reason));
    return;
  }
  if (delete_message_days < 0 || delete_message_days > MAX_DELETE_MESSAGE_DAYS) {
    log_error("'delete_message_days' is outside the interval (0, %d)",
        MAX_DELETE_MESSAGE_DAYS);
    return;
  }

  void *A[2] = {0}; // pointer availability array.
  if (delete_message_days > 0)
    A[0] = (void *)&delete_message_days;
  if (!IS_EMPTY_STRING(reason))
    A[1] = (void *)reason;

  char payload[MAX_PAYLOAD_LEN];
  int ret = json_inject(payload, sizeof(payload),
                        "(delete_message_days):d"
                        "(reason):s"
                        "@arg_switches",
                        &delete_message_days,
                        reason,
                        A, sizeof(A));

  struct sized_buffer req_body = {payload, (size_t)ret};

  discord_adapter_run( 
    &client->adapter,
    NULL,
    &req_body,
    HTTP_PUT, 
    "/guilds/%"PRIu64"/bans/%"PRIu64, guild_id, user_id);
}

void
discord_get_guild_roles(
  struct discord *client, 
  const u64_snowflake_t guild_id, 
  NTL_T(struct discord_guild_role) *p_roles)
{
  if (!guild_id) {
    log_error("Missing 'guild_id'");
    return;
  }

  struct ua_resp_handle resp_handle =
    { .ok_cb = &discord_guild_role_list_from_json_v, .ok_obj = (void*)p_roles};

  discord_adapter_run( 
    &client->adapter,
    &resp_handle,
    NULL,
    HTTP_GET, 
    "/guilds/%"PRIu64"/roles", guild_id);
}
void
discord_remove_guild_ban(
  struct discord *client, 
  const u64_snowflake_t guild_id, 
  const u64_snowflake_t user_id, 
  const char reason[])
{
  if (!guild_id) {
    log_error("Missing 'guild_id'");
    return;
  }
  if (!user_id) {
    log_error("Missing 'user_id'");
    return;
  }
  if (!orka_str_bounds_check(reason, MAX_REASON_LEN)) {
    log_error("Reason length exceeds %u characters threshold (%zu)",
        MAX_REASON_LEN, strlen(reason));
    return;
  }

  void *A[1] = {0}; // pointer availability array.
  if(!IS_EMPTY_STRING(reason))
    A[0] = (void *)reason;

  char payload[MAX_PAYLOAD_LEN];
  int ret = json_inject(payload, sizeof (payload),
                        "(reason):s"
                        "@arg_switches",
                        reason,
                        A, sizeof(A));

  struct sized_buffer req_body = {payload, (size_t)ret};

  discord_adapter_run( 
    &client->adapter,
    NULL,
    &req_body,
    HTTP_DELETE, 
    "/guilds/%"PRIu64"/bans/%"PRIu64, guild_id, user_id);
}

void 
discord_create_guild_role(
  struct discord *client, 
  const u64_snowflake_t guild_id, 
  struct discord_create_guild_role_params *params, 
  struct discord_guild_role *p_role)
{
  if (!guild_id) {
    log_error("Missing 'guild_id'");
    return;
  }

  char payload[MAX_PAYLOAD_LEN];
  discord_create_guild_role_params_to_json(payload, sizeof(payload), params);

  struct ua_resp_handle resp_handle = {
    .ok_cb = p_role ? &discord_guild_role_from_json_v : NULL,
    .ok_obj = p_role,
  };

  struct sized_buffer req_body = {payload, strlen(payload)};

  discord_adapter_run( 
    &client->adapter,
    &resp_handle,
    &req_body,
    HTTP_POST, 
    "/guilds/%"PRIu64"/roles", guild_id);
}

void 
discord_delete_guild_role(
  struct discord *client, 
  const u64_snowflake_t guild_id, 
  const u64_snowflake_t role_id)
{
  if (!guild_id) {
    log_error("Missing 'guild_id'");
    return;
  }
  if (!role_id) {
    log_error("Missing 'role_id'");
    return;
  }

  discord_adapter_run(
    &client->adapter,
    NULL,
    NULL,
    HTTP_DELETE, 
    "/guilds/%"PRIu64"/roles/%"PRIu64, guild_id, role_id);
}
