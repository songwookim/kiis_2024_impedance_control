// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/GetSensordata.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__GET_SENSORDATA__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__GET_SENSORDATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__GetSensordata __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__GetSensordata __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GetSensordata_
{
  using Type = GetSensordata_<ContainerAllocator>;

  explicit GetSensordata_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit GetSensordata_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _sensordata_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _sensordata_type sensordata;

  // setters for named parameter idiom
  Type & set__sensordata(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->sensordata = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::GetSensordata_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::GetSensordata_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::GetSensordata_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::GetSensordata_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::GetSensordata_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::GetSensordata_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::GetSensordata_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::GetSensordata_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::GetSensordata_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::GetSensordata_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__GetSensordata
    std::shared_ptr<custom_interfaces::msg::GetSensordata_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__GetSensordata
    std::shared_ptr<custom_interfaces::msg::GetSensordata_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetSensordata_ & other) const
  {
    if (this->sensordata != other.sensordata) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetSensordata_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetSensordata_

// alias to use template instance with default allocator
using GetSensordata =
  custom_interfaces::msg::GetSensordata_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__GET_SENSORDATA__STRUCT_HPP_
