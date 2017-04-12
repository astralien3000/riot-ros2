// generated from rosidl_generator_c/resource/msg__functions.c.em
// generated code does not contain a copyright notice

#include "rosidl_generator_c/msg/nested__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// include message dependencies
// primitives
// two_primitives
// up_to_three_primitives
// unbounded_primitives
#include "rosidl_generator_c/msg/primitives__functions.h"

bool
rosidl_generator_c__msg__Nested__init(rosidl_generator_c__msg__Nested * msg)
{
  if (!msg) {
    return false;
  }
  // primitives
  rosidl_generator_c__msg__Primitives__init(&msg->primitives);
  // two_primitives
  for (size_t i = 0; i < 2; ++i) {
    rosidl_generator_c__msg__Primitives__init(&msg->two_primitives[i]);
  }
  // up_to_three_primitives
  rosidl_generator_c__msg__Primitives__Array__init(&msg->up_to_three_primitives, 0);
  // unbounded_primitives
  rosidl_generator_c__msg__Primitives__Array__init(&msg->unbounded_primitives, 0);
  return true;
}

void
rosidl_generator_c__msg__Nested__fini(rosidl_generator_c__msg__Nested * msg)
{
  if (!msg) {
    return;
  }
  // primitives
  rosidl_generator_c__msg__Primitives__fini(&msg->primitives);
  // two_primitives
  for (size_t i = 0; i < 2; ++i) {
    rosidl_generator_c__msg__Primitives__fini(&msg->two_primitives[i]);
  }
  // up_to_three_primitives
  rosidl_generator_c__msg__Primitives__Array__fini(&msg->up_to_three_primitives);
  // unbounded_primitives
  rosidl_generator_c__msg__Primitives__Array__fini(&msg->unbounded_primitives);
}

rosidl_generator_c__msg__Nested *
rosidl_generator_c__msg__Nested__create()
{
  rosidl_generator_c__msg__Nested * msg = (rosidl_generator_c__msg__Nested *)malloc(sizeof(rosidl_generator_c__msg__Nested));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosidl_generator_c__msg__Nested));
  bool success = rosidl_generator_c__msg__Nested__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rosidl_generator_c__msg__Nested__destroy(rosidl_generator_c__msg__Nested * msg)
{
  if (msg) {
    rosidl_generator_c__msg__Nested__fini(msg);
  }
  free(msg);
}


bool
rosidl_generator_c__msg__Nested__Array__init(rosidl_generator_c__msg__Nested__Array * array, size_t size)
{
  if (!array) {
    return false;
  }
  rosidl_generator_c__msg__Nested * data = NULL;
  if (size) {
    data = (rosidl_generator_c__msg__Nested *)calloc(size, sizeof(rosidl_generator_c__msg__Nested));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosidl_generator_c__msg__Nested__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosidl_generator_c__msg__Nested__fini(&data[i - 1]);
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
rosidl_generator_c__msg__Nested__Array__fini(rosidl_generator_c__msg__Nested__Array * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rosidl_generator_c__msg__Nested__fini(&array->data[i]);
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

rosidl_generator_c__msg__Nested__Array *
rosidl_generator_c__msg__Nested__Array__create(size_t size)
{
  rosidl_generator_c__msg__Nested__Array * array = (rosidl_generator_c__msg__Nested__Array *)malloc(sizeof(rosidl_generator_c__msg__Nested__Array));
  if (!array) {
    return NULL;
  }
  bool success = rosidl_generator_c__msg__Nested__Array__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rosidl_generator_c__msg__Nested__Array__destroy(rosidl_generator_c__msg__Nested__Array * array)
{
  if (array) {
    rosidl_generator_c__msg__Nested__Array__fini(array);
  }
  free(array);
}
