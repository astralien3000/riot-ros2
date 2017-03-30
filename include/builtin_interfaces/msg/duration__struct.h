// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef BUILTIN_INTERFACES__MSG__DURATION__STRUCT_H_
#define BUILTIN_INTERFACES__MSG__DURATION__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/// Struct of message builtin_interfaces/Duration
typedef struct builtin_interfaces__msg__Duration
{
  int32_t sec;
  uint32_t nanosec;
} builtin_interfaces__msg__Duration;

/// Struct for an array of messages
typedef struct builtin_interfaces__msg__Duration__Array
{
  builtin_interfaces__msg__Duration * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} builtin_interfaces__msg__Duration__Array;

#if __cplusplus
}
#endif

#endif  // BUILTIN_INTERFACES__MSG__DURATION__STRUCT_H_
