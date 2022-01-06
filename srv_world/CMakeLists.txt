cmake_minimum_required(VERSION 3.0.2)
project(srv_world)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)

 add_service_files(
   FILES
   hey_world.srv
 )
generate_messages(
  DEPENDENCIES
  std_msgs
)
catkin_package(DEPENDS message_runtime)

include_directories(

  ${catkin_INCLUDE_DIRS}
)



add_executable(world_service src/hey_world_service.cpp)

 target_link_libraries(world_service ${catkin_LIBRARIES})

add_executable(world_client src/hey_world_client.cpp)

 target_link_libraries(world_client ${catkin_LIBRARIES})