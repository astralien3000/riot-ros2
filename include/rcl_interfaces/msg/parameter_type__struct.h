// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__MSG__PARAMETER_TYPE__STRUCT_H_
#define RCL_INTERFACES__MSG__PARAMETER_TYPE__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// constants defined in the message
// PARAMETER_NOT_SET
enum
{
  rcl_interfaces__msg__ParameterType__PARAMETER_NOT_SET = 0u
};
// PARAMETER_BOOL
enum
{
  rcl_interfaces__msg__ParameterType__PARAMETER_BOOL = 1u
};
// PARAMETER_INTEGER
enum
{
  rcl_interfaces__msg__ParameterType__PARAMETER_INTEGER = 2u
};
// PARAMETER_DOUBLE
enum
{
  rcl_interfaces__msg__ParameterType__PARAMETER_DOUBLE = 3u
};
// PARAMETER_STRING
enum
{
  rcl_interfaces__msg__ParameterType__PARAMETER_STRING = 4u
};
// PARAMETER_BYTES
enum
{
  rcl_interfaces__msg__ParameterType__PARAMETER_BYTES = 5u
};

/// Struct of message rcl_interfaces/ParameterType
typedef struct rcl_interfaces__msg__ParameterType
{
  bool _dummy;
} rcl_interfaces__msg__ParameterType;

/// Struct for an array of messages
typedef struct rcl_interfaces__msg__ParameterType__Array
{
  rcl_interfaces__msg__ParameterType * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rcl_interfaces__msg__ParameterType__Array;

#if __cplusplus
}
#endif

#endif  // RCL_INTERFACES__MSG__PARAMETER_TYPE__STRUCT_H_
