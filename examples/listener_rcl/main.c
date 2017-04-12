#include "rcl/rcl.h"
#include "std_msgs/msg/string.h"
#include <stdio.h>

void chatterCallback(const std_msgs__msg__String * msg)
{
  printf("I heard: [%s]\n", msg->data.data);
}

int main(void)
{
  static int argc = 0;
  static char **argv = NULL;

  rcl_ret_t ret = rcl_init(argc, argv, rcl_get_default_allocator());
  if(ret != RCL_RET_OK) {
    puts("ERROR : rcl_init");
  }

  rcl_node_t node = rcl_get_zero_initialized_node();
  rcl_node_options_t node_ops = rcl_node_get_default_options();
  // ... node options customization
  ret = rcl_node_init(&node, "listener", &node_ops);
  if(ret != RCL_RET_OK) {
    puts("ERROR : rcl_node_init");
  }

  const rosidl_message_type_support_t * ts = ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, String);
  rcl_subscription_t subscription = rcl_get_zero_initialized_subscription();
  rcl_subscription_options_t subscription_ops = rcl_subscription_get_default_options();
  ret = rcl_subscription_init(&subscription, &node, ts, "chatter", &subscription_ops);
  if(ret != RCL_RET_OK) {
    puts("ERROR : rcl_subscription_init");
  }

  rcl_wait_set_t wait_set = rcl_get_zero_initialized_wait_set();
  ret = rcl_wait_set_init(&wait_set, 1, 0, 0, 0, 0, rcl_get_default_allocator());
  if(ret != RCL_RET_OK) {
    puts("ERROR : rcl_wait_set_init");
  }

  while(1) {
    ret = rcl_wait_set_clear_subscriptions(&wait_set);
    if(ret != RCL_RET_OK) {
      puts("ERROR : rcl_wait_set_clear_subscriptions");
    }

    ret = rcl_wait_set_add_subscription(&wait_set, &subscription);
    if(ret != RCL_RET_OK) {
      puts("ERROR : rcl_wait_set_add_subscription");
    }

    ret = rcl_wait(&wait_set, RCL_MS_TO_NS(1000));  // 1000ms == 1s, passed as ns
    if (ret == RCL_RET_TIMEOUT) {
      continue;
    }

    for (size_t i = 0; i < wait_set.size_of_subscriptions; ++i) {
      if (wait_set.subscriptions[i]) {
        std_msgs__msg__String msg;
        ret = rcl_take(wait_set.subscriptions[i], (void*)&msg, NULL);
        if(ret != RCL_RET_OK) {
          puts("ERROR : rcl_take");
        }
        else {
          chatterCallback(&msg);
        }
      }
    }
  }

  return 0;
}
