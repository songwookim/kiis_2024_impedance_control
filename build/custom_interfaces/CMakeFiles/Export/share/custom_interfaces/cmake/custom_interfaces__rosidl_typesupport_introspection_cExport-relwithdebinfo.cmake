#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "custom_interfaces::custom_interfaces__rosidl_typesupport_introspection_c" for configuration "RelWithDebInfo"
set_property(TARGET custom_interfaces::custom_interfaces__rosidl_typesupport_introspection_c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(custom_interfaces::custom_interfaces__rosidl_typesupport_introspection_c PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libcustom_interfaces__rosidl_typesupport_introspection_c.so"
  IMPORTED_SONAME_RELWITHDEBINFO "libcustom_interfaces__rosidl_typesupport_introspection_c.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS custom_interfaces::custom_interfaces__rosidl_typesupport_introspection_c )
list(APPEND _IMPORT_CHECK_FILES_FOR_custom_interfaces::custom_interfaces__rosidl_typesupport_introspection_c "${_IMPORT_PREFIX}/lib/libcustom_interfaces__rosidl_typesupport_introspection_c.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
