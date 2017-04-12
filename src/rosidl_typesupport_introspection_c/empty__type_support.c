// generated from rosidl_typesupport_introspection_c/resource/msg__type_support.c.em
// generated code does not contain a copyright notice


// providing offsetof()
#include <stddef.h>

#include <std_msgs/msg/empty__introspection_type_support.h>
#include "std_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"

#include "std_msgs/msg/empty__struct.h"

#if __cplusplus
extern "C"
{
#endif

static const rosidl_typesupport_introspection_c__MessageMembers std_msgs__msg__rosidl_typesupport_introspection_c__Empty_message_members = {
  "std_msgs",  // package name
  "Empty",  // message name
  0,  // number of fields
  0  // message members
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t std_msgs__msg__rosidl_typesupport_introspection_c__Empty_message_type_support_handle = {
  0,
  &std_msgs__msg__rosidl_typesupport_introspection_c__Empty_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_GENERATOR_C_EXPORT_std_msgs
const rosidl_message_type_support_t *
ROSIDL_GET_TYPE_SUPPORT_FUNCTION(std_msgs, msg, Empty)() {
  if (!std_msgs__msg__rosidl_typesupport_introspection_c__Empty_message_type_support_handle.typesupport_identifier) {
    std_msgs__msg__rosidl_typesupport_introspection_c__Empty_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &std_msgs__msg__rosidl_typesupport_introspection_c__Empty_message_type_support_handle;
}

#if __cplusplus
}
#endif
