// generated from rosidl_typesupport_opensplice_cpp/resource/msg__type_support.hpp.em
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__MSG__DDS_OPENSPLICE__PARAMETER_TYPE__TYPE_SUPPORT_HPP_
#define RCL_INTERFACES__MSG__DDS_OPENSPLICE__PARAMETER_TYPE__TYPE_SUPPORT_HPP_

#include "rcl_interfaces/msg/parameter_type__struct.hpp"
#include "rcl_interfaces/msg/dds_opensplice/ccpp_ParameterType_.h"
#include "rcl_interfaces/msg/dds_opensplice/visibility_control.h"

namespace DDS
{
class DomainParticipant;
class DataReader;
class DataWriter;
}  // namespace DDS

namespace rcl_interfaces
{

namespace msg
{

namespace typesupport_opensplice_cpp
{

ROSIDL_TYPESUPPORT_OPENSPLICE_CPP_PUBLIC_rcl_interfaces
extern void register_type__ParameterType(
  DDS::DomainParticipant * participant,
  const char * type_name);

ROSIDL_TYPESUPPORT_OPENSPLICE_CPP_PUBLIC_rcl_interfaces
extern void convert_ros_message_to_dds(
  const rcl_interfaces::msg::ParameterType & ros_message,
  rcl_interfaces::msg::dds_::ParameterType_ & dds_message);

ROSIDL_TYPESUPPORT_OPENSPLICE_CPP_PUBLIC_rcl_interfaces
extern void publish__ParameterType(
  DDS::DataWriter * topic_writer,
  const void * untyped_ros_message);

ROSIDL_TYPESUPPORT_OPENSPLICE_CPP_PUBLIC_rcl_interfaces
extern void convert_dds_message_to_ros(
  const rcl_interfaces::msg::dds_::ParameterType_ & dds_message,
  rcl_interfaces::msg::ParameterType & ros_message);

ROSIDL_TYPESUPPORT_OPENSPLICE_CPP_PUBLIC_rcl_interfaces
extern bool take__ParameterType(
  DDS::DataReader * topic_reader,
  bool ignore_local_publications,
  void * untyped_ros_message,
  bool * taken);

}  // namespace typesupport_opensplice_cpp

}  // namespace msg

}  // namespace rcl_interfaces

#endif  // RCL_INTERFACES__MSG__DDS_OPENSPLICE__PARAMETER_TYPE__TYPE_SUPPORT_HPP_
