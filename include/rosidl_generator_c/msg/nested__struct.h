// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef ROSIDL_GENERATOR_C__MSG__NESTED__STRUCT_H_
#define ROSIDL_GENERATOR_C__MSG__NESTED__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// include message dependencies
// primitives
// two_primitives
// up_to_three_primitives
// unbounded_primitives
#include "rosidl_generator_c/msg/primitives__struct.h"

// constants defined in the message
// ANSWER
enum
{
  rosidl_generator_c__msg__Nested__ANSWER = 42u
};

// constants for array fields with an upper bound
// up_to_three_primitives
enum
{
  rosidl_generator_c__msg__Nested__up_to_three_primitives__MAX_SIZE = 3
};

/// Struct of message rosidl_generator_c/Nested
typedef struct rosidl_generator_c__msg__Nested
{
  rosidl_generator_c__msg__Primitives primitives;
  rosidl_generator_c__msg__Primitives two_primitives[2];
  rosidl_generator_c__msg__Primitives__Array up_to_three_primitives;
  rosidl_generator_c__msg__Primitives__Array unbounded_primitives;
} rosidl_generator_c__msg__Nested;

/// Struct for an array of messages
typedef struct rosidl_generator_c__msg__Nested__Array
{
  rosidl_generator_c__msg__Nested * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosidl_generator_c__msg__Nested__Array;

#if __cplusplus
}
#endif

#endif  // ROSIDL_GENERATOR_C__MSG__NESTED__STRUCT_H_
