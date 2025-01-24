// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:srv/SetPosition.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__SET_POSITION__BUILDER_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__SET_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/srv/detail/set_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetPosition_Request_position
{
public:
  explicit Init_SetPosition_Request_position(::custom_interfaces::srv::SetPosition_Request & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::SetPosition_Request position(::custom_interfaces::srv::SetPosition_Request::_position_type arg)
  {
    msg_.position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::SetPosition_Request msg_;
};

class Init_SetPosition_Request_id
{
public:
  Init_SetPosition_Request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetPosition_Request_position id(::custom_interfaces::srv::SetPosition_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_SetPosition_Request_position(msg_);
  }

private:
  ::custom_interfaces::srv::SetPosition_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::SetPosition_Request>()
{
  return custom_interfaces::srv::builder::Init_SetPosition_Request_id();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetPosition_Response_position
{
public:
  Init_SetPosition_Response_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::srv::SetPosition_Response position(::custom_interfaces::srv::SetPosition_Response::_position_type arg)
  {
    msg_.position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::SetPosition_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::SetPosition_Response>()
{
  return custom_interfaces::srv::builder::Init_SetPosition_Response_position();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__SET_POSITION__BUILDER_HPP_
