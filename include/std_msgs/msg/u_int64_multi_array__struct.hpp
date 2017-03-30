// generated from rosidl_generator_cpp/resource/msg__struct.hpp.em
// generated code does not contain a copyright notice

#ifndef STD_MSGS__MSG__U_INT64_MULTI_ARRAY__STRUCT_HPP_
#define STD_MSGS__MSG__U_INT64_MULTI_ARRAY__STRUCT_HPP_

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
#include "std_msgs/msg/multi_array_layout.hpp"  // layout

#ifndef _WIN32
# define DEPRECATED_std_msgs_msg_UInt64MultiArray __attribute__((deprecated))
#else
# define DEPRECATED_std_msgs_msg_UInt64MultiArray __declspec(deprecated)
#endif

namespace std_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UInt64MultiArray_
{
  using Type = UInt64MultiArray_<ContainerAllocator>;

  UInt64MultiArray_()
  {
  }
  explicit UInt64MultiArray_(const ContainerAllocator & _alloc)
// *INDENT-OFF* (prevent uncrustify from making unnecessary indents here)
  : data(_alloc)
// *INDENT-ON*
  {
  }

  // field types and members
  using _layout_type =
      std_msgs::msg::MultiArrayLayout_<ContainerAllocator>;
  _layout_type layout;
  using _data_type =
      std::vector<uint64_t, typename ContainerAllocator::template rebind<uint64_t>::other>;
  _data_type data;

  // setters for named parameter idiom
  Type * set__layout(
    const std_msgs::msg::MultiArrayLayout_<ContainerAllocator> & _arg)
  {
    this->layout = _arg;
    return this;
  }
  Type * set__data(
    const std::vector<uint64_t, typename ContainerAllocator::template rebind<uint64_t>::other> & _arg)
  {
    this->data = _arg;
    return this;
  }

  // constants

  // pointer types
  using RawPtr =
      std_msgs::msg::UInt64MultiArray_<ContainerAllocator> *;
  using ConstRawPtr =
      const std_msgs::msg::UInt64MultiArray_<ContainerAllocator> *;
  using SharedPtr =
      std::shared_ptr<std_msgs::msg::UInt64MultiArray_<ContainerAllocator>>;
  using ConstSharedPtr =
      std::shared_ptr<std_msgs::msg::UInt64MultiArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
    std_msgs::msg::UInt64MultiArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
      std::unique_ptr<std_msgs::msg::UInt64MultiArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
    std_msgs::msg::UInt64MultiArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
      std::unique_ptr<std_msgs::msg::UInt64MultiArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
      std::weak_ptr<std_msgs::msg::UInt64MultiArray_<ContainerAllocator>>;
  using ConstWeakPtr =
      std::weak_ptr<std_msgs::msg::UInt64MultiArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED_std_msgs_msg_UInt64MultiArray
    std::shared_ptr<std_msgs::msg::UInt64MultiArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED_std_msgs_msg_UInt64MultiArray
    std::shared_ptr<std_msgs::msg::UInt64MultiArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UInt64MultiArray_ & other) const
  {
    if (this->layout != other.layout) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const UInt64MultiArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UInt64MultiArray_

// alias to use template instance with default allocator
using UInt64MultiArray =
    std_msgs::msg::UInt64MultiArray_<std::allocator<void>>;

// constants requiring out of line definition

}  // namespace msg

}  // namespace std_msgs

#endif  // STD_MSGS__MSG__U_INT64_MULTI_ARRAY__STRUCT_HPP_
