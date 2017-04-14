// generated from rosidl_generator_cpp/resource/msg__struct.hpp.em
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__MSG__PARAMETER_VALUE__STRUCT_HPP_
#define RCL_INTERFACES__MSG__PARAMETER_VALUE__STRUCT_HPP_

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
# define DEPRECATED_rcl_interfaces_msg_ParameterValue __attribute__((deprecated))
#else
# define DEPRECATED_rcl_interfaces_msg_ParameterValue __declspec(deprecated)
#endif

namespace rcl_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ParameterValue_
{
  using Type = ParameterValue_<ContainerAllocator>;

  ParameterValue_()
  {
  }
  explicit ParameterValue_(const ContainerAllocator & _alloc)
// *INDENT-OFF* (prevent uncrustify from making unnecessary indents here)
  : bytes_value(_alloc)
// *INDENT-ON*
  {
  }

  // field types and members
  using _type_type =
      uint8_t;
  _type_type type;
  using _bool_value_type =
      bool;
  _bool_value_type bool_value;
  using _integer_value_type =
      int64_t;
  _integer_value_type integer_value;
  using _double_value_type =
      double;
  _double_value_type double_value;
  using _string_value_type =
      std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _string_value_type string_value;
  using _bytes_value_type =
      std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other>;
  _bytes_value_type bytes_value;

  // setters for named parameter idiom
  Type * set__type(
    const uint8_t & _arg)
  {
    this->type = _arg;
    return this;
  }
  Type * set__bool_value(
    const bool & _arg)
  {
    this->bool_value = _arg;
    return this;
  }
  Type * set__integer_value(
    const int64_t & _arg)
  {
    this->integer_value = _arg;
    return this;
  }
  Type * set__double_value(
    const double & _arg)
  {
    this->double_value = _arg;
    return this;
  }
  Type * set__string_value(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->string_value = _arg;
    return this;
  }
  Type * set__bytes_value(
    const std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other> & _arg)
  {
    this->bytes_value = _arg;
    return this;
  }

  // constants

  // pointer types
  using RawPtr =
      rcl_interfaces::msg::ParameterValue_<ContainerAllocator> *;
  using ConstRawPtr =
      const rcl_interfaces::msg::ParameterValue_<ContainerAllocator> *;
  using SharedPtr =
      std::shared_ptr<rcl_interfaces::msg::ParameterValue_<ContainerAllocator>>;
  using ConstSharedPtr =
      std::shared_ptr<rcl_interfaces::msg::ParameterValue_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
    rcl_interfaces::msg::ParameterValue_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
      std::unique_ptr<rcl_interfaces::msg::ParameterValue_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
    rcl_interfaces::msg::ParameterValue_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
      std::unique_ptr<rcl_interfaces::msg::ParameterValue_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
      std::weak_ptr<rcl_interfaces::msg::ParameterValue_<ContainerAllocator>>;
  using ConstWeakPtr =
      std::weak_ptr<rcl_interfaces::msg::ParameterValue_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED_rcl_interfaces_msg_ParameterValue
    std::shared_ptr<rcl_interfaces::msg::ParameterValue_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED_rcl_interfaces_msg_ParameterValue
    std::shared_ptr<rcl_interfaces::msg::ParameterValue_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ParameterValue_ & other) const
  {
    if (this->type != other.type) {
      return false;
    }
    if (this->bool_value != other.bool_value) {
      return false;
    }
    if (this->integer_value != other.integer_value) {
      return false;
    }
    if (this->double_value != other.double_value) {
      return false;
    }
    if (this->string_value != other.string_value) {
      return false;
    }
    if (this->bytes_value != other.bytes_value) {
      return false;
    }
    return true;
  }
  bool operator!=(const ParameterValue_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ParameterValue_

// alias to use template instance with default allocator
using ParameterValue =
    rcl_interfaces::msg::ParameterValue_<std::allocator<void>>;

// constants requiring out of line definition

}  // namespace msg

}  // namespace rcl_interfaces

#endif  // RCL_INTERFACES__MSG__PARAMETER_VALUE__STRUCT_HPP_
