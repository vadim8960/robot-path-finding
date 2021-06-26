cmake_minimum_required(VERSION 3.17)
project(custom-shape-obj)

set(CMAKE_CXX_STANDARD 17)
set(SFML_LIBS sfml-graphics sfml-window sfml-system)

set(CUSTOM_SHAPE_HEADERS inc/CustomCircleShape.h inc/CustomLineShape.h inc/CustomRectShape.h)
set(CUSTOM_SHAPE_SOURCES src/CustomCircleShape.cpp src/CustomLineShape.cpp src/CustomRectShape.cpp)

add_library(${PROJECT_NAME}
        ${CUSTOM_SHAPE_HEADERS}
        ${CUSTOM_SHAPE_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC src)
target_include_directories(${PROJECT_NAME} PUBLIC inc)
target_include_directories(${PROJECT_NAME} PUBLIC line_shape)

target_link_libraries(${PROJECT_NAME} PUBLIC ${SFML_LIBS})

