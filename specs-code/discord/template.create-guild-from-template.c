/* This file is generated from specs/discord/template.create-guild-from-template.json, Please don't edit it. */
#include "specs.h"
/*

*/

void discord_create_guild_from_template_params_from_json(char *json, size_t len, struct discord_create_guild_from_template_params *p)
{
  static size_t ret=0; // used for debugging
  size_t r=0;
  r=json_extract(json, len, 
  /* specs/discord/template.create-guild-from-template.json:11:20
     '{ "name": "name", "type":{ "base":"char", "dec":"*"}, "comment":"name of the guild"}'
  */
                "(name):?s,"
  /* specs/discord/template.create-guild-from-template.json:12:20
     '{ "name": "icon", "type":{ "base":"char", "dec":"*" }, "comment":"base64 128x128 image for the guild icon"}'
  */
                "(icon):?s,"
                "@arg_switches:b"
                "@record_defined"
                "@record_null",
  /* specs/discord/template.create-guild-from-template.json:11:20
     '{ "name": "name", "type":{ "base":"char", "dec":"*"}, "comment":"name of the guild"}'
  */
                &p->name,
  /* specs/discord/template.create-guild-from-template.json:12:20
     '{ "name": "icon", "type":{ "base":"char", "dec":"*" }, "comment":"base64 128x128 image for the guild icon"}'
  */
                &p->icon,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches,
                p->__M.record_defined, sizeof(p->__M.record_defined),
                p->__M.record_null, sizeof(p->__M.record_null));
  ret = r;
}

static void discord_create_guild_from_template_params_use_default_inject_settings(struct discord_create_guild_from_template_params *p)
{
  p->__M.enable_arg_switches = true;
  /* specs/discord/template.create-guild-from-template.json:11:20
     '{ "name": "name", "type":{ "base":"char", "dec":"*"}, "comment":"name of the guild"}'
  */
  p->__M.arg_switches[0] = p->name;

  /* specs/discord/template.create-guild-from-template.json:12:20
     '{ "name": "icon", "type":{ "base":"char", "dec":"*" }, "comment":"base64 128x128 image for the guild icon"}'
  */
  p->__M.arg_switches[1] = p->icon;

}

size_t discord_create_guild_from_template_params_to_json(char *json, size_t len, struct discord_create_guild_from_template_params *p)
{
  size_t r;
  discord_create_guild_from_template_params_use_default_inject_settings(p);
  r=json_inject(json, len, 
  /* specs/discord/template.create-guild-from-template.json:11:20
     '{ "name": "name", "type":{ "base":"char", "dec":"*"}, "comment":"name of the guild"}'
  */
                "(name):s,"
  /* specs/discord/template.create-guild-from-template.json:12:20
     '{ "name": "icon", "type":{ "base":"char", "dec":"*" }, "comment":"base64 128x128 image for the guild icon"}'
  */
                "(icon):s,"
                "@arg_switches:b",
  /* specs/discord/template.create-guild-from-template.json:11:20
     '{ "name": "name", "type":{ "base":"char", "dec":"*"}, "comment":"name of the guild"}'
  */
                p->name,
  /* specs/discord/template.create-guild-from-template.json:12:20
     '{ "name": "icon", "type":{ "base":"char", "dec":"*" }, "comment":"base64 128x128 image for the guild icon"}'
  */
                p->icon,
                p->__M.arg_switches, sizeof(p->__M.arg_switches), p->__M.enable_arg_switches);
  return r;
}


typedef void (*vfvp)(void *);
typedef void (*vfcpsvp)(char *, size_t, void *);
typedef size_t (*sfcpsvp)(char *, size_t, void *);
void discord_create_guild_from_template_params_cleanup_v(void *p) {
  discord_create_guild_from_template_params_cleanup((struct discord_create_guild_from_template_params *)p);
}

void discord_create_guild_from_template_params_init_v(void *p) {
  discord_create_guild_from_template_params_init((struct discord_create_guild_from_template_params *)p);
}

void discord_create_guild_from_template_params_free_v(void *p) {
 discord_create_guild_from_template_params_free((struct discord_create_guild_from_template_params *)p);
};

void discord_create_guild_from_template_params_from_json_v(char *json, size_t len, void *p) {
 discord_create_guild_from_template_params_from_json(json, len, (struct discord_create_guild_from_template_params*)p);
}

size_t discord_create_guild_from_template_params_to_json_v(char *json, size_t len, void *p) {
  return discord_create_guild_from_template_params_to_json(json, len, (struct discord_create_guild_from_template_params*)p);
}

void discord_create_guild_from_template_params_list_free_v(void **p) {
  discord_create_guild_from_template_params_list_free((struct discord_create_guild_from_template_params**)p);
}

void discord_create_guild_from_template_params_list_from_json_v(char *str, size_t len, void *p) {
  discord_create_guild_from_template_params_list_from_json(str, len, (struct discord_create_guild_from_template_params ***)p);
}

size_t discord_create_guild_from_template_params_list_to_json_v(char *str, size_t len, void *p){
  return discord_create_guild_from_template_params_list_to_json(str, len, (struct discord_create_guild_from_template_params **)p);
}


void discord_create_guild_from_template_params_cleanup(struct discord_create_guild_from_template_params *d) {
  /* specs/discord/template.create-guild-from-template.json:11:20
     '{ "name": "name", "type":{ "base":"char", "dec":"*"}, "comment":"name of the guild"}'
  */
  if (d->name)
    free(d->name);
  /* specs/discord/template.create-guild-from-template.json:12:20
     '{ "name": "icon", "type":{ "base":"char", "dec":"*" }, "comment":"base64 128x128 image for the guild icon"}'
  */
  if (d->icon)
    free(d->icon);
}

void discord_create_guild_from_template_params_init(struct discord_create_guild_from_template_params *p) {
  memset(p, 0, sizeof(struct discord_create_guild_from_template_params));
  /* specs/discord/template.create-guild-from-template.json:11:20
     '{ "name": "name", "type":{ "base":"char", "dec":"*"}, "comment":"name of the guild"}'
  */

  /* specs/discord/template.create-guild-from-template.json:12:20
     '{ "name": "icon", "type":{ "base":"char", "dec":"*" }, "comment":"base64 128x128 image for the guild icon"}'
  */

}
struct discord_create_guild_from_template_params* discord_create_guild_from_template_params_alloc() {
  struct discord_create_guild_from_template_params *p= (struct discord_create_guild_from_template_params*)malloc(sizeof(struct discord_create_guild_from_template_params));
  discord_create_guild_from_template_params_init(p);
  return p;
}

void discord_create_guild_from_template_params_free(struct discord_create_guild_from_template_params *p) {
  discord_create_guild_from_template_params_cleanup(p);
  free(p);
}

void discord_create_guild_from_template_params_list_free(struct discord_create_guild_from_template_params **p) {
  ntl_free((void**)p, (vfvp)discord_create_guild_from_template_params_cleanup);
}

void discord_create_guild_from_template_params_list_from_json(char *str, size_t len, struct discord_create_guild_from_template_params ***p)
{
  struct ntl_deserializer d;
  memset(&d, 0, sizeof(d));
  d.elem_size = sizeof(struct discord_create_guild_from_template_params);
  d.init_elem = discord_create_guild_from_template_params_init_v;
  d.elem_from_buf = discord_create_guild_from_template_params_from_json_v;
  d.ntl_recipient_p= (void***)p;
  extract_ntl_from_json(str, len, &d);
}

size_t discord_create_guild_from_template_params_list_to_json(char *str, size_t len, struct discord_create_guild_from_template_params **p)
{
  return ntl_to_buf(str, len, (void **)p, NULL, discord_create_guild_from_template_params_to_json_v);
}

