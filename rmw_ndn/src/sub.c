#include "sub.h"

#include "app.h"

#include <xtimer.h>

#include <stdlib.h>
#include <string.h>

#define ENABLE_DEBUG 0
#include <debug.h>

#define MAX_TIMEOUT (2000000) // 2s,   in us
#define MIN_TIMEOUT (  10000) // 10ms, in us

#define MIN_WINDOW (1)

void sub_init(sub_t* sub, const char* topic_name, size_t (*deserialize)(void*, const char*, size_t)) {
  sub->_seq = 0;
  sub->_timeout_us = MAX_TIMEOUT;
  sub->_deserialize = deserialize;
  sub->_data.next = NULL;

  sub->_topic_name = (char*)malloc(strlen(topic_name));
  strcpy(sub->_topic_name, topic_name);
  app_add_sub(sub);
  sub->_last_interest_date_us = xtimer_now_usec() - sub->_timeout_us;
  sub_update(sub);
}

sub_t* sub_create(const char* topic_name, size_t (*deserialize)(void*, const char*, size_t)) {
  sub_t* sub = (sub_t*)malloc(sizeof(sub_t));
  sub_init(sub, topic_name, deserialize);
  return sub;
}

void sub_destroy(sub_t* sub) {
  free(sub->_topic_name);
  free(sub);
}

void sub_push_data(sub_t* sub, unsigned int seq, const char* data, size_t size) {
  DEBUG("push_data(%u, data, %u)\n", seq, (unsigned int)size);

  if(sub->_seq >= seq) {
    return;
  }

  sub->_seq = seq;

  raw_msg_data_t* sub_data = (raw_msg_data_t*)malloc(sizeof(raw_msg_data_t));
  sub_data->node.next = NULL;
  sub_data->data = data;
  sub_data->size = size;

  clist_rpush(&sub->_data, &sub_data->node);

  const uint32_t dur = xtimer_now_usec() - sub->_last_interest_date_us;
  if(dur < sub->_timeout_us / 4) {
    sub->_timeout_us /= 2;
    if(sub->_timeout_us < MIN_TIMEOUT) {
      sub->_timeout_us = MIN_TIMEOUT;
    }
  }

  app_send_data_interest(sub->_topic_name, sub->_seq+1, MIN_WINDOW, sub->_timeout_us);
  sub->_last_interest_date_us = xtimer_now_usec();
}

void sub_on_timeout(sub_t* sub) {
  sub->_timeout_us *= 2;
  if(sub->_timeout_us > MAX_TIMEOUT) {
    sub->_timeout_us = MAX_TIMEOUT;
  }

  app_send_sync_interest(sub->_topic_name, sub->_timeout_us);
  sub->_last_interest_date_us = xtimer_now_usec();
}

void sub_update(sub_t* sub) {
  const uint32_t timeout_date = sub->_last_interest_date_us + sub->_timeout_us;
  if(timeout_date <= xtimer_now_usec()) {
    sub_on_timeout(sub);
  }
}

bool sub_take(sub_t* sub, void* msg) {
  if(!sub_can_take(sub)) {
    return false;
  }

  clist_node_t* _ret = clist_lpop(&sub->_data);
  raw_msg_data_t* ret = container_of(_ret, raw_msg_data_t, node);
  const char* data = ret->data;
  size_t size = ret->size;
  free(ret);

  DEBUG("%i :: %i :: [%s] \n", ret->size, sub->_deserialize(msg, data, size), data);
  return size == sub->_deserialize(msg, data, size);
}
