// generated from rosidl_generator_c/resource/msg__functions.c.em
// generated code does not contain a copyright notice

#include "rosidl_generator_c/msg/bool__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool
rosidl_generator_c__msg__Bool__init(rosidl_generator_c__msg__Bool * msg)
{
  if (!msg) {
    return false;
  }
  // empty_bool
  return true;
}

void
rosidl_generator_c__msg__Bool__fini(rosidl_generator_c__msg__Bool * msg)
{
  if (!msg) {
    return;
  }
  // empty_bool
}

rosidl_generator_c__msg__Bool *
rosidl_generator_c__msg__Bool__create()
{
  rosidl_generator_c__msg__Bool * msg = (rosidl_generator_c__msg__Bool *)malloc(sizeof(rosidl_generator_c__msg__Bool));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosidl_generator_c__msg__Bool));
  bool success = rosidl_generator_c__msg__Bool__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rosidl_generator_c__msg__Bool__destroy(rosidl_generator_c__msg__Bool * msg)
{
  if (msg) {
    rosidl_generator_c__msg__Bool__fini(msg);
  }
  free(msg);
}


bool
rosidl_generator_c__msg__Bool__Array__init(rosidl_generator_c__msg__Bool__Array * array, size_t size)
{
  if (!array) {
    return false;
  }
  rosidl_generator_c__msg__Bool * data = NULL;
  if (size) {
    data = (rosidl_generator_c__msg__Bool *)calloc(size, sizeof(rosidl_generator_c__msg__Bool));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosidl_generator_c__msg__Bool__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosidl_generator_c__msg__Bool__fini(&data[i - 1]);
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
rosidl_generator_c__msg__Bool__Array__fini(rosidl_generator_c__msg__Bool__Array * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rosidl_generator_c__msg__Bool__fini(&array->data[i]);
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

rosidl_generator_c__msg__Bool__Array *
rosidl_generator_c__msg__Bool__Array__create(size_t size)
{
  rosidl_generator_c__msg__Bool__Array * array = (rosidl_generator_c__msg__Bool__Array *)malloc(sizeof(rosidl_generator_c__msg__Bool__Array));
  if (!array) {
    return NULL;
  }
  bool success = rosidl_generator_c__msg__Bool__Array__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rosidl_generator_c__msg__Bool__Array__destroy(rosidl_generator_c__msg__Bool__Array * array)
{
  if (array) {
    rosidl_generator_c__msg__Bool__Array__fini(array);
  }
  free(array);
}
