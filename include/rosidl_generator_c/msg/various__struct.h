// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef ROSIDL_GENERATOR_C__MSG__VARIOUS__STRUCT_H_
#define ROSIDL_GENERATOR_C__MSG__VARIOUS__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// include message dependencies
// up_to_three_int32_values
// up_to_three_int32_values_with_default_values
// unbounded_uint64_values
#include "rosidl_generator_c/primitives_array.h"
// empty
// two_empty
// unbounded_empty
#include "rosidl_generator_c/msg/empty__struct.h"
// nested
// two_nested
// up_to_three_nested
// unbounded_nested
#include "rosidl_generator_c/msg/nested__struct.h"

// constants defined in the message
// FOO
static const bool rosidl_generator_c__msg__Various__FOO = true;
// BAR
static const float rosidl_generator_c__msg__Various__BAR = 1.125f;
// BAZ
enum
{
  rosidl_generator_c__msg__Various__BAZ = 42u
};

// constants for array fields with an upper bound
// up_to_three_int32_values
enum
{
  rosidl_generator_c__msg__Various__up_to_three_int32_values__MAX_SIZE = 3
};
// up_to_three_int32_values_with_default_values
enum
{
  rosidl_generator_c__msg__Various__up_to_three_int32_values_with_default_values__MAX_SIZE = 3
};
// up_to_three_nested
enum
{
  rosidl_generator_c__msg__Various__up_to_three_nested__MAX_SIZE = 3
};

/// Struct of message rosidl_generator_c/Various
typedef struct rosidl_generator_c__msg__Various
{
  bool bool_value;
  uint8_t byte_value;
  char char_value;
  float float32_value;
  double float64_value;
  int8_t int8_value;
  uint16_t two_uint16_value[2];
  rosidl_generator_c__int32__Array up_to_three_int32_values;
  rosidl_generator_c__int32__Array up_to_three_int32_values_with_default_values;
  rosidl_generator_c__uint64__Array unbounded_uint64_values;
  rosidl_generator_c__msg__Empty empty;
  rosidl_generator_c__msg__Empty two_empty[2];
  rosidl_generator_c__msg__Empty__Array unbounded_empty;
  rosidl_generator_c__msg__Nested nested;
  rosidl_generator_c__msg__Nested two_nested[2];
  rosidl_generator_c__msg__Nested__Array up_to_three_nested;
  rosidl_generator_c__msg__Nested__Array unbounded_nested;
} rosidl_generator_c__msg__Various;

/// Struct for an array of messages
typedef struct rosidl_generator_c__msg__Various__Array
{
  rosidl_generator_c__msg__Various * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosidl_generator_c__msg__Various__Array;

#if __cplusplus
}
#endif

#endif  // ROSIDL_GENERATOR_C__MSG__VARIOUS__STRUCT_H_
