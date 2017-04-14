// generated from rosidl_generator_cpp/resource/msg__struct.hpp.em
// generated code does not contain a copyright notice

#ifndef RCL_INTERFACES__MSG__PARAMETER_EVENT_DESCRIPTORS__STRUCT_HPP_
#define RCL_INTERFACES__MSG__PARAMETER_EVENT_DESCRIPTORS__STRUCT_HPP_

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
#include "rcl_interfaces/msg/parameter_descriptor.hpp"  // deleted_parameters, new_parameters, changed_parameters

#ifndef _WIN32
# define DEPRECATED_rcl_interfaces_msg_ParameterEventDescriptors __attribute__((deprecated))
#else
# define DEPRECATED_rcl_interfaces_msg_ParameterEventDescriptors __declspec(deprecated)
#endif

namespace rcl_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ParameterEventDescriptors_
{
  using Type = ParameterEventDescriptors_<ContainerAllocator>;

  ParameterEventDescriptors_()
  {
  }
  explicit ParameterEventDescriptors_(const ContainerAllocator & _alloc)
// *INDENT-OFF* (prevent uncrustify from making unnecessary indents here)
  : new_parameters(_alloc),
    changed_parameters(_alloc),
    deleted_parameters(_alloc)
// *INDENT-ON*
  {
  }

  // field types and members
  using _new_parameters_type =
      std::vector<rcl_interfaces::msg::ParameterDescriptor_<ContainerAllocator>, typename ContainerAllocator::template rebind<rcl_interfaces::msg::ParameterDescriptor_<ContainerAllocator>>::other>;
  _new_parameters_type new_parameters;
  using _changed_parameters_type =
      std::vector<rcl_interfaces::msg::ParameterDescriptor_<ContainerAllocator>, typename ContainerAllocator::template rebind<rcl_interfaces::msg::ParameterDescriptor_<ContainerAllocator>>::other>;
  _changed_parameters_type changed_parameters;
  using _deleted_parameters_type =
      std::vector<rcl_interfaces::msg::ParameterDescriptor_<ContainerAllocator>, typename ContainerAllocator::template rebind<rcl_interfaces::msg::ParameterDescriptor_<ContainerAllocator>>::other>;
  _deleted_parameters_type deleted_parameters;

  // setters for named parameter idiom
  Type * set__new_parameters(
    const std::vector<rcl_interfaces::msg::ParameterDescriptor_<ContainerAllocator>, typename ContainerAllocator::template rebind<rcl_interfaces::msg::ParameterDescriptor_<ContainerAllocator>>::other> & _arg)
  {
    this->new_parameters = _arg;
    return this;
  }
  Type * set__changed_parameters(
    const std::vector<rcl_interfaces::msg::ParameterDescriptor_<ContainerAllocator>, typename ContainerAllocator::template rebind<rcl_interfaces::msg::ParameterDescriptor_<ContainerAllocator>>::other> & _arg)
  {
    this->changed_parameters = _arg;
    return this;
  }
  Type * set__deleted_parameters(
    const std::vector<rcl_interfaces::msg::ParameterDescriptor_<ContainerAllocator>, typename ContainerAllocator::template rebind<rcl_interfaces::msg::ParameterDescriptor_<ContainerAllocator>>::other> & _arg)
  {
    this->deleted_parameters = _arg;
    return this;
  }

  // constants

  // pointer types
  using RawPtr =
      rcl_interfaces::msg::ParameterEventDescriptors_<ContainerAllocator> *;
  using ConstRawPtr =
      const rcl_interfaces::msg::ParameterEventDescriptors_<ContainerAllocator> *;
  using SharedPtr =
      std::shared_ptr<rcl_interfaces::msg::ParameterEventDescriptors_<ContainerAllocator>>;
  using ConstSharedPtr =
      std::shared_ptr<rcl_interfaces::msg::ParameterEventDescriptors_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
    rcl_interfaces::msg::ParameterEventDescriptors_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
      std::unique_ptr<rcl_interfaces::msg::ParameterEventDescriptors_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
    rcl_interfaces::msg::ParameterEventDescriptors_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
      std::unique_ptr<rcl_interfaces::msg::ParameterEventDescriptors_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
      std::weak_ptr<rcl_interfaces::msg::ParameterEventDescriptors_<ContainerAllocator>>;
  using ConstWeakPtr =
      std::weak_ptr<rcl_interfaces::msg::ParameterEventDescriptors_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED_rcl_interfaces_msg_ParameterEventDescriptors
    std::shared_ptr<rcl_interfaces::msg::ParameterEventDescriptors_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED_rcl_interfaces_msg_ParameterEventDescriptors
    std::shared_ptr<rcl_interfaces::msg::ParameterEventDescriptors_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ParameterEventDescriptors_ & other) const
  {
    if (this->new_parameters != other.new_parameters) {
      return false;
    }
    if (this->changed_parameters != other.changed_parameters) {
      return false;
    }
    if (this->deleted_parameters != other.deleted_parameters) {
      return false;
    }
    return true;
  }
  bool operator!=(const ParameterEventDescriptors_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ParameterEventDescriptors_

// alias to use template instance with default allocator
using ParameterEventDescriptors =
    rcl_interfaces::msg::ParameterEventDescriptors_<std::allocator<void>>;

// constants requiring out of line definition

}  // namespace msg

}  // namespace rcl_interfaces

#endif  // RCL_INTERFACES__MSG__PARAMETER_EVENT_DESCRIPTORS__STRUCT_HPP_
