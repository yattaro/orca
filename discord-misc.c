#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "discord.h"
#include "discord-internal.h"
#include "orka-utils.h"

struct msg {
  u64_snowflake_t id;
  bool matched;
};

void
discord_delete_messages_by_author_id(
  struct discord *client, 
  u64_snowflake_t channel_id, 
  u64_snowflake_t author_id)
{
  if (!channel_id) {
    log_error("Missing 'channel_id");
    return;
  }

  struct discord_get_channel_messages_params params = {
    .limit = 100
  };

  NTL_T(struct discord_message) messages = NULL;
  discord_get_channel_messages(client, channel_id, &params, &messages);

  u64_unix_ms_t now = orka_timestamp_ms();

  NTL_T(u64_snowflake_t) list = NULL;
  int count = 0;
  for (int i = 0; messages[i]; i++) {
    if(now > messages[i]->timestamp && now - messages[i]->timestamp > 1209600000)
    {
      break;
    }
    if (author_id == 0)
      count ++;
    else if (messages[i]->author->id == author_id)
      count ++;
  }
  if (count == 0)
    return;
  list = (NTL_T(u64_snowflake_t))ntl_calloc(count, sizeof(u64_snowflake_t));

  for (int i = 0, j = 0; messages[i] && j < count; i++) {
    if (author_id == 0) {
      *list[j] = messages[i]->id;
      j++;
    }
    else if (messages[i]->author->id == author_id) {
      *list[j] = messages[i]->id;
      j++;
    }
  }
  ntl_free((ntl_t)messages, discord_message_cleanup_v);

  if (count == 1)
    discord_delete_message(client, channel_id, *list[0]);
  else
    discord_bulk_delete_messages(client, channel_id, list);
}

void
discord_message_from_json(char *json, size_t len, struct discord_message *p)
{
  p->referenced_message = discord_message_alloc();

  static size_t ret=0; // used for debugging
  size_t r=0;
  r=json_extract(json, len, 
                "(id):F,"
                "(channel_id):F,"
                "(guild_id):F,"
                "(author):F,"
                "(member):F,"
                "(content):?s,"
                "(timestamp):F,"
                "(edited_timestamp):F,"
                "(tts):b,"
                "(mention_everyone):b,"
                "(mentions):F,"
                "(mention_roles):F,"
                "(mention_channels):F,"
                "(attachments):F,"
                "(embeds):F,"
                "(reactions):F,"
                "(nonce):?s,"
                "(pinned):b,"
                "(webhook_id):F,"
                "(type):d,"
                "(activity):F,"
                "(application):F,"
                "(message_reference):F,"
                "(flags):d,"
                "(stickers):F,"
                "(referenced_message):F,"
                "@arg_switches:b"
                "@record_defined"
                "@record_null",
                orka_strtoull, &p->id,
                orka_strtoull, &p->channel_id,
                orka_strtoull, &p->guild_id,
                discord_user_from_json, p->author,
                discord_guild_member_from_json, p->member,
                &p->content,
                orka_iso8601_to_unix_ms, &p->timestamp,
                orka_iso8601_to_unix_ms, &p->edited_timestamp,
                &p->tts,
                &p->mention_everyone,
                discord_user_list_from_json, &p->mentions,
                ja_u64_list_from_json, &p->mention_roles,
                discord_channel_mention_list_from_json, &p->mention_channels,
                discord_channel_attachment_list_from_json, &p->attachments,
                discord_embed_list_from_json, &p->embeds,
                discord_channel_reaction_list_from_json, &p->reactions,
                &p->nonce,
                &p->pinned,
                orka_strtoull, &p->webhook_id,
                &p->type,
                discord_message_activity_from_json, p->activity,
                discord_message_application_list_from_json, &p->application,
                discord_message_reference_from_json, p->message_reference,
                &p->flags,
                discord_message_sticker_list_from_json, &p->stickers,
                discord_message_from_json, p->referenced_message,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches,
                p->__M.record_defined, sizeof(p->__M.record_defined),
                p->__M.record_null, sizeof(p->__M.record_null));

  if(!p->referenced_message->id) {
    discord_message_free(p->referenced_message);
    p->referenced_message = NULL;
  }
  ret = r;
}

void discord_channel_overwrite_from_json(char *json, size_t len, struct discord_channel_overwrite *p)
{
  static size_t ret=0; //used for debugging
  size_t r=0;

  r=json_extract(json, len,
                 "(id):F,"
                 //"(type):s," @todo
                 //"(allow_new):s," @todo
                 "(allow):lld,"
                 //"(deny_new):s," @todo
                 "(deny):lld,"
                 "@arg_switches:b"
                 "@record_defined"
                 "@record_null",
                 orka_strtoull, &p->id,
                 //&p->type,
                 &p->allow,
                 &p->deny,
                 p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches,
                 p->__M.record_defined, sizeof(p->__M.record_defined),
                 p->__M.record_null, sizeof(p->__M.record_null));
  ret = r;
  (void)ret;
}

size_t 
discord_channel_overwrite_to_json(char *json, size_t len, struct discord_channel_overwrite *p)
{
  size_t r;
  r=json_inject(json, len,
                "(id):|F|,"
                "(type):d,"
                "(allow):s_as_u64,"
                "(deny):s_as_u64,"
                "@arg_switches:b",
                orka_ulltostr, &p->id,
                &p->type,
                &p->allow,
                &p->deny,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches);
  return r;
}

void
discord_embed_set_footer(
  struct discord_embed *embed, 
  char text[], 
  char icon_url[], 
  char proxy_icon_url[])
{
  if (IS_EMPTY_STRING(text)) {
    log_error("Missing 'text'");
    return;
  }

  if (embed->footer) {
    free(embed->footer);
  }

  struct discord_embed_footer *new_footer = discord_embed_footer_alloc();
  strncpy(new_footer->text, text, EMBED_FOOTER_TEXT_LEN);
  if (!IS_EMPTY_STRING(icon_url))
    strncpy(new_footer->icon_url, icon_url, MAX_URL_LEN);
  if (!IS_EMPTY_STRING(proxy_icon_url))
    strncpy(new_footer->proxy_icon_url, proxy_icon_url, MAX_URL_LEN);

  embed->footer = new_footer;
}

void
discord_embed_set_thumbnail(
  struct discord_embed *embed, 
  char url[], 
  char proxy_url[], 
  int height, 
  int width)
{
  if (embed->thumbnail) {
    free(embed->thumbnail);
  }

  struct discord_embed_thumbnail *new_thumbnail = discord_embed_thumbnail_alloc();
  if (!IS_EMPTY_STRING(url))
    strncpy(new_thumbnail->url, url, MAX_URL_LEN);
  if (!IS_EMPTY_STRING(proxy_url))
    strncpy(new_thumbnail->proxy_url, proxy_url, MAX_URL_LEN);
  if (height)
    new_thumbnail->height = height;
  if (width)
    new_thumbnail->width = width;

  embed->thumbnail = new_thumbnail;
}

void
discord_embed_set_image(
  struct discord_embed *embed, 
  char url[], 
  char proxy_url[], 
  int height, 
  int width)
{
  if (embed->image) {
    free(embed->image);
  }

  struct discord_embed_image *new_image = discord_embed_image_alloc();
  if (!IS_EMPTY_STRING(url))
    strncpy(new_image->url, url, MAX_URL_LEN);
  if (!IS_EMPTY_STRING(proxy_url))
    strncpy(new_image->proxy_url, proxy_url, MAX_URL_LEN);
  if (height)
    new_image->height = height;
  if (width)
    new_image->width = width;

  embed->image = new_image;
}

void
discord_embed_set_video(
  struct discord_embed *embed, 
  char url[], 
  char proxy_url[], 
  int height, 
  int width)
{
  if (embed->video) {
    free(embed->video);
  }

  struct discord_embed_video *new_video = discord_embed_video_alloc();
  if (!IS_EMPTY_STRING(url))
    strncpy(new_video->url, url, MAX_URL_LEN);
  if (!IS_EMPTY_STRING(proxy_url))
    strncpy(new_video->proxy_url, proxy_url, MAX_URL_LEN);
  if (height)
    new_video->height = height;
  if (width)
    new_video->width = width;

  embed->video = new_video;
}

void
discord_embed_set_provider(struct discord_embed *embed, char name[], char url[])
{
  if (embed->provider) {
    free(embed->provider);
  }

  struct discord_embed_provider *new_provider = discord_embed_provider_alloc();
  if (!IS_EMPTY_STRING(url))
    strncpy(new_provider->url, url, MAX_URL_LEN);
  if (!IS_EMPTY_STRING(name))
    strncpy(new_provider->name, name, EMBED_AUTHOR_NAME_LEN);

  embed->provider = new_provider;
}

void
discord_embed_set_author(
  struct discord_embed *embed, 
  char name[], 
  char url[], 
  char icon_url[], 
  char proxy_icon_url[])
{
  if (embed->author) {
    free(embed->author);
  }

  struct discord_embed_author *new_author = discord_embed_author_alloc();
  if (!IS_EMPTY_STRING(name))
    strncpy(new_author->name, name, EMBED_AUTHOR_NAME_LEN);
  if (!IS_EMPTY_STRING(url))
    strncpy(new_author->url, url, MAX_URL_LEN);
  if (!IS_EMPTY_STRING(icon_url))
    strncpy(new_author->icon_url, icon_url, MAX_URL_LEN);
  if (!IS_EMPTY_STRING(proxy_icon_url))
    strncpy(new_author->proxy_icon_url, proxy_icon_url, MAX_URL_LEN);

  embed->author = new_author;
}

void
discord_embed_add_field(struct discord_embed *embed, char name[], char value[], bool Inline)
{
  if (ntl_length((ntl_t)embed->fields) >= EMBED_MAX_FIELDS) {
    log_error("Reach embed fields threshold (max %d)", EMBED_MAX_FIELDS);
    return;
  }
  if (IS_EMPTY_STRING(name)) {
    log_error("Missing 'name'");
    return;
  }
  if (IS_EMPTY_STRING(value)) {
    log_error("Missing 'value'");
    return;
  }

  struct discord_embed_field *field = discord_embed_field_alloc();
  field->Inline = Inline;

  size_t ret;
  if (!(ret = orka_str_bounds_check(name, sizeof(field->name)))) {
    log_warn("'name' exceeds %d characters, truncation will occur", sizeof(field->name));
    snprintf(field->name, sizeof(field->name), "%.*s(...)", \
        (int)(sizeof(field->name)-6), name);
  }
  else {
    snprintf(field->name, sizeof(field->name), "%s", name);
  }

  if (!(ret = orka_str_bounds_check(value, sizeof(field->value)))) {
    log_warn("'value' exceeds %d characters, truncation will occur", sizeof(field->value));
    snprintf(field->value, sizeof(field->value), "%.*s(...)", \
        (int)(sizeof(field->value)-6), value);
  }
  else {
    snprintf(field->value, sizeof(field->value), "%s", value);
  }

  ntl_append2((ntl_t*)&embed->fields, sizeof(struct discord_embed_field), field);

  discord_embed_field_free(field);
}

void
discord_overwrite_append(
  NTL_T(struct discord_channel_overwrite) *permission_overwrites, 
  u64_snowflake_t id, 
  int type, 
  enum discord_permissions_bitwise_flags allow, 
  enum discord_permissions_bitwise_flags deny)
{
  if (!id) {
    log_error("Missing 'id'");
    return;
  }
  if ( !(0 == type || 1 == type) ) {
    log_error("'type' should be 0 (role) or 1 (member)");
    return;
  }

  struct discord_channel_overwrite new_overwrite;
  discord_channel_overwrite_init(&new_overwrite);
  new_overwrite.id = id;
  new_overwrite.type = type;
  new_overwrite.allow = allow;
  new_overwrite.deny = deny;

  ntl_append2((ntl_t*)permission_overwrites, sizeof(struct discord_channel_overwrite), &new_overwrite);
}

//@todo create some manner of copying a struct, including its pointer fields
void
discord_get_channel_at_pos(
  struct discord *client, 
  const u64_snowflake_t guild_id, 
  const enum discord_channel_types type,
  const size_t position,
  struct discord_channel *p_channel)
{
  NTL_T(struct discord_channel) channels = NULL;
  discord_get_guild_channels(client, guild_id, &channels);
  if (NULL == channels) return;

  size_t j=0; // calculate position
  for (size_t i=0; channels[i]; ++i) {
    if (type == channels[i]->type && j++ == position) {
      memcpy(p_channel, channels[i], sizeof(struct discord_channel));
      // avoid double freeing
      p_channel->permission_overwrites = NULL;
      p_channel->recipients = NULL;
      p_channel->messages = NULL;
      break; /* EARLY BREAK */
    }
  }
  discord_channel_list_free(channels);
}
