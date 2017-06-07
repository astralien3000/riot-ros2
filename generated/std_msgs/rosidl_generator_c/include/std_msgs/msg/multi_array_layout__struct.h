// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef STD_MSGS__MSG__MULTI_ARRAY_LAYOUT__STRUCT_H_
#define STD_MSGS__MSG__MULTI_ARRAY_LAYOUT__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// include message dependencies
// dim
#include "std_msgs/msg/multi_array_dimension__struct.h"

/// Struct of message std_msgs/MultiArrayLayout
typedef struct std_msgs__msg__MultiArrayLayout
{
  std_msgs__msg__MultiArrayDimension__Array dim;
  uint32_t data_offset;
} std_msgs__msg__MultiArrayLayout;

/// Struct for an array of messages
typedef struct std_msgs__msg__MultiArrayLayout__Array
{
  std_msgs__msg__MultiArrayLayout * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} std_msgs__msg__MultiArrayLayout__Array;

#if __cplusplus
}
#endif

#endif  // STD_MSGS__MSG__MULTI_ARRAY_LAYOUT__STRUCT_H_
