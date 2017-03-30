// generated from rosidl_generator_cpp/resource/msg__struct.hpp.em
// generated code does not contain a copyright notice

#ifndef STD_MSGS__MSG__MULTI_ARRAY_DIMENSION__STRUCT_HPP_
#define STD_MSGS__MSG__MULTI_ARRAY_DIMENSION__STRUCT_HPP_

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
# define DEPRECATED_std_msgs_msg_MultiArrayDimension __attribute__((deprecated))
#else
# define DEPRECATED_std_msgs_msg_MultiArrayDimension __declspec(deprecated)
#endif

namespace std_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MultiArrayDimension_
{
  using Type = MultiArrayDimension_<ContainerAllocator>;

  MultiArrayDimension_()
  {
  }
  explicit MultiArrayDimension_(const ContainerAllocator & _alloc)
// *INDENT-OFF* (prevent uncrustify from making unnecessary indents here)
// *INDENT-ON*
  {
    (void)_alloc;
  }

  // field types and members
  using _label_type =
      std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _label_type label;
  using _size_type =
      uint32_t;
  _size_type size;
  using _stride_type =
      uint32_t;
  _stride_type stride;

  // setters for named parameter idiom
  Type * set__label(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->label = _arg;
    return this;
  }
  Type * set__size(
    const uint32_t & _arg)
  {
    this->size = _arg;
    return this;
  }
  Type * set__stride(
    const uint32_t & _arg)
  {
    this->stride = _arg;
    return this;
  }

  // constants

  // pointer types
  using RawPtr =
      std_msgs::msg::MultiArrayDimension_<ContainerAllocator> *;
  using ConstRawPtr =
      const std_msgs::msg::MultiArrayDimension_<ContainerAllocator> *;
  using SharedPtr =
      std::shared_ptr<std_msgs::msg::MultiArrayDimension_<ContainerAllocator>>;
  using ConstSharedPtr =
      std::shared_ptr<std_msgs::msg::MultiArrayDimension_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
    std_msgs::msg::MultiArrayDimension_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
      std::unique_ptr<std_msgs::msg::MultiArrayDimension_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
    std_msgs::msg::MultiArrayDimension_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
      std::unique_ptr<std_msgs::msg::MultiArrayDimension_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
      std::weak_ptr<std_msgs::msg::MultiArrayDimension_<ContainerAllocator>>;
  using ConstWeakPtr =
      std::weak_ptr<std_msgs::msg::MultiArrayDimension_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED_std_msgs_msg_MultiArrayDimension
    std::shared_ptr<std_msgs::msg::MultiArrayDimension_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED_std_msgs_msg_MultiArrayDimension
    std::shared_ptr<std_msgs::msg::MultiArrayDimension_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MultiArrayDimension_ & other) const
  {
    if (this->label != other.label) {
      return false;
    }
    if (this->size != other.size) {
      return false;
    }
    if (this->stride != other.stride) {
      return false;
    }
    return true;
  }
  bool operator!=(const MultiArrayDimension_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MultiArrayDimension_

// alias to use template instance with default allocator
using MultiArrayDimension =
    std_msgs::msg::MultiArrayDimension_<std::allocator<void>>;

// constants requiring out of line definition

}  // namespace msg

}  // namespace std_msgs

#endif  // STD_MSGS__MSG__MULTI_ARRAY_DIMENSION__STRUCT_HPP_
