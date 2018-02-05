#include "pub.hpp"

#include "app.h"

#include <stdlib.h>
#include <string.h>

#define ENABLE_DEBUG 0
#include <debug.h>

using namespace rmw::ndn;

Publisher::Publisher(const char* topic_name, size_t (*serialize)(const void*, char*, size_t)) {
  _cur_seq = 0;
  _req_seq = 0;
  _serialize = serialize;
  _data.next = NULL;

  _topic_name = (char*)malloc(strlen(topic_name));
  strcpy(_topic_name, topic_name);
  app_add_pub((pub_t*)this);
}

void pub_get_sync_data(pub_t* pub, unsigned int* seq, const char** data, size_t* size) {
  *seq = pub->_cur_seq;
  if(pub->_data.next) {
    clist_node_t* _ret = clist_rpeek(&pub->_data);
    sub_data_t* ret = container_of(_ret, sub_data_t, node);
    *data = ret->data;
    *size = ret->size;
    DEBUG("SYNC DATA : [%s]\n", *data);
  }
  else {
    *data = NULL;
    DEBUG("NO SYNC DATA\n", *data);
  }
}

void pub_on_interest(pub_t* pub, unsigned int seq) {
  if(pub->_req_seq < seq) {
    pub->_req_seq = seq;
  }

  if(pub->_cur_seq <= pub->_req_seq) {
    clist_node_t* _ret = clist_rpeek(&pub->_data);
    sub_data_t* ret = container_of(_ret, sub_data_t, node);
    app_publish(pub->_topic_name, pub->_cur_seq, ret->data, ret->size);
  }
}

void Publisher::push_data(const void* msg) {
  char* data = (char*)malloc(64);
  size_t size = 0;
  
  size = _serialize(msg, data, 64);
  data = (char*)realloc(data, size);
  DEBUG("push_data(%s) on %s\n", data, _topic_name);

  // TODO : if _data.size() >= MAX_QUEUE
  if(_data.next) {
    clist_node_t* ret = clist_lpop(&_data);
    free(container_of(ret, sub_data_t, node));
  }

  _cur_seq++;

  sub_data_t* pub_data = (sub_data_t*)malloc(sizeof(sub_data_t));
  pub_data->node.next = NULL;
  pub_data->data = data;
  pub_data->size = size;

  clist_rpush(&_data, &pub_data->node);

  if(_cur_seq <= _req_seq) {
    app_publish(_topic_name, _cur_seq, data, size);
  }
}
