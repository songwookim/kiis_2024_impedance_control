// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_interfaces:msg/SetPositions.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_interfaces/msg/detail/set_positions__rosidl_typesupport_introspection_c.h"
#include "custom_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_interfaces/msg/detail/set_positions__functions.h"
#include "custom_interfaces/msg/detail/set_positions__struct.h"


// Include directives for member types
// Member `ids`
// Member `positions`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__SetPositions_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_interfaces__msg__SetPositions__init(message_memory);
}

void custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__SetPositions_fini_function(void * message_memory)
{
  custom_interfaces__msg__SetPositions__fini(message_memory);
}

size_t custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__size_function__SetPositions__ids(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__get_const_function__SetPositions__ids(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__get_function__SetPositions__ids(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__fetch_function__SetPositions__ids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__get_const_function__SetPositions__ids(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__assign_function__SetPositions__ids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__get_function__SetPositions__ids(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__resize_function__SetPositions__ids(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

size_t custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__size_function__SetPositions__positions(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__get_const_function__SetPositions__positions(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__get_function__SetPositions__positions(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__fetch_function__SetPositions__positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__get_const_function__SetPositions__positions(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__assign_function__SetPositions__positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__get_function__SetPositions__positions(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__resize_function__SetPositions__positions(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__SetPositions_message_member_array[2] = {
  {
    "ids",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__SetPositions, ids),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__size_function__SetPositions__ids,  // size() function pointer
    custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__get_const_function__SetPositions__ids,  // get_const(index) function pointer
    custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__get_function__SetPositions__ids,  // get(index) function pointer
    custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__fetch_function__SetPositions__ids,  // fetch(index, &value) function pointer
    custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__assign_function__SetPositions__ids,  // assign(index, value) function pointer
    custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__resize_function__SetPositions__ids  // resize(index) function pointer
  },
  {
    "positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_interfaces__msg__SetPositions, positions),  // bytes offset in struct
    NULL,  // default value
    custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__size_function__SetPositions__positions,  // size() function pointer
    custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__get_const_function__SetPositions__positions,  // get_const(index) function pointer
    custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__get_function__SetPositions__positions,  // get(index) function pointer
    custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__fetch_function__SetPositions__positions,  // fetch(index, &value) function pointer
    custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__assign_function__SetPositions__positions,  // assign(index, value) function pointer
    custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__resize_function__SetPositions__positions  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__SetPositions_message_members = {
  "custom_interfaces__msg",  // message namespace
  "SetPositions",  // message name
  2,  // number of fields
  sizeof(custom_interfaces__msg__SetPositions),
  custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__SetPositions_message_member_array,  // message members
  custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__SetPositions_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__SetPositions_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__SetPositions_message_type_support_handle = {
  0,
  &custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__SetPositions_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_interfaces, msg, SetPositions)() {
  if (!custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__SetPositions_message_type_support_handle.typesupport_identifier) {
    custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__SetPositions_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_interfaces__msg__SetPositions__rosidl_typesupport_introspection_c__SetPositions_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
