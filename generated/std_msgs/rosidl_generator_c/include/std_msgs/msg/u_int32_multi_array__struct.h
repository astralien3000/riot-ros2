// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef STD_MSGS__MSG__U_INT32_MULTI_ARRAY__STRUCT_H_
#define STD_MSGS__MSG__U_INT32_MULTI_ARRAY__STRUCT_H_

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

/// Struct of message std_msgs/UInt32MultiArray
typedef struct std_msgs__msg__UInt32MultiArray
{
  std_msgs__msg__MultiArrayLayout layout;
  rosidl_generator_c__uint32__Array data;
} std_msgs__msg__UInt32MultiArray;

/// Struct for an array of messages
typedef struct std_msgs__msg__UInt32MultiArray__Array
{
  std_msgs__msg__UInt32MultiArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} std_msgs__msg__UInt32MultiArray__Array;

#if __cplusplus
}
#endif

#endif  // STD_MSGS__MSG__U_INT32_MULTI_ARRAY__STRUCT_H_
