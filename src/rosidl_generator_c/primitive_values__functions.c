// generated from rosidl_generator_c/resource/msg__functions.c.em
// generated code does not contain a copyright notice

#include "rosidl_generator_c/msg/primitive_values__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool
rosidl_generator_c__msg__PrimitiveValues__init(rosidl_generator_c__msg__PrimitiveValues * msg)
{
  if (!msg) {
    return false;
  }
  // def_bool_1
  msg->def_bool_1 = true;
  // def_bool_2
  msg->def_bool_2 = false;
  // def_byte
  msg->def_byte = 66;
  // def_char
  msg->def_char = -66;
  // def_float32
  msg->def_float32 = 1.125f;
  // def_float64
  msg->def_float64 = 1.125l;
  // def_int8
  msg->def_int8 = 3;
  // def_int16
  msg->def_int16 = 6;
  // def_int32
  msg->def_int32 = 10;
  // def_int64
  msg->def_int64 = 15;
  // def_uint8
  msg->def_uint8 = 33u;
  // def_uint16
  msg->def_uint16 = 36u;
  // def_uint32
  msg->def_uint32 = 310u;
  // def_uint64
  msg->def_uint64 = 315u;
  return true;
}

void
rosidl_generator_c__msg__PrimitiveValues__fini(rosidl_generator_c__msg__PrimitiveValues * msg)
{
  if (!msg) {
    return;
  }
  // def_bool_1
  // def_bool_2
  // def_byte
  // def_char
  // def_float32
  // def_float64
  // def_int8
  // def_int16
  // def_int32
  // def_int64
  // def_uint8
  // def_uint16
  // def_uint32
  // def_uint64
}

rosidl_generator_c__msg__PrimitiveValues *
rosidl_generator_c__msg__PrimitiveValues__create()
{
  rosidl_generator_c__msg__PrimitiveValues * msg = (rosidl_generator_c__msg__PrimitiveValues *)malloc(sizeof(rosidl_generator_c__msg__PrimitiveValues));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosidl_generator_c__msg__PrimitiveValues));
  bool success = rosidl_generator_c__msg__PrimitiveValues__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rosidl_generator_c__msg__PrimitiveValues__destroy(rosidl_generator_c__msg__PrimitiveValues * msg)
{
  if (msg) {
    rosidl_generator_c__msg__PrimitiveValues__fini(msg);
  }
  free(msg);
}


bool
rosidl_generator_c__msg__PrimitiveValues__Array__init(rosidl_generator_c__msg__PrimitiveValues__Array * array, size_t size)
{
  if (!array) {
    return false;
  }
  rosidl_generator_c__msg__PrimitiveValues * data = NULL;
  if (size) {
    data = (rosidl_generator_c__msg__PrimitiveValues *)calloc(size, sizeof(rosidl_generator_c__msg__PrimitiveValues));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosidl_generator_c__msg__PrimitiveValues__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosidl_generator_c__msg__PrimitiveValues__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
rosidl_generator_c__msg__PrimitiveValues__Array__fini(rosidl_generator_c__msg__PrimitiveValues__Array * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rosidl_generator_c__msg__PrimitiveValues__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

rosidl_generator_c__msg__PrimitiveValues__Array *
rosidl_generator_c__msg__PrimitiveValues__Array__create(size_t size)
{
  rosidl_generator_c__msg__PrimitiveValues__Array * array = (rosidl_generator_c__msg__PrimitiveValues__Array *)malloc(sizeof(rosidl_generator_c__msg__PrimitiveValues__Array));
  if (!array) {
    return NULL;
  }
  bool success = rosidl_generator_c__msg__PrimitiveValues__Array__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rosidl_generator_c__msg__PrimitiveValues__Array__destroy(rosidl_generator_c__msg__PrimitiveValues__Array * array)
{
  if (array) {
    rosidl_generator_c__msg__PrimitiveValues__Array__fini(array);
  }
  free(array);
}
