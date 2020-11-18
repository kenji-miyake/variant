cmake_minimum_required(VERSION 3.0.2)
project(test_package)

add_compile_options(-std=c++14)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  test_msgs
  variant_topic_tools
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(test_package
  src/test_package/main.cpp
)

target_link_libraries(test_package
  ${catkin_LIBRARIES}
)

add_dependencies(test_package
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS}
)

install(
  TARGETS
    test_package
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
