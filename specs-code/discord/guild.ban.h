/* This file is generated from specs/discord/guild.ban.json, Please don't edit it. */
/*
https://discord.com/developers/docs/resources/guild#ban-object
*/

/* This is defined at specs/discord/guild.ban.json:7:22 */
struct discord_guild_ban {
  /* specs/discord/guild.ban.json:10:20
     '{ "name": "reason", "type":{ "base":"char", "dec":"[MAX_REASON_LEN]" }}'
  */
  char reason[MAX_REASON_LEN];

  /* specs/discord/guild.ban.json:11:20
     '{ "name": "user", "type":{ "base":"struct discord_user", "dec":"*"}, "comment":"partial user object"}'
  */
  struct discord_user *user; // partial user object

  // The following is metadata used to 
  // 1. control which field should be extracted/injected
  // 2. record which field is presented(defined) in JSON
  // 3. record which field is null in JSON
  struct {
    bool enable_arg_switches;
    bool enable_record_defined;
    bool enable_record_null;
    void *arg_switches[2];
    void *record_defined[2];
    void *record_null[2];
  } __M; // metadata
};
extern void discord_guild_ban_cleanup_v(void *p);
extern void discord_guild_ban_cleanup(struct discord_guild_ban *p);
extern void discord_guild_ban_init_v(void *p);
extern void discord_guild_ban_init(struct discord_guild_ban *p);
extern struct discord_guild_ban * discord_guild_ban_alloc();
extern void discord_guild_ban_free_v(void *p);
extern void discord_guild_ban_free(struct discord_guild_ban *p);
extern void discord_guild_ban_from_json_v(char *json, size_t len, void *p);
extern void discord_guild_ban_from_json(char *json, size_t len, struct discord_guild_ban *p);
extern size_t discord_guild_ban_to_json_v(char *json, size_t len, void *p);
extern size_t discord_guild_ban_to_json(char *json, size_t len, struct discord_guild_ban *p);
extern size_t discord_guild_ban_to_query_v(char *json, size_t len, void *p);
extern size_t discord_guild_ban_to_query(char *json, size_t len, struct discord_guild_ban *p);
extern void discord_guild_ban_list_free_v(void **p);
extern void discord_guild_ban_list_free(struct discord_guild_ban **p);
extern void discord_guild_ban_list_from_json_v(char *str, size_t len, void *p);
extern void discord_guild_ban_list_from_json(char *str, size_t len, struct discord_guild_ban ***p);
extern size_t discord_guild_ban_list_to_json_v(char *str, size_t len, void *p);
extern size_t discord_guild_ban_list_to_json(char *str, size_t len, struct discord_guild_ban **p);
