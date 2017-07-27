#include "rmw/rmw.h"

#include "std_msgs/msg/string.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"

#include <stdlib.h>
#include <string.h>

#include "sub.hpp"

#define ENABLE_DEBUG 0
#include <debug.h>

using Sub = rmw::mqtt::Subscription;

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

  rmw_subscription_t * ret = (rmw_subscription_t *)malloc(sizeof(rmw_subscription_t));
  ret->implementation_identifier = rmw_get_implementation_identifier();
  ret->topic_name = topic_name;

  //Sub* sub = new Sub(topic_name);
  //ret->data = (void*)sub;

  return ret;
}

rmw_ret_t
rmw_destroy_subscription(rmw_node_t * node, rmw_subscription_t * subscription)
{
  (void) node;
  DEBUG("rmw_destroy_subscription" "\n");
  //delete (Sub*)subscription->data;
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

  //Sub* sub = (Sub*)subscription->data;
  //char* data = (char*)sub->take();
  /*
  if(data == NULL) {
    *taken = false;
    return RMW_RET_ERROR;
  }

  *taken = true;

  std_msgs__msg__String* msg = (std_msgs__msg__String*)ros_message;
  msg->data.data = data;
  msg->data.size = strlen(data);
  */
  return RMW_RET_OK;
}
