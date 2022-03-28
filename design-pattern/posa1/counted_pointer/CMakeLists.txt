cmake_minimum_required(VERSION 3.14)

project(ref_count)

set(SRC
  main.cc
  handle.cc
)

add_executable(ref_count ${SRC})