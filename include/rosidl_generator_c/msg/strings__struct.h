// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef ROSIDL_GENERATOR_C__MSG__STRINGS__STRUCT_H_
#define ROSIDL_GENERATOR_C__MSG__STRINGS__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// include message dependencies
// empty_string
// def_string
// ub_string
// ub_def_string
#include "rosidl_generator_c/string.h"

// constants for array fields with an upper bound
// ub_string
enum
{
  rosidl_generator_c__msg__Strings__ub_string__MAX_STRING_SIZE = 22
};
// ub_def_string
enum
{
  rosidl_generator_c__msg__Strings__ub_def_string__MAX_STRING_SIZE = 22
};

/// Struct of message rosidl_generator_c/Strings
typedef struct rosidl_generator_c__msg__Strings
{
  rosidl_generator_c__String empty_string;
  rosidl_generator_c__String def_string;
  rosidl_generator_c__String ub_string;
  rosidl_generator_c__String ub_def_string;
} rosidl_generator_c__msg__Strings;

/// Struct for an array of messages
typedef struct rosidl_generator_c__msg__Strings__Array
{
  rosidl_generator_c__msg__Strings * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosidl_generator_c__msg__Strings__Array;

#if __cplusplus
}
#endif

#endif  // ROSIDL_GENERATOR_C__MSG__STRINGS__STRUCT_H_
