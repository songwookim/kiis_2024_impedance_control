// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:srv/SetPositions.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__SET_POSITIONS__TRAITS_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__SET_POSITIONS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/srv/detail/set_positions__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetPositions_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: ids
  {
    if (msg.ids.size() == 0) {
      out << "ids: []";
    } else {
      out << "ids: [";
      size_t pending_items = msg.ids.size();
      for (auto item : msg.ids) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: positions
  {
    if (msg.positions.size() == 0) {
      out << "positions: []";
    } else {
      out << "positions: [";
      size_t pending_items = msg.positions.size();
      for (auto item : msg.positions) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

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
  const SetPositions_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: ids
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.ids.size() == 0) {
      out << "ids: []\n";
    } else {
      out << "ids:\n";
      for (auto item : msg.ids) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.positions.size() == 0) {
      out << "positions: []\n";
    } else {
      out << "positions:\n";
      for (auto item : msg.positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

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

inline std::string to_yaml(const SetPositions_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::srv::SetPositions_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::SetPositions_Request & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::SetPositions_Request>()
{
  return "custom_interfaces::srv::SetPositions_Request";
}

template<>
inline const char * name<custom_interfaces::srv::SetPositions_Request>()
{
  return "custom_interfaces/srv/SetPositions_Request";
}

template<>
struct has_fixed_size<custom_interfaces::srv::SetPositions_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::srv::SetPositions_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interfaces::srv::SetPositions_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetPositions_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: torques
  {
    if (msg.torques.size() == 0) {
      out << "torques: []";
    } else {
      out << "torques: [";
      size_t pending_items = msg.torques.size();
      for (auto item : msg.torques) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: timestamp
  {
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetPositions_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: torques
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.torques.size() == 0) {
      out << "torques: []\n";
    } else {
      out << "torques:\n";
      for (auto item : msg.torques) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetPositions_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::srv::SetPositions_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::SetPositions_Response & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::SetPositions_Response>()
{
  return "custom_interfaces::srv::SetPositions_Response";
}

template<>
inline const char * name<custom_interfaces::srv::SetPositions_Response>()
{
  return "custom_interfaces/srv/SetPositions_Response";
}

template<>
struct has_fixed_size<custom_interfaces::srv::SetPositions_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::srv::SetPositions_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_interfaces::srv::SetPositions_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interfaces::srv::SetPositions>()
{
  return "custom_interfaces::srv::SetPositions";
}

template<>
inline const char * name<custom_interfaces::srv::SetPositions>()
{
  return "custom_interfaces/srv/SetPositions";
}

template<>
struct has_fixed_size<custom_interfaces::srv::SetPositions>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_interfaces::srv::SetPositions_Request>::value &&
    has_fixed_size<custom_interfaces::srv::SetPositions_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_interfaces::srv::SetPositions>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_interfaces::srv::SetPositions_Request>::value &&
    has_bounded_size<custom_interfaces::srv::SetPositions_Response>::value
  >
{
};

template<>
struct is_service<custom_interfaces::srv::SetPositions>
  : std::true_type
{
};

template<>
struct is_service_request<custom_interfaces::srv::SetPositions_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_interfaces::srv::SetPositions_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__SET_POSITIONS__TRAITS_HPP_
