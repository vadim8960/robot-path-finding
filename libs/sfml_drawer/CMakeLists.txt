cmake_minimum_required(VERSION 3.17)
project(sfml-drawer)

set(CMAKE_CXX_STANDARD 17)
set(SFML_LIBS sfml-graphics sfml-window sfml-system)

add_library(${PROJECT_NAME} SFMLDrawer.cpp SFMLDrawer.h sfline.cpp sfline.h)

target_link_libraries(${PROJECT_NAME} PUBLIC ${SFML_LIBS})

