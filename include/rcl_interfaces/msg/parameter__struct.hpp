// generated from rosidl_generator_cpp/resource/msg__struct.hpp.em
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__MSG__PARAMETER__STRUCT_HPP_
#define RCL_INTERFACES__MSG__PARAMETER__STRUCT_HPP_

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
#include "rcl_interfaces/msg/parameter_value.hpp"  // value

#ifndef _WIN32
# define DEPRECATED_rcl_interfaces_msg_Parameter __attribute__((deprecated))
#else
# define DEPRECATED_rcl_interfaces_msg_Parameter __declspec(deprecated)
#endif

namespace rcl_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Parameter_
{
  using Type = Parameter_<ContainerAllocator>;

  Parameter_()
  {
  }
  explicit Parameter_(const ContainerAllocator & _alloc)
// *INDENT-OFF* (prevent uncrustify from making unnecessary indents here)
// *INDENT-ON*
  {
    (void)_alloc;
  }

  // field types and members
  using _name_type =
      std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _name_type name;
  using _value_type =
      rcl_interfaces::msg::ParameterValue_<ContainerAllocator>;
  _value_type value;

  // setters for named parameter idiom
  Type * set__name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->name = _arg;
    return this;
  }
  Type * set__value(
    const rcl_interfaces::msg::ParameterValue_<ContainerAllocator> & _arg)
  {
    this->value = _arg;
    return this;
  }

  // constants

  // pointer types
  using RawPtr =
      rcl_interfaces::msg::Parameter_<ContainerAllocator> *;
  using ConstRawPtr =
      const rcl_interfaces::msg::Parameter_<ContainerAllocator> *;
  using SharedPtr =
      std::shared_ptr<rcl_interfaces::msg::Parameter_<ContainerAllocator>>;
  using ConstSharedPtr =
      std::shared_ptr<rcl_interfaces::msg::Parameter_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
    rcl_interfaces::msg::Parameter_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
      std::unique_ptr<rcl_interfaces::msg::Parameter_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
    rcl_interfaces::msg::Parameter_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
      std::unique_ptr<rcl_interfaces::msg::Parameter_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
      std::weak_ptr<rcl_interfaces::msg::Parameter_<ContainerAllocator>>;
  using ConstWeakPtr =
      std::weak_ptr<rcl_interfaces::msg::Parameter_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED_rcl_interfaces_msg_Parameter
    std::shared_ptr<rcl_interfaces::msg::Parameter_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED_rcl_interfaces_msg_Parameter
    std::shared_ptr<rcl_interfaces::msg::Parameter_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Parameter_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const Parameter_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Parameter_

// alias to use template instance with default allocator
using Parameter =
    rcl_interfaces::msg::Parameter_<std::allocator<void>>;

// constants requiring out of line definition

}  // namespace msg

}  // namespace rcl_interfaces

#endif  // RCL_INTERFACES__MSG__PARAMETER__STRUCT_HPP_
