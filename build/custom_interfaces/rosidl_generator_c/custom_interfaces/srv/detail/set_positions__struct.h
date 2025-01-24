// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:srv/SetPositions.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__SET_POSITIONS__STRUCT_H_
#define CUSTOM_INTERFACES__SRV__DETAIL__SET_POSITIONS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'ids'
// Member 'positions'
// Member 'sensordata'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/SetPositions in the package custom_interfaces.
typedef struct custom_interfaces__srv__SetPositions_Request
{
  rosidl_runtime_c__uint8__Sequence ids;
  rosidl_runtime_c__double__Sequence positions;
  rosidl_runtime_c__double__Sequence sensordata;
} custom_interfaces__srv__SetPositions_Request;

// Struct for a sequence of custom_interfaces__srv__SetPositions_Request.
typedef struct custom_interfaces__srv__SetPositions_Request__Sequence
{
  custom_interfaces__srv__SetPositions_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__SetPositions_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'torques'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/SetPositions in the package custom_interfaces.
typedef struct custom_interfaces__srv__SetPositions_Response
{
  rosidl_runtime_c__double__Sequence torques;
  uint64_t timestamp;
} custom_interfaces__srv__SetPositions_Response;

// Struct for a sequence of custom_interfaces__srv__SetPositions_Response.
typedef struct custom_interfaces__srv__SetPositions_Response__Sequence
{
  custom_interfaces__srv__SetPositions_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__SetPositions_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__SET_POSITIONS__STRUCT_H_
