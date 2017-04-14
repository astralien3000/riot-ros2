// generated from rosidl_generator_cpp/resource/msg__traits.hpp.em
// generated code does not contain a copyright notice

#ifndef BUILTIN_INTERFACES__MSG__DURATION__TRAITS_HPP_
#define BUILTIN_INTERFACES__MSG__DURATION__TRAITS_HPP_

#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

#ifndef __ROSIDL_GENERATOR_CPP_TRAITS
#define __ROSIDL_GENERATOR_CPP_TRAITS

template<typename T>
struct has_fixed_size : std::false_type {};

#endif  // __ROSIDL_GENERATOR_CPP_TRAITS

#include "builtin_interfaces/msg/duration__struct.hpp"


template<>
struct has_fixed_size<builtin_interfaces::msg::Duration>
  : std::integral_constant<bool, true>{};

}  // namespace rosidl_generator_traits

#endif  // BUILTIN_INTERFACES__MSG__DURATION__TRAITS_HPP_
