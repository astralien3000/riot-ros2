#include <rclc/rclc.h>

#include <std_msgs/msg/string.h>

#include <stdio.h>

void chatter_callback(const void* v_msg)
{
  const std_msgs__msg__String* msg = v_msg;
  printf("I heard: [%s]\n", msg->data.data);
}

int main(void)
{
  static int argc = 0;
  static char **argv = NULL;

  rclc_init(argc, argv);
  rclc_node_t* node = rclc_create_node("listener", "");
  rclc_subscription_t* sub =
      rclc_create_subscription(node, RCLC_GET_MSG_TYPE_SUPPORT(std_msgs, msg, String), "chatter", chatter_callback, 1, false);
  
  rclc_spin_node(node);
  
  rclc_destroy_subscription(sub);
  rclc_destroy_node(node);
  return 0;
}
