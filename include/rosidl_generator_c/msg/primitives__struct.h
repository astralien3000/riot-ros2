// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef ROSIDL_GENERATOR_C__MSG__PRIMITIVES__STRUCT_H_
#define ROSIDL_GENERATOR_C__MSG__PRIMITIVES__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// include message dependencies
// string_value
// string_value_with_default
// fixed_length_string_value
// upper_bound_string_value
// unbound_string_value
#include "rosidl_generator_c/string.h"

// constants for array fields with an upper bound
// fixed_length_string_value
enum
{
  rosidl_generator_c__msg__Primitives__fixed_length_string_value__MAX_STRING_SIZE = 5
};
// upper_bound_string_value
enum
{
  rosidl_generator_c__msg__Primitives__upper_bound_string_value__MAX_STRING_SIZE = 5
};
// upper_bound_string_value
enum
{
  rosidl_generator_c__msg__Primitives__upper_bound_string_value__MAX_SIZE = 10
};

/// Struct of message rosidl_generator_c/Primitives
typedef struct rosidl_generator_c__msg__Primitives
{
  bool bool_value;
  uint8_t byte_value;
  char char_value;
  float float32_value;
  double float64_value;
  int8_t int8_value;
  uint8_t uint8_value;
  int16_t int16_value;
  uint16_t uint16_value;
  int32_t int32_value;
  uint32_t uint32_value;
  int64_t int64_value;
  uint64_t uint64_value;
  rosidl_generator_c__String string_value;
  rosidl_generator_c__String string_value_with_default;
  rosidl_generator_c__String fixed_length_string_value[3];
  rosidl_generator_c__String__Array upper_bound_string_value;
  rosidl_generator_c__String unbound_string_value;
} rosidl_generator_c__msg__Primitives;

/// Struct for an array of messages
typedef struct rosidl_generator_c__msg__Primitives__Array
{
  rosidl_generator_c__msg__Primitives * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosidl_generator_c__msg__Primitives__Array;

#if __cplusplus
}
#endif

#endif  // ROSIDL_GENERATOR_C__MSG__PRIMITIVES__STRUCT_H_
