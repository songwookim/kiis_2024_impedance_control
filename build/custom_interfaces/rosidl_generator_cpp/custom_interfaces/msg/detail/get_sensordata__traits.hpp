// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:msg/GetSensordata.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__GET_SENSORDATA__TRAITS_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__GET_SENSORDATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/msg/detail/get_sensordata__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const GetSensordata & msg,
  std::ostream & out)
{
  out << "{";
  // member: sensordata
  {
    if (msg.sensordata.size() == 0) {
      out << "sensordata: []";
    } else {
      out << "sensordata: [";
      size_t pending_items = msg.sensordata.size();
      for (auto item : msg.sensordata) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetSensordata & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: sensordata
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.sensordata.size() == 0) {
      out << "sensordata: []\n";
    } else {
      out << "sensordata:\n";
      for (auto item : msg.sensordata) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetSensordata & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::msg::GetSensordata & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::msg::GetSensordata & msg)
{
  return custom_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::msg::GetSensordata>()
{
  return "custom_interfaces::msg::GetSensordata";
}

template<>
inline const char * name<custom_interfaces::msg::GetSensordata>()
{
  return "custom_interfaces/msg/GetSensordata";
}

template<>
struct has_fixed_size<custom_interfaces::msg::GetSensordata>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::msg::GetSensordata>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interfaces::msg::GetSensordata>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__GET_SENSORDATA__TRAITS_HPP_
