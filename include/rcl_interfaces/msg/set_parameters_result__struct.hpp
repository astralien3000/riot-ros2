// generated from rosidl_generator_cpp/resource/msg__struct.hpp.em
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__MSG__SET_PARAMETERS_RESULT__STRUCT_HPP_
#define RCL_INTERFACES__MSG__SET_PARAMETERS_RESULT__STRUCT_HPP_

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

#ifndef _WIN32
# define DEPRECATED_rcl_interfaces_msg_SetParametersResult __attribute__((deprecated))
#else
# define DEPRECATED_rcl_interfaces_msg_SetParametersResult __declspec(deprecated)
#endif

namespace rcl_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SetParametersResult_
{
  using Type = SetParametersResult_<ContainerAllocator>;

  SetParametersResult_()
  {
  }
  explicit SetParametersResult_(const ContainerAllocator & _alloc)
// *INDENT-OFF* (prevent uncrustify from making unnecessary indents here)
// *INDENT-ON*
  {
    (void)_alloc;
  }

  // field types and members
  using _successful_type =
      bool;
  _successful_type successful;
  using _reason_type =
      std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _reason_type reason;

  // setters for named parameter idiom
  Type * set__successful(
    const bool & _arg)
  {
    this->successful = _arg;
    return this;
  }
  Type * set__reason(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->reason = _arg;
    return this;
  }

  // constants

  // pointer types
  using RawPtr =
      rcl_interfaces::msg::SetParametersResult_<ContainerAllocator> *;
  using ConstRawPtr =
      const rcl_interfaces::msg::SetParametersResult_<ContainerAllocator> *;
  using SharedPtr =
      std::shared_ptr<rcl_interfaces::msg::SetParametersResult_<ContainerAllocator>>;
  using ConstSharedPtr =
      std::shared_ptr<rcl_interfaces::msg::SetParametersResult_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
    rcl_interfaces::msg::SetParametersResult_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
      std::unique_ptr<rcl_interfaces::msg::SetParametersResult_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
    rcl_interfaces::msg::SetParametersResult_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
      std::unique_ptr<rcl_interfaces::msg::SetParametersResult_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
      std::weak_ptr<rcl_interfaces::msg::SetParametersResult_<ContainerAllocator>>;
  using ConstWeakPtr =
      std::weak_ptr<rcl_interfaces::msg::SetParametersResult_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED_rcl_interfaces_msg_SetParametersResult
    std::shared_ptr<rcl_interfaces::msg::SetParametersResult_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED_rcl_interfaces_msg_SetParametersResult
    std::shared_ptr<rcl_interfaces::msg::SetParametersResult_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetParametersResult_ & other) const
  {
    if (this->successful != other.successful) {
      return false;
    }
    if (this->reason != other.reason) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetParametersResult_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetParametersResult_

// alias to use template instance with default allocator
using SetParametersResult =
    rcl_interfaces::msg::SetParametersResult_<std::allocator<void>>;

// constants requiring out of line definition

}  // namespace msg

}  // namespace rcl_interfaces

#endif  // RCL_INTERFACES__MSG__SET_PARAMETERS_RESULT__STRUCT_HPP_
