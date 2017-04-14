// generated from rosidl_generator_cpp/resource/srv__traits.hpp.em
// generated code does not contain a copyright notice


#include "rcl_interfaces/srv/get_parameter_types__struct.hpp"

#ifndef RCL_INTERFACES__SRV__GET_PARAMETER_TYPES__TRAITS_HPP_
#define RCL_INTERFACES__SRV__GET_PARAMETER_TYPES__TRAITS_HPP_

namespace rosidl_generator_traits
{

#ifndef __ROSIDL_GENERATOR_CPP_TRAITS
#define __ROSIDL_GENERATOR_CPP_TRAITS

template<typename T>
struct has_fixed_size : std::false_type {};

#endif  // __ROSIDL_GENERATOR_CPP_TRAITS

template<>
struct has_fixed_size<rcl_interfaces::srv::GetParameterTypes>
  : std::integral_constant<
    bool,
    has_fixed_size<rcl_interfaces::srv::GetParameterTypes_Request>::value &&
    has_fixed_size<rcl_interfaces::srv::GetParameterTypes_Response>::value
  >
{
};

}  // namespace rosidl_generator_traits

#endif  // RCL_INTERFACES__SRV__GET_PARAMETER_TYPES__TRAITS_HPP_
