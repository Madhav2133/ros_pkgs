cmake_minimum_required(VERSION 3.0.2)
project(msg_world)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)

## Generate messages in the 'msg' folder
add_message_files(
   FILES
   hello_world.msg
 )

generate_messages(
  DEPENDENCIES
  std_msgs
)

 add_executable(announce src/hello_world.cpp)

  target_link_libraries(announce ${catkin_LIBRARIES})

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)


