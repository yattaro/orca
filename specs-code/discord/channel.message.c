/* This file is generated from specs/discord/channel.message.json, Please don't edit it. */
#include "specs.h"
/*

*/


enum discord_message_sticker_format_types discord_message_sticker_format_types_from_string(char *s){
  if(strcasecmp("PNG", s) == 0) return DISCORD_MESSAGE_STICKER_PNG;
  if(strcasecmp("APNG", s) == 0) return DISCORD_MESSAGE_STICKER_APNG;
  if(strcasecmp("LOTTIE", s) == 0) return DISCORD_MESSAGE_STICKER_LOTTIE;
  abort();
}
char* discord_message_sticker_format_types_to_string(enum discord_message_sticker_format_types v){
  if (v == DISCORD_MESSAGE_STICKER_PNG) return "PNG";
  if (v == DISCORD_MESSAGE_STICKER_APNG) return "APNG";
  if (v == DISCORD_MESSAGE_STICKER_LOTTIE) return "LOTTIE";

  return (void*)0;
}
bool discord_message_sticker_format_types_has(enum discord_message_sticker_format_types v, char *s) {
  enum discord_message_sticker_format_types v1 = discord_message_sticker_format_types_from_string(s);
  if (v == v1) return true;
  if (v == v1) return true;
  if (v == v1) return true;
  return false;
}

void discord_message_sticker_from_json(char *json, size_t len, struct discord_message_sticker *p)
{
  static size_t ret=0; // used for debugging
  size_t r=0;
  r=json_extract(json, len, 
  /* specs/discord/channel.message.json:22:18
     '{"name":"id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}}'
  */
                "(id):F,"
  /* specs/discord/channel.message.json:23:18
     '{"name":"pack_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}}'
  */
                "(pack_id):F,"
  /* specs/discord/channel.message.json:24:18
     '{"name":"name", "type":{"base":"char", "dec":"*"}}'
  */
                "(name):?s,"
  /* specs/discord/channel.message.json:25:18
     '{"name":"description", "type":{"base":"char", "dec":"*"}}'
  */
                "(description):?s,"
  /* specs/discord/channel.message.json:26:18
     '{"name":"tags", "type":{"base":"char", "dec":"*"}, "option":true, "inject_of_not":null}'
  */
                "(tags):?s,"
  /* specs/discord/channel.message.json:27:18
     '{"name":"asset","type":{"base":"char", "dec":"[MAX_SHA256_LEN]"}}'
  */
                "(asset):s,"
  /* specs/discord/channel.message.json:28:18
     '{"name":"preview_asset", "type":{"base":"char", "dec":"[MAX_SHA256_LEN]"}, 
         "option":true, "inject_if_not":""}'
  */
                "(preview_asset):s,"
  /* specs/discord/channel.message.json:30:18
     '{"name":"type", "type":{"base":"int", "int_alias":"enum discord_message_sticker_format_types"}}'
  */
                "(type):d,"
                "@arg_switches:b"
                "@record_defined"
                "@record_null",
  /* specs/discord/channel.message.json:22:18
     '{"name":"id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}}'
  */
                orka_strtoull, &p->id,
  /* specs/discord/channel.message.json:23:18
     '{"name":"pack_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}}'
  */
                orka_strtoull, &p->pack_id,
  /* specs/discord/channel.message.json:24:18
     '{"name":"name", "type":{"base":"char", "dec":"*"}}'
  */
                &p->name,
  /* specs/discord/channel.message.json:25:18
     '{"name":"description", "type":{"base":"char", "dec":"*"}}'
  */
                &p->description,
  /* specs/discord/channel.message.json:26:18
     '{"name":"tags", "type":{"base":"char", "dec":"*"}, "option":true, "inject_of_not":null}'
  */
                &p->tags,
  /* specs/discord/channel.message.json:27:18
     '{"name":"asset","type":{"base":"char", "dec":"[MAX_SHA256_LEN]"}}'
  */
                p->asset,
  /* specs/discord/channel.message.json:28:18
     '{"name":"preview_asset", "type":{"base":"char", "dec":"[MAX_SHA256_LEN]"}, 
         "option":true, "inject_if_not":""}'
  */
                p->preview_asset,
  /* specs/discord/channel.message.json:30:18
     '{"name":"type", "type":{"base":"int", "int_alias":"enum discord_message_sticker_format_types"}}'
  */
                &p->type,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches,
                p->__M.record_defined, sizeof(p->__M.record_defined),
                p->__M.record_null, sizeof(p->__M.record_null));
  ret = r;
}

static void discord_message_sticker_use_default_inject_settings(struct discord_message_sticker *p)
{
  p->__M.enable_arg_switches = true;
  /* specs/discord/channel.message.json:22:18
     '{"name":"id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}}'
  */
  p->__M.arg_switches[0] = &p->id;

  /* specs/discord/channel.message.json:23:18
     '{"name":"pack_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}}'
  */
  p->__M.arg_switches[1] = &p->pack_id;

  /* specs/discord/channel.message.json:24:18
     '{"name":"name", "type":{"base":"char", "dec":"*"}}'
  */
  p->__M.arg_switches[2] = p->name;

  /* specs/discord/channel.message.json:25:18
     '{"name":"description", "type":{"base":"char", "dec":"*"}}'
  */
  p->__M.arg_switches[3] = p->description;

  /* specs/discord/channel.message.json:26:18
     '{"name":"tags", "type":{"base":"char", "dec":"*"}, "option":true, "inject_of_not":null}'
  */
  p->__M.arg_switches[4] = p->tags;

  /* specs/discord/channel.message.json:27:18
     '{"name":"asset","type":{"base":"char", "dec":"[MAX_SHA256_LEN]"}}'
  */
  p->__M.arg_switches[5] = p->asset;

  /* specs/discord/channel.message.json:28:18
     '{"name":"preview_asset", "type":{"base":"char", "dec":"[MAX_SHA256_LEN]"}, 
         "option":true, "inject_if_not":""}'
  */
  if (strlen(p->preview_asset) != 0)
    p->__M.arg_switches[6] = p->preview_asset;

  /* specs/discord/channel.message.json:30:18
     '{"name":"type", "type":{"base":"int", "int_alias":"enum discord_message_sticker_format_types"}}'
  */
  p->__M.arg_switches[7] = &p->type;

}

size_t discord_message_sticker_to_json(char *json, size_t len, struct discord_message_sticker *p)
{
  size_t r;
  discord_message_sticker_use_default_inject_settings(p);
  r=json_inject(json, len, 
  /* specs/discord/channel.message.json:22:18
     '{"name":"id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}}'
  */
                "(id):|F|,"
  /* specs/discord/channel.message.json:23:18
     '{"name":"pack_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}}'
  */
                "(pack_id):|F|,"
  /* specs/discord/channel.message.json:24:18
     '{"name":"name", "type":{"base":"char", "dec":"*"}}'
  */
                "(name):s,"
  /* specs/discord/channel.message.json:25:18
     '{"name":"description", "type":{"base":"char", "dec":"*"}}'
  */
                "(description):s,"
  /* specs/discord/channel.message.json:26:18
     '{"name":"tags", "type":{"base":"char", "dec":"*"}, "option":true, "inject_of_not":null}'
  */
                "(tags):s,"
  /* specs/discord/channel.message.json:27:18
     '{"name":"asset","type":{"base":"char", "dec":"[MAX_SHA256_LEN]"}}'
  */
                "(asset):s,"
  /* specs/discord/channel.message.json:28:18
     '{"name":"preview_asset", "type":{"base":"char", "dec":"[MAX_SHA256_LEN]"}, 
         "option":true, "inject_if_not":""}'
  */
                "(preview_asset):s,"
  /* specs/discord/channel.message.json:30:18
     '{"name":"type", "type":{"base":"int", "int_alias":"enum discord_message_sticker_format_types"}}'
  */
                "(type):d,"
                "@arg_switches:b",
  /* specs/discord/channel.message.json:22:18
     '{"name":"id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}}'
  */
                orka_ulltostr, &p->id,
  /* specs/discord/channel.message.json:23:18
     '{"name":"pack_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}}'
  */
                orka_ulltostr, &p->pack_id,
  /* specs/discord/channel.message.json:24:18
     '{"name":"name", "type":{"base":"char", "dec":"*"}}'
  */
                p->name,
  /* specs/discord/channel.message.json:25:18
     '{"name":"description", "type":{"base":"char", "dec":"*"}}'
  */
                p->description,
  /* specs/discord/channel.message.json:26:18
     '{"name":"tags", "type":{"base":"char", "dec":"*"}, "option":true, "inject_of_not":null}'
  */
                p->tags,
  /* specs/discord/channel.message.json:27:18
     '{"name":"asset","type":{"base":"char", "dec":"[MAX_SHA256_LEN]"}}'
  */
                p->asset,
  /* specs/discord/channel.message.json:28:18
     '{"name":"preview_asset", "type":{"base":"char", "dec":"[MAX_SHA256_LEN]"}, 
         "option":true, "inject_if_not":""}'
  */
                p->preview_asset,
  /* specs/discord/channel.message.json:30:18
     '{"name":"type", "type":{"base":"int", "int_alias":"enum discord_message_sticker_format_types"}}'
  */
                &p->type,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches);
  return r;
}


typedef void (*vfvp)(void *);
typedef void (*vfcpsvp)(char *, size_t, void *);
typedef size_t (*sfcpsvp)(char *, size_t, void *);
void discord_message_sticker_cleanup_v(void *p) {
  discord_message_sticker_cleanup((struct discord_message_sticker *)p);
}

void discord_message_sticker_init_v(void *p) {
  discord_message_sticker_init((struct discord_message_sticker *)p);
}

void discord_message_sticker_free_v(void *p) {
 discord_message_sticker_free((struct discord_message_sticker *)p);
};

void discord_message_sticker_from_json_v(char *json, size_t len, void *p) {
 discord_message_sticker_from_json(json, len, (struct discord_message_sticker*)p);
}

size_t discord_message_sticker_to_json_v(char *json, size_t len, void *p) {
  return discord_message_sticker_to_json(json, len, (struct discord_message_sticker*)p);
}

void discord_message_sticker_list_free_v(void **p) {
  discord_message_sticker_list_free((struct discord_message_sticker**)p);
}

void discord_message_sticker_list_from_json_v(char *str, size_t len, void *p) {
  discord_message_sticker_list_from_json(str, len, (struct discord_message_sticker ***)p);
}

size_t discord_message_sticker_list_to_json_v(char *str, size_t len, void *p){
  return discord_message_sticker_list_to_json(str, len, (struct discord_message_sticker **)p);
}


void discord_message_sticker_cleanup(struct discord_message_sticker *d) {
  /* specs/discord/channel.message.json:22:18
     '{"name":"id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}}'
  */
  //p->id is a scalar
  /* specs/discord/channel.message.json:23:18
     '{"name":"pack_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}}'
  */
  //p->pack_id is a scalar
  /* specs/discord/channel.message.json:24:18
     '{"name":"name", "type":{"base":"char", "dec":"*"}}'
  */
  if (d->name)
    free(d->name);
  /* specs/discord/channel.message.json:25:18
     '{"name":"description", "type":{"base":"char", "dec":"*"}}'
  */
  if (d->description)
    free(d->description);
  /* specs/discord/channel.message.json:26:18
     '{"name":"tags", "type":{"base":"char", "dec":"*"}, "option":true, "inject_of_not":null}'
  */
  if (d->tags)
    free(d->tags);
  /* specs/discord/channel.message.json:27:18
     '{"name":"asset","type":{"base":"char", "dec":"[MAX_SHA256_LEN]"}}'
  */
  //p->asset is a scalar
  /* specs/discord/channel.message.json:28:18
     '{"name":"preview_asset", "type":{"base":"char", "dec":"[MAX_SHA256_LEN]"}, 
         "option":true, "inject_if_not":""}'
  */
  //p->preview_asset is a scalar
  /* specs/discord/channel.message.json:30:18
     '{"name":"type", "type":{"base":"int", "int_alias":"enum discord_message_sticker_format_types"}}'
  */
  //p->type is a scalar
}

void discord_message_sticker_init(struct discord_message_sticker *p) {
  memset(p, 0, sizeof(struct discord_message_sticker));
  /* specs/discord/channel.message.json:22:18
     '{"name":"id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}}'
  */

  /* specs/discord/channel.message.json:23:18
     '{"name":"pack_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}}'
  */

  /* specs/discord/channel.message.json:24:18
     '{"name":"name", "type":{"base":"char", "dec":"*"}}'
  */

  /* specs/discord/channel.message.json:25:18
     '{"name":"description", "type":{"base":"char", "dec":"*"}}'
  */

  /* specs/discord/channel.message.json:26:18
     '{"name":"tags", "type":{"base":"char", "dec":"*"}, "option":true, "inject_of_not":null}'
  */

  /* specs/discord/channel.message.json:27:18
     '{"name":"asset","type":{"base":"char", "dec":"[MAX_SHA256_LEN]"}}'
  */

  /* specs/discord/channel.message.json:28:18
     '{"name":"preview_asset", "type":{"base":"char", "dec":"[MAX_SHA256_LEN]"}, 
         "option":true, "inject_if_not":""}'
  */

  /* specs/discord/channel.message.json:30:18
     '{"name":"type", "type":{"base":"int", "int_alias":"enum discord_message_sticker_format_types"}}'
  */

}
struct discord_message_sticker* discord_message_sticker_alloc() {
  struct discord_message_sticker *p= (struct discord_message_sticker*)malloc(sizeof(struct discord_message_sticker));
  discord_message_sticker_init(p);
  return p;
}

void discord_message_sticker_free(struct discord_message_sticker *p) {
  discord_message_sticker_cleanup(p);
  free(p);
}

void discord_message_sticker_list_free(struct discord_message_sticker **p) {
  ntl_free((void**)p, (vfvp)discord_message_sticker_cleanup);
}

void discord_message_sticker_list_from_json(char *str, size_t len, struct discord_message_sticker ***p)
{
  struct ntl_deserializer d;
  memset(&d, 0, sizeof(d));
  d.elem_size = sizeof(struct discord_message_sticker);
  d.init_elem = discord_message_sticker_init_v;
  d.elem_from_buf = discord_message_sticker_from_json_v;
  d.ntl_recipient_p= (void***)p;
  extract_ntl_from_json(str, len, &d);
}

size_t discord_message_sticker_list_to_json(char *str, size_t len, struct discord_message_sticker **p)
{
  return ntl_to_buf(str, len, (void **)p, NULL, discord_message_sticker_to_json_v);
}



enum discord_message_flags discord_message_flags_from_string(char *s){
  if(strcasecmp("CROSSPOSTED", s) == 0) return DISCORD_MESSAGE_CROSSPOSTED;
  if(strcasecmp("IS_CROSSPOST", s) == 0) return DISCORD_MESSAGE_IS_CROSSPOST;
  if(strcasecmp("SUPRESS_EMBEDS", s) == 0) return DISCORD_MESSAGE_SUPRESS_EMBEDS;
  if(strcasecmp("SOURCE_MESSAGE_DELETED", s) == 0) return DISCORD_MESSAGE_SOURCE_MESSAGE_DELETED;
  if(strcasecmp("URGENT", s) == 0) return DISCORD_MESSAGE_URGENT;
  abort();
}
char* discord_message_flags_to_string(enum discord_message_flags v){
  if (v == DISCORD_MESSAGE_CROSSPOSTED) return "CROSSPOSTED";
  if (v == DISCORD_MESSAGE_IS_CROSSPOST) return "IS_CROSSPOST";
  if (v == DISCORD_MESSAGE_SUPRESS_EMBEDS) return "SUPRESS_EMBEDS";
  if (v == DISCORD_MESSAGE_SOURCE_MESSAGE_DELETED) return "SOURCE_MESSAGE_DELETED";
  if (v == DISCORD_MESSAGE_URGENT) return "URGENT";

  return (void*)0;
}
bool discord_message_flags_has(enum discord_message_flags v, char *s) {
  enum discord_message_flags v1 = discord_message_flags_from_string(s);
  if (v == v1) return true;
  if (v == v1) return true;
  if (v == v1) return true;
  if (v == v1) return true;
  if (v == v1) return true;
  return false;
}

void discord_message_reference_from_json(char *json, size_t len, struct discord_message_reference *p)
{
  static size_t ret=0; // used for debugging
  size_t r=0;
  r=json_extract(json, len, 
  /* specs/discord/channel.message.json:52:18
     '{"name":"message_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}, 
         "option":true, "inject_if_not":0}'
  */
                "(message_id):F,"
  /* specs/discord/channel.message.json:54:18
     '{"name":"channel_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}, 
         "option":true, "inject_if_not":0}'
  */
                "(channel_id):F,"
  /* specs/discord/channel.message.json:56:18
     '{"name":"guild_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}, 
         "option":true, "inject_if_not":0}'
  */
                "(guild_id):F,"
  /* specs/discord/channel.message.json:58:18
     '{"name":"fail_if_not_exists", "type":{"base":"bool"}, 
         "option":true, "inject_if_not":false}'
  */
                "(fail_if_not_exists):b,"
                "@arg_switches:b"
                "@record_defined"
                "@record_null",
  /* specs/discord/channel.message.json:52:18
     '{"name":"message_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}, 
         "option":true, "inject_if_not":0}'
  */
                orka_strtoull, &p->message_id,
  /* specs/discord/channel.message.json:54:18
     '{"name":"channel_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}, 
         "option":true, "inject_if_not":0}'
  */
                orka_strtoull, &p->channel_id,
  /* specs/discord/channel.message.json:56:18
     '{"name":"guild_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}, 
         "option":true, "inject_if_not":0}'
  */
                orka_strtoull, &p->guild_id,
  /* specs/discord/channel.message.json:58:18
     '{"name":"fail_if_not_exists", "type":{"base":"bool"}, 
         "option":true, "inject_if_not":false}'
  */
                &p->fail_if_not_exists,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches,
                p->__M.record_defined, sizeof(p->__M.record_defined),
                p->__M.record_null, sizeof(p->__M.record_null));
  ret = r;
}

static void discord_message_reference_use_default_inject_settings(struct discord_message_reference *p)
{
  p->__M.enable_arg_switches = true;
  /* specs/discord/channel.message.json:52:18
     '{"name":"message_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}, 
         "option":true, "inject_if_not":0}'
  */
  if (p->message_id != 0)
    p->__M.arg_switches[0] = &p->message_id;

  /* specs/discord/channel.message.json:54:18
     '{"name":"channel_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}, 
         "option":true, "inject_if_not":0}'
  */
  if (p->channel_id != 0)
    p->__M.arg_switches[1] = &p->channel_id;

  /* specs/discord/channel.message.json:56:18
     '{"name":"guild_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}, 
         "option":true, "inject_if_not":0}'
  */
  if (p->guild_id != 0)
    p->__M.arg_switches[2] = &p->guild_id;

  /* specs/discord/channel.message.json:58:18
     '{"name":"fail_if_not_exists", "type":{"base":"bool"}, 
         "option":true, "inject_if_not":false}'
  */
  if (p->fail_if_not_exists != false)
    p->__M.arg_switches[3] = &p->fail_if_not_exists;

}

size_t discord_message_reference_to_json(char *json, size_t len, struct discord_message_reference *p)
{
  size_t r;
  discord_message_reference_use_default_inject_settings(p);
  r=json_inject(json, len, 
  /* specs/discord/channel.message.json:52:18
     '{"name":"message_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}, 
         "option":true, "inject_if_not":0}'
  */
                "(message_id):|F|,"
  /* specs/discord/channel.message.json:54:18
     '{"name":"channel_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}, 
         "option":true, "inject_if_not":0}'
  */
                "(channel_id):|F|,"
  /* specs/discord/channel.message.json:56:18
     '{"name":"guild_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}, 
         "option":true, "inject_if_not":0}'
  */
                "(guild_id):|F|,"
  /* specs/discord/channel.message.json:58:18
     '{"name":"fail_if_not_exists", "type":{"base":"bool"}, 
         "option":true, "inject_if_not":false}'
  */
                "(fail_if_not_exists):b,"
                "@arg_switches:b",
  /* specs/discord/channel.message.json:52:18
     '{"name":"message_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}, 
         "option":true, "inject_if_not":0}'
  */
                orka_ulltostr, &p->message_id,
  /* specs/discord/channel.message.json:54:18
     '{"name":"channel_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}, 
         "option":true, "inject_if_not":0}'
  */
                orka_ulltostr, &p->channel_id,
  /* specs/discord/channel.message.json:56:18
     '{"name":"guild_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}, 
         "option":true, "inject_if_not":0}'
  */
                orka_ulltostr, &p->guild_id,
  /* specs/discord/channel.message.json:58:18
     '{"name":"fail_if_not_exists", "type":{"base":"bool"}, 
         "option":true, "inject_if_not":false}'
  */
                &p->fail_if_not_exists,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches);
  return r;
}


typedef void (*vfvp)(void *);
typedef void (*vfcpsvp)(char *, size_t, void *);
typedef size_t (*sfcpsvp)(char *, size_t, void *);
void discord_message_reference_cleanup_v(void *p) {
  discord_message_reference_cleanup((struct discord_message_reference *)p);
}

void discord_message_reference_init_v(void *p) {
  discord_message_reference_init((struct discord_message_reference *)p);
}

void discord_message_reference_free_v(void *p) {
 discord_message_reference_free((struct discord_message_reference *)p);
};

void discord_message_reference_from_json_v(char *json, size_t len, void *p) {
 discord_message_reference_from_json(json, len, (struct discord_message_reference*)p);
}

size_t discord_message_reference_to_json_v(char *json, size_t len, void *p) {
  return discord_message_reference_to_json(json, len, (struct discord_message_reference*)p);
}

void discord_message_reference_list_free_v(void **p) {
  discord_message_reference_list_free((struct discord_message_reference**)p);
}

void discord_message_reference_list_from_json_v(char *str, size_t len, void *p) {
  discord_message_reference_list_from_json(str, len, (struct discord_message_reference ***)p);
}

size_t discord_message_reference_list_to_json_v(char *str, size_t len, void *p){
  return discord_message_reference_list_to_json(str, len, (struct discord_message_reference **)p);
}


void discord_message_reference_cleanup(struct discord_message_reference *d) {
  /* specs/discord/channel.message.json:52:18
     '{"name":"message_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}, 
         "option":true, "inject_if_not":0}'
  */
  //p->message_id is a scalar
  /* specs/discord/channel.message.json:54:18
     '{"name":"channel_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}, 
         "option":true, "inject_if_not":0}'
  */
  //p->channel_id is a scalar
  /* specs/discord/channel.message.json:56:18
     '{"name":"guild_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}, 
         "option":true, "inject_if_not":0}'
  */
  //p->guild_id is a scalar
  /* specs/discord/channel.message.json:58:18
     '{"name":"fail_if_not_exists", "type":{"base":"bool"}, 
         "option":true, "inject_if_not":false}'
  */
  //p->fail_if_not_exists is a scalar
}

void discord_message_reference_init(struct discord_message_reference *p) {
  memset(p, 0, sizeof(struct discord_message_reference));
  /* specs/discord/channel.message.json:52:18
     '{"name":"message_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}, 
         "option":true, "inject_if_not":0}'
  */

  /* specs/discord/channel.message.json:54:18
     '{"name":"channel_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}, 
         "option":true, "inject_if_not":0}'
  */

  /* specs/discord/channel.message.json:56:18
     '{"name":"guild_id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}, 
         "option":true, "inject_if_not":0}'
  */

  /* specs/discord/channel.message.json:58:18
     '{"name":"fail_if_not_exists", "type":{"base":"bool"}, 
         "option":true, "inject_if_not":false}'
  */

}
struct discord_message_reference* discord_message_reference_alloc() {
  struct discord_message_reference *p= (struct discord_message_reference*)malloc(sizeof(struct discord_message_reference));
  discord_message_reference_init(p);
  return p;
}

void discord_message_reference_free(struct discord_message_reference *p) {
  discord_message_reference_cleanup(p);
  free(p);
}

void discord_message_reference_list_free(struct discord_message_reference **p) {
  ntl_free((void**)p, (vfvp)discord_message_reference_cleanup);
}

void discord_message_reference_list_from_json(char *str, size_t len, struct discord_message_reference ***p)
{
  struct ntl_deserializer d;
  memset(&d, 0, sizeof(d));
  d.elem_size = sizeof(struct discord_message_reference);
  d.init_elem = discord_message_reference_init_v;
  d.elem_from_buf = discord_message_reference_from_json_v;
  d.ntl_recipient_p= (void***)p;
  extract_ntl_from_json(str, len, &d);
}

size_t discord_message_reference_list_to_json(char *str, size_t len, struct discord_message_reference **p)
{
  return ntl_to_buf(str, len, (void **)p, NULL, discord_message_reference_to_json_v);
}


void discord_message_application_from_json(char *json, size_t len, struct discord_message_application *p)
{
  static size_t ret=0; // used for debugging
  size_t r=0;
  r=json_extract(json, len, 
  /* specs/discord/channel.message.json:68:18
     '{"name":"id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}}'
  */
                "(id):F,"
  /* specs/discord/channel.message.json:69:18
     '{"name":"cover_image", "type":{"base":"char", "dec":"*"},
         "option":true, "inject_if_not":null}'
  */
                "(cover_image):?s,"
  /* specs/discord/channel.message.json:71:18
     '{"name":"description", "type":{"base":"char", "dec":"*"}}'
  */
                "(description):?s,"
  /* specs/discord/channel.message.json:72:18
     '{"name":"icon", "type":{"base":"char", "dec":"*"}, "inject_if_not":null}'
  */
                "(icon):?s,"
  /* specs/discord/channel.message.json:73:18
     '{"name":"name", "type":{"base":"char", "dec":"*"}}'
  */
                "(name):?s,"
                "@arg_switches:b"
                "@record_defined"
                "@record_null",
  /* specs/discord/channel.message.json:68:18
     '{"name":"id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}}'
  */
                orka_strtoull, &p->id,
  /* specs/discord/channel.message.json:69:18
     '{"name":"cover_image", "type":{"base":"char", "dec":"*"},
         "option":true, "inject_if_not":null}'
  */
                &p->cover_image,
  /* specs/discord/channel.message.json:71:18
     '{"name":"description", "type":{"base":"char", "dec":"*"}}'
  */
                &p->description,
  /* specs/discord/channel.message.json:72:18
     '{"name":"icon", "type":{"base":"char", "dec":"*"}, "inject_if_not":null}'
  */
                &p->icon,
  /* specs/discord/channel.message.json:73:18
     '{"name":"name", "type":{"base":"char", "dec":"*"}}'
  */
                &p->name,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches,
                p->__M.record_defined, sizeof(p->__M.record_defined),
                p->__M.record_null, sizeof(p->__M.record_null));
  ret = r;
}

static void discord_message_application_use_default_inject_settings(struct discord_message_application *p)
{
  p->__M.enable_arg_switches = true;
  /* specs/discord/channel.message.json:68:18
     '{"name":"id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}}'
  */
  p->__M.arg_switches[0] = &p->id;

  /* specs/discord/channel.message.json:69:18
     '{"name":"cover_image", "type":{"base":"char", "dec":"*"},
         "option":true, "inject_if_not":null}'
  */
  if (p->cover_image != NULL)
    p->__M.arg_switches[1] = p->cover_image;

  /* specs/discord/channel.message.json:71:18
     '{"name":"description", "type":{"base":"char", "dec":"*"}}'
  */
  p->__M.arg_switches[2] = p->description;

  /* specs/discord/channel.message.json:72:18
     '{"name":"icon", "type":{"base":"char", "dec":"*"}, "inject_if_not":null}'
  */
  if (p->icon != NULL)
    p->__M.arg_switches[3] = p->icon;

  /* specs/discord/channel.message.json:73:18
     '{"name":"name", "type":{"base":"char", "dec":"*"}}'
  */
  p->__M.arg_switches[4] = p->name;

}

size_t discord_message_application_to_json(char *json, size_t len, struct discord_message_application *p)
{
  size_t r;
  discord_message_application_use_default_inject_settings(p);
  r=json_inject(json, len, 
  /* specs/discord/channel.message.json:68:18
     '{"name":"id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}}'
  */
                "(id):|F|,"
  /* specs/discord/channel.message.json:69:18
     '{"name":"cover_image", "type":{"base":"char", "dec":"*"},
         "option":true, "inject_if_not":null}'
  */
                "(cover_image):s,"
  /* specs/discord/channel.message.json:71:18
     '{"name":"description", "type":{"base":"char", "dec":"*"}}'
  */
                "(description):s,"
  /* specs/discord/channel.message.json:72:18
     '{"name":"icon", "type":{"base":"char", "dec":"*"}, "inject_if_not":null}'
  */
                "(icon):s,"
  /* specs/discord/channel.message.json:73:18
     '{"name":"name", "type":{"base":"char", "dec":"*"}}'
  */
                "(name):s,"
                "@arg_switches:b",
  /* specs/discord/channel.message.json:68:18
     '{"name":"id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}}'
  */
                orka_ulltostr, &p->id,
  /* specs/discord/channel.message.json:69:18
     '{"name":"cover_image", "type":{"base":"char", "dec":"*"},
         "option":true, "inject_if_not":null}'
  */
                p->cover_image,
  /* specs/discord/channel.message.json:71:18
     '{"name":"description", "type":{"base":"char", "dec":"*"}}'
  */
                p->description,
  /* specs/discord/channel.message.json:72:18
     '{"name":"icon", "type":{"base":"char", "dec":"*"}, "inject_if_not":null}'
  */
                p->icon,
  /* specs/discord/channel.message.json:73:18
     '{"name":"name", "type":{"base":"char", "dec":"*"}}'
  */
                p->name,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches);
  return r;
}


typedef void (*vfvp)(void *);
typedef void (*vfcpsvp)(char *, size_t, void *);
typedef size_t (*sfcpsvp)(char *, size_t, void *);
void discord_message_application_cleanup_v(void *p) {
  discord_message_application_cleanup((struct discord_message_application *)p);
}

void discord_message_application_init_v(void *p) {
  discord_message_application_init((struct discord_message_application *)p);
}

void discord_message_application_free_v(void *p) {
 discord_message_application_free((struct discord_message_application *)p);
};

void discord_message_application_from_json_v(char *json, size_t len, void *p) {
 discord_message_application_from_json(json, len, (struct discord_message_application*)p);
}

size_t discord_message_application_to_json_v(char *json, size_t len, void *p) {
  return discord_message_application_to_json(json, len, (struct discord_message_application*)p);
}

void discord_message_application_list_free_v(void **p) {
  discord_message_application_list_free((struct discord_message_application**)p);
}

void discord_message_application_list_from_json_v(char *str, size_t len, void *p) {
  discord_message_application_list_from_json(str, len, (struct discord_message_application ***)p);
}

size_t discord_message_application_list_to_json_v(char *str, size_t len, void *p){
  return discord_message_application_list_to_json(str, len, (struct discord_message_application **)p);
}


void discord_message_application_cleanup(struct discord_message_application *d) {
  /* specs/discord/channel.message.json:68:18
     '{"name":"id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}}'
  */
  //p->id is a scalar
  /* specs/discord/channel.message.json:69:18
     '{"name":"cover_image", "type":{"base":"char", "dec":"*"},
         "option":true, "inject_if_not":null}'
  */
  if (d->cover_image)
    free(d->cover_image);
  /* specs/discord/channel.message.json:71:18
     '{"name":"description", "type":{"base":"char", "dec":"*"}}'
  */
  if (d->description)
    free(d->description);
  /* specs/discord/channel.message.json:72:18
     '{"name":"icon", "type":{"base":"char", "dec":"*"}, "inject_if_not":null}'
  */
  if (d->icon)
    free(d->icon);
  /* specs/discord/channel.message.json:73:18
     '{"name":"name", "type":{"base":"char", "dec":"*"}}'
  */
  if (d->name)
    free(d->name);
}

void discord_message_application_init(struct discord_message_application *p) {
  memset(p, 0, sizeof(struct discord_message_application));
  /* specs/discord/channel.message.json:68:18
     '{"name":"id", "type":{"base":"char", "dec":"*", "converter":"snowflake"}}'
  */

  /* specs/discord/channel.message.json:69:18
     '{"name":"cover_image", "type":{"base":"char", "dec":"*"},
         "option":true, "inject_if_not":null}'
  */

  /* specs/discord/channel.message.json:71:18
     '{"name":"description", "type":{"base":"char", "dec":"*"}}'
  */

  /* specs/discord/channel.message.json:72:18
     '{"name":"icon", "type":{"base":"char", "dec":"*"}, "inject_if_not":null}'
  */

  /* specs/discord/channel.message.json:73:18
     '{"name":"name", "type":{"base":"char", "dec":"*"}}'
  */

}
struct discord_message_application* discord_message_application_alloc() {
  struct discord_message_application *p= (struct discord_message_application*)malloc(sizeof(struct discord_message_application));
  discord_message_application_init(p);
  return p;
}

void discord_message_application_free(struct discord_message_application *p) {
  discord_message_application_cleanup(p);
  free(p);
}

void discord_message_application_list_free(struct discord_message_application **p) {
  ntl_free((void**)p, (vfvp)discord_message_application_cleanup);
}

void discord_message_application_list_from_json(char *str, size_t len, struct discord_message_application ***p)
{
  struct ntl_deserializer d;
  memset(&d, 0, sizeof(d));
  d.elem_size = sizeof(struct discord_message_application);
  d.init_elem = discord_message_application_init_v;
  d.elem_from_buf = discord_message_application_from_json_v;
  d.ntl_recipient_p= (void***)p;
  extract_ntl_from_json(str, len, &d);
}

size_t discord_message_application_list_to_json(char *str, size_t len, struct discord_message_application **p)
{
  return ntl_to_buf(str, len, (void **)p, NULL, discord_message_application_to_json_v);
}



enum discord_message_activity_types discord_message_activity_types_from_string(char *s){
  if(strcasecmp("JOIN", s) == 0) return DISCORD_MESSAGE_ACTIVITY_JOIN;
  if(strcasecmp("SPECTATE", s) == 0) return DISCORD_MESSAGE_ACTIVITY_SPECTATE;
  if(strcasecmp("LISTEN", s) == 0) return DISCORD_MESSAGE_ACTIVITY_LISTEN;
  if(strcasecmp("JOIN_REQUEST", s) == 0) return DISCORD_MESSAGE_ACTIVITY_JOIN_REQUEST;
  abort();
}
char* discord_message_activity_types_to_string(enum discord_message_activity_types v){
  if (v == DISCORD_MESSAGE_ACTIVITY_JOIN) return "JOIN";
  if (v == DISCORD_MESSAGE_ACTIVITY_SPECTATE) return "SPECTATE";
  if (v == DISCORD_MESSAGE_ACTIVITY_LISTEN) return "LISTEN";
  if (v == DISCORD_MESSAGE_ACTIVITY_JOIN_REQUEST) return "JOIN_REQUEST";

  return (void*)0;
}
bool discord_message_activity_types_has(enum discord_message_activity_types v, char *s) {
  enum discord_message_activity_types v1 = discord_message_activity_types_from_string(s);
  if (v == v1) return true;
  if (v == v1) return true;
  if (v == v1) return true;
  if (v == v1) return true;
  return false;
}

void discord_message_activity_from_json(char *json, size_t len, struct discord_message_activity *p)
{
  static size_t ret=0; // used for debugging
  size_t r=0;
  r=json_extract(json, len, 
  /* specs/discord/channel.message.json:94:18
     '{"name":"type", "type":{"base":"int", "int_alias":"enum discord_message_activity_types"}}'
  */
                "(type):d,"
  /* specs/discord/channel.message.json:95:18
     '{"name":"party_id", "type":{"base":"char", "dec":"*"},
         "option":true, "inject_if_not":null}'
  */
                "(party_id):?s,"
                "@arg_switches:b"
                "@record_defined"
                "@record_null",
  /* specs/discord/channel.message.json:94:18
     '{"name":"type", "type":{"base":"int", "int_alias":"enum discord_message_activity_types"}}'
  */
                &p->type,
  /* specs/discord/channel.message.json:95:18
     '{"name":"party_id", "type":{"base":"char", "dec":"*"},
         "option":true, "inject_if_not":null}'
  */
                &p->party_id,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches,
                p->__M.record_defined, sizeof(p->__M.record_defined),
                p->__M.record_null, sizeof(p->__M.record_null));
  ret = r;
}

static void discord_message_activity_use_default_inject_settings(struct discord_message_activity *p)
{
  p->__M.enable_arg_switches = true;
  /* specs/discord/channel.message.json:94:18
     '{"name":"type", "type":{"base":"int", "int_alias":"enum discord_message_activity_types"}}'
  */
  p->__M.arg_switches[0] = &p->type;

  /* specs/discord/channel.message.json:95:18
     '{"name":"party_id", "type":{"base":"char", "dec":"*"},
         "option":true, "inject_if_not":null}'
  */
  if (p->party_id != NULL)
    p->__M.arg_switches[1] = p->party_id;

}

size_t discord_message_activity_to_json(char *json, size_t len, struct discord_message_activity *p)
{
  size_t r;
  discord_message_activity_use_default_inject_settings(p);
  r=json_inject(json, len, 
  /* specs/discord/channel.message.json:94:18
     '{"name":"type", "type":{"base":"int", "int_alias":"enum discord_message_activity_types"}}'
  */
                "(type):d,"
  /* specs/discord/channel.message.json:95:18
     '{"name":"party_id", "type":{"base":"char", "dec":"*"},
         "option":true, "inject_if_not":null}'
  */
                "(party_id):s,"
                "@arg_switches:b",
  /* specs/discord/channel.message.json:94:18
     '{"name":"type", "type":{"base":"int", "int_alias":"enum discord_message_activity_types"}}'
  */
                &p->type,
  /* specs/discord/channel.message.json:95:18
     '{"name":"party_id", "type":{"base":"char", "dec":"*"},
         "option":true, "inject_if_not":null}'
  */
                p->party_id,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches);
  return r;
}


typedef void (*vfvp)(void *);
typedef void (*vfcpsvp)(char *, size_t, void *);
typedef size_t (*sfcpsvp)(char *, size_t, void *);
void discord_message_activity_cleanup_v(void *p) {
  discord_message_activity_cleanup((struct discord_message_activity *)p);
}

void discord_message_activity_init_v(void *p) {
  discord_message_activity_init((struct discord_message_activity *)p);
}

void discord_message_activity_free_v(void *p) {
 discord_message_activity_free((struct discord_message_activity *)p);
};

void discord_message_activity_from_json_v(char *json, size_t len, void *p) {
 discord_message_activity_from_json(json, len, (struct discord_message_activity*)p);
}

size_t discord_message_activity_to_json_v(char *json, size_t len, void *p) {
  return discord_message_activity_to_json(json, len, (struct discord_message_activity*)p);
}

void discord_message_activity_list_free_v(void **p) {
  discord_message_activity_list_free((struct discord_message_activity**)p);
}

void discord_message_activity_list_from_json_v(char *str, size_t len, void *p) {
  discord_message_activity_list_from_json(str, len, (struct discord_message_activity ***)p);
}

size_t discord_message_activity_list_to_json_v(char *str, size_t len, void *p){
  return discord_message_activity_list_to_json(str, len, (struct discord_message_activity **)p);
}


void discord_message_activity_cleanup(struct discord_message_activity *d) {
  /* specs/discord/channel.message.json:94:18
     '{"name":"type", "type":{"base":"int", "int_alias":"enum discord_message_activity_types"}}'
  */
  //p->type is a scalar
  /* specs/discord/channel.message.json:95:18
     '{"name":"party_id", "type":{"base":"char", "dec":"*"},
         "option":true, "inject_if_not":null}'
  */
  if (d->party_id)
    free(d->party_id);
}

void discord_message_activity_init(struct discord_message_activity *p) {
  memset(p, 0, sizeof(struct discord_message_activity));
  /* specs/discord/channel.message.json:94:18
     '{"name":"type", "type":{"base":"int", "int_alias":"enum discord_message_activity_types"}}'
  */

  /* specs/discord/channel.message.json:95:18
     '{"name":"party_id", "type":{"base":"char", "dec":"*"},
         "option":true, "inject_if_not":null}'
  */

}
struct discord_message_activity* discord_message_activity_alloc() {
  struct discord_message_activity *p= (struct discord_message_activity*)malloc(sizeof(struct discord_message_activity));
  discord_message_activity_init(p);
  return p;
}

void discord_message_activity_free(struct discord_message_activity *p) {
  discord_message_activity_cleanup(p);
  free(p);
}

void discord_message_activity_list_free(struct discord_message_activity **p) {
  ntl_free((void**)p, (vfvp)discord_message_activity_cleanup);
}

void discord_message_activity_list_from_json(char *str, size_t len, struct discord_message_activity ***p)
{
  struct ntl_deserializer d;
  memset(&d, 0, sizeof(d));
  d.elem_size = sizeof(struct discord_message_activity);
  d.init_elem = discord_message_activity_init_v;
  d.elem_from_buf = discord_message_activity_from_json_v;
  d.ntl_recipient_p= (void***)p;
  extract_ntl_from_json(str, len, &d);
}

size_t discord_message_activity_list_to_json(char *str, size_t len, struct discord_message_activity **p)
{
  return ntl_to_buf(str, len, (void **)p, NULL, discord_message_activity_to_json_v);
}



enum discord_message_types discord_message_types_from_string(char *s){
  if(strcasecmp("DEFAULT", s) == 0) return DISCORD_MESSAGE_DEFAULT;
  if(strcasecmp("RECIPIENT_ADD", s) == 0) return DISCORD_MESSAGE_RECIPIENT_ADD;
  if(strcasecmp("RECIPIENT_REMOVE", s) == 0) return DISCORD_MESSAGE_RECIPIENT_REMOVE;
  if(strcasecmp("CALL", s) == 0) return DISCORD_MESSAGE_CALL;
  if(strcasecmp("CHANNEL_NAME_CHANGE", s) == 0) return DISCORD_MESSAGE_CHANNEL_NAME_CHANGE;
  if(strcasecmp("CHANNEL_ICON_CHANGE", s) == 0) return DISCORD_MESSAGE_CHANNEL_ICON_CHANGE;
  if(strcasecmp("CHANNEL_PINNED_MESSAGE", s) == 0) return DISCORD_MESSAGE_CHANNEL_PINNED_MESSAGE;
  if(strcasecmp("GUILD_MEMBER_JOIN", s) == 0) return DISCORD_MESSAGE_GUILD_MEMBER_JOIN;
  if(strcasecmp("USER_PREMIUM_GUILD_SUBSCRIPTION", s) == 0) return DISCORD_MESSAGE_USER_PREMIUM_GUILD_SUBSCRIPTION;
  if(strcasecmp("USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_1", s) == 0) return DISCORD_MESSAGE_USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_1;
  if(strcasecmp("USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_2", s) == 0) return DISCORD_MESSAGE_USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_2;
  if(strcasecmp("USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_3", s) == 0) return DISCORD_MESSAGE_USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_3;
  if(strcasecmp("CHANNEL_FOLLOW_ADD", s) == 0) return DISCORD_MESSAGE_CHANNEL_FOLLOW_ADD;
  if(strcasecmp("GUILD_DISCOVERY_DISQUALIFIED", s) == 0) return DISCORD_MESSAGE_GUILD_DISCOVERY_DISQUALIFIED;
  if(strcasecmp("GUILD_DISCOVERY_REQUALIFIED", s) == 0) return DISCORD_MESSAGE_GUILD_DISCOVERY_REQUALIFIED;
  if(strcasecmp("REPLY", s) == 0) return DISCORD_MESSAGE_REPLY;
  if(strcasecmp("APPLICATION_COMMAND", s) == 0) return DISCORD_MESSAGE_APPLICATION_COMMAND;
  abort();
}
char* discord_message_types_to_string(enum discord_message_types v){
  if (v == DISCORD_MESSAGE_DEFAULT) return "DEFAULT";
  if (v == DISCORD_MESSAGE_RECIPIENT_ADD) return "RECIPIENT_ADD";
  if (v == DISCORD_MESSAGE_RECIPIENT_REMOVE) return "RECIPIENT_REMOVE";
  if (v == DISCORD_MESSAGE_CALL) return "CALL";
  if (v == DISCORD_MESSAGE_CHANNEL_NAME_CHANGE) return "CHANNEL_NAME_CHANGE";
  if (v == DISCORD_MESSAGE_CHANNEL_ICON_CHANGE) return "CHANNEL_ICON_CHANGE";
  if (v == DISCORD_MESSAGE_CHANNEL_PINNED_MESSAGE) return "CHANNEL_PINNED_MESSAGE";
  if (v == DISCORD_MESSAGE_GUILD_MEMBER_JOIN) return "GUILD_MEMBER_JOIN";
  if (v == DISCORD_MESSAGE_USER_PREMIUM_GUILD_SUBSCRIPTION) return "USER_PREMIUM_GUILD_SUBSCRIPTION";
  if (v == DISCORD_MESSAGE_USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_1) return "USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_1";
  if (v == DISCORD_MESSAGE_USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_2) return "USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_2";
  if (v == DISCORD_MESSAGE_USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_3) return "USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_3";
  if (v == DISCORD_MESSAGE_CHANNEL_FOLLOW_ADD) return "CHANNEL_FOLLOW_ADD";
  if (v == DISCORD_MESSAGE_GUILD_DISCOVERY_DISQUALIFIED) return "GUILD_DISCOVERY_DISQUALIFIED";
  if (v == DISCORD_MESSAGE_GUILD_DISCOVERY_REQUALIFIED) return "GUILD_DISCOVERY_REQUALIFIED";
  if (v == DISCORD_MESSAGE_REPLY) return "REPLY";
  if (v == DISCORD_MESSAGE_APPLICATION_COMMAND) return "APPLICATION_COMMAND";

  return (void*)0;
}
bool discord_message_types_has(enum discord_message_types v, char *s) {
  enum discord_message_types v1 = discord_message_types_from_string(s);
  if (v == v1) return true;
  if (v == v1) return true;
  if (v == v1) return true;
  if (v == v1) return true;
  if (v == v1) return true;
  if (v == v1) return true;
  if (v == v1) return true;
  if (v == v1) return true;
  if (v == v1) return true;
  if (v == v1) return true;
  if (v == v1) return true;
  if (v == v1) return true;
  if (v == v1) return true;
  if (v == v1) return true;
  if (v == v1) return true;
  if (v == v1) return true;
  if (v == v1) return true;
  return false;
}


/* This method is disabled at specs/discord/channel.message.json:127:31 */
void discord_message_from_json_disabled(char *json, size_t len, struct discord_message *p)
{
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
  ret = r;
}

static void discord_message_use_default_inject_settings(struct discord_message *p)
{
  p->__M.enable_arg_switches = true;
  /* specs/discord/channel.message.json:130:79
     '{"type":{"base":"char", "dec":"*", "converter":"snowflake"}, "name":"id"}'
  */
  p->__M.arg_switches[0] = &p->id;

  /* specs/discord/channel.message.json:131:79
     '{"type":{"base":"char", "dec":"*", "converter":"snowflake"}, "name":"channel_id"}'
  */
  p->__M.arg_switches[1] = &p->channel_id;

  /* specs/discord/channel.message.json:132:79
     '{"type":{"base":"char", "dec":"*", "converter":"snowflake"}, "name":"guild_id",
          "option":true, "inject_if_not":0}'
  */
  if (p->guild_id != 0)
    p->__M.arg_switches[2] = &p->guild_id;

  /* specs/discord/channel.message.json:134:69
     '{"type":{"base":"struct discord_user", "dec":"*"}, "name":"author"}'
  */
  p->__M.arg_switches[3] = p->author;

  /* specs/discord/channel.message.json:135:77
     '{"type":{"base":"struct discord_guild_member", "dec":"*"}, "name":"member", 
          "option":true, "comment":"partial guild member object"}'
  */
  p->__M.arg_switches[4] = p->member;

  /* specs/discord/channel.message.json:137:54
     '{"type":{"base":"char", "dec":"*"}, "name":"content"}'
  */
  p->__M.arg_switches[5] = p->content;

  /* specs/discord/channel.message.json:138:76
     '{"type":{"base":"char", "dec":"*", "converter":"iso8601"},"name":"timestamp"}'
  */
  p->__M.arg_switches[6] = &p->timestamp;

  /* specs/discord/channel.message.json:139:77
     '{"type":{"base":"char", "dec":"*", "converter":"iso8601"}, "name":"edited_timestamp",
          "inject_if_not":0}'
  */
  if (p->edited_timestamp != 0)
    p->__M.arg_switches[7] = &p->edited_timestamp;

  /* specs/discord/channel.message.json:141:43
     '{"type":{"base":"bool"}, "name":"tts"}'
  */
  p->__M.arg_switches[8] = &p->tts;

  /* specs/discord/channel.message.json:142:43
     '{"type":{"base":"bool"}, "name":"mention_everyone"}'
  */
  p->__M.arg_switches[9] = &p->mention_everyone;

  /* specs/discord/channel.message.json:143:71
     '{"type":{"base":"struct discord_user", "dec":"ntl"}, "name":"mentions", 
          "comment":"array of user objects, with an additional partial member field"}'
  */
  p->__M.arg_switches[10] = p->mentions;

  /* specs/discord/channel.message.json:145:58
     '{"type":{"base":"ja_u64", "dec":"ntl"}, "name":"mention_roles", "comment":"array of role object ids"}'
  */
  p->__M.arg_switches[11] = p->mention_roles;

  /* specs/discord/channel.message.json:146:82
     '{"type":{"base":"struct discord_channel_mention", "dec":"ntl"}, "name":"mention_channels",
          "option":true }'
  */
  p->__M.arg_switches[12] = p->mention_channels;

  /* specs/discord/channel.message.json:148:85
     '{"type":{"base":"struct discord_channel_attachment", "dec":"ntl"}, "name":"attachments"}'
  */
  p->__M.arg_switches[13] = p->attachments;

  /* specs/discord/channel.message.json:149:72
     '{"type":{"base":"struct discord_embed", "dec":"ntl"}, "name":"embeds"}'
  */
  p->__M.arg_switches[14] = p->embeds;

  /* specs/discord/channel.message.json:150:82
     '{"type":{"base":"struct discord_channel_reaction","dec":"ntl"}, "name":"reactions", 
          "option":true }'
  */
  p->__M.arg_switches[15] = p->reactions;

  /* specs/discord/channel.message.json:152:54
     '{"type":{"base":"char", "dec":"*"}, "name":"nonce", "comment":"integer or string",
          "option":true }'
  */
  p->__M.arg_switches[16] = p->nonce;

  /* specs/discord/channel.message.json:154:43
     '{"type":{"base":"bool"}, "name":"pinned"}'
  */
  p->__M.arg_switches[17] = &p->pinned;

  /* specs/discord/channel.message.json:155:79
     '{"type":{"base":"char", "dec":"*", "converter":"snowflake"}, "name":"webhook_id",
          "option":true }'
  */
  p->__M.arg_switches[18] = &p->webhook_id;

  /* specs/discord/channel.message.json:157:84
     '{"type":{"base":"int", "int_alias":"enum discord_message_types"}, "name":"type"}'
  */
  p->__M.arg_switches[19] = &p->type;

  /* specs/discord/channel.message.json:158:81
     '{"type":{"base":"struct discord_message_activity", "dec":"*"}, "name":"activity", 
          "option":true, "inject_if_not":null }'
  */
  if (p->activity != NULL)
    p->__M.arg_switches[20] = p->activity;

  /* specs/discord/channel.message.json:160:86
     '{"type":{"base":"struct discord_message_application", "dec":"ntl"}, "name":"application",
          "option":true, "inject_if_not":null }'
  */
  if (p->application != NULL)
    p->__M.arg_switches[21] = p->application;

  /* specs/discord/channel.message.json:162:82
     '{"type":{"base":"struct discord_message_reference", "dec":"*"}, "name":"message_reference",
          "option":true, "inject_if_not":null }'
  */
  if (p->message_reference != NULL)
    p->__M.arg_switches[22] = p->message_reference;

  /* specs/discord/channel.message.json:164:84
     '{"type":{"base":"int", "int_alias":"enum discord_message_flags"}, "name":"flags",
          "option":true, "inject_if_not":0 }'
  */
  if (p->flags != 0)
    p->__M.arg_switches[23] = &p->flags;

  /* specs/discord/channel.message.json:166:82
     '{"type":{"base":"struct discord_message_sticker", "dec":"ntl"}, "name":"stickers",
          "option":true, "inject_if_not":null, "comment":"array of sticker objects"}'
  */
  if (p->stickers != NULL)
    p->__M.arg_switches[24] = p->stickers;

  /* specs/discord/channel.message.json:168:72
     '{"type":{"base":"struct discord_message", "dec":"*"}, "name":"referenced_message", 
          "lazy_init":true, "option":true", "inject_if_not":null,
          "comment":"this will cause recursive allocation if allocating as the parent"}'
  */
  if (p->referenced_message != NULL)
    p->__M.arg_switches[25] = p->referenced_message;

}

size_t discord_message_to_json(char *json, size_t len, struct discord_message *p)
{
  size_t r;
  discord_message_use_default_inject_settings(p);
  r=json_inject(json, len, 
  /* specs/discord/channel.message.json:130:79
     '{"type":{"base":"char", "dec":"*", "converter":"snowflake"}, "name":"id"}'
  */
                "(id):|F|,"
  /* specs/discord/channel.message.json:131:79
     '{"type":{"base":"char", "dec":"*", "converter":"snowflake"}, "name":"channel_id"}'
  */
                "(channel_id):|F|,"
  /* specs/discord/channel.message.json:132:79
     '{"type":{"base":"char", "dec":"*", "converter":"snowflake"}, "name":"guild_id",
          "option":true, "inject_if_not":0}'
  */
                "(guild_id):|F|,"
  /* specs/discord/channel.message.json:134:69
     '{"type":{"base":"struct discord_user", "dec":"*"}, "name":"author"}'
  */
                "(author):F,"
  /* specs/discord/channel.message.json:135:77
     '{"type":{"base":"struct discord_guild_member", "dec":"*"}, "name":"member", 
          "option":true, "comment":"partial guild member object"}'
  */
                "(member):F,"
  /* specs/discord/channel.message.json:137:54
     '{"type":{"base":"char", "dec":"*"}, "name":"content"}'
  */
                "(content):s,"
  /* specs/discord/channel.message.json:138:76
     '{"type":{"base":"char", "dec":"*", "converter":"iso8601"},"name":"timestamp"}'
  */
                "(timestamp):|F|,"
  /* specs/discord/channel.message.json:139:77
     '{"type":{"base":"char", "dec":"*", "converter":"iso8601"}, "name":"edited_timestamp",
          "inject_if_not":0}'
  */
                "(edited_timestamp):|F|,"
  /* specs/discord/channel.message.json:141:43
     '{"type":{"base":"bool"}, "name":"tts"}'
  */
                "(tts):b,"
  /* specs/discord/channel.message.json:142:43
     '{"type":{"base":"bool"}, "name":"mention_everyone"}'
  */
                "(mention_everyone):b,"
  /* specs/discord/channel.message.json:143:71
     '{"type":{"base":"struct discord_user", "dec":"ntl"}, "name":"mentions", 
          "comment":"array of user objects, with an additional partial member field"}'
  */
                "(mentions):F,"
  /* specs/discord/channel.message.json:145:58
     '{"type":{"base":"ja_u64", "dec":"ntl"}, "name":"mention_roles", "comment":"array of role object ids"}'
  */
                "(mention_roles):F,"
  /* specs/discord/channel.message.json:146:82
     '{"type":{"base":"struct discord_channel_mention", "dec":"ntl"}, "name":"mention_channels",
          "option":true }'
  */
                "(mention_channels):F,"
  /* specs/discord/channel.message.json:148:85
     '{"type":{"base":"struct discord_channel_attachment", "dec":"ntl"}, "name":"attachments"}'
  */
                "(attachments):F,"
  /* specs/discord/channel.message.json:149:72
     '{"type":{"base":"struct discord_embed", "dec":"ntl"}, "name":"embeds"}'
  */
                "(embeds):F,"
  /* specs/discord/channel.message.json:150:82
     '{"type":{"base":"struct discord_channel_reaction","dec":"ntl"}, "name":"reactions", 
          "option":true }'
  */
                "(reactions):F,"
  /* specs/discord/channel.message.json:152:54
     '{"type":{"base":"char", "dec":"*"}, "name":"nonce", "comment":"integer or string",
          "option":true }'
  */
                "(nonce):s,"
  /* specs/discord/channel.message.json:154:43
     '{"type":{"base":"bool"}, "name":"pinned"}'
  */
                "(pinned):b,"
  /* specs/discord/channel.message.json:155:79
     '{"type":{"base":"char", "dec":"*", "converter":"snowflake"}, "name":"webhook_id",
          "option":true }'
  */
                "(webhook_id):|F|,"
  /* specs/discord/channel.message.json:157:84
     '{"type":{"base":"int", "int_alias":"enum discord_message_types"}, "name":"type"}'
  */
                "(type):d,"
  /* specs/discord/channel.message.json:158:81
     '{"type":{"base":"struct discord_message_activity", "dec":"*"}, "name":"activity", 
          "option":true, "inject_if_not":null }'
  */
                "(activity):F,"
  /* specs/discord/channel.message.json:160:86
     '{"type":{"base":"struct discord_message_application", "dec":"ntl"}, "name":"application",
          "option":true, "inject_if_not":null }'
  */
                "(application):F,"
  /* specs/discord/channel.message.json:162:82
     '{"type":{"base":"struct discord_message_reference", "dec":"*"}, "name":"message_reference",
          "option":true, "inject_if_not":null }'
  */
                "(message_reference):F,"
  /* specs/discord/channel.message.json:164:84
     '{"type":{"base":"int", "int_alias":"enum discord_message_flags"}, "name":"flags",
          "option":true, "inject_if_not":0 }'
  */
                "(flags):d,"
  /* specs/discord/channel.message.json:166:82
     '{"type":{"base":"struct discord_message_sticker", "dec":"ntl"}, "name":"stickers",
          "option":true, "inject_if_not":null, "comment":"array of sticker objects"}'
  */
                "(stickers):F,"
  /* specs/discord/channel.message.json:168:72
     '{"type":{"base":"struct discord_message", "dec":"*"}, "name":"referenced_message", 
          "lazy_init":true, "option":true", "inject_if_not":null,
          "comment":"this will cause recursive allocation if allocating as the parent"}'
  */
                "(referenced_message):F,"
                "@arg_switches:b",
  /* specs/discord/channel.message.json:130:79
     '{"type":{"base":"char", "dec":"*", "converter":"snowflake"}, "name":"id"}'
  */
                orka_ulltostr, &p->id,
  /* specs/discord/channel.message.json:131:79
     '{"type":{"base":"char", "dec":"*", "converter":"snowflake"}, "name":"channel_id"}'
  */
                orka_ulltostr, &p->channel_id,
  /* specs/discord/channel.message.json:132:79
     '{"type":{"base":"char", "dec":"*", "converter":"snowflake"}, "name":"guild_id",
          "option":true, "inject_if_not":0}'
  */
                orka_ulltostr, &p->guild_id,
  /* specs/discord/channel.message.json:134:69
     '{"type":{"base":"struct discord_user", "dec":"*"}, "name":"author"}'
  */
                discord_user_to_json, p->author,
  /* specs/discord/channel.message.json:135:77
     '{"type":{"base":"struct discord_guild_member", "dec":"*"}, "name":"member", 
          "option":true, "comment":"partial guild member object"}'
  */
                discord_guild_member_to_json, p->member,
  /* specs/discord/channel.message.json:137:54
     '{"type":{"base":"char", "dec":"*"}, "name":"content"}'
  */
                p->content,
  /* specs/discord/channel.message.json:138:76
     '{"type":{"base":"char", "dec":"*", "converter":"iso8601"},"name":"timestamp"}'
  */
                orka_unix_ms_to_iso8601, &p->timestamp,
  /* specs/discord/channel.message.json:139:77
     '{"type":{"base":"char", "dec":"*", "converter":"iso8601"}, "name":"edited_timestamp",
          "inject_if_not":0}'
  */
                orka_unix_ms_to_iso8601, &p->edited_timestamp,
  /* specs/discord/channel.message.json:141:43
     '{"type":{"base":"bool"}, "name":"tts"}'
  */
                &p->tts,
  /* specs/discord/channel.message.json:142:43
     '{"type":{"base":"bool"}, "name":"mention_everyone"}'
  */
                &p->mention_everyone,
  /* specs/discord/channel.message.json:143:71
     '{"type":{"base":"struct discord_user", "dec":"ntl"}, "name":"mentions", 
          "comment":"array of user objects, with an additional partial member field"}'
  */
                discord_user_list_to_json, p->mentions,
  /* specs/discord/channel.message.json:145:58
     '{"type":{"base":"ja_u64", "dec":"ntl"}, "name":"mention_roles", "comment":"array of role object ids"}'
  */
                ja_u64_list_to_json, p->mention_roles,
  /* specs/discord/channel.message.json:146:82
     '{"type":{"base":"struct discord_channel_mention", "dec":"ntl"}, "name":"mention_channels",
          "option":true }'
  */
                discord_channel_mention_list_to_json, p->mention_channels,
  /* specs/discord/channel.message.json:148:85
     '{"type":{"base":"struct discord_channel_attachment", "dec":"ntl"}, "name":"attachments"}'
  */
                discord_channel_attachment_list_to_json, p->attachments,
  /* specs/discord/channel.message.json:149:72
     '{"type":{"base":"struct discord_embed", "dec":"ntl"}, "name":"embeds"}'
  */
                discord_embed_list_to_json, p->embeds,
  /* specs/discord/channel.message.json:150:82
     '{"type":{"base":"struct discord_channel_reaction","dec":"ntl"}, "name":"reactions", 
          "option":true }'
  */
                discord_channel_reaction_list_to_json, p->reactions,
  /* specs/discord/channel.message.json:152:54
     '{"type":{"base":"char", "dec":"*"}, "name":"nonce", "comment":"integer or string",
          "option":true }'
  */
                p->nonce,
  /* specs/discord/channel.message.json:154:43
     '{"type":{"base":"bool"}, "name":"pinned"}'
  */
                &p->pinned,
  /* specs/discord/channel.message.json:155:79
     '{"type":{"base":"char", "dec":"*", "converter":"snowflake"}, "name":"webhook_id",
          "option":true }'
  */
                orka_ulltostr, &p->webhook_id,
  /* specs/discord/channel.message.json:157:84
     '{"type":{"base":"int", "int_alias":"enum discord_message_types"}, "name":"type"}'
  */
                &p->type,
  /* specs/discord/channel.message.json:158:81
     '{"type":{"base":"struct discord_message_activity", "dec":"*"}, "name":"activity", 
          "option":true, "inject_if_not":null }'
  */
                discord_message_activity_to_json, p->activity,
  /* specs/discord/channel.message.json:160:86
     '{"type":{"base":"struct discord_message_application", "dec":"ntl"}, "name":"application",
          "option":true, "inject_if_not":null }'
  */
                discord_message_application_list_to_json, p->application,
  /* specs/discord/channel.message.json:162:82
     '{"type":{"base":"struct discord_message_reference", "dec":"*"}, "name":"message_reference",
          "option":true, "inject_if_not":null }'
  */
                discord_message_reference_to_json, p->message_reference,
  /* specs/discord/channel.message.json:164:84
     '{"type":{"base":"int", "int_alias":"enum discord_message_flags"}, "name":"flags",
          "option":true, "inject_if_not":0 }'
  */
                &p->flags,
  /* specs/discord/channel.message.json:166:82
     '{"type":{"base":"struct discord_message_sticker", "dec":"ntl"}, "name":"stickers",
          "option":true, "inject_if_not":null, "comment":"array of sticker objects"}'
  */
                discord_message_sticker_list_to_json, p->stickers,
  /* specs/discord/channel.message.json:168:72
     '{"type":{"base":"struct discord_message", "dec":"*"}, "name":"referenced_message", 
          "lazy_init":true, "option":true", "inject_if_not":null,
          "comment":"this will cause recursive allocation if allocating as the parent"}'
  */
                discord_message_to_json, p->referenced_message,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches);
  return r;
}


typedef void (*vfvp)(void *);
typedef void (*vfcpsvp)(char *, size_t, void *);
typedef size_t (*sfcpsvp)(char *, size_t, void *);
void discord_message_cleanup_v(void *p) {
  discord_message_cleanup((struct discord_message *)p);
}

void discord_message_init_v(void *p) {
  discord_message_init((struct discord_message *)p);
}

void discord_message_free_v(void *p) {
 discord_message_free((struct discord_message *)p);
};

void discord_message_from_json_v(char *json, size_t len, void *p) {
 discord_message_from_json(json, len, (struct discord_message*)p);
}

size_t discord_message_to_json_v(char *json, size_t len, void *p) {
  return discord_message_to_json(json, len, (struct discord_message*)p);
}

void discord_message_list_free_v(void **p) {
  discord_message_list_free((struct discord_message**)p);
}

void discord_message_list_from_json_v(char *str, size_t len, void *p) {
  discord_message_list_from_json(str, len, (struct discord_message ***)p);
}

size_t discord_message_list_to_json_v(char *str, size_t len, void *p){
  return discord_message_list_to_json(str, len, (struct discord_message **)p);
}


void discord_message_cleanup(struct discord_message *d) {
  /* specs/discord/channel.message.json:130:79
     '{"type":{"base":"char", "dec":"*", "converter":"snowflake"}, "name":"id"}'
  */
  //p->id is a scalar
  /* specs/discord/channel.message.json:131:79
     '{"type":{"base":"char", "dec":"*", "converter":"snowflake"}, "name":"channel_id"}'
  */
  //p->channel_id is a scalar
  /* specs/discord/channel.message.json:132:79
     '{"type":{"base":"char", "dec":"*", "converter":"snowflake"}, "name":"guild_id",
          "option":true, "inject_if_not":0}'
  */
  //p->guild_id is a scalar
  /* specs/discord/channel.message.json:134:69
     '{"type":{"base":"struct discord_user", "dec":"*"}, "name":"author"}'
  */
  if (d->author)
    discord_user_free(d->author);
  /* specs/discord/channel.message.json:135:77
     '{"type":{"base":"struct discord_guild_member", "dec":"*"}, "name":"member", 
          "option":true, "comment":"partial guild member object"}'
  */
  if (d->member)
    discord_guild_member_free(d->member);
  /* specs/discord/channel.message.json:137:54
     '{"type":{"base":"char", "dec":"*"}, "name":"content"}'
  */
  if (d->content)
    free(d->content);
  /* specs/discord/channel.message.json:138:76
     '{"type":{"base":"char", "dec":"*", "converter":"iso8601"},"name":"timestamp"}'
  */
  //p->timestamp is a scalar
  /* specs/discord/channel.message.json:139:77
     '{"type":{"base":"char", "dec":"*", "converter":"iso8601"}, "name":"edited_timestamp",
          "inject_if_not":0}'
  */
  //p->edited_timestamp is a scalar
  /* specs/discord/channel.message.json:141:43
     '{"type":{"base":"bool"}, "name":"tts"}'
  */
  //p->tts is a scalar
  /* specs/discord/channel.message.json:142:43
     '{"type":{"base":"bool"}, "name":"mention_everyone"}'
  */
  //p->mention_everyone is a scalar
  /* specs/discord/channel.message.json:143:71
     '{"type":{"base":"struct discord_user", "dec":"ntl"}, "name":"mentions", 
          "comment":"array of user objects, with an additional partial member field"}'
  */
  if (d->mentions)
    discord_user_list_free(d->mentions);
  /* specs/discord/channel.message.json:145:58
     '{"type":{"base":"ja_u64", "dec":"ntl"}, "name":"mention_roles", "comment":"array of role object ids"}'
  */
  if (d->mention_roles)
    ja_u64_list_free(d->mention_roles);
  /* specs/discord/channel.message.json:146:82
     '{"type":{"base":"struct discord_channel_mention", "dec":"ntl"}, "name":"mention_channels",
          "option":true }'
  */
  if (d->mention_channels)
    discord_channel_mention_list_free(d->mention_channels);
  /* specs/discord/channel.message.json:148:85
     '{"type":{"base":"struct discord_channel_attachment", "dec":"ntl"}, "name":"attachments"}'
  */
  if (d->attachments)
    discord_channel_attachment_list_free(d->attachments);
  /* specs/discord/channel.message.json:149:72
     '{"type":{"base":"struct discord_embed", "dec":"ntl"}, "name":"embeds"}'
  */
  if (d->embeds)
    discord_embed_list_free(d->embeds);
  /* specs/discord/channel.message.json:150:82
     '{"type":{"base":"struct discord_channel_reaction","dec":"ntl"}, "name":"reactions", 
          "option":true }'
  */
  if (d->reactions)
    discord_channel_reaction_list_free(d->reactions);
  /* specs/discord/channel.message.json:152:54
     '{"type":{"base":"char", "dec":"*"}, "name":"nonce", "comment":"integer or string",
          "option":true }'
  */
  if (d->nonce)
    free(d->nonce);
  /* specs/discord/channel.message.json:154:43
     '{"type":{"base":"bool"}, "name":"pinned"}'
  */
  //p->pinned is a scalar
  /* specs/discord/channel.message.json:155:79
     '{"type":{"base":"char", "dec":"*", "converter":"snowflake"}, "name":"webhook_id",
          "option":true }'
  */
  //p->webhook_id is a scalar
  /* specs/discord/channel.message.json:157:84
     '{"type":{"base":"int", "int_alias":"enum discord_message_types"}, "name":"type"}'
  */
  //p->type is a scalar
  /* specs/discord/channel.message.json:158:81
     '{"type":{"base":"struct discord_message_activity", "dec":"*"}, "name":"activity", 
          "option":true, "inject_if_not":null }'
  */
  if (d->activity)
    discord_message_activity_free(d->activity);
  /* specs/discord/channel.message.json:160:86
     '{"type":{"base":"struct discord_message_application", "dec":"ntl"}, "name":"application",
          "option":true, "inject_if_not":null }'
  */
  if (d->application)
    discord_message_application_list_free(d->application);
  /* specs/discord/channel.message.json:162:82
     '{"type":{"base":"struct discord_message_reference", "dec":"*"}, "name":"message_reference",
          "option":true, "inject_if_not":null }'
  */
  if (d->message_reference)
    discord_message_reference_free(d->message_reference);
  /* specs/discord/channel.message.json:164:84
     '{"type":{"base":"int", "int_alias":"enum discord_message_flags"}, "name":"flags",
          "option":true, "inject_if_not":0 }'
  */
  //p->flags is a scalar
  /* specs/discord/channel.message.json:166:82
     '{"type":{"base":"struct discord_message_sticker", "dec":"ntl"}, "name":"stickers",
          "option":true, "inject_if_not":null, "comment":"array of sticker objects"}'
  */
  if (d->stickers)
    discord_message_sticker_list_free(d->stickers);
  /* specs/discord/channel.message.json:168:72
     '{"type":{"base":"struct discord_message", "dec":"*"}, "name":"referenced_message", 
          "lazy_init":true, "option":true", "inject_if_not":null,
          "comment":"this will cause recursive allocation if allocating as the parent"}'
  */
  if (d->referenced_message)
    discord_message_free(d->referenced_message);
}

void discord_message_init(struct discord_message *p) {
  memset(p, 0, sizeof(struct discord_message));
  /* specs/discord/channel.message.json:130:79
     '{"type":{"base":"char", "dec":"*", "converter":"snowflake"}, "name":"id"}'
  */

  /* specs/discord/channel.message.json:131:79
     '{"type":{"base":"char", "dec":"*", "converter":"snowflake"}, "name":"channel_id"}'
  */

  /* specs/discord/channel.message.json:132:79
     '{"type":{"base":"char", "dec":"*", "converter":"snowflake"}, "name":"guild_id",
          "option":true, "inject_if_not":0}'
  */

  /* specs/discord/channel.message.json:134:69
     '{"type":{"base":"struct discord_user", "dec":"*"}, "name":"author"}'
  */
  p->author = discord_user_alloc();

  /* specs/discord/channel.message.json:135:77
     '{"type":{"base":"struct discord_guild_member", "dec":"*"}, "name":"member", 
          "option":true, "comment":"partial guild member object"}'
  */
  p->member = discord_guild_member_alloc();

  /* specs/discord/channel.message.json:137:54
     '{"type":{"base":"char", "dec":"*"}, "name":"content"}'
  */

  /* specs/discord/channel.message.json:138:76
     '{"type":{"base":"char", "dec":"*", "converter":"iso8601"},"name":"timestamp"}'
  */

  /* specs/discord/channel.message.json:139:77
     '{"type":{"base":"char", "dec":"*", "converter":"iso8601"}, "name":"edited_timestamp",
          "inject_if_not":0}'
  */

  /* specs/discord/channel.message.json:141:43
     '{"type":{"base":"bool"}, "name":"tts"}'
  */

  /* specs/discord/channel.message.json:142:43
     '{"type":{"base":"bool"}, "name":"mention_everyone"}'
  */

  /* specs/discord/channel.message.json:143:71
     '{"type":{"base":"struct discord_user", "dec":"ntl"}, "name":"mentions", 
          "comment":"array of user objects, with an additional partial member field"}'
  */

  /* specs/discord/channel.message.json:145:58
     '{"type":{"base":"ja_u64", "dec":"ntl"}, "name":"mention_roles", "comment":"array of role object ids"}'
  */

  /* specs/discord/channel.message.json:146:82
     '{"type":{"base":"struct discord_channel_mention", "dec":"ntl"}, "name":"mention_channels",
          "option":true }'
  */

  /* specs/discord/channel.message.json:148:85
     '{"type":{"base":"struct discord_channel_attachment", "dec":"ntl"}, "name":"attachments"}'
  */

  /* specs/discord/channel.message.json:149:72
     '{"type":{"base":"struct discord_embed", "dec":"ntl"}, "name":"embeds"}'
  */

  /* specs/discord/channel.message.json:150:82
     '{"type":{"base":"struct discord_channel_reaction","dec":"ntl"}, "name":"reactions", 
          "option":true }'
  */

  /* specs/discord/channel.message.json:152:54
     '{"type":{"base":"char", "dec":"*"}, "name":"nonce", "comment":"integer or string",
          "option":true }'
  */

  /* specs/discord/channel.message.json:154:43
     '{"type":{"base":"bool"}, "name":"pinned"}'
  */

  /* specs/discord/channel.message.json:155:79
     '{"type":{"base":"char", "dec":"*", "converter":"snowflake"}, "name":"webhook_id",
          "option":true }'
  */

  /* specs/discord/channel.message.json:157:84
     '{"type":{"base":"int", "int_alias":"enum discord_message_types"}, "name":"type"}'
  */

  /* specs/discord/channel.message.json:158:81
     '{"type":{"base":"struct discord_message_activity", "dec":"*"}, "name":"activity", 
          "option":true, "inject_if_not":null }'
  */
  p->activity = discord_message_activity_alloc();

  /* specs/discord/channel.message.json:160:86
     '{"type":{"base":"struct discord_message_application", "dec":"ntl"}, "name":"application",
          "option":true, "inject_if_not":null }'
  */

  /* specs/discord/channel.message.json:162:82
     '{"type":{"base":"struct discord_message_reference", "dec":"*"}, "name":"message_reference",
          "option":true, "inject_if_not":null }'
  */
  p->message_reference = discord_message_reference_alloc();

  /* specs/discord/channel.message.json:164:84
     '{"type":{"base":"int", "int_alias":"enum discord_message_flags"}, "name":"flags",
          "option":true, "inject_if_not":0 }'
  */

  /* specs/discord/channel.message.json:166:82
     '{"type":{"base":"struct discord_message_sticker", "dec":"ntl"}, "name":"stickers",
          "option":true, "inject_if_not":null, "comment":"array of sticker objects"}'
  */

  /* specs/discord/channel.message.json:168:72
     '{"type":{"base":"struct discord_message", "dec":"*"}, "name":"referenced_message", 
          "lazy_init":true, "option":true", "inject_if_not":null,
          "comment":"this will cause recursive allocation if allocating as the parent"}'
  */

}
struct discord_message* discord_message_alloc() {
  struct discord_message *p= (struct discord_message*)malloc(sizeof(struct discord_message));
  discord_message_init(p);
  return p;
}

void discord_message_free(struct discord_message *p) {
  discord_message_cleanup(p);
  free(p);
}

void discord_message_list_free(struct discord_message **p) {
  ntl_free((void**)p, (vfvp)discord_message_cleanup);
}

void discord_message_list_from_json(char *str, size_t len, struct discord_message ***p)
{
  struct ntl_deserializer d;
  memset(&d, 0, sizeof(d));
  d.elem_size = sizeof(struct discord_message);
  d.init_elem = discord_message_init_v;
  d.elem_from_buf = discord_message_from_json_v;
  d.ntl_recipient_p= (void***)p;
  extract_ntl_from_json(str, len, &d);
}

size_t discord_message_list_to_json(char *str, size_t len, struct discord_message **p)
{
  return ntl_to_buf(str, len, (void **)p, NULL, discord_message_to_json_v);
}

