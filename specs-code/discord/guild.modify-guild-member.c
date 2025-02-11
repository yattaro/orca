/* This file is generated from specs/discord/guild.modify-guild-member.json, Please don't edit it. */
#include "specs.h"
/*

*/

void discord_modify_guild_member_params_from_json(char *json, size_t len, struct discord_modify_guild_member_params *p)
{
  static size_t ret=0; // used for debugging
  size_t r=0;
  r=json_extract(json, len, 
  /* specs/discord/guild.modify-guild-member.json:11:20
     '{ "name": "nick", "type":{ "base":"char", "dec":"*" }}'
  */
                "(nick):?s,"
  /* specs/discord/guild.modify-guild-member.json:12:20
     '{ "name": "roles", "type":{ "base":"ja_u64", "dec":"ntl" }, "inject_if_not":null}'
  */
                "(roles):F,"
  /* specs/discord/guild.modify-guild-member.json:13:20
     '{ "name": "mute", "type":{ "base":"bool" }, "inject_if_not":false}'
  */
                "(mute):b,"
  /* specs/discord/guild.modify-guild-member.json:14:20
     '{ "name": "deaf", "type":{ "base":"bool" }, "inject_if_not":false}'
  */
                "(deaf):b,"
  /* specs/discord/guild.modify-guild-member.json:15:20
     '{ "name": "channel_id", "type":{ "base":"char", "dec":"*", "converter":"snowflake" }, "inject_if_not":0}'
  */
                "(channel_id):F,"
                "@arg_switches:b"
                "@record_defined"
                "@record_null",
  /* specs/discord/guild.modify-guild-member.json:11:20
     '{ "name": "nick", "type":{ "base":"char", "dec":"*" }}'
  */
                &p->nick,
  /* specs/discord/guild.modify-guild-member.json:12:20
     '{ "name": "roles", "type":{ "base":"ja_u64", "dec":"ntl" }, "inject_if_not":null}'
  */
                ja_u64_list_from_json, &p->roles,
  /* specs/discord/guild.modify-guild-member.json:13:20
     '{ "name": "mute", "type":{ "base":"bool" }, "inject_if_not":false}'
  */
                &p->mute,
  /* specs/discord/guild.modify-guild-member.json:14:20
     '{ "name": "deaf", "type":{ "base":"bool" }, "inject_if_not":false}'
  */
                &p->deaf,
  /* specs/discord/guild.modify-guild-member.json:15:20
     '{ "name": "channel_id", "type":{ "base":"char", "dec":"*", "converter":"snowflake" }, "inject_if_not":0}'
  */
                orka_strtoull, &p->channel_id,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches,
                p->__M.record_defined, sizeof(p->__M.record_defined),
                p->__M.record_null, sizeof(p->__M.record_null));
  ret = r;
}

static void discord_modify_guild_member_params_use_default_inject_settings(struct discord_modify_guild_member_params *p)
{
  p->__M.enable_arg_switches = true;
  /* specs/discord/guild.modify-guild-member.json:11:20
     '{ "name": "nick", "type":{ "base":"char", "dec":"*" }}'
  */
  p->__M.arg_switches[0] = p->nick;

  /* specs/discord/guild.modify-guild-member.json:12:20
     '{ "name": "roles", "type":{ "base":"ja_u64", "dec":"ntl" }, "inject_if_not":null}'
  */
  if (p->roles != NULL)
    p->__M.arg_switches[1] = p->roles;

  /* specs/discord/guild.modify-guild-member.json:13:20
     '{ "name": "mute", "type":{ "base":"bool" }, "inject_if_not":false}'
  */
  if (p->mute != false)
    p->__M.arg_switches[2] = &p->mute;

  /* specs/discord/guild.modify-guild-member.json:14:20
     '{ "name": "deaf", "type":{ "base":"bool" }, "inject_if_not":false}'
  */
  if (p->deaf != false)
    p->__M.arg_switches[3] = &p->deaf;

  /* specs/discord/guild.modify-guild-member.json:15:20
     '{ "name": "channel_id", "type":{ "base":"char", "dec":"*", "converter":"snowflake" }, "inject_if_not":0}'
  */
  if (p->channel_id != 0)
    p->__M.arg_switches[4] = &p->channel_id;

}

size_t discord_modify_guild_member_params_to_json(char *json, size_t len, struct discord_modify_guild_member_params *p)
{
  size_t r;
  discord_modify_guild_member_params_use_default_inject_settings(p);
  r=json_inject(json, len, 
  /* specs/discord/guild.modify-guild-member.json:11:20
     '{ "name": "nick", "type":{ "base":"char", "dec":"*" }}'
  */
                "(nick):s,"
  /* specs/discord/guild.modify-guild-member.json:12:20
     '{ "name": "roles", "type":{ "base":"ja_u64", "dec":"ntl" }, "inject_if_not":null}'
  */
                "(roles):F,"
  /* specs/discord/guild.modify-guild-member.json:13:20
     '{ "name": "mute", "type":{ "base":"bool" }, "inject_if_not":false}'
  */
                "(mute):b,"
  /* specs/discord/guild.modify-guild-member.json:14:20
     '{ "name": "deaf", "type":{ "base":"bool" }, "inject_if_not":false}'
  */
                "(deaf):b,"
  /* specs/discord/guild.modify-guild-member.json:15:20
     '{ "name": "channel_id", "type":{ "base":"char", "dec":"*", "converter":"snowflake" }, "inject_if_not":0}'
  */
                "(channel_id):|F|,"
                "@arg_switches:b",
  /* specs/discord/guild.modify-guild-member.json:11:20
     '{ "name": "nick", "type":{ "base":"char", "dec":"*" }}'
  */
                p->nick,
  /* specs/discord/guild.modify-guild-member.json:12:20
     '{ "name": "roles", "type":{ "base":"ja_u64", "dec":"ntl" }, "inject_if_not":null}'
  */
                ja_u64_list_to_json, p->roles,
  /* specs/discord/guild.modify-guild-member.json:13:20
     '{ "name": "mute", "type":{ "base":"bool" }, "inject_if_not":false}'
  */
                &p->mute,
  /* specs/discord/guild.modify-guild-member.json:14:20
     '{ "name": "deaf", "type":{ "base":"bool" }, "inject_if_not":false}'
  */
                &p->deaf,
  /* specs/discord/guild.modify-guild-member.json:15:20
     '{ "name": "channel_id", "type":{ "base":"char", "dec":"*", "converter":"snowflake" }, "inject_if_not":0}'
  */
                orka_ulltostr, &p->channel_id,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches);
  return r;
}


typedef void (*vfvp)(void *);
typedef void (*vfcpsvp)(char *, size_t, void *);
typedef size_t (*sfcpsvp)(char *, size_t, void *);
void discord_modify_guild_member_params_cleanup_v(void *p) {
  discord_modify_guild_member_params_cleanup((struct discord_modify_guild_member_params *)p);
}

void discord_modify_guild_member_params_init_v(void *p) {
  discord_modify_guild_member_params_init((struct discord_modify_guild_member_params *)p);
}

void discord_modify_guild_member_params_free_v(void *p) {
 discord_modify_guild_member_params_free((struct discord_modify_guild_member_params *)p);
};

void discord_modify_guild_member_params_from_json_v(char *json, size_t len, void *p) {
 discord_modify_guild_member_params_from_json(json, len, (struct discord_modify_guild_member_params*)p);
}

size_t discord_modify_guild_member_params_to_json_v(char *json, size_t len, void *p) {
  return discord_modify_guild_member_params_to_json(json, len, (struct discord_modify_guild_member_params*)p);
}

void discord_modify_guild_member_params_list_free_v(void **p) {
  discord_modify_guild_member_params_list_free((struct discord_modify_guild_member_params**)p);
}

void discord_modify_guild_member_params_list_from_json_v(char *str, size_t len, void *p) {
  discord_modify_guild_member_params_list_from_json(str, len, (struct discord_modify_guild_member_params ***)p);
}

size_t discord_modify_guild_member_params_list_to_json_v(char *str, size_t len, void *p){
  return discord_modify_guild_member_params_list_to_json(str, len, (struct discord_modify_guild_member_params **)p);
}


void discord_modify_guild_member_params_cleanup(struct discord_modify_guild_member_params *d) {
  /* specs/discord/guild.modify-guild-member.json:11:20
     '{ "name": "nick", "type":{ "base":"char", "dec":"*" }}'
  */
  if (d->nick)
    free(d->nick);
  /* specs/discord/guild.modify-guild-member.json:12:20
     '{ "name": "roles", "type":{ "base":"ja_u64", "dec":"ntl" }, "inject_if_not":null}'
  */
  if (d->roles)
    ja_u64_list_free(d->roles);
  /* specs/discord/guild.modify-guild-member.json:13:20
     '{ "name": "mute", "type":{ "base":"bool" }, "inject_if_not":false}'
  */
  //p->mute is a scalar
  /* specs/discord/guild.modify-guild-member.json:14:20
     '{ "name": "deaf", "type":{ "base":"bool" }, "inject_if_not":false}'
  */
  //p->deaf is a scalar
  /* specs/discord/guild.modify-guild-member.json:15:20
     '{ "name": "channel_id", "type":{ "base":"char", "dec":"*", "converter":"snowflake" }, "inject_if_not":0}'
  */
  //p->channel_id is a scalar
}

void discord_modify_guild_member_params_init(struct discord_modify_guild_member_params *p) {
  memset(p, 0, sizeof(struct discord_modify_guild_member_params));
  /* specs/discord/guild.modify-guild-member.json:11:20
     '{ "name": "nick", "type":{ "base":"char", "dec":"*" }}'
  */

  /* specs/discord/guild.modify-guild-member.json:12:20
     '{ "name": "roles", "type":{ "base":"ja_u64", "dec":"ntl" }, "inject_if_not":null}'
  */

  /* specs/discord/guild.modify-guild-member.json:13:20
     '{ "name": "mute", "type":{ "base":"bool" }, "inject_if_not":false}'
  */

  /* specs/discord/guild.modify-guild-member.json:14:20
     '{ "name": "deaf", "type":{ "base":"bool" }, "inject_if_not":false}'
  */

  /* specs/discord/guild.modify-guild-member.json:15:20
     '{ "name": "channel_id", "type":{ "base":"char", "dec":"*", "converter":"snowflake" }, "inject_if_not":0}'
  */

}
struct discord_modify_guild_member_params* discord_modify_guild_member_params_alloc() {
  struct discord_modify_guild_member_params *p= (struct discord_modify_guild_member_params*)malloc(sizeof(struct discord_modify_guild_member_params));
  discord_modify_guild_member_params_init(p);
  return p;
}

void discord_modify_guild_member_params_free(struct discord_modify_guild_member_params *p) {
  discord_modify_guild_member_params_cleanup(p);
  free(p);
}

void discord_modify_guild_member_params_list_free(struct discord_modify_guild_member_params **p) {
  ntl_free((void**)p, (vfvp)discord_modify_guild_member_params_cleanup);
}

void discord_modify_guild_member_params_list_from_json(char *str, size_t len, struct discord_modify_guild_member_params ***p)
{
  struct ntl_deserializer d;
  memset(&d, 0, sizeof(d));
  d.elem_size = sizeof(struct discord_modify_guild_member_params);
  d.init_elem = discord_modify_guild_member_params_init_v;
  d.elem_from_buf = discord_modify_guild_member_params_from_json_v;
  d.ntl_recipient_p= (void***)p;
  extract_ntl_from_json(str, len, &d);
}

size_t discord_modify_guild_member_params_list_to_json(char *str, size_t len, struct discord_modify_guild_member_params **p)
{
  return ntl_to_buf(str, len, (void **)p, NULL, discord_modify_guild_member_params_to_json_v);
}

