/* This file is generated from specs/discord/webhook.edit-webhook-message.json, Please don't edit it. */
#include "specs.h"
/*

*/

void discord_edit_webhook_message_params_from_json(char *json, size_t len, struct discord_edit_webhook_message_params *p)
{
  static size_t ret=0; // used for debugging
  size_t r=0;
  r=json_extract(json, len, 
  /* specs/discord/webhook.edit-webhook-message.json:11:20
     '{ "name": "content", "type":{ "base":"char", "dec":"[2000+1]" }, 
          "comment":"name of the webhook(1-2000) chars" }'
  */
                "(content):s,"
  /* specs/discord/webhook.edit-webhook-message.json:13:20
     '{ "name": "embeds", "type":{ "base":"struct discord_embed", "dec":"ntl" }, 
          "comment":"array of up to 10 embeds objects" }'
  */
                "(embeds):F,"
  /* specs/discord/webhook.edit-webhook-message.json:15:20
     '{ "name": "allowed_mentions", 
          "type":{ "base":"struct discord_channel_allowed_mentions", "dec":"*" }, 
          "comment":"allowed mentions for the message" }'
  */
                "(allowed_mentions):F,"
                "@arg_switches:b"
                "@record_defined"
                "@record_null",
  /* specs/discord/webhook.edit-webhook-message.json:11:20
     '{ "name": "content", "type":{ "base":"char", "dec":"[2000+1]" }, 
          "comment":"name of the webhook(1-2000) chars" }'
  */
                p->content,
  /* specs/discord/webhook.edit-webhook-message.json:13:20
     '{ "name": "embeds", "type":{ "base":"struct discord_embed", "dec":"ntl" }, 
          "comment":"array of up to 10 embeds objects" }'
  */
                discord_embed_list_from_json, &p->embeds,
  /* specs/discord/webhook.edit-webhook-message.json:15:20
     '{ "name": "allowed_mentions", 
          "type":{ "base":"struct discord_channel_allowed_mentions", "dec":"*" }, 
          "comment":"allowed mentions for the message" }'
  */
                discord_channel_allowed_mentions_from_json, p->allowed_mentions,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches,
                p->__M.record_defined, sizeof(p->__M.record_defined),
                p->__M.record_null, sizeof(p->__M.record_null));
  ret = r;
}

static void discord_edit_webhook_message_params_use_default_inject_settings(struct discord_edit_webhook_message_params *p)
{
  p->__M.enable_arg_switches = true;
  /* specs/discord/webhook.edit-webhook-message.json:11:20
     '{ "name": "content", "type":{ "base":"char", "dec":"[2000+1]" }, 
          "comment":"name of the webhook(1-2000) chars" }'
  */
  p->__M.arg_switches[0] = p->content;

  /* specs/discord/webhook.edit-webhook-message.json:13:20
     '{ "name": "embeds", "type":{ "base":"struct discord_embed", "dec":"ntl" }, 
          "comment":"array of up to 10 embeds objects" }'
  */
  p->__M.arg_switches[1] = p->embeds;

  /* specs/discord/webhook.edit-webhook-message.json:15:20
     '{ "name": "allowed_mentions", 
          "type":{ "base":"struct discord_channel_allowed_mentions", "dec":"*" }, 
          "comment":"allowed mentions for the message" }'
  */
  p->__M.arg_switches[2] = p->allowed_mentions;

}

size_t discord_edit_webhook_message_params_to_json(char *json, size_t len, struct discord_edit_webhook_message_params *p)
{
  size_t r;
  discord_edit_webhook_message_params_use_default_inject_settings(p);
  r=json_inject(json, len, 
  /* specs/discord/webhook.edit-webhook-message.json:11:20
     '{ "name": "content", "type":{ "base":"char", "dec":"[2000+1]" }, 
          "comment":"name of the webhook(1-2000) chars" }'
  */
                "(content):s,"
  /* specs/discord/webhook.edit-webhook-message.json:13:20
     '{ "name": "embeds", "type":{ "base":"struct discord_embed", "dec":"ntl" }, 
          "comment":"array of up to 10 embeds objects" }'
  */
                "(embeds):F,"
  /* specs/discord/webhook.edit-webhook-message.json:15:20
     '{ "name": "allowed_mentions", 
          "type":{ "base":"struct discord_channel_allowed_mentions", "dec":"*" }, 
          "comment":"allowed mentions for the message" }'
  */
                "(allowed_mentions):F,"
                "@arg_switches:b",
  /* specs/discord/webhook.edit-webhook-message.json:11:20
     '{ "name": "content", "type":{ "base":"char", "dec":"[2000+1]" }, 
          "comment":"name of the webhook(1-2000) chars" }'
  */
                p->content,
  /* specs/discord/webhook.edit-webhook-message.json:13:20
     '{ "name": "embeds", "type":{ "base":"struct discord_embed", "dec":"ntl" }, 
          "comment":"array of up to 10 embeds objects" }'
  */
                discord_embed_list_to_json, p->embeds,
  /* specs/discord/webhook.edit-webhook-message.json:15:20
     '{ "name": "allowed_mentions", 
          "type":{ "base":"struct discord_channel_allowed_mentions", "dec":"*" }, 
          "comment":"allowed mentions for the message" }'
  */
                discord_channel_allowed_mentions_to_json, p->allowed_mentions,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches);
  return r;
}


typedef void (*vfvp)(void *);
typedef void (*vfcpsvp)(char *, size_t, void *);
typedef size_t (*sfcpsvp)(char *, size_t, void *);
void discord_edit_webhook_message_params_cleanup_v(void *p) {
  discord_edit_webhook_message_params_cleanup((struct discord_edit_webhook_message_params *)p);
}

void discord_edit_webhook_message_params_init_v(void *p) {
  discord_edit_webhook_message_params_init((struct discord_edit_webhook_message_params *)p);
}

void discord_edit_webhook_message_params_free_v(void *p) {
 discord_edit_webhook_message_params_free((struct discord_edit_webhook_message_params *)p);
};

void discord_edit_webhook_message_params_from_json_v(char *json, size_t len, void *p) {
 discord_edit_webhook_message_params_from_json(json, len, (struct discord_edit_webhook_message_params*)p);
}

size_t discord_edit_webhook_message_params_to_json_v(char *json, size_t len, void *p) {
  return discord_edit_webhook_message_params_to_json(json, len, (struct discord_edit_webhook_message_params*)p);
}

void discord_edit_webhook_message_params_list_free_v(void **p) {
  discord_edit_webhook_message_params_list_free((struct discord_edit_webhook_message_params**)p);
}

void discord_edit_webhook_message_params_list_from_json_v(char *str, size_t len, void *p) {
  discord_edit_webhook_message_params_list_from_json(str, len, (struct discord_edit_webhook_message_params ***)p);
}

size_t discord_edit_webhook_message_params_list_to_json_v(char *str, size_t len, void *p){
  return discord_edit_webhook_message_params_list_to_json(str, len, (struct discord_edit_webhook_message_params **)p);
}


void discord_edit_webhook_message_params_cleanup(struct discord_edit_webhook_message_params *d) {
  /* specs/discord/webhook.edit-webhook-message.json:11:20
     '{ "name": "content", "type":{ "base":"char", "dec":"[2000+1]" }, 
          "comment":"name of the webhook(1-2000) chars" }'
  */
  //p->content is a scalar
  /* specs/discord/webhook.edit-webhook-message.json:13:20
     '{ "name": "embeds", "type":{ "base":"struct discord_embed", "dec":"ntl" }, 
          "comment":"array of up to 10 embeds objects" }'
  */
  if (d->embeds)
    discord_embed_list_free(d->embeds);
  /* specs/discord/webhook.edit-webhook-message.json:15:20
     '{ "name": "allowed_mentions", 
          "type":{ "base":"struct discord_channel_allowed_mentions", "dec":"*" }, 
          "comment":"allowed mentions for the message" }'
  */
  if (d->allowed_mentions)
    discord_channel_allowed_mentions_free(d->allowed_mentions);
}

void discord_edit_webhook_message_params_init(struct discord_edit_webhook_message_params *p) {
  memset(p, 0, sizeof(struct discord_edit_webhook_message_params));
  /* specs/discord/webhook.edit-webhook-message.json:11:20
     '{ "name": "content", "type":{ "base":"char", "dec":"[2000+1]" }, 
          "comment":"name of the webhook(1-2000) chars" }'
  */

  /* specs/discord/webhook.edit-webhook-message.json:13:20
     '{ "name": "embeds", "type":{ "base":"struct discord_embed", "dec":"ntl" }, 
          "comment":"array of up to 10 embeds objects" }'
  */

  /* specs/discord/webhook.edit-webhook-message.json:15:20
     '{ "name": "allowed_mentions", 
          "type":{ "base":"struct discord_channel_allowed_mentions", "dec":"*" }, 
          "comment":"allowed mentions for the message" }'
  */
  p->allowed_mentions = discord_channel_allowed_mentions_alloc();

}
struct discord_edit_webhook_message_params* discord_edit_webhook_message_params_alloc() {
  struct discord_edit_webhook_message_params *p= (struct discord_edit_webhook_message_params*)malloc(sizeof(struct discord_edit_webhook_message_params));
  discord_edit_webhook_message_params_init(p);
  return p;
}

void discord_edit_webhook_message_params_free(struct discord_edit_webhook_message_params *p) {
  discord_edit_webhook_message_params_cleanup(p);
  free(p);
}

void discord_edit_webhook_message_params_list_free(struct discord_edit_webhook_message_params **p) {
  ntl_free((void**)p, (vfvp)discord_edit_webhook_message_params_cleanup);
}

void discord_edit_webhook_message_params_list_from_json(char *str, size_t len, struct discord_edit_webhook_message_params ***p)
{
  struct ntl_deserializer d;
  memset(&d, 0, sizeof(d));
  d.elem_size = sizeof(struct discord_edit_webhook_message_params);
  d.init_elem = discord_edit_webhook_message_params_init_v;
  d.elem_from_buf = discord_edit_webhook_message_params_from_json_v;
  d.ntl_recipient_p= (void***)p;
  extract_ntl_from_json(str, len, &d);
}

size_t discord_edit_webhook_message_params_list_to_json(char *str, size_t len, struct discord_edit_webhook_message_params **p)
{
  return ntl_to_buf(str, len, (void **)p, NULL, discord_edit_webhook_message_params_to_json_v);
}

