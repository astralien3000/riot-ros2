#include "sub.hpp"

#include "app.h"

#include <stdlib.h>
#include <string.h>

#define ENABLE_DEBUG 0
#include <debug.h>

using namespace rmw::ndn;

Subscription::Subscription(const char* topic_name, size_t (*deserialize)(void*, const char*, size_t)) {
  _seq = 0;
  _timeout_us = MAX_TIMEOUT;
  _window = MIN_WINDOW;
  _deserialize = deserialize;
  _data.next = NULL;

  _topic_name = (char*)malloc(strlen(topic_name));
  strcpy(_topic_name, topic_name);
  app_add_sub((sub_t*)this);
  _last_interest_date_us = Timer::now() - _timeout_us;
  sub_update((sub_t*)this);
}

void sub_push_data(sub_t* sub, unsigned int seq, const char* data, size_t size) {
  DEBUG("push_data(%u, data, %u)\n", seq, (unsigned int)size);

  if(sub->_seq >= seq) {
    return;
  }

  sub->_seq = seq;

  sub_data_t* sub_data = (sub_data_t*)malloc(sizeof(sub_data_t));
  sub_data->node.next = NULL;
  sub_data->data = data;
  sub_data->size = size;

  clist_rpush(&sub->_data, &sub_data->node);

  const Timer::us dur = Timer::now() - sub->_last_interest_date_us;
  if(dur < sub->_timeout_us / 4) {
    sub->_timeout_us /= 2;
    if(sub->_timeout_us < Subscription::MIN_TIMEOUT) {
      sub->_timeout_us = Subscription::MIN_TIMEOUT;
    }
  }

  app_send_data_interest(sub->_topic_name, sub->_seq+1, sub->_window, sub->_timeout_us);
  sub->_last_interest_date_us = Timer::now();
}

void Subscription::on_timeout(void) {
  _timeout_us *= 2;
  if(_timeout_us > MAX_TIMEOUT) {
    _timeout_us = MAX_TIMEOUT;
  }

  app_send_sync_interest(_topic_name, _timeout_us);
  _last_interest_date_us = Timer::now();
}

void sub_update(sub_t* sub) {
  Subscription* _sub = (Subscription*)sub;
  const Timer::us timeout_date = sub->_last_interest_date_us + sub->_timeout_us;
  if(timeout_date <= Timer::now()) {
    _sub->on_timeout();
  }
}

bool Subscription::take(void* msg) {
  if(!can_take()) {
    return false;
  }

  clist_node_t* _ret = clist_lpop(&_data);
  sub_data_t* ret = container_of(_ret, sub_data_t, node);
  const char* data = ret->data;
  size_t size = ret->size;
  free(ret);

  DEBUG("%i :: %i :: [%s] \n", ret->size, _deserialize(msg, data, size), data);
  return size == _deserialize(msg, data, size);
}
