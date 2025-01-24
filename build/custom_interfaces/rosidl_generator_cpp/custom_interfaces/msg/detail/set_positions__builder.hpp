// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/SetPositions.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__SET_POSITIONS__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__SET_POSITIONS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/set_positions__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_SetPositions_positions
{
public:
  explicit Init_SetPositions_positions(::custom_interfaces::msg::SetPositions & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::SetPositions positions(::custom_interfaces::msg::SetPositions::_positions_type arg)
  {
    msg_.positions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::SetPositions msg_;
};

class Init_SetPositions_ids
{
public:
  Init_SetPositions_ids()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetPositions_positions ids(::custom_interfaces::msg::SetPositions::_ids_type arg)
  {
    msg_.ids = std::move(arg);
    return Init_SetPositions_positions(msg_);
  }

private:
  ::custom_interfaces::msg::SetPositions msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::SetPositions>()
{
  return custom_interfaces::msg::builder::Init_SetPositions_ids();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__SET_POSITIONS__BUILDER_HPP_
