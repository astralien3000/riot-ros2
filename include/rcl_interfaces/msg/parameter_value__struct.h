// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__MSG__PARAMETER_VALUE__STRUCT_H_
#define RCL_INTERFACES__MSG__PARAMETER_VALUE__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// include message dependencies
// string_value
#include "rosidl_generator_c/string.h"
// bytes_value
#include "rosidl_generator_c/primitives_array.h"

/// Struct of message rcl_interfaces/ParameterValue
typedef struct rcl_interfaces__msg__ParameterValue
{
  uint8_t type;
  bool bool_value;
  int64_t integer_value;
  double double_value;
  rosidl_generator_c__String string_value;
  rosidl_generator_c__byte__Array bytes_value;
} rcl_interfaces__msg__ParameterValue;

/// Struct for an array of messages
typedef struct rcl_interfaces__msg__ParameterValue__Array
{
  rcl_interfaces__msg__ParameterValue * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rcl_interfaces__msg__ParameterValue__Array;

#if __cplusplus
}
#endif

#endif  // RCL_INTERFACES__MSG__PARAMETER_VALUE__STRUCT_H_
