#include <stdio.h>
#include <math.h>
#include <string.h>

#include <xtimer.h>
#include "motors.hpp"

extern "C" {
#include <rclc/rclc.h>
}

#include <std_msgs/msg/int32.h>

void chatter_callback(const void* v_msg)
{
  const std_msgs__msg__Int32* msg = (const std_msgs__msg__Int32*)v_msg;
  printf("I heard: [%i]\n", (int)msg->data);

  int angle = msg->data;

  Motors::instance().left().put(angle);
  Motors::instance().right().put(-angle);
}

int main(void) {
  static int argc = 0;
  static char **argv = NULL;

  Motors::instance().start();

  rclc_init(argc, argv);
  rclc_node_t* node = rclc_create_node("listener");
  rclc_subscription_t* sub =
      rclc_create_subscription(node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, Int32), "chatter", chatter_callback, 1, false);

  rclc_spin_node(node);

  rclc_destroy_subscription(sub);
  rclc_destroy_node(node);
  
  return 0;
}
