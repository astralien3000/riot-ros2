#include <stdio.h>
#include <math.h>
#include <string.h>

#include <xtimer.h>
#include "motors.hpp"

extern "C" {
#include <rclc/rclc.h>
}

#include <custom_msgs/msg/gyro.h>

void chatter_callback(const void* v_msg)
{
  const custom_msgs__msg__Gyro* msg = (const custom_msgs__msg__Gyro*)v_msg;
  printf("I heard: [ %i %i %i ]\n", (int)msg->z_angle, (int)msg->z_angle, (int)msg->z_angle);

  int angle = msg->z_angle;
  int dist = msg->x_angle;

  Motors::instance().left().put(dist+angle);
  Motors::instance().right().put(dist-angle);
}

int main(void) {
  static int argc = 0;
  static char **argv = NULL;

  Motors::instance().start();

  rclc_init(argc, argv);
  rclc_node_t* node = rclc_create_node("listener");
  rclc_subscription_t* sub =
      rclc_create_subscription(node, ROSIDL_GET_MSG_TYPE_SUPPORT(custom_msgs, Gyro), "chatter", chatter_callback, 1, false);

  rclc_spin_node(node);

  rclc_destroy_subscription(sub);
  rclc_destroy_node(node);
  
  return 0;
}
