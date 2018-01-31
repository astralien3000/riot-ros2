#include <rclc/rclc.h>

#include <std_msgs/msg/int32.h>

#include <stdio.h>

int main(void)
{
  static int argc = 0;
  static char **argv = NULL;

  rclc_init(argc, argv);
  rclc_node_t* node = rclc_create_node("pub_int", "");
  rclc_publisher_t* pub = rclc_create_publisher(node, RCLC_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32), "int32", 1);

  std_msgs__msg__Int32 msg;
  msg.data = -100;
  
  while (rclc_ok()) {
    msg.data++;
    printf("Publishing: '%i'\n", (int)msg.data);
    
    rclc_publish(pub, (const void*)&msg);

    rclc_spin_node_once(node, 100);
  }
    
  rclc_destroy_publisher(pub);
  rclc_destroy_node(node);
  return 0;
}
