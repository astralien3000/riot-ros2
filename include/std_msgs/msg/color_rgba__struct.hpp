// generated from rosidl_generator_cpp/resource/msg__struct.hpp.em
// generated code does not contain a copyright notice

#ifndef STD_MSGS__MSG__COLOR_RGBA__STRUCT_HPP_
#define STD_MSGS__MSG__COLOR_RGBA__STRUCT_HPP_

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
# define DEPRECATED_std_msgs_msg_ColorRGBA __attribute__((deprecated))
#else
# define DEPRECATED_std_msgs_msg_ColorRGBA __declspec(deprecated)
#endif

namespace std_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ColorRGBA_
{
  using Type = ColorRGBA_<ContainerAllocator>;

  ColorRGBA_()
  {
  }
  explicit ColorRGBA_(const ContainerAllocator & _alloc)
// *INDENT-OFF* (prevent uncrustify from making unnecessary indents here)
// *INDENT-ON*
  {
    (void)_alloc;
  }

  // field types and members
  using _r_type =
      float;
  _r_type r;
  using _g_type =
      float;
  _g_type g;
  using _b_type =
      float;
  _b_type b;
  using _a_type =
      float;
  _a_type a;

  // setters for named parameter idiom
  Type * set__r(
    const float & _arg)
  {
    this->r = _arg;
    return this;
  }
  Type * set__g(
    const float & _arg)
  {
    this->g = _arg;
    return this;
  }
  Type * set__b(
    const float & _arg)
  {
    this->b = _arg;
    return this;
  }
  Type * set__a(
    const float & _arg)
  {
    this->a = _arg;
    return this;
  }

  // constants

  // pointer types
  using RawPtr =
      std_msgs::msg::ColorRGBA_<ContainerAllocator> *;
  using ConstRawPtr =
      const std_msgs::msg::ColorRGBA_<ContainerAllocator> *;
  using SharedPtr =
      std::shared_ptr<std_msgs::msg::ColorRGBA_<ContainerAllocator>>;
  using ConstSharedPtr =
      std::shared_ptr<std_msgs::msg::ColorRGBA_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
    std_msgs::msg::ColorRGBA_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
      std::unique_ptr<std_msgs::msg::ColorRGBA_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
    std_msgs::msg::ColorRGBA_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
      std::unique_ptr<std_msgs::msg::ColorRGBA_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
      std::weak_ptr<std_msgs::msg::ColorRGBA_<ContainerAllocator>>;
  using ConstWeakPtr =
      std::weak_ptr<std_msgs::msg::ColorRGBA_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED_std_msgs_msg_ColorRGBA
    std::shared_ptr<std_msgs::msg::ColorRGBA_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED_std_msgs_msg_ColorRGBA
    std::shared_ptr<std_msgs::msg::ColorRGBA_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ColorRGBA_ & other) const
  {
    if (this->r != other.r) {
      return false;
    }
    if (this->g != other.g) {
      return false;
    }
    if (this->b != other.b) {
      return false;
    }
    if (this->a != other.a) {
      return false;
    }
    return true;
  }
  bool operator!=(const ColorRGBA_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ColorRGBA_

// alias to use template instance with default allocator
using ColorRGBA =
    std_msgs::msg::ColorRGBA_<std::allocator<void>>;

// constants requiring out of line definition

}  // namespace msg

}  // namespace std_msgs

#endif  // STD_MSGS__MSG__COLOR_RGBA__STRUCT_HPP_
