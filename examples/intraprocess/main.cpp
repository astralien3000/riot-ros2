#include <iostream>
#include <memory>

#include "rclcpp/rclcpp.hpp"

#include "std_msgs/msg/string.hpp"

void chatterCallback(const std_msgs::msg::String::SharedPtr msg)
{
  std::cout << "I heard: [" << msg->data << "]" << std::endl;
}

int main(void)
{
  static int argc = 0;
  static char **argv = NULL;

  rclcpp::init(argc, argv);

  // listener
  auto listener_node = rclcpp::Node::make_shared("listener");

  auto sub = listener_node->create_subscription<std_msgs::msg::String>(
    "chatter", chatterCallback, rmw_qos_profile_default);

  // talker
  auto talker_node = rclcpp::node::Node::make_shared("talker");

  rmw_qos_profile_t custom_qos_profile = rmw_qos_profile_default;
  custom_qos_profile.depth = 7;

  auto chatter_pub = talker_node->create_publisher<std_msgs::msg::String>("chatter", custom_qos_profile);

  rclcpp::WallRate loop_rate(2);

  auto msg = std::make_shared<std_msgs::msg::String>();
  auto i = 1;

  while (rclcpp::ok()) {
    msg->data = "Hello World: " + std::to_string(i++);
    std::cout << "Publishing: '" << msg->data << "'" << std::endl;
    chatter_pub->publish(msg);
    rclcpp::spin_some(talker_node);
    rclcpp::spin_some(listener_node);
    loop_rate.sleep();
  }

  return 0;
}
