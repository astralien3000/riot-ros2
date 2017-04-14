// generated from rosidl_generator_cpp/resource/msg__struct.hpp.em
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__SRV__SET_PARAMETERS__RESPONSE__STRUCT_HPP_
#define RCL_INTERFACES__SRV__SET_PARAMETERS__RESPONSE__STRUCT_HPP_

// Protect against ERROR being predefined on Windows, in case somebody defines a
// constant by that name.
#if defined(_WIN32) && defined(ERROR)
  #undef ERROR
#endif

#include <rosidl_generator_cpp/bounded_vector.hpp>
#include <array>
#include <memory>
#include <string>
#include <vector>

// include message dependencies
#include "rcl_interfaces/msg/set_parameters_result.hpp"  // results

#ifndef _WIN32
# define DEPRECATED_rcl_interfaces_srv_SetParameters_Response __attribute__((deprecated))
#else
# define DEPRECATED_rcl_interfaces_srv_SetParameters_Response __declspec(deprecated)
#endif

namespace rcl_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetParameters_Response_
{
  using Type = SetParameters_Response_<ContainerAllocator>;

  SetParameters_Response_()
  {
  }
  explicit SetParameters_Response_(const ContainerAllocator & _alloc)
// *INDENT-OFF* (prevent uncrustify from making unnecessary indents here)
  : results(_alloc)
// *INDENT-ON*
  {
  }

  // field types and members
  using _results_type =
      std::vector<rcl_interfaces::msg::SetParametersResult_<ContainerAllocator>, typename ContainerAllocator::template rebind<rcl_interfaces::msg::SetParametersResult_<ContainerAllocator>>::other>;
  _results_type results;

  // setters for named parameter idiom
  Type * set__results(
    const std::vector<rcl_interfaces::msg::SetParametersResult_<ContainerAllocator>, typename ContainerAllocator::template rebind<rcl_interfaces::msg::SetParametersResult_<ContainerAllocator>>::other> & _arg)
  {
    this->results = _arg;
    return this;
  }

  // constants

  // pointer types
  using RawPtr =
      rcl_interfaces::srv::SetParameters_Response_<ContainerAllocator> *;
  using ConstRawPtr =
      const rcl_interfaces::srv::SetParameters_Response_<ContainerAllocator> *;
  using SharedPtr =
      std::shared_ptr<rcl_interfaces::srv::SetParameters_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
      std::shared_ptr<rcl_interfaces::srv::SetParameters_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
    rcl_interfaces::srv::SetParameters_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
      std::unique_ptr<rcl_interfaces::srv::SetParameters_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
    rcl_interfaces::srv::SetParameters_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
      std::unique_ptr<rcl_interfaces::srv::SetParameters_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
      std::weak_ptr<rcl_interfaces::srv::SetParameters_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
      std::weak_ptr<rcl_interfaces::srv::SetParameters_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED_rcl_interfaces_srv_SetParameters_Response
    std::shared_ptr<rcl_interfaces::srv::SetParameters_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED_rcl_interfaces_srv_SetParameters_Response
    std::shared_ptr<rcl_interfaces::srv::SetParameters_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetParameters_Response_ & other) const
  {
    if (this->results != other.results) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetParameters_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetParameters_Response_

// alias to use template instance with default allocator
using SetParameters_Response =
    rcl_interfaces::srv::SetParameters_Response_<std::allocator<void>>;

// constants requiring out of line definition

}  // namespace srv

}  // namespace rcl_interfaces

#endif  // RCL_INTERFACES__SRV__SET_PARAMETERS__RESPONSE__STRUCT_HPP_
