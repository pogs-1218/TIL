cmake_minimum_required(VERSION 3.14)

project(structural)

set(SOURCES
  main.cc
  facade/facade.cc
  )

add_executable(structural ${SOURCES})
