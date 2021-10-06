cmake_minimum_required(VERSION 3.0.2)
project(chat_bot)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(a_talker src/a_talker.cpp)
  target_link_libraries(a_talker
  ${catkin_LIBRARIES}
)

add_executable(b_talker src/b_talker.cpp)
  target_link_libraries(b_talker
  ${catkin_LIBRARIES}
)

add_executable(a_slistener src/a_listener.cpp)
  target_link_libraries(a_slistener
  ${catkin_LIBRARIES}
)

add_executable(b_listener src/b_listener.cpp)
  target_link_libraries(b_listener
  ${catkin_LIBRARIES}
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

