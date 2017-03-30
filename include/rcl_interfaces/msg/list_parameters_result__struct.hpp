// generated from rosidl_generator_cpp/resource/msg__struct.hpp.em
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__MSG__LIST_PARAMETERS_RESULT__STRUCT_HPP_
#define RCL_INTERFACES__MSG__LIST_PARAMETERS_RESULT__STRUCT_HPP_

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
# define DEPRECATED_rcl_interfaces_msg_ListParametersResult __attribute__((deprecated))
#else
# define DEPRECATED_rcl_interfaces_msg_ListParametersResult __declspec(deprecated)
#endif

namespace rcl_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ListParametersResult_
{
  using Type = ListParametersResult_<ContainerAllocator>;

  ListParametersResult_()
  {
  }
  explicit ListParametersResult_(const ContainerAllocator & _alloc)
// *INDENT-OFF* (prevent uncrustify from making unnecessary indents here)
  : names(_alloc),
    prefixes(_alloc)
// *INDENT-ON*
  {
  }

  // field types and members
  using _names_type =
      std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>, typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>>::other>;
  _names_type names;
  using _prefixes_type =
      std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>, typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>>::other>;
  _prefixes_type prefixes;

  // setters for named parameter idiom
  Type * set__names(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>, typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>>::other> & _arg)
  {
    this->names = _arg;
    return this;
  }
  Type * set__prefixes(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>, typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>>::other> & _arg)
  {
    this->prefixes = _arg;
    return this;
  }

  // constants

  // pointer types
  using RawPtr =
      rcl_interfaces::msg::ListParametersResult_<ContainerAllocator> *;
  using ConstRawPtr =
      const rcl_interfaces::msg::ListParametersResult_<ContainerAllocator> *;
  using SharedPtr =
      std::shared_ptr<rcl_interfaces::msg::ListParametersResult_<ContainerAllocator>>;
  using ConstSharedPtr =
      std::shared_ptr<rcl_interfaces::msg::ListParametersResult_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
    rcl_interfaces::msg::ListParametersResult_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
      std::unique_ptr<rcl_interfaces::msg::ListParametersResult_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
    rcl_interfaces::msg::ListParametersResult_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
      std::unique_ptr<rcl_interfaces::msg::ListParametersResult_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
      std::weak_ptr<rcl_interfaces::msg::ListParametersResult_<ContainerAllocator>>;
  using ConstWeakPtr =
      std::weak_ptr<rcl_interfaces::msg::ListParametersResult_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED_rcl_interfaces_msg_ListParametersResult
    std::shared_ptr<rcl_interfaces::msg::ListParametersResult_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED_rcl_interfaces_msg_ListParametersResult
    std::shared_ptr<rcl_interfaces::msg::ListParametersResult_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ListParametersResult_ & other) const
  {
    if (this->names != other.names) {
      return false;
    }
    if (this->prefixes != other.prefixes) {
      return false;
    }
    return true;
  }
  bool operator!=(const ListParametersResult_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ListParametersResult_

// alias to use template instance with default allocator
using ListParametersResult =
    rcl_interfaces::msg::ListParametersResult_<std::allocator<void>>;

// constants requiring out of line definition

}  // namespace msg

}  // namespace rcl_interfaces

#endif  // RCL_INTERFACES__MSG__LIST_PARAMETERS_RESULT__STRUCT_HPP_
