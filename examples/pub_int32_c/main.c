/*
Copyright 2017 INRIA

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

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
