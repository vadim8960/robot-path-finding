cmake_minimum_required(VERSION 3.17)
project(robot_path_finding)

set(CMAKE_CXX_STANDARD 17)

include_directories(libs)
include_directories(libs/sfml_drawer)

add_subdirectory(libs/sfml_drawer)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC sfml-drawer)
