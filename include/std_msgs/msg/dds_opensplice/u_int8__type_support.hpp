// generated from rosidl_typesupport_opensplice_cpp/resource/msg__type_support.hpp.em
// generated code does not contain a copyright notice

#ifndef STD_MSGS__MSG__DDS_OPENSPLICE__U_INT8__TYPE_SUPPORT_HPP_
#define STD_MSGS__MSG__DDS_OPENSPLICE__U_INT8__TYPE_SUPPORT_HPP_

#include "std_msgs/msg/u_int8__struct.hpp"
#include "std_msgs/msg/dds_opensplice/ccpp_UInt8_.h"
#include "std_msgs/msg/dds_opensplice/visibility_control.h"

namespace DDS
{
class DomainParticipant;
class DataReader;
class DataWriter;
}  // namespace DDS

namespace std_msgs
{

namespace msg
{

namespace typesupport_opensplice_cpp
{

ROSIDL_TYPESUPPORT_OPENSPLICE_CPP_PUBLIC_std_msgs
extern void register_type__UInt8(
  DDS::DomainParticipant * participant,
  const char * type_name);

ROSIDL_TYPESUPPORT_OPENSPLICE_CPP_PUBLIC_std_msgs
extern void convert_ros_message_to_dds(
  const std_msgs::msg::UInt8 & ros_message,
  std_msgs::msg::dds_::UInt8_ & dds_message);

ROSIDL_TYPESUPPORT_OPENSPLICE_CPP_PUBLIC_std_msgs
extern void publish__UInt8(
  DDS::DataWriter * topic_writer,
  const void * untyped_ros_message);

ROSIDL_TYPESUPPORT_OPENSPLICE_CPP_PUBLIC_std_msgs
extern void convert_dds_message_to_ros(
  const std_msgs::msg::dds_::UInt8_ & dds_message,
  std_msgs::msg::UInt8 & ros_message);

ROSIDL_TYPESUPPORT_OPENSPLICE_CPP_PUBLIC_std_msgs
extern bool take__UInt8(
  DDS::DataReader * topic_reader,
  bool ignore_local_publications,
  void * untyped_ros_message,
  bool * taken);

}  // namespace typesupport_opensplice_cpp

}  // namespace msg

}  // namespace std_msgs

#endif  // STD_MSGS__MSG__DDS_OPENSPLICE__U_INT8__TYPE_SUPPORT_HPP_
