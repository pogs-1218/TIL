cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Debug)
set(SRC employee_test.cc employee.cc database.cc)

add_compile_options(-g -Wall -std=c++2a)

add_executable("employee_test" ${SRC})