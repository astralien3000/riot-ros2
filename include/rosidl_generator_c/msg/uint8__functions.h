// generated from rosidl_generator_c/resource/msg__functions.h.em
// generated code does not contain a copyright notice

#ifndef ROSIDL_GENERATOR_C__MSG__UINT8__FUNCTIONS_H_
#define ROSIDL_GENERATOR_C__MSG__UINT8__FUNCTIONS_H_

#if __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_generator_c/visibility_control.h"
#include "rosidl_generator_c/msg/rosidl_generator_c__visibility_control.h"

#include "rosidl_generator_c/msg/uint8__struct.h"

/// Initialize rosidl_generator_c/Uint8 message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(rosidl_generator_c__msg__Uint8)) before
 * or use rosidl_generator_c__msg__Uint8__create() to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rosidl_generator_c
bool
rosidl_generator_c__msg__Uint8__init(rosidl_generator_c__msg__Uint8 * msg);

/// Finalize rosidl_generator_c/Uint8 message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rosidl_generator_c
void
rosidl_generator_c__msg__Uint8__fini(rosidl_generator_c__msg__Uint8 * msg);

/// Create rosidl_generator_c/Uint8 message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls rosidl_generator_c__msg__Uint8__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rosidl_generator_c
rosidl_generator_c__msg__Uint8 *
rosidl_generator_c__msg__Uint8__create();

/// Destroy rosidl_generator_c/Uint8 message.
/**
 * It calls rosidl_generator_c__msg__Uint8__fini() and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rosidl_generator_c
void
rosidl_generator_c__msg__Uint8__destroy(rosidl_generator_c__msg__Uint8 * msg);


/// Initialize array of rosidl_generator_c/Uint8 messages.
/**
 * It allocates the memory for the number of elements and
 * calls rosidl_generator_c__msg__Uint8__init() for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rosidl_generator_c
bool
rosidl_generator_c__msg__Uint8__Array__init(rosidl_generator_c__msg__Uint8__Array * array, size_t size);

/// Finalize array of rosidl_generator_c/Uint8 messages.
/**
 * It calls rosidl_generator_c__msg__Uint8__fini() for each element of the array and
 * frees the memory for the number of elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rosidl_generator_c
void
rosidl_generator_c__msg__Uint8__Array__fini(rosidl_generator_c__msg__Uint8__Array * array);

/// Create array of rosidl_generator_c/Uint8 messages.
/**
 * It allocates the memory for the array and
 * calls rosidl_generator_c__msg__Uint8__Array__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rosidl_generator_c
rosidl_generator_c__msg__Uint8__Array *
rosidl_generator_c__msg__Uint8__Array__create(size_t size);

/// Destroy array of rosidl_generator_c/Uint8 messages.
/**
 * It calls rosidl_generator_c__msg__Uint8__Array__fini() on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rosidl_generator_c
void
rosidl_generator_c__msg__Uint8__Array__destroy(rosidl_generator_c__msg__Uint8__Array * array);

#if __cplusplus
}
#endif

#endif  // ROSIDL_GENERATOR_C__MSG__UINT8__FUNCTIONS_H_
