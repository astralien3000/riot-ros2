// generated from rosidl_generator_c/resource/msg__struct.h.em
// generated code does not contain a copyright notice

#ifndef ROSIDL_GENERATOR_C__MSG__PRIMITIVE_VALUES__STRUCT_H_
#define ROSIDL_GENERATOR_C__MSG__PRIMITIVE_VALUES__STRUCT_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/// Struct of message rosidl_generator_c/PrimitiveValues
typedef struct rosidl_generator_c__msg__PrimitiveValues
{
  bool def_bool_1;
  bool def_bool_2;
  uint8_t def_byte;
  char def_char;
  float def_float32;
  double def_float64;
  int8_t def_int8;
  int16_t def_int16;
  int32_t def_int32;
  int64_t def_int64;
  uint8_t def_uint8;
  uint16_t def_uint16;
  uint32_t def_uint32;
  uint64_t def_uint64;
} rosidl_generator_c__msg__PrimitiveValues;

/// Struct for an array of messages
typedef struct rosidl_generator_c__msg__PrimitiveValues__Array
{
  rosidl_generator_c__msg__PrimitiveValues * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rosidl_generator_c__msg__PrimitiveValues__Array;

#if __cplusplus
}
#endif

#endif  // ROSIDL_GENERATOR_C__MSG__PRIMITIVE_VALUES__STRUCT_H_
