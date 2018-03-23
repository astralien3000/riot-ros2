#include "rmw/rmw.h"

#include "std_msgs/msg/string.h"
#include "rosidl_typesupport_cbor/message_introspection.h"

#include <stdlib.h>
#include <string.h>

#include "app.h"

#define ENABLE_DEBUG 0
#include <debug.h>

static sub_t* _sub_create(const char* topic_name, size_t (*deserialize)(void*, const char*, size_t)) {
  sub_t* sub = (sub_t*)malloc(sizeof(sub_t));
  sub->_seq = 0;
  sub->_timeout_us = 0;
  sub->_last_interest_date_us = 0;
  sub->_deserialize = deserialize;
  sub->_data.next = NULL;

  sub->_topic_name = (char*)malloc(strlen(topic_name));
  strcpy(sub->_topic_name, topic_name);
  app_add_sub(sub);
  return sub;
}

static void _sub_destroy(sub_t* sub) {
  app_rm_sub(sub);
  free(sub->_topic_name);
  free(sub);
}

static bool _sub_take(sub_t* sub, void* msg) {
  if(!sub->_data.next) {
    return false;
  }

  clist_node_t* _ret = clist_lpop(&sub->_data);
  raw_msg_data_t* ret = container_of(_ret, raw_msg_data_t, clist_node);
  const char* data = ret->data;
  size_t size = ret->size;
  free(ret);

  return size == sub->_deserialize(msg, data, size);
}

rmw_subscription_t *
rmw_create_subscription(
    const rmw_node_t * node,
    const rosidl_message_type_support_t * type_support,
    const char * topic_name,
    const rmw_qos_profile_t * qos_policies,
    bool ignore_local_publications)
{
  (void) node;
  (void) type_support;
  (void) qos_policies;
  (void) ignore_local_publications;
  DEBUG("rmw_create_subscription" "\n");
  rosidl_typesupport_cbor__MessageMembers* tsdata = (rosidl_typesupport_cbor__MessageMembers*)type_support->data;

  rmw_subscription_t * ret = (rmw_subscription_t *)malloc(sizeof(rmw_subscription_t));
  ret->implementation_identifier = rmw_get_implementation_identifier();
  ret->topic_name = topic_name;

  sub_t* sub = _sub_create(topic_name, tsdata->deserialize_);
  ret->data = (void*)sub;

  return ret;
}

rmw_ret_t
rmw_destroy_subscription(rmw_node_t * node, rmw_subscription_t * subscription)
{
  (void) node;
  DEBUG("rmw_destroy_subscription" "\n");
  _sub_destroy((sub_t*)subscription->data);
  free(subscription);
  return RMW_RET_OK;
}

rmw_ret_t
rmw_take(const rmw_subscription_t * subscription, void * ros_message, bool * taken)
{
  (void) subscription;
  (void) ros_message;
  (void) taken;
  DEBUG("rmw_take" "\n");
  return RMW_RET_OK;
}

rmw_ret_t
rmw_take_with_info(
    const rmw_subscription_t * subscription,
    void * ros_message,
    bool * taken,
    rmw_message_info_t * message_info)
{
  (void) message_info;
  DEBUG("rmw_take_with_info" "\n");

  sub_t* sub = (sub_t*)subscription->data;
  *taken = _sub_take(sub, ros_message);

  return RMW_RET_OK;
}
