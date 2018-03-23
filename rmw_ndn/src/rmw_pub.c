#include "rmw/rmw.h"

#include "std_msgs/msg/string.h"
#include "rosidl_typesupport_cbor/message_introspection.h"

#include <stdlib.h>
#include <string.h>

#include "app.h"

#define ENABLE_DEBUG 0
#include <debug.h>

#define MAX_QUEUE (1)

pub_t* _pub_create(const char* topic_name, size_t (*serialize)(const void*, char*, size_t)) {
  pub_t* pub = (pub_t*)malloc(sizeof(pub_t));
  pub->_cur_seq = 0;
  pub->_req_seq = 0;
  pub->_snd_seq = 0;
  pub->_serialize = serialize;
  pub->_data.next = NULL;

  pub->_topic_name = (char*)malloc(strlen(topic_name)+1);
  strcpy(pub->_topic_name, topic_name);
  app_add_pub(pub);
  return pub;
}

void _pub_destroy(pub_t* pub) {
  app_rm_pub(pub);
  free(pub->_topic_name);
  free(pub);
}

void _pub_push_data(pub_t* pub, const void* msg) {
  char* data = (char*)malloc(64);
  size_t size = 0;

  size = pub->_serialize(msg, data, 64);
  data = (char*)realloc(data, size);
  DEBUG("push_data(%s) on %s\n", data, pub->_topic_name);

  pub->_cur_seq++;

  clist_node_t* clist_node = clist_lpop(&pub->_data);
  if(clist_node) {
    raw_msg_data_t* raw_msg = container_of(clist_node, raw_msg_data_t, clist_node);
    DEBUG("free[%i] on %s\n", (int)raw_msg->_seq, pub->_topic_name);
    free(raw_msg->data);
    free(raw_msg);
  }

  raw_msg_data_t* raw_msg = (raw_msg_data_t*)malloc(sizeof(raw_msg_data_t));
  raw_msg->clist_node.next = NULL;
  raw_msg->_seq = pub->_cur_seq;
  raw_msg->data = data;
  raw_msg->size = size;

  clist_rpush(&pub->_data, &raw_msg->clist_node);
}

rmw_publisher_t *
rmw_create_publisher(
    const rmw_node_t * node,
    const rosidl_message_type_support_t * type_support,
    const char * topic_name,
    const rmw_qos_profile_t * qos_policies)
{
  (void) node;
  (void) type_support;
  (void) topic_name;
  (void) qos_policies;
  DEBUG("rmw_create_publisher" "\n");
  rosidl_typesupport_cbor__MessageMembers* tsdata = (rosidl_typesupport_cbor__MessageMembers*)type_support->data;

  rmw_publisher_t * ret = (rmw_publisher_t *)malloc(sizeof(rmw_publisher_t));
  ret->implementation_identifier = rmw_get_implementation_identifier();
  ret->topic_name = topic_name;

  pub_t* pub = _pub_create(topic_name, tsdata->serialize_);
  ret->data = (void*)pub;

  return ret;
}

rmw_ret_t
rmw_destroy_publisher(rmw_node_t * node, rmw_publisher_t * publisher)
{
  (void) node;
  DEBUG("rmw_destroy_publisher" "\n");
  _pub_destroy((pub_t*)publisher->data);
  free(publisher);
  return RMW_RET_OK;
}

rmw_ret_t
rmw_publish(const rmw_publisher_t * publisher, const void * ros_message)
{
  (void) publisher;
  (void) ros_message;
  DEBUG("rmw_publish" "\n");

  std_msgs__msg__String* msg = (std_msgs__msg__String*)ros_message;
  DEBUG("msg: %s\n", msg->data.data);

  pub_t* pub = (pub_t*)publisher->data;
  _pub_push_data(pub, ros_message);

  return RMW_RET_OK;
}
