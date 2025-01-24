// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/GetSensordata.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__GET_SENSORDATA__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__GET_SENSORDATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/get_sensordata__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_GetSensordata_sensordata
{
public:
  Init_GetSensordata_sensordata()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::msg::GetSensordata sensordata(::custom_interfaces::msg::GetSensordata::_sensordata_type arg)
  {
    msg_.sensordata = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::GetSensordata msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::GetSensordata>()
{
  return custom_interfaces::msg::builder::Init_GetSensordata_sensordata();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__GET_SENSORDATA__BUILDER_HPP_
