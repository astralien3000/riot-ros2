#ifndef APP_HPP
#define APP_HPP

#include <clist.h>

#include <stdlib.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct raw_msg_data {
  clist_node_t node;
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
  list_node_t node;
} sub_t;

typedef struct pub {
  char* _topic_name;
  unsigned int _cur_seq;
  unsigned int _req_seq;
  clist_node_t _data;
  size_t (*_serialize)(const void*, char*, size_t);
  list_node_t node;
} pub_t;

void app_add_sub(sub_t* sub);
void app_rm_sub(sub_t* sub);

void app_add_pub(pub_t* pub);
void app_rm_pub(pub_t* pub);

void app_send_sync_interest(const char* topic, unsigned int timeout);
void app_send_data_interest(const char* topic, unsigned int seq, unsigned int window, unsigned int timeout);

void app_publish(const char* topic, unsigned int seq, const char* data, size_t size);

void app_create(void);
void app_destroy(void);

void app_update(void);

// sub.h

void sub_update(sub_t* sub);
void sub_push_data(sub_t* sub, unsigned int seq, const char* data, size_t size);

// pub.h

void pub_get_sync_data(pub_t* pub, unsigned int* seq, const char** data, size_t* size);
void pub_on_interest(pub_t* pub, unsigned int seq);

#ifdef __cplusplus
}
#endif

#endif//APP_HPP
