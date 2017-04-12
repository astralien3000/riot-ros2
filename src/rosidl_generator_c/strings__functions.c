// generated from rosidl_generator_c/resource/msg__functions.c.em
// generated code does not contain a copyright notice

#include "rosidl_generator_c/msg/strings__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// include message dependencies
// empty_string
// def_string
// ub_string
// ub_def_string
#include "rosidl_generator_c/string_functions.h"

bool
rosidl_generator_c__msg__Strings__init(rosidl_generator_c__msg__Strings * msg)
{
  if (!msg) {
    return false;
  }
  // empty_string
  rosidl_generator_c__String__init(&msg->empty_string);
  // def_string
  rosidl_generator_c__String__init(&msg->def_string);
  {
    bool success = rosidl_generator_c__String__assign(&msg->def_string, "Hello world!");
    if (!success) {
      goto abort_init_0;
    }
  }
  // ub_string
  rosidl_generator_c__String__init(&msg->ub_string);
  // ub_def_string
  rosidl_generator_c__String__init(&msg->ub_def_string);
  {
    bool success = rosidl_generator_c__String__assign(&msg->ub_def_string, "Upper bounded string.");
    if (!success) {
      goto abort_init_1;
    }
  }
  return true;
abort_init_1:
  rosidl_generator_c__String__fini(&msg->def_string);
abort_init_0:
  return false;
}

void
rosidl_generator_c__msg__Strings__fini(rosidl_generator_c__msg__Strings * msg)
{
  if (!msg) {
    return;
  }
  // empty_string
  rosidl_generator_c__String__fini(&msg->empty_string);
  // def_string
  rosidl_generator_c__String__fini(&msg->def_string);
  // ub_string
  rosidl_generator_c__String__fini(&msg->ub_string);
  // ub_def_string
  rosidl_generator_c__String__fini(&msg->ub_def_string);
}

rosidl_generator_c__msg__Strings *
rosidl_generator_c__msg__Strings__create()
{
  rosidl_generator_c__msg__Strings * msg = (rosidl_generator_c__msg__Strings *)malloc(sizeof(rosidl_generator_c__msg__Strings));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosidl_generator_c__msg__Strings));
  bool success = rosidl_generator_c__msg__Strings__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rosidl_generator_c__msg__Strings__destroy(rosidl_generator_c__msg__Strings * msg)
{
  if (msg) {
    rosidl_generator_c__msg__Strings__fini(msg);
  }
  free(msg);
}


bool
rosidl_generator_c__msg__Strings__Array__init(rosidl_generator_c__msg__Strings__Array * array, size_t size)
{
  if (!array) {
    return false;
  }
  rosidl_generator_c__msg__Strings * data = NULL;
  if (size) {
    data = (rosidl_generator_c__msg__Strings *)calloc(size, sizeof(rosidl_generator_c__msg__Strings));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosidl_generator_c__msg__Strings__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosidl_generator_c__msg__Strings__fini(&data[i - 1]);
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
rosidl_generator_c__msg__Strings__Array__fini(rosidl_generator_c__msg__Strings__Array * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rosidl_generator_c__msg__Strings__fini(&array->data[i]);
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

rosidl_generator_c__msg__Strings__Array *
rosidl_generator_c__msg__Strings__Array__create(size_t size)
{
  rosidl_generator_c__msg__Strings__Array * array = (rosidl_generator_c__msg__Strings__Array *)malloc(sizeof(rosidl_generator_c__msg__Strings__Array));
  if (!array) {
    return NULL;
  }
  bool success = rosidl_generator_c__msg__Strings__Array__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rosidl_generator_c__msg__Strings__Array__destroy(rosidl_generator_c__msg__Strings__Array * array)
{
  if (array) {
    rosidl_generator_c__msg__Strings__Array__fini(array);
  }
  free(array);
}
