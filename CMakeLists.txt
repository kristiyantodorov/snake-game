cmake_minimum_required(VERSION 3.5)

project(shapes)

set(SRCS
    src/main.cpp
    src/Game.cpp
    src/SDLRenderer.cpp
    src/Rectangle.cpp
    src/Shape.cpp
    src/Snake.cpp
    src/Food.cpp
    src/Coord2d.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} SDL2)