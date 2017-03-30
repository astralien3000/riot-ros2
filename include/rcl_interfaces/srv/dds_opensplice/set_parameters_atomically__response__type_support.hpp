// generated from rosidl_typesupport_opensplice_cpp/resource/msg__type_support.hpp.em
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__SRV__DDS_OPENSPLICE__SET_PARAMETERS_ATOMICALLY__RESPONSE__TYPE_SUPPORT_HPP_
#define RCL_INTERFACES__SRV__DDS_OPENSPLICE__SET_PARAMETERS_ATOMICALLY__RESPONSE__TYPE_SUPPORT_HPP_

#include "rcl_interfaces/srv/set_parameters_atomically__response__struct.hpp"
#include "rcl_interfaces/srv/dds_opensplice/ccpp_SetParametersAtomically_Response_.h"
#include "rcl_interfaces/msg/dds_opensplice/visibility_control.h"

namespace DDS
{
class DomainParticipant;
class DataReader;
class DataWriter;
}  // namespace DDS

namespace rcl_interfaces
{

namespace srv
{

namespace typesupport_opensplice_cpp
{

ROSIDL_TYPESUPPORT_OPENSPLICE_CPP_PUBLIC_rcl_interfaces
extern void register_type__SetParametersAtomically_Response(
  DDS::DomainParticipant * participant,
  const char * type_name);

ROSIDL_TYPESUPPORT_OPENSPLICE_CPP_PUBLIC_rcl_interfaces
extern void convert_ros_message_to_dds(
  const rcl_interfaces::srv::SetParametersAtomically_Response & ros_message,
  rcl_interfaces::srv::dds_::SetParametersAtomically_Response_ & dds_message);

ROSIDL_TYPESUPPORT_OPENSPLICE_CPP_PUBLIC_rcl_interfaces
extern void publish__SetParametersAtomically_Response(
  DDS::DataWriter * topic_writer,
  const void * untyped_ros_message);

ROSIDL_TYPESUPPORT_OPENSPLICE_CPP_PUBLIC_rcl_interfaces
extern void convert_dds_message_to_ros(
  const rcl_interfaces::srv::dds_::SetParametersAtomically_Response_ & dds_message,
  rcl_interfaces::srv::SetParametersAtomically_Response & ros_message);

ROSIDL_TYPESUPPORT_OPENSPLICE_CPP_PUBLIC_rcl_interfaces
extern bool take__SetParametersAtomically_Response(
  DDS::DataReader * topic_reader,
  bool ignore_local_publications,
  void * untyped_ros_message,
  bool * taken);

}  // namespace typesupport_opensplice_cpp

}  // namespace srv

}  // namespace rcl_interfaces

#endif  // RCL_INTERFACES__SRV__DDS_OPENSPLICE__SET_PARAMETERS_ATOMICALLY__RESPONSE__TYPE_SUPPORT_HPP_
