cmake_minimum_required(VERSION 3.8)
project(custom_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

# add !
find_package(rosidl_default_generators REQUIRED)
set(msg_files
  # "msg/SetPosition.msg"
  "msg/SetPositions.msg"
  "msg/GetSensordata.msg"
)

set(srv_files
  "srv/GetPositions.srv"
  "srv/SetPositions.srv"
  "srv/SetPosition.srv"
)
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/SetPositions.msg"
  "msg/GetSensordata.msg"
  "srv/GetPositions.srv"
  "srv/SetPositions.srv"
  "srv/SetPosition.srv"
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
