// generated from rosidl_generator_cpp/resource/msg__struct.hpp.em
// generated code does not contain a copyright notice

#ifndef STD_MSGS__MSG__HEADER__STRUCT_HPP_
#define STD_MSGS__MSG__HEADER__STRUCT_HPP_

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
#include "builtin_interfaces/msg/time.hpp"  // stamp

#ifndef _WIN32
# define DEPRECATED_std_msgs_msg_Header __attribute__((deprecated))
#else
# define DEPRECATED_std_msgs_msg_Header __declspec(deprecated)
#endif

namespace std_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Header_
{
  using Type = Header_<ContainerAllocator>;

  Header_()
  {
  }
  explicit Header_(const ContainerAllocator & _alloc)
// *INDENT-OFF* (prevent uncrustify from making unnecessary indents here)
// *INDENT-ON*
  {
    (void)_alloc;
  }

  // field types and members
  using _stamp_type =
      builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;
  using _frame_id_type =
      std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _frame_id_type frame_id;

  // setters for named parameter idiom
  Type * set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return this;
  }
  Type * set__frame_id(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->frame_id = _arg;
    return this;
  }

  // constants

  // pointer types
  using RawPtr =
      std_msgs::msg::Header_<ContainerAllocator> *;
  using ConstRawPtr =
      const std_msgs::msg::Header_<ContainerAllocator> *;
  using SharedPtr =
      std::shared_ptr<std_msgs::msg::Header_<ContainerAllocator>>;
  using ConstSharedPtr =
      std::shared_ptr<std_msgs::msg::Header_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
    std_msgs::msg::Header_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
      std::unique_ptr<std_msgs::msg::Header_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
    std_msgs::msg::Header_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
      std::unique_ptr<std_msgs::msg::Header_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
      std::weak_ptr<std_msgs::msg::Header_<ContainerAllocator>>;
  using ConstWeakPtr =
      std::weak_ptr<std_msgs::msg::Header_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED_std_msgs_msg_Header
    std::shared_ptr<std_msgs::msg::Header_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED_std_msgs_msg_Header
    std::shared_ptr<std_msgs::msg::Header_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Header_ & other) const
  {
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->frame_id != other.frame_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const Header_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Header_

// alias to use template instance with default allocator
using Header =
    std_msgs::msg::Header_<std::allocator<void>>;

// constants requiring out of line definition

}  // namespace msg

}  // namespace std_msgs

#endif  // STD_MSGS__MSG__HEADER__STRUCT_HPP_
