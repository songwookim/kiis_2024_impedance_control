// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/GetSensordata.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__GET_SENSORDATA__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__GET_SENSORDATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'sensordata'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/GetSensordata in the package custom_interfaces.
/**
  * Messages
 */
typedef struct custom_interfaces__msg__GetSensordata
{
  rosidl_runtime_c__double__Sequence sensordata;
} custom_interfaces__msg__GetSensordata;

// Struct for a sequence of custom_interfaces__msg__GetSensordata.
typedef struct custom_interfaces__msg__GetSensordata__Sequence
{
  custom_interfaces__msg__GetSensordata * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__GetSensordata__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__GET_SENSORDATA__STRUCT_H_
