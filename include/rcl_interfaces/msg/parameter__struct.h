// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__MSG__PARAMETER__STRUCT_H_
#define RCL_INTERFACES__MSG__PARAMETER__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// include message dependencies
// name
#include "rosidl_generator_c/string.h"
// value
#include "rcl_interfaces/msg/parameter_value__struct.h"

/// Struct of message rcl_interfaces/Parameter
typedef struct rcl_interfaces__msg__Parameter
{
  rosidl_generator_c__String name;
  rcl_interfaces__msg__ParameterValue value;
} rcl_interfaces__msg__Parameter;

/// Struct for an array of messages
typedef struct rcl_interfaces__msg__Parameter__Array
{
  rcl_interfaces__msg__Parameter * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rcl_interfaces__msg__Parameter__Array;

#if __cplusplus
}
#endif

#endif  // RCL_INTERFACES__MSG__PARAMETER__STRUCT_H_
