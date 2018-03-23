#ifndef APP_HPP
#define APP_HPP

#include <clist.h>

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct raw_msg_data {
  clist_node_t clist_node;
  unsigned int _seq;
  const char* data;
  size_t size;
} raw_msg_data_t;

typedef struct sub {
  char* _topic_name;
  unsigned int _seq;
  uint32_t _timeout_us;
  clist_node_t _data;
  uint32_t _last_interest_date_us;
  size_t (*_deserialize)(void*, const char*, size_t);
  list_node_t clist_node;
} sub_t;

typedef struct pub {
  char* _topic_name;
  unsigned int _cur_seq;
  unsigned int _req_seq;
  unsigned int _snd_seq;
  clist_node_t _data;
  size_t (*_serialize)(const void*, char*, size_t);
  list_node_t clist_node;
} pub_t;

void app_add_sub(sub_t* sub);
void app_rm_sub(sub_t* sub);

void app_add_pub(pub_t* pub);
void app_rm_pub(pub_t* pub);

void app_create(void);
void app_destroy(void);

void app_update(void);

#ifdef __cplusplus
}
#endif

#endif//APP_HPP
