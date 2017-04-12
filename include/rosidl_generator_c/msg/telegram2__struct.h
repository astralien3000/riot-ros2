// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef ROSIDL_GENERATOR_C__MSG__TELEGRAM2__STRUCT_H_
#define ROSIDL_GENERATOR_C__MSG__TELEGRAM2__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// include message dependencies
// text_array
#include "rosidl_generator_c/string.h"

/// Struct of message rosidl_generator_c/Telegram2
typedef struct rosidl_generator_c__msg__Telegram2
{
  rosidl_generator_c__String text_array[3];
  float number_array[3];
} rosidl_generator_c__msg__Telegram2;

/// Struct for an array of messages
typedef struct rosidl_generator_c__msg__Telegram2__Array
{
  rosidl_generator_c__msg__Telegram2 * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosidl_generator_c__msg__Telegram2__Array;

#if __cplusplus
}
#endif

#endif  // ROSIDL_GENERATOR_C__MSG__TELEGRAM2__STRUCT_H_
