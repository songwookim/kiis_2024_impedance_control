// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_interfaces:srv/SetPositions.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_interfaces/srv/detail/set_positions__rosidl_typesupport_introspection_c.h"
#include "custom_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_interfaces/srv/detail/set_positions__functions.h"
#include "custom_interfaces/srv/detail/set_positions__struct.h"


// Include directives for member types
// Member `ids`
// Member `positions`
// Member `sensordata`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__SetPositions_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_interfaces__srv__SetPositions_Request__init(message_memory);
}

void custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__SetPositions_Request_fini_function(void * message_memory)
{
  custom_interfaces__srv__SetPositions_Request__fini(message_memory);
}

size_t custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__size_function__SetPositions_Request__ids(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__get_const_function__SetPositions_Request__ids(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__get_function__SetPositions_Request__ids(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__fetch_function__SetPositions_Request__ids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__get_const_function__SetPositions_Request__ids(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__assign_function__SetPositions_Request__ids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__get_function__SetPositions_Request__ids(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__resize_function__SetPositions_Request__ids(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

size_t custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__size_function__SetPositions_Request__positions(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__get_const_function__SetPositions_Request__positions(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__get_function__SetPositions_Request__positions(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__fetch_function__SetPositions_Request__positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__get_const_function__SetPositions_Request__positions(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__assign_function__SetPositions_Request__positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__get_function__SetPositions_Request__positions(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__resize_function__SetPositions_Request__positions(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__size_function__SetPositions_Request__sensordata(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__get_const_function__SetPositions_Request__sensordata(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__get_function__SetPositions_Request__sensordata(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__fetch_function__SetPositions_Request__sensordata(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__get_const_function__SetPositions_Request__sensordata(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__assign_function__SetPositions_Request__sensordata(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__get_function__SetPositions_Request__sensordata(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__resize_function__SetPositions_Request__sensordata(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__SetPositions_Request_message_member_array[3] = {
  {
    "ids",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__srv__SetPositions_Request, ids),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__size_function__SetPositions_Request__ids,  // size() function pointer
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__get_const_function__SetPositions_Request__ids,  // get_const(index) function pointer
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__get_function__SetPositions_Request__ids,  // get(index) function pointer
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__fetch_function__SetPositions_Request__ids,  // fetch(index, &value) function pointer
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__assign_function__SetPositions_Request__ids,  // assign(index, value) function pointer
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__resize_function__SetPositions_Request__ids  // resize(index) function pointer
  },
  {
    "positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__srv__SetPositions_Request, positions),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__size_function__SetPositions_Request__positions,  // size() function pointer
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__get_const_function__SetPositions_Request__positions,  // get_const(index) function pointer
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__get_function__SetPositions_Request__positions,  // get(index) function pointer
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__fetch_function__SetPositions_Request__positions,  // fetch(index, &value) function pointer
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__assign_function__SetPositions_Request__positions,  // assign(index, value) function pointer
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__resize_function__SetPositions_Request__positions  // resize(index) function pointer
  },
  {
    "sensordata",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__srv__SetPositions_Request, sensordata),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__size_function__SetPositions_Request__sensordata,  // size() function pointer
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__get_const_function__SetPositions_Request__sensordata,  // get_const(index) function pointer
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__get_function__SetPositions_Request__sensordata,  // get(index) function pointer
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__fetch_function__SetPositions_Request__sensordata,  // fetch(index, &value) function pointer
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__assign_function__SetPositions_Request__sensordata,  // assign(index, value) function pointer
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__resize_function__SetPositions_Request__sensordata  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__SetPositions_Request_message_members = {
  "custom_interfaces__srv",  // message namespace
  "SetPositions_Request",  // message name
  3,  // number of fields
  sizeof(custom_interfaces__srv__SetPositions_Request),
  custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__SetPositions_Request_message_member_array,  // message members
  custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__SetPositions_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__SetPositions_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__SetPositions_Request_message_type_support_handle = {
  0,
  &custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__SetPositions_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, srv, SetPositions_Request)() {
  if (!custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__SetPositions_Request_message_type_support_handle.typesupport_identifier) {
    custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__SetPositions_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_interfaces__srv__SetPositions_Request__rosidl_typesupport_introspection_c__SetPositions_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "custom_interfaces/srv/detail/set_positions__rosidl_typesupport_introspection_c.h"
// already included above
// #include "custom_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "custom_interfaces/srv/detail/set_positions__functions.h"
// already included above
// #include "custom_interfaces/srv/detail/set_positions__struct.h"


// Include directives for member types
// Member `torques`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__SetPositions_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_interfaces__srv__SetPositions_Response__init(message_memory);
}

void custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__SetPositions_Response_fini_function(void * message_memory)
{
  custom_interfaces__srv__SetPositions_Response__fini(message_memory);
}

size_t custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__size_function__SetPositions_Response__torques(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__get_const_function__SetPositions_Response__torques(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__get_function__SetPositions_Response__torques(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__fetch_function__SetPositions_Response__torques(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__get_const_function__SetPositions_Response__torques(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__assign_function__SetPositions_Response__torques(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__get_function__SetPositions_Response__torques(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__resize_function__SetPositions_Response__torques(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__SetPositions_Response_message_member_array[2] = {
  {
    "torques",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__srv__SetPositions_Response, torques),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__size_function__SetPositions_Response__torques,  // size() function pointer
    custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__get_const_function__SetPositions_Response__torques,  // get_const(index) function pointer
    custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__get_function__SetPositions_Response__torques,  // get(index) function pointer
    custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__fetch_function__SetPositions_Response__torques,  // fetch(index, &value) function pointer
    custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__assign_function__SetPositions_Response__torques,  // assign(index, value) function pointer
    custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__resize_function__SetPositions_Response__torques  // resize(index) function pointer
  },
  {
    "timestamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__srv__SetPositions_Response, timestamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__SetPositions_Response_message_members = {
  "custom_interfaces__srv",  // message namespace
  "SetPositions_Response",  // message name
  2,  // number of fields
  sizeof(custom_interfaces__srv__SetPositions_Response),
  custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__SetPositions_Response_message_member_array,  // message members
  custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__SetPositions_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__SetPositions_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__SetPositions_Response_message_type_support_handle = {
  0,
  &custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__SetPositions_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, srv, SetPositions_Response)() {
  if (!custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__SetPositions_Response_message_type_support_handle.typesupport_identifier) {
    custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__SetPositions_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_interfaces__srv__SetPositions_Response__rosidl_typesupport_introspection_c__SetPositions_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "custom_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "custom_interfaces/srv/detail/set_positions__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers custom_interfaces__srv__detail__set_positions__rosidl_typesupport_introspection_c__SetPositions_service_members = {
  "custom_interfaces__srv",  // service namespace
  "SetPositions",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // custom_interfaces__srv__detail__set_positions__rosidl_typesupport_introspection_c__SetPositions_Request_message_type_support_handle,
  NULL  // response message
  // custom_interfaces__srv__detail__set_positions__rosidl_typesupport_introspection_c__SetPositions_Response_message_type_support_handle
};

static rosidl_service_type_support_t custom_interfaces__srv__detail__set_positions__rosidl_typesupport_introspection_c__SetPositions_service_type_support_handle = {
  0,
  &custom_interfaces__srv__detail__set_positions__rosidl_typesupport_introspection_c__SetPositions_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, srv, SetPositions_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, srv, SetPositions_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, srv, SetPositions)() {
  if (!custom_interfaces__srv__detail__set_positions__rosidl_typesupport_introspection_c__SetPositions_service_type_support_handle.typesupport_identifier) {
    custom_interfaces__srv__detail__set_positions__rosidl_typesupport_introspection_c__SetPositions_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)custom_interfaces__srv__detail__set_positions__rosidl_typesupport_introspection_c__SetPositions_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, srv, SetPositions_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, srv, SetPositions_Response)()->data;
  }

  return &custom_interfaces__srv__detail__set_positions__rosidl_typesupport_introspection_c__SetPositions_service_type_support_handle;
}
