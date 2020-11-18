cmake_minimum_required(VERSION 3.0.2)
project(test_msgs)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  mobileye_560_660_msgs
  std_msgs
)

add_message_files(
  DIRECTORY msg
  FILES
    Test.msg
)

generate_messages(
  DEPENDENCIES
    mobileye_560_660_msgs
    std_msgs
)

catkin_package(
  CATKIN_DEPENDS
    message_runtime
    mobileye_560_660_msgs
    std_msgs
)
