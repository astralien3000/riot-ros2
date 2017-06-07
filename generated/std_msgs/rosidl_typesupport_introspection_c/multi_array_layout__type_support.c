// generated from rosidl_typesupport_introspection_c/resource/msg__type_support.c.em
// generated code does not contain a copyright notice


// providing offsetof()
#include <stddef.h>

#include <std_msgs/msg/multi_array_layout__introspection_type_support.h>
#include "std_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"

#include "std_msgs/msg/multi_array_layout__struct.h"

// include message dependencies
// dim
#include "std_msgs/msg/multi_array_dimension.h"
// dim
#include "std_msgs/msg/multi_array_dimension__introspection_type_support.h"

#if __cplusplus
extern "C"
{
#endif

size_t std_msgs__msg__rosidl_typesupport_introspection_c__size_function__MultiArrayLayout__dim(
  const void * untyped_member)
{
  const std_msgs__msg__MultiArrayDimension__Array * member =
    (const std_msgs__msg__MultiArrayDimension__Array *)(untyped_member);
  return member->size;
}

const void * std_msgs__msg__rosidl_typesupport_introspection_c__get_const_function__MultiArrayLayout__dim(
  const void * untyped_member, size_t index)
{
  const std_msgs__msg__MultiArrayDimension__Array * member =
    (const std_msgs__msg__MultiArrayDimension__Array *)(untyped_member);
  return &member->data[index];
}

void * std_msgs__msg__rosidl_typesupport_introspection_c__get_function__MultiArrayLayout__dim(
  void * untyped_member, size_t index)
{
  std_msgs__msg__MultiArrayDimension__Array * member =
    (std_msgs__msg__MultiArrayDimension__Array *)(untyped_member);
  return &member->data[index];
}

bool std_msgs__msg__rosidl_typesupport_introspection_c__resize_function__MultiArrayLayout__dim(
  void * untyped_member, size_t size)
{
  std_msgs__msg__MultiArrayDimension__Array * member =
    (std_msgs__msg__MultiArrayDimension__Array *)(untyped_member);
  std_msgs__msg__MultiArrayDimension__Array__fini(member);
  return std_msgs__msg__MultiArrayDimension__Array__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember std_msgs__msg__rosidl_typesupport_introspection_c__MultiArrayLayout_message_member_array[2] = {
  {
    "dim",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(std_msgs__msg__MultiArrayLayout, dim),  // bytes offset in struct
    NULL,  // default value
    std_msgs__msg__rosidl_typesupport_introspection_c__size_function__MultiArrayLayout__dim,  // size() function pointer
    std_msgs__msg__rosidl_typesupport_introspection_c__get_const_function__MultiArrayLayout__dim,  // get_const(index) function pointer
    std_msgs__msg__rosidl_typesupport_introspection_c__get_function__MultiArrayLayout__dim,  // get(index) function pointer
    std_msgs__msg__rosidl_typesupport_introspection_c__resize_function__MultiArrayLayout__dim  // resize(index) function pointer
  },
  {
    "data_offset",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(std_msgs__msg__MultiArrayLayout, data_offset),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers std_msgs__msg__rosidl_typesupport_introspection_c__MultiArrayLayout_message_members = {
  "std_msgs",  // package name
  "MultiArrayLayout",  // message name
  2,  // number of fields
  std_msgs__msg__rosidl_typesupport_introspection_c__MultiArrayLayout_message_member_array  // message members
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t std_msgs__msg__rosidl_typesupport_introspection_c__MultiArrayLayout_message_type_support_handle = {
  0,
  &std_msgs__msg__rosidl_typesupport_introspection_c__MultiArrayLayout_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_GENERATOR_C_EXPORT_std_msgs
const rosidl_message_type_support_t *
ROSIDL_GET_TYPE_SUPPORT_FUNCTION(std_msgs, msg, MultiArrayLayout)() {
  std_msgs__msg__rosidl_typesupport_introspection_c__MultiArrayLayout_message_member_array[0].members_ = ROSIDL_GET_TYPE_SUPPORT(std_msgs, msg, MultiArrayDimension);
  if (!std_msgs__msg__rosidl_typesupport_introspection_c__MultiArrayLayout_message_type_support_handle.typesupport_identifier) {
    std_msgs__msg__rosidl_typesupport_introspection_c__MultiArrayLayout_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &std_msgs__msg__rosidl_typesupport_introspection_c__MultiArrayLayout_message_type_support_handle;
}

#if __cplusplus
}
#endif
