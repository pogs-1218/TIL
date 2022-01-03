cmake_minimum_required(VERSION 3.10)

project(creational)

set(CMAKE_CXX_STANDARD 17)
set(SRC main.cc maze_game.cc maze.cc)

add_executable(creational ${SRC})
