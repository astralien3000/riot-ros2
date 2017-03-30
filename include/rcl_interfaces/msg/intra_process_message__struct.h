// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__MSG__INTRA_PROCESS_MESSAGE__STRUCT_H_
#define RCL_INTERFACES__MSG__INTRA_PROCESS_MESSAGE__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/// Struct of message rcl_interfaces/IntraProcessMessage
typedef struct rcl_interfaces__msg__IntraProcessMessage
{
  uint64_t publisher_id;
  uint64_t message_sequence;
} rcl_interfaces__msg__IntraProcessMessage;

/// Struct for an array of messages
typedef struct rcl_interfaces__msg__IntraProcessMessage__Array
{
  rcl_interfaces__msg__IntraProcessMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rcl_interfaces__msg__IntraProcessMessage__Array;

#if __cplusplus
}
#endif

#endif  // RCL_INTERFACES__MSG__INTRA_PROCESS_MESSAGE__STRUCT_H_
