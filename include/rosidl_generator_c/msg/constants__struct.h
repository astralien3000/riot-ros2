// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef ROSIDL_GENERATOR_C__MSG__CONSTANTS__STRUCT_H_
#define ROSIDL_GENERATOR_C__MSG__CONSTANTS__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// constants defined in the message
// X
enum
{
  rosidl_generator_c__msg__Constants__X = 123
};
// Y
enum
{
  rosidl_generator_c__msg__Constants__Y = -123
};
// FOO
static const char * const rosidl_generator_c__msg__Constants__FOO = "foo";
// TOTO
enum
{
  rosidl_generator_c__msg__Constants__TOTO = 127
};
// TATA
enum
{
  rosidl_generator_c__msg__Constants__TATA = 48
};

/// Struct of message rosidl_generator_c/Constants
typedef struct rosidl_generator_c__msg__Constants
{
  bool _dummy;
} rosidl_generator_c__msg__Constants;

/// Struct for an array of messages
typedef struct rosidl_generator_c__msg__Constants__Array
{
  rosidl_generator_c__msg__Constants * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosidl_generator_c__msg__Constants__Array;

#if __cplusplus
}
#endif

#endif  // ROSIDL_GENERATOR_C__MSG__CONSTANTS__STRUCT_H_
