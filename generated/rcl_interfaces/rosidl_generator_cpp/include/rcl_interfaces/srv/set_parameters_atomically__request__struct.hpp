// generated from rosidl_generator_cpp/resource/msg__struct.hpp.em
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__SRV__SET_PARAMETERS_ATOMICALLY__REQUEST__STRUCT_HPP_
#define RCL_INTERFACES__SRV__SET_PARAMETERS_ATOMICALLY__REQUEST__STRUCT_HPP_

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
#include "rcl_interfaces/msg/parameter.hpp"  // parameters

#ifndef _WIN32
# define DEPRECATED_rcl_interfaces_srv_SetParametersAtomically_Request __attribute__((deprecated))
#else
# define DEPRECATED_rcl_interfaces_srv_SetParametersAtomically_Request __declspec(deprecated)
#endif

namespace rcl_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetParametersAtomically_Request_
{
  using Type = SetParametersAtomically_Request_<ContainerAllocator>;

  SetParametersAtomically_Request_()
  {
  }
  explicit SetParametersAtomically_Request_(const ContainerAllocator & _alloc)
// *INDENT-OFF* (prevent uncrustify from making unnecessary indents here)
  : parameters(_alloc)
// *INDENT-ON*
  {
  }

  // field types and members
  using _parameters_type =
      std::vector<rcl_interfaces::msg::Parameter_<ContainerAllocator>, typename ContainerAllocator::template rebind<rcl_interfaces::msg::Parameter_<ContainerAllocator>>::other>;
  _parameters_type parameters;

  // setters for named parameter idiom
  Type * set__parameters(
    const std::vector<rcl_interfaces::msg::Parameter_<ContainerAllocator>, typename ContainerAllocator::template rebind<rcl_interfaces::msg::Parameter_<ContainerAllocator>>::other> & _arg)
  {
    this->parameters = _arg;
    return this;
  }

  // constants

  // pointer types
  using RawPtr =
      rcl_interfaces::srv::SetParametersAtomically_Request_<ContainerAllocator> *;
  using ConstRawPtr =
      const rcl_interfaces::srv::SetParametersAtomically_Request_<ContainerAllocator> *;
  using SharedPtr =
      std::shared_ptr<rcl_interfaces::srv::SetParametersAtomically_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
      std::shared_ptr<rcl_interfaces::srv::SetParametersAtomically_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
    rcl_interfaces::srv::SetParametersAtomically_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
      std::unique_ptr<rcl_interfaces::srv::SetParametersAtomically_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
    rcl_interfaces::srv::SetParametersAtomically_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
      std::unique_ptr<rcl_interfaces::srv::SetParametersAtomically_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
      std::weak_ptr<rcl_interfaces::srv::SetParametersAtomically_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
      std::weak_ptr<rcl_interfaces::srv::SetParametersAtomically_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED_rcl_interfaces_srv_SetParametersAtomically_Request
    std::shared_ptr<rcl_interfaces::srv::SetParametersAtomically_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED_rcl_interfaces_srv_SetParametersAtomically_Request
    std::shared_ptr<rcl_interfaces::srv::SetParametersAtomically_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetParametersAtomically_Request_ & other) const
  {
    if (this->parameters != other.parameters) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetParametersAtomically_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetParametersAtomically_Request_

// alias to use template instance with default allocator
using SetParametersAtomically_Request =
    rcl_interfaces::srv::SetParametersAtomically_Request_<std::allocator<void>>;

// constants requiring out of line definition

}  // namespace srv

}  // namespace rcl_interfaces

#endif  // RCL_INTERFACES__SRV__SET_PARAMETERS_ATOMICALLY__REQUEST__STRUCT_HPP_
