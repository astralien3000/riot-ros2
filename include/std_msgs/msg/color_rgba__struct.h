// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef STD_MSGS__MSG__COLOR_RGBA__STRUCT_H_
#define STD_MSGS__MSG__COLOR_RGBA__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/// Struct of message std_msgs/ColorRGBA
typedef struct std_msgs__msg__ColorRGBA
{
  float r;
  float g;
  float b;
  float a;
} std_msgs__msg__ColorRGBA;

/// Struct for an array of messages
typedef struct std_msgs__msg__ColorRGBA__Array
{
  std_msgs__msg__ColorRGBA * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} std_msgs__msg__ColorRGBA__Array;

#if __cplusplus
}
#endif

#endif  // STD_MSGS__MSG__COLOR_RGBA__STRUCT_H_
