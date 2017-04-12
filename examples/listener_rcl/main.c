#include "rcl/rcl.h"
#include "std_msgs/msg/string.h"
#include <stdio.h>

void chatterCallback(const std_msgs__msg__String * msg)
{
  printf("I heard: [%s]", msg->data.data);
}

int main(void)
{
  static int argc = 0;
  static char **argv = NULL;

  rcl_ret_t res = rcl_init(argc, argv, rcl_get_default_allocator());
  if(res != RCL_RET_OK) {
    puts("ERROR : rcl_init");
  }

  rcl_node_t node = rcl_get_zero_initialized_node();
  rcl_node_options_t node_ops = rcl_node_get_default_options();
  // ... node options customization
  res = rcl_node_init(&node, "listener", &node_ops);
  if(res != RCL_RET_OK) {
    puts("ERROR : rcl_node_init");
  }

  const rosidl_message_type_support_t * ts = ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, String);
  rcl_subscription_t subscription = rcl_get_zero_initialized_subscription();
  rcl_subscription_options_t subscription_ops = rcl_subscription_get_default_options();
  res = rcl_subscription_init(&subscription, &node, ts, "chatter", &subscription_ops);
  if(res != RCL_RET_OK) {
    puts("ERROR : rcl_subscription_init");
  }

/*
  auto sub = node->create_subscription<std_msgs::msg::String>(
    "chatter", chatterCallback, rmw_qos_profile_default);

  rclcpp::spin(node);
  */

  return 0;
}
