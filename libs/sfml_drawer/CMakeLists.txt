cmake_minimum_required(VERSION 3.17)
project(sfml-drawer)

set(CMAKE_CXX_STANDARD 17)

include_directories(custom_shape_obj)

add_subdirectory(custom_shape_obj)

add_library(${PROJECT_NAME} SFMLDrawer.cpp SFMLDrawer.h)

target_link_libraries(${PROJECT_NAME} PUBLIC custom-shape-obj)

