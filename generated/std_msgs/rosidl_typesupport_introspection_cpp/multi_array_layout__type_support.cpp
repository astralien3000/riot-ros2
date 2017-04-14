// generated from rosidl_typesupport_introspection_cpp/resource/msg__type_support.cpp.em
// generated code does not contain a copyright notice

#ifndef __std_msgs__msg__multi_array_layout__type_support__h__
#define __std_msgs__msg__multi_array_layout__type_support__h__

// providing offsetof()
#include <cstddef>
#include <vector>

#include "rosidl_generator_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"

#include "std_msgs/msg/multi_array_layout__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace std_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

size_t size_function__MultiArrayLayout__dim(const void * untyped_member)
{
  const std::vector<std_msgs::msg::MultiArrayDimension> * member =
    reinterpret_cast<const std::vector<std_msgs::msg::MultiArrayDimension> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MultiArrayLayout__dim(const void * untyped_member, size_t index)
{
  const std::vector<std_msgs::msg::MultiArrayDimension> & member =
    *reinterpret_cast<const std::vector<std_msgs::msg::MultiArrayDimension> *>(untyped_member);
  return &member[index];
}

void * get_function__MultiArrayLayout__dim(void * untyped_member, size_t index)
{
  std::vector<std_msgs::msg::MultiArrayDimension> & member =
    *reinterpret_cast<std::vector<std_msgs::msg::MultiArrayDimension> *>(untyped_member);
  return &member[index];
}

void resize_function__MultiArrayLayout__dim(void * untyped_member, size_t size)
{
  std::vector<std_msgs::msg::MultiArrayDimension> * member =
    reinterpret_cast<std::vector<std_msgs::msg::MultiArrayDimension> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MultiArrayLayout_message_member_array[2] = {
  {
    "dim",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::MultiArrayDimension>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(std_msgs::msg::MultiArrayLayout, dim),  // bytes offset in struct
    nullptr,  // default value
    size_function__MultiArrayLayout__dim,  // size() function pointer
    get_const_function__MultiArrayLayout__dim,  // get_const(index) function pointer
    get_function__MultiArrayLayout__dim,  // get(index) function pointer
    resize_function__MultiArrayLayout__dim  // resize(index) function pointer
  },
  {
    "data_offset",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(std_msgs::msg::MultiArrayLayout, data_offset),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MultiArrayLayout_message_members = {
  "std_msgs",  // package name
  "MultiArrayLayout",  // message name
  2,  // number of fields
  MultiArrayLayout_message_member_array  // message members
};

static const rosidl_message_type_support_t MultiArrayLayout_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MultiArrayLayout_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace std_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<std_msgs::msg::MultiArrayLayout>()
{
  return &::std_msgs::msg::rosidl_typesupport_introspection_cpp::MultiArrayLayout_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, std_msgs, msg, MultiArrayLayout)() {
  return &::std_msgs::msg::rosidl_typesupport_introspection_cpp::MultiArrayLayout_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#endif  // __std_msgs__msg__multi_array_layout__type_support__h__
