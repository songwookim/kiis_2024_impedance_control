// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:srv/SetPositions.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__SET_POSITIONS__BUILDER_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__SET_POSITIONS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/srv/detail/set_positions__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetPositions_Request_sensordata
{
public:
  explicit Init_SetPositions_Request_sensordata(::custom_interfaces::srv::SetPositions_Request & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::SetPositions_Request sensordata(::custom_interfaces::srv::SetPositions_Request::_sensordata_type arg)
  {
    msg_.sensordata = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::SetPositions_Request msg_;
};

class Init_SetPositions_Request_positions
{
public:
  explicit Init_SetPositions_Request_positions(::custom_interfaces::srv::SetPositions_Request & msg)
  : msg_(msg)
  {}
  Init_SetPositions_Request_sensordata positions(::custom_interfaces::srv::SetPositions_Request::_positions_type arg)
  {
    msg_.positions = std::move(arg);
    return Init_SetPositions_Request_sensordata(msg_);
  }

private:
  ::custom_interfaces::srv::SetPositions_Request msg_;
};

class Init_SetPositions_Request_ids
{
public:
  Init_SetPositions_Request_ids()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetPositions_Request_positions ids(::custom_interfaces::srv::SetPositions_Request::_ids_type arg)
  {
    msg_.ids = std::move(arg);
    return Init_SetPositions_Request_positions(msg_);
  }

private:
  ::custom_interfaces::srv::SetPositions_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::SetPositions_Request>()
{
  return custom_interfaces::srv::builder::Init_SetPositions_Request_ids();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetPositions_Response_timestamp
{
public:
  explicit Init_SetPositions_Response_timestamp(::custom_interfaces::srv::SetPositions_Response & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::SetPositions_Response timestamp(::custom_interfaces::srv::SetPositions_Response::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::SetPositions_Response msg_;
};

class Init_SetPositions_Response_torques
{
public:
  Init_SetPositions_Response_torques()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetPositions_Response_timestamp torques(::custom_interfaces::srv::SetPositions_Response::_torques_type arg)
  {
    msg_.torques = std::move(arg);
    return Init_SetPositions_Response_timestamp(msg_);
  }

private:
  ::custom_interfaces::srv::SetPositions_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::SetPositions_Response>()
{
  return custom_interfaces::srv::builder::Init_SetPositions_Response_torques();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__SET_POSITIONS__BUILDER_HPP_
