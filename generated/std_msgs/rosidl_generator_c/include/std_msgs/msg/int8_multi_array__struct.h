// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef STD_MSGS__MSG__INT8_MULTI_ARRAY__STRUCT_H_
#define STD_MSGS__MSG__INT8_MULTI_ARRAY__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// include message dependencies
// layout
#include "std_msgs/msg/multi_array_layout__struct.h"
// data
#include "rosidl_generator_c/primitives_array.h"

/// Struct of message std_msgs/Int8MultiArray
typedef struct std_msgs__msg__Int8MultiArray
{
  std_msgs__msg__MultiArrayLayout layout;
  rosidl_generator_c__int8__Array data;
} std_msgs__msg__Int8MultiArray;

/// Struct for an array of messages
typedef struct std_msgs__msg__Int8MultiArray__Array
{
  std_msgs__msg__Int8MultiArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} std_msgs__msg__Int8MultiArray__Array;

#if __cplusplus
}
#endif

#endif  // STD_MSGS__MSG__INT8_MULTI_ARRAY__STRUCT_H_
