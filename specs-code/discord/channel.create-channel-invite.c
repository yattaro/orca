/* This file is generated from specs/discord/channel.create-channel-invite.json, Please don't edit it. */
#include "specs.h"
/*

*/

void discord_create_channel_invite_params_from_json(char *json, size_t len, struct discord_create_channel_invite_params *p)
{
  static size_t ret=0; // used for debugging
  size_t r=0;
  r=json_extract(json, len, 
  /* specs/discord/channel.create-channel-invite.json:11:20
     '{ "name": "channel_id", "type":{ "base":"char", "dec":"*", "converter":"snowflake"}, "loc":"url"}'
  */
                "(channel_id):F,"
  /* specs/discord/channel.create-channel-invite.json:12:20
     '{ "name": "max_age", "type":{ "base":"int" } }'
  */
                "(max_age):d,"
  /* specs/discord/channel.create-channel-invite.json:13:20
     '{ "name": "max_uses", "type":{ "base":"int" } }'
  */
                "(max_uses):d,"
  /* specs/discord/channel.create-channel-invite.json:14:20
     '{ "name": "temporary", "type":{ "base":"bool"}}'
  */
                "(temporary):b,"
  /* specs/discord/channel.create-channel-invite.json:15:20
     '{ "name": "unique", "type":{ "base":"bool"}}'
  */
                "(unique):b,"
  /* specs/discord/channel.create-channel-invite.json:16:20
     '{ "name": "target_user", "type":{ "base":"char", "dec":"*"}, 
          "option":true, "inject_if_not":null}'
  */
                "(target_user):?s,"
  /* specs/discord/channel.create-channel-invite.json:18:20
     '{ "name": "target_user_type", "type":{ "base":"int" },
          "option":true, "inject_if_not":0}'
  */
                "(target_user_type):d,"
                "@arg_switches:b"
                "@record_defined"
                "@record_null",
  /* specs/discord/channel.create-channel-invite.json:11:20
     '{ "name": "channel_id", "type":{ "base":"char", "dec":"*", "converter":"snowflake"}, "loc":"url"}'
  */
                orka_strtoull, &p->channel_id,
  /* specs/discord/channel.create-channel-invite.json:12:20
     '{ "name": "max_age", "type":{ "base":"int" } }'
  */
                &p->max_age,
  /* specs/discord/channel.create-channel-invite.json:13:20
     '{ "name": "max_uses", "type":{ "base":"int" } }'
  */
                &p->max_uses,
  /* specs/discord/channel.create-channel-invite.json:14:20
     '{ "name": "temporary", "type":{ "base":"bool"}}'
  */
                &p->temporary,
  /* specs/discord/channel.create-channel-invite.json:15:20
     '{ "name": "unique", "type":{ "base":"bool"}}'
  */
                &p->unique,
  /* specs/discord/channel.create-channel-invite.json:16:20
     '{ "name": "target_user", "type":{ "base":"char", "dec":"*"}, 
          "option":true, "inject_if_not":null}'
  */
                &p->target_user,
  /* specs/discord/channel.create-channel-invite.json:18:20
     '{ "name": "target_user_type", "type":{ "base":"int" },
          "option":true, "inject_if_not":0}'
  */
                &p->target_user_type,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches,
                p->__M.record_defined, sizeof(p->__M.record_defined),
                p->__M.record_null, sizeof(p->__M.record_null));
  ret = r;
}

static void discord_create_channel_invite_params_use_default_inject_settings(struct discord_create_channel_invite_params *p)
{
  p->__M.enable_arg_switches = true;
  /* specs/discord/channel.create-channel-invite.json:11:20
     '{ "name": "channel_id", "type":{ "base":"char", "dec":"*", "converter":"snowflake"}, "loc":"url"}'
  */
  p->__M.arg_switches[0] = &p->channel_id;

  /* specs/discord/channel.create-channel-invite.json:12:20
     '{ "name": "max_age", "type":{ "base":"int" } }'
  */
  p->__M.arg_switches[1] = &p->max_age;

  /* specs/discord/channel.create-channel-invite.json:13:20
     '{ "name": "max_uses", "type":{ "base":"int" } }'
  */
  p->__M.arg_switches[2] = &p->max_uses;

  /* specs/discord/channel.create-channel-invite.json:14:20
     '{ "name": "temporary", "type":{ "base":"bool"}}'
  */
  p->__M.arg_switches[3] = &p->temporary;

  /* specs/discord/channel.create-channel-invite.json:15:20
     '{ "name": "unique", "type":{ "base":"bool"}}'
  */
  p->__M.arg_switches[4] = &p->unique;

  /* specs/discord/channel.create-channel-invite.json:16:20
     '{ "name": "target_user", "type":{ "base":"char", "dec":"*"}, 
          "option":true, "inject_if_not":null}'
  */
  if (p->target_user != NULL)
    p->__M.arg_switches[5] = p->target_user;

  /* specs/discord/channel.create-channel-invite.json:18:20
     '{ "name": "target_user_type", "type":{ "base":"int" },
          "option":true, "inject_if_not":0}'
  */
  if (p->target_user_type != 0)
    p->__M.arg_switches[6] = &p->target_user_type;

}

size_t discord_create_channel_invite_params_to_json(char *json, size_t len, struct discord_create_channel_invite_params *p)
{
  size_t r;
  discord_create_channel_invite_params_use_default_inject_settings(p);
  r=json_inject(json, len, 
  /* specs/discord/channel.create-channel-invite.json:11:20
     '{ "name": "channel_id", "type":{ "base":"char", "dec":"*", "converter":"snowflake"}, "loc":"url"}'
  */
                "(channel_id):|F|,"
  /* specs/discord/channel.create-channel-invite.json:12:20
     '{ "name": "max_age", "type":{ "base":"int" } }'
  */
                "(max_age):d,"
  /* specs/discord/channel.create-channel-invite.json:13:20
     '{ "name": "max_uses", "type":{ "base":"int" } }'
  */
                "(max_uses):d,"
  /* specs/discord/channel.create-channel-invite.json:14:20
     '{ "name": "temporary", "type":{ "base":"bool"}}'
  */
                "(temporary):b,"
  /* specs/discord/channel.create-channel-invite.json:15:20
     '{ "name": "unique", "type":{ "base":"bool"}}'
  */
                "(unique):b,"
  /* specs/discord/channel.create-channel-invite.json:16:20
     '{ "name": "target_user", "type":{ "base":"char", "dec":"*"}, 
          "option":true, "inject_if_not":null}'
  */
                "(target_user):s,"
  /* specs/discord/channel.create-channel-invite.json:18:20
     '{ "name": "target_user_type", "type":{ "base":"int" },
          "option":true, "inject_if_not":0}'
  */
                "(target_user_type):d,"
                "@arg_switches:b",
  /* specs/discord/channel.create-channel-invite.json:11:20
     '{ "name": "channel_id", "type":{ "base":"char", "dec":"*", "converter":"snowflake"}, "loc":"url"}'
  */
                orka_ulltostr, &p->channel_id,
  /* specs/discord/channel.create-channel-invite.json:12:20
     '{ "name": "max_age", "type":{ "base":"int" } }'
  */
                &p->max_age,
  /* specs/discord/channel.create-channel-invite.json:13:20
     '{ "name": "max_uses", "type":{ "base":"int" } }'
  */
                &p->max_uses,
  /* specs/discord/channel.create-channel-invite.json:14:20
     '{ "name": "temporary", "type":{ "base":"bool"}}'
  */
                &p->temporary,
  /* specs/discord/channel.create-channel-invite.json:15:20
     '{ "name": "unique", "type":{ "base":"bool"}}'
  */
                &p->unique,
  /* specs/discord/channel.create-channel-invite.json:16:20
     '{ "name": "target_user", "type":{ "base":"char", "dec":"*"}, 
          "option":true, "inject_if_not":null}'
  */
                p->target_user,
  /* specs/discord/channel.create-channel-invite.json:18:20
     '{ "name": "target_user_type", "type":{ "base":"int" },
          "option":true, "inject_if_not":0}'
  */
                &p->target_user_type,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches);
  return r;
}


typedef void (*vfvp)(void *);
typedef void (*vfcpsvp)(char *, size_t, void *);
typedef size_t (*sfcpsvp)(char *, size_t, void *);
void discord_create_channel_invite_params_cleanup_v(void *p) {
  discord_create_channel_invite_params_cleanup((struct discord_create_channel_invite_params *)p);
}

void discord_create_channel_invite_params_init_v(void *p) {
  discord_create_channel_invite_params_init((struct discord_create_channel_invite_params *)p);
}

void discord_create_channel_invite_params_free_v(void *p) {
 discord_create_channel_invite_params_free((struct discord_create_channel_invite_params *)p);
};

void discord_create_channel_invite_params_from_json_v(char *json, size_t len, void *p) {
 discord_create_channel_invite_params_from_json(json, len, (struct discord_create_channel_invite_params*)p);
}

size_t discord_create_channel_invite_params_to_json_v(char *json, size_t len, void *p) {
  return discord_create_channel_invite_params_to_json(json, len, (struct discord_create_channel_invite_params*)p);
}

void discord_create_channel_invite_params_list_free_v(void **p) {
  discord_create_channel_invite_params_list_free((struct discord_create_channel_invite_params**)p);
}

void discord_create_channel_invite_params_list_from_json_v(char *str, size_t len, void *p) {
  discord_create_channel_invite_params_list_from_json(str, len, (struct discord_create_channel_invite_params ***)p);
}

size_t discord_create_channel_invite_params_list_to_json_v(char *str, size_t len, void *p){
  return discord_create_channel_invite_params_list_to_json(str, len, (struct discord_create_channel_invite_params **)p);
}


void discord_create_channel_invite_params_cleanup(struct discord_create_channel_invite_params *d) {
  /* specs/discord/channel.create-channel-invite.json:11:20
     '{ "name": "channel_id", "type":{ "base":"char", "dec":"*", "converter":"snowflake"}, "loc":"url"}'
  */
  //p->channel_id is a scalar
  /* specs/discord/channel.create-channel-invite.json:12:20
     '{ "name": "max_age", "type":{ "base":"int" } }'
  */
  //p->max_age is a scalar
  /* specs/discord/channel.create-channel-invite.json:13:20
     '{ "name": "max_uses", "type":{ "base":"int" } }'
  */
  //p->max_uses is a scalar
  /* specs/discord/channel.create-channel-invite.json:14:20
     '{ "name": "temporary", "type":{ "base":"bool"}}'
  */
  //p->temporary is a scalar
  /* specs/discord/channel.create-channel-invite.json:15:20
     '{ "name": "unique", "type":{ "base":"bool"}}'
  */
  //p->unique is a scalar
  /* specs/discord/channel.create-channel-invite.json:16:20
     '{ "name": "target_user", "type":{ "base":"char", "dec":"*"}, 
          "option":true, "inject_if_not":null}'
  */
  if (d->target_user)
    free(d->target_user);
  /* specs/discord/channel.create-channel-invite.json:18:20
     '{ "name": "target_user_type", "type":{ "base":"int" },
          "option":true, "inject_if_not":0}'
  */
  //p->target_user_type is a scalar
}

void discord_create_channel_invite_params_init(struct discord_create_channel_invite_params *p) {
  memset(p, 0, sizeof(struct discord_create_channel_invite_params));
  /* specs/discord/channel.create-channel-invite.json:11:20
     '{ "name": "channel_id", "type":{ "base":"char", "dec":"*", "converter":"snowflake"}, "loc":"url"}'
  */

  /* specs/discord/channel.create-channel-invite.json:12:20
     '{ "name": "max_age", "type":{ "base":"int" } }'
  */

  /* specs/discord/channel.create-channel-invite.json:13:20
     '{ "name": "max_uses", "type":{ "base":"int" } }'
  */

  /* specs/discord/channel.create-channel-invite.json:14:20
     '{ "name": "temporary", "type":{ "base":"bool"}}'
  */

  /* specs/discord/channel.create-channel-invite.json:15:20
     '{ "name": "unique", "type":{ "base":"bool"}}'
  */

  /* specs/discord/channel.create-channel-invite.json:16:20
     '{ "name": "target_user", "type":{ "base":"char", "dec":"*"}, 
          "option":true, "inject_if_not":null}'
  */

  /* specs/discord/channel.create-channel-invite.json:18:20
     '{ "name": "target_user_type", "type":{ "base":"int" },
          "option":true, "inject_if_not":0}'
  */

}
struct discord_create_channel_invite_params* discord_create_channel_invite_params_alloc() {
  struct discord_create_channel_invite_params *p= (struct discord_create_channel_invite_params*)malloc(sizeof(struct discord_create_channel_invite_params));
  discord_create_channel_invite_params_init(p);
  return p;
}

void discord_create_channel_invite_params_free(struct discord_create_channel_invite_params *p) {
  discord_create_channel_invite_params_cleanup(p);
  free(p);
}

void discord_create_channel_invite_params_list_free(struct discord_create_channel_invite_params **p) {
  ntl_free((void**)p, (vfvp)discord_create_channel_invite_params_cleanup);
}

void discord_create_channel_invite_params_list_from_json(char *str, size_t len, struct discord_create_channel_invite_params ***p)
{
  struct ntl_deserializer d;
  memset(&d, 0, sizeof(d));
  d.elem_size = sizeof(struct discord_create_channel_invite_params);
  d.init_elem = discord_create_channel_invite_params_init_v;
  d.elem_from_buf = discord_create_channel_invite_params_from_json_v;
  d.ntl_recipient_p= (void***)p;
  extract_ntl_from_json(str, len, &d);
}

size_t discord_create_channel_invite_params_list_to_json(char *str, size_t len, struct discord_create_channel_invite_params **p)
{
  return ntl_to_buf(str, len, (void **)p, NULL, discord_create_channel_invite_params_to_json_v);
}

