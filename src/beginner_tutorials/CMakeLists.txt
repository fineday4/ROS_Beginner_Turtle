cmake_minimum_required(VERSION 2.8.3)
project(beginner_tutorials)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

## Declare ROS messages and services
add_message_files(FILES Num.msg)
add_service_files(FILES AddTwoInts.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
#include_directories(include ${catkin_INCLUDE_DIRS})

#add_executable(mytalker src/talker.cpp)
#target_link_libraries(mytalker ${catkin_LIBRARIES})
#add_dependencies(mytalker beginner_tutorials_generate_messages_cpp)

#add_executable(mylistener src/listener.cpp)
#target_link_libraries(mylistener ${catkin_LIBRARIES})
#add_dependencies(mylistener beginner_tutorials_generate_messages_cpp)

# %EndTag(FULLTEXT)%
## Build service client and server
# %Tag(SRVCLIENT)%
include_directories(include ${catkin_INCLUDE_DIRS})
add_executable(my_add_two_ints_server src/add_two_ints_server.cpp)
target_link_libraries(my_add_two_ints_server ${catkin_LIBRARIES})
add_dependencies(my_add_two_ints_server beginner_tutorials_gencpp)

add_executable(my_add_two_ints_client src/add_two_ints_client.cpp)
target_link_libraries(my_add_two_ints_client ${catkin_LIBRARIES})
add_dependencies(my_add_two_ints_client beginner_tutorials_gencpp)
# %EndTag(FULLTEXT)%

