cmake_minimum_required(VERSION 3.10)
project(pubsub_intro)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

#这里的每一个find_package都要在package.xml里有对应的<depend>
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

#让#include "rclcpp/rclcpp.hpp"等头文件能被找到
include_directories(include)

#可执行文件名得叫intro_node，这样后面ros2 run pubsub_intro intro_node才能对上
add_executable(intro_node 
    src/main.cpp
    src/intro_node.cpp)

#把依赖链接到可执行文件上。名字要和上面 find_package 的一致
ament_target_dependencies(intro_node
  rclcpp
  std_msgs
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

#安装到 install/pubsub_intro/lib/pubsub_intro/，ros2 run 才能找到它
install(TARGETS intro_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()
