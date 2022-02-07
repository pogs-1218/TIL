cmake_minimum_required(VERSION 3.14)

project(behavioral)

set(CMAKE_CXX_STANDARD 17)

set(SRC
  command/command1.cc
  command/invoker.cc
  command/main.cc
  )

add_executable(behavioral ${SRC})