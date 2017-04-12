// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef ROSIDL_GENERATOR_C__MSG__WIRE__STRUCT_H_
#define ROSIDL_GENERATOR_C__MSG__WIRE__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// include message dependencies
// cablegram1
#include "rosidl_generator_c/msg/telegram1__struct.h"
// cablegram2
#include "rosidl_generator_c/msg/telegram2__struct.h"

/// Struct of message rosidl_generator_c/Wire
typedef struct rosidl_generator_c__msg__Wire
{
  rosidl_generator_c__msg__Telegram1 cablegram1[3];
  rosidl_generator_c__msg__Telegram2 cablegram2;
} rosidl_generator_c__msg__Wire;

/// Struct for an array of messages
typedef struct rosidl_generator_c__msg__Wire__Array
{
  rosidl_generator_c__msg__Wire * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosidl_generator_c__msg__Wire__Array;

#if __cplusplus
}
#endif

#endif  // ROSIDL_GENERATOR_C__MSG__WIRE__STRUCT_H_
