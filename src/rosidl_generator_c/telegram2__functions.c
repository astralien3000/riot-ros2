// generated from rosidl_generator_c/resource/msg__functions.c.em
// generated code does not contain a copyright notice

#include "rosidl_generator_c/msg/telegram2__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// include message dependencies
// text_array
#include "rosidl_generator_c/string_functions.h"

bool
rosidl_generator_c__msg__Telegram2__init(rosidl_generator_c__msg__Telegram2 * msg)
{
  if (!msg) {
    return false;
  }
  // text_array
  for (size_t i = 0; i < 3; ++i) {
    rosidl_generator_c__String__init(&msg->text_array[i]);
  }
  // number_array
  return true;
}

void
rosidl_generator_c__msg__Telegram2__fini(rosidl_generator_c__msg__Telegram2 * msg)
{
  if (!msg) {
    return;
  }
  // text_array
  for (size_t i = 0; i < 3; ++i) {
    rosidl_generator_c__String__fini(&msg->text_array[i]);
  }
  // number_array
}

rosidl_generator_c__msg__Telegram2 *
rosidl_generator_c__msg__Telegram2__create()
{
  rosidl_generator_c__msg__Telegram2 * msg = (rosidl_generator_c__msg__Telegram2 *)malloc(sizeof(rosidl_generator_c__msg__Telegram2));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosidl_generator_c__msg__Telegram2));
  bool success = rosidl_generator_c__msg__Telegram2__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
rosidl_generator_c__msg__Telegram2__destroy(rosidl_generator_c__msg__Telegram2 * msg)
{
  if (msg) {
    rosidl_generator_c__msg__Telegram2__fini(msg);
  }
  free(msg);
}


bool
rosidl_generator_c__msg__Telegram2__Array__init(rosidl_generator_c__msg__Telegram2__Array * array, size_t size)
{
  if (!array) {
    return false;
  }
  rosidl_generator_c__msg__Telegram2 * data = NULL;
  if (size) {
    data = (rosidl_generator_c__msg__Telegram2 *)calloc(size, sizeof(rosidl_generator_c__msg__Telegram2));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosidl_generator_c__msg__Telegram2__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosidl_generator_c__msg__Telegram2__fini(&data[i - 1]);
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
rosidl_generator_c__msg__Telegram2__Array__fini(rosidl_generator_c__msg__Telegram2__Array * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rosidl_generator_c__msg__Telegram2__fini(&array->data[i]);
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

rosidl_generator_c__msg__Telegram2__Array *
rosidl_generator_c__msg__Telegram2__Array__create(size_t size)
{
  rosidl_generator_c__msg__Telegram2__Array * array = (rosidl_generator_c__msg__Telegram2__Array *)malloc(sizeof(rosidl_generator_c__msg__Telegram2__Array));
  if (!array) {
    return NULL;
  }
  bool success = rosidl_generator_c__msg__Telegram2__Array__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
rosidl_generator_c__msg__Telegram2__Array__destroy(rosidl_generator_c__msg__Telegram2__Array * array)
{
  if (array) {
    rosidl_generator_c__msg__Telegram2__Array__fini(array);
  }
  free(array);
}
