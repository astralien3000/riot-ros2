// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef STD_MSGS__MSG__MULTI_ARRAY_DIMENSION__STRUCT_H_
#define STD_MSGS__MSG__MULTI_ARRAY_DIMENSION__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// include message dependencies
// label
#include "rosidl_generator_c/string.h"

/// Struct of message std_msgs/MultiArrayDimension
typedef struct std_msgs__msg__MultiArrayDimension
{
  rosidl_generator_c__String label;
  uint32_t size;
  uint32_t stride;
} std_msgs__msg__MultiArrayDimension;

/// Struct for an array of messages
typedef struct std_msgs__msg__MultiArrayDimension__Array
{
  std_msgs__msg__MultiArrayDimension * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} std_msgs__msg__MultiArrayDimension__Array;

#if __cplusplus
}
#endif

#endif  // STD_MSGS__MSG__MULTI_ARRAY_DIMENSION__STRUCT_H_
