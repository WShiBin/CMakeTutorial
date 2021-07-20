cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(03CheckIncludeFile)

# 1.引入模块
include(CheckIncludeFile)
# CHECK_INCLUDE_FILE(<include> <variable> [<flags>])
CHECK_INCLUDE_FILE(stdio.h HAVE_STDIO_H)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/header.h.in
    ${CMAKE_CURRENT_SOURCE_DIR}/header.h
)

add_executable(CheckIncludeFile main.c)
