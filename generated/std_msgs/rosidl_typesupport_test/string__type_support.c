// generated from rosidl_typesupport_test/resource/msg__type_support.c.em
// generated code does not contain a copyright notice


// providing offsetof()
#include <stddef.h>
#include <stdio.h>
#include <cbor.h>

#include <std_msgs/msg/string__test_type_support.h>
#include "std_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "rosidl_typesupport_test/field_types.h"
#include "rosidl_typesupport_test/identifier.h"
#include "rosidl_typesupport_test/message_introspection.h"

#include "std_msgs/msg/string__struct.h"

#if __cplusplus
extern "C"
{
#endif


static rosidl_typesupport_test__MessageMember std_msgs__msg__rosidl_typesupport_test__String_message_member_array[1] = {
  {
    "data",  // name
    rosidl_typesupport_test__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(std_msgs__msg__String, data),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

size_t std_msgs__msg__rosidl_typesupport_test__String_serialize(const void* ros_message, char* buffer, size_t buffer_size) {
    const std_msgs__msg__String* msg = ros_message;
    size_t ret = 0;
    cbor_stream_t stream;
    cbor_init(&stream, (unsigned char*)buffer, buffer_size);
    cbor_clear(&stream);
    ret += cbor_serialize_byte_stringl(&stream, msg->data.data, msg->data.size);
    return ret;
}

size_t std_msgs__msg__rosidl_typesupport_test__String_deserialize(void* ros_message, const char* buffer, size_t buffer_size) {
    std_msgs__msg__String* msg = ros_message;
    size_t ret = 0;
    cbor_stream_t stream;
    cbor_init(&stream, (unsigned char*)buffer, buffer_size);
    stream.pos = buffer_size;
    msg->data.capacity = buffer_size;
    msg->data.data = realloc(msg->data.data, sizeof(char)*buffer_size);
    ret += msg->data.size = cbor_deserialize_byte_string(&stream, ret, msg->data.data, msg->data.capacity);
    return ret;
}

static const rosidl_typesupport_test__MessageMembers std_msgs__msg__rosidl_typesupport_test__String_message_members = {
  "std_msgs",  // package name
  "String",  // message name
  1,  // number of fields
  std_msgs__msg__rosidl_typesupport_test__String_message_member_array,
  std_msgs__msg__rosidl_typesupport_test__String_serialize,
  std_msgs__msg__rosidl_typesupport_test__String_deserialize
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t std_msgs__msg__rosidl_typesupport_test__String_message_type_support_handle = {
  0,
  &std_msgs__msg__rosidl_typesupport_test__String_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_GENERATOR_C_EXPORT_std_msgs
const rosidl_message_type_support_t *
ROSIDL_GET_TYPE_SUPPORT_FUNCTION(std_msgs, msg, String)() {
  if (!std_msgs__msg__rosidl_typesupport_test__String_message_type_support_handle.typesupport_identifier) {
    std_msgs__msg__rosidl_typesupport_test__String_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_test__identifier;
  }
  return &std_msgs__msg__rosidl_typesupport_test__String_message_type_support_handle;
}

#if __cplusplus
}
#endif
