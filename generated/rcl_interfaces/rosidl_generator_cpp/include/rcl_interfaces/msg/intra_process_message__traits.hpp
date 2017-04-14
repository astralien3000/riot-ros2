// generated from rosidl_generator_cpp/resource/msg__traits.hpp.em
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__MSG__INTRA_PROCESS_MESSAGE__TRAITS_HPP_
#define RCL_INTERFACES__MSG__INTRA_PROCESS_MESSAGE__TRAITS_HPP_

#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

#ifndef __ROSIDL_GENERATOR_CPP_TRAITS
#define __ROSIDL_GENERATOR_CPP_TRAITS

template<typename T>
struct has_fixed_size : std::false_type {};

#endif  // __ROSIDL_GENERATOR_CPP_TRAITS

#include "rcl_interfaces/msg/intra_process_message__struct.hpp"


template<>
struct has_fixed_size<rcl_interfaces::msg::IntraProcessMessage>
  : std::integral_constant<bool, true>{};

}  // namespace rosidl_generator_traits

#endif  // RCL_INTERFACES__MSG__INTRA_PROCESS_MESSAGE__TRAITS_HPP_
