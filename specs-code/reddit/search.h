/* This file is generated from specs/reddit/search.json, Please don't edit it. */
/*

*/

/* https://www.reddit.com/dev/api/#GET_search */
/* This is defined at specs/reddit/search.json:8:22 */
struct reddit_search_params {
  /* specs/reddit/search.json:11:20
     '{ "name": "after", "type":{ "base":"char", "dec":"*" }, "comment":"fullname of a thing"}'
  */
  char *after; // fullname of a thing

  /* specs/reddit/search.json:12:20
     '{ "name": "before", "type":{ "base":"char", "dec":"*" }, "comment":"fullname of a thing"}'
  */
  char *before; // fullname of a thing

  /* specs/reddit/search.json:13:20
     '{ "name": "category", "type":{ "base":"char", "dec":"*" }, "comment":"a string no longer than 5 character"}'
  */
  char *category; // a string no longer than 5 character

  /* specs/reddit/search.json:14:20
     '{ "name": "count", "type":{ "base":"int" }, "comment":"a positive integer (default: 0)"}'
  */
  int count; // a positive integer (default: 0)

  /* specs/reddit/search.json:15:20
     '{ "name": "include_facets", "type":{ "base":"bool" }, "comment":"boolean value"}'
  */
  bool include_facets; // boolean value

  /* specs/reddit/search.json:16:20
     '{ "name": "limit", "type":{ "base":"int" }, "comment":"the maximum number of items desired (default: 25, maximum: 100)"}'
  */
  int limit; // the maximum number of items desired (default: 25, maximum: 100)

  /* specs/reddit/search.json:17:20
     '{ "name": "q", "type":{ "base":"char", "dec":"*" }, "comment":"a string no longer than 512 characters"}'
  */
  char *q; // a string no longer than 512 characters

  /* specs/reddit/search.json:18:20
     '{ "name": "restrict_sr", "type":{ "base":"bool" }, "comment":"boolean value"}'
  */
  bool restrict_sr; // boolean value

  /* specs/reddit/search.json:19:20
     '{ "name": "show", "type":{ "base":"char", "dec":"*" }, "comment":"(optional)the string all"}'
  */
  char *show; // (optional)the string all

  /* specs/reddit/search.json:20:20
     '{ "name": "sort", "type":{ "base":"char", "dec":"*" }, "comment":"one of(relevance, hot, top, new, comments)"}'
  */
  char *sort; // one of(relevance, hot, top, new, comments)

  /* specs/reddit/search.json:21:20
     '{ "name": "sr_detail", "type":{ "base":"char", "dec":"*" }, "comment":"expand subreddits"}'
  */
  char *sr_detail; // expand subreddits

  /* specs/reddit/search.json:22:20
     '{ "name": "t", "type":{ "base":"char", "dec":"*" }, "comment":"one of(hour, day, week, month, year, all)"}'
  */
  char *t; // one of(hour, day, week, month, year, all)

  /* specs/reddit/search.json:23:20
     '{ "name": "type", "type":{ "base":"char", "dec":"*" }, "comment":"(optional) comma-delimited list of result types (sr, link, user)"}'
  */
  char *type; // (optional) comma-delimited list of result types (sr, link, user)

  // The following is metadata used to 
  // 1. control which field should be extracted/injected
  // 2. record which field is presented(defined) in JSON
  // 3. record which field is null in JSON
  struct {
    bool enable_arg_switches;
    bool enable_record_defined;
    bool enable_record_null;
    void *arg_switches[13];
    void *record_defined[13];
    void *record_null[13];
  } __M; // metadata
};
extern void reddit_search_params_cleanup_v(void *p);
extern void reddit_search_params_cleanup(struct reddit_search_params *p);
extern void reddit_search_params_init_v(void *p);
extern void reddit_search_params_init(struct reddit_search_params *p);
extern struct reddit_search_params * reddit_search_params_alloc();
extern void reddit_search_params_free_v(void *p);
extern void reddit_search_params_free(struct reddit_search_params *p);
extern void reddit_search_params_from_json_v(char *json, size_t len, void *p);
extern void reddit_search_params_from_json(char *json, size_t len, struct reddit_search_params *p);
extern size_t reddit_search_params_to_json_v(char *json, size_t len, void *p);
extern size_t reddit_search_params_to_json(char *json, size_t len, struct reddit_search_params *p);
extern size_t reddit_search_params_to_query_v(char *json, size_t len, void *p);
extern size_t reddit_search_params_to_query(char *json, size_t len, struct reddit_search_params *p);
extern void reddit_search_params_list_free_v(void **p);
extern void reddit_search_params_list_free(struct reddit_search_params **p);
extern void reddit_search_params_list_from_json_v(char *str, size_t len, void *p);
extern void reddit_search_params_list_from_json(char *str, size_t len, struct reddit_search_params ***p);
extern size_t reddit_search_params_list_to_json_v(char *str, size_t len, void *p);
extern size_t reddit_search_params_list_to_json(char *str, size_t len, struct reddit_search_params **p);
