#include "pub.h"

#include "app.h"

#include <stdlib.h>
#include <string.h>

#define ENABLE_DEBUG 0
#include <debug.h>

void pub_init(pub_t* pub, const char* topic_name, size_t (*serialize)(const void*, char*, size_t)) {
  pub->_cur_seq = 0;
  pub->_req_seq = 0;
  pub->_serialize = serialize;
  pub->_data.next = NULL;

  pub->_topic_name = (char*)malloc(strlen(topic_name));
  strcpy(pub->_topic_name, topic_name);
  app_add_pub(pub);
}

pub_t* pub_create(const char* topic_name, size_t (*serialize)(const void*, char*, size_t)) {
  pub_t* pub = (pub_t*)malloc(sizeof(pub_t));
  pub_init(pub, topic_name, serialize);
  return pub;
}

void pub_destroy(pub_t* pub) {
  free(pub);
}

void pub_get_sync_data(pub_t* pub, unsigned int* seq, const char** data, size_t* size) {
  *seq = pub->_cur_seq;
  if(pub->_data.next) {
    clist_node_t* _ret = clist_rpeek(&pub->_data);
    raw_msg_data_t* ret = container_of(_ret, raw_msg_data_t, node);
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
    raw_msg_data_t* ret = container_of(_ret, raw_msg_data_t, node);
    app_publish(pub->_topic_name, pub->_cur_seq, ret->data, ret->size);
  }
}

void pub_push_data(pub_t* pub, const void* msg) {
  char* data = (char*)malloc(64);
  size_t size = 0;
  
  size = pub->_serialize(msg, data, 64);
  data = (char*)realloc(data, size);
  DEBUG("push_data(%s) on %s\n", data, pub->_topic_name);

  // TODO : if _data.size() >= MAX_QUEUE
  if(pub->_data.next) {
    clist_node_t* ret = clist_lpop(&pub->_data);
    free(container_of(ret, raw_msg_data_t, node));
  }

  pub->_cur_seq++;

  raw_msg_data_t* pub_data = (raw_msg_data_t*)malloc(sizeof(raw_msg_data_t));
  pub_data->node.next = NULL;
  pub_data->data = data;
  pub_data->size = size;

  clist_rpush(&pub->_data, &pub_data->node);

  if(pub->_cur_seq <= pub->_req_seq) {
    app_publish(pub->_topic_name, pub->_cur_seq, data, size);
  }
}
