cmake_minimum_required(VERSION 3.9.1)

project(laser_emulator)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories("${PROJECT_SOURCE_DIR}")


add_subdirectory(HMI/src)
add_subdirectory(cmdProcessor/src)
add_subdirectory(controlPanel/src)

add_executable(laser src/Laser.cpp ${PROJECT_SOURCE_DIR}/main.cpp)

target_link_libraries(laser HMI CmdProcessor ControlPanel)
