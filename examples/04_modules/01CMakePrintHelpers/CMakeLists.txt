cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(01CMakePrintHelpers)

set(CMAKE_BUILD_TYPE Debug)

message(STATUS "WARNING:CMAKE_BUILD_TYPE = " ${CMAKE_BUILD_TYPE})

# 1.引入模块
include(CMakePrintHelpers)

# 2.使用模块中提供的function/command
cmake_print_variables(CMAKE_BUILD_TYPE CMAKE_BUILD_TYPE)

add_executable(CMakePrintHelpers main.c)