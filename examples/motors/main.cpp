#include <stdio.h>
#include <math.h>
#include <string.h>

#include <xtimer.h>
#include "motors.hpp"

extern "C" {
#include <rclc/rclc.h>
}

#include <std_msgs/msg/string.h>

void chatter_callback(const void* v_msg)
{
  const std_msgs__msg__String* msg = (const std_msgs__msg__String*)v_msg;
  printf("I heard: [%s]\n", msg->data.data);

  int angle = atoi(msg->data.data);

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
      rclc_create_subscription(node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, String), "chatter", chatter_callback, 1, false);

  rclc_spin_node(node);

  rclc_destroy_subscription(sub);
  rclc_destroy_node(node);
  
  return 0;
}
