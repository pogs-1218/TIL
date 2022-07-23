cmake_minimum_required(VERSION 3.14)

project(creational)

set(CMAKE_CXX_STANDARD 17)

set(SRC
  cpp/main.cc
  cpp/maze_game.cc
  cpp/maze.cc
  cpp/singleton_maze_factory.cc
  cpp/pi_maze_factory.cc
  )

add_executable(creational ${SRC})
