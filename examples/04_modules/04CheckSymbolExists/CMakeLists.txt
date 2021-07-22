cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(04CheckSymbolExists)

# 1.引入模块
include(CheckSymbolExists)

# Check for macro SEEK_SET
check_symbol_exists(SEEK_SET "stdio.h" HAVE_SEEK_SET)
# Check for function fopen
check_symbol_exists(fopen "stdio.h" HAVE_FOPEN)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/header.h.in
    ${CMAKE_CURRENT_SOURCE_DIR}/header.h
)

add_executable(CheckSymbolExists main.c)