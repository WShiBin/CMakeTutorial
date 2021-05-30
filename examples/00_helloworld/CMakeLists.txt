# cmake_minimum_required(VERSION <min>[...<max>] [FATAL_ERROR])
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(00helloworld)

add_executable(helloworld main.c)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_BUILD_TYPE Release)
# echo(shell) / printf(c)
# message(FATAL_ERROR "WARNING:CMAKE_BUILD_TYPE = " ${CMAKE_BUILD_TYPE})
# 后面空行
message(WARNING "WARNING:CMAKE_BUILD_TYPE = " ${CMAKE_BUILD_TYPE})
# ---
message(STATUS "STATUS:CMAKE_BUILD_TYPE = " ${CMAKE_BUILD_TYPE})
message("NONE:CMAKE_BUILD_TYPE = " ${CMAKE_BUILD_TYPE})
message(TRACE "TRACE:CMAKE_BUILD_TYPE = " ${CMAKE_BUILD_TYPE})

#[==================[
message("NONE:CMAKE_BUILD_TYPE = " ${CMAKE_BUILD_TYPE})
message(TRACE "TRACE:CMAKE_BUILD_TYPE = " ${CMAKE_BUILD_TYPE})
#]==================]

#[[
message("NONE:CMAKE_BUILD_TYPE = " ${CMAKE_BUILD_TYPE})
message(TRACE "TRACE:CMAKE_BUILD_TYPE = " ${CMAKE_BUILD_TYPE})
]]

#[[
This is a bracket comment.
It runs until the close bracket.
]]
message("First Argument\n" #[[Bracket Comment]] "Second Argument")
message("xixi")