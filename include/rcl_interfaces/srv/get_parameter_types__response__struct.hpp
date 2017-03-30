// generated from rosidl_generator_cpp/resource/msg__struct.hpp.em
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__SRV__GET_PARAMETER_TYPES__RESPONSE__STRUCT_HPP_
#define RCL_INTERFACES__SRV__GET_PARAMETER_TYPES__RESPONSE__STRUCT_HPP_

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
# define DEPRECATED_rcl_interfaces_srv_GetParameterTypes_Response __attribute__((deprecated))
#else
# define DEPRECATED_rcl_interfaces_srv_GetParameterTypes_Response __declspec(deprecated)
#endif

namespace rcl_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetParameterTypes_Response_
{
  using Type = GetParameterTypes_Response_<ContainerAllocator>;

  GetParameterTypes_Response_()
  {
  }
  explicit GetParameterTypes_Response_(const ContainerAllocator & _alloc)
// *INDENT-OFF* (prevent uncrustify from making unnecessary indents here)
  : types(_alloc)
// *INDENT-ON*
  {
  }

  // field types and members
  using _types_type =
      std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other>;
  _types_type types;

  // setters for named parameter idiom
  Type * set__types(
    const std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other> & _arg)
  {
    this->types = _arg;
    return this;
  }

  // constants

  // pointer types
  using RawPtr =
      rcl_interfaces::srv::GetParameterTypes_Response_<ContainerAllocator> *;
  using ConstRawPtr =
      const rcl_interfaces::srv::GetParameterTypes_Response_<ContainerAllocator> *;
  using SharedPtr =
      std::shared_ptr<rcl_interfaces::srv::GetParameterTypes_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
      std::shared_ptr<rcl_interfaces::srv::GetParameterTypes_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
    rcl_interfaces::srv::GetParameterTypes_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
      std::unique_ptr<rcl_interfaces::srv::GetParameterTypes_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
    rcl_interfaces::srv::GetParameterTypes_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
      std::unique_ptr<rcl_interfaces::srv::GetParameterTypes_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
      std::weak_ptr<rcl_interfaces::srv::GetParameterTypes_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
      std::weak_ptr<rcl_interfaces::srv::GetParameterTypes_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED_rcl_interfaces_srv_GetParameterTypes_Response
    std::shared_ptr<rcl_interfaces::srv::GetParameterTypes_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED_rcl_interfaces_srv_GetParameterTypes_Response
    std::shared_ptr<rcl_interfaces::srv::GetParameterTypes_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetParameterTypes_Response_ & other) const
  {
    if (this->types != other.types) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetParameterTypes_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetParameterTypes_Response_

// alias to use template instance with default allocator
using GetParameterTypes_Response =
    rcl_interfaces::srv::GetParameterTypes_Response_<std::allocator<void>>;

// constants requiring out of line definition

}  // namespace srv

}  // namespace rcl_interfaces

#endif  // RCL_INTERFACES__SRV__GET_PARAMETER_TYPES__RESPONSE__STRUCT_HPP_
