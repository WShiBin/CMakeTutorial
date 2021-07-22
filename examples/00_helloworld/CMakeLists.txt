cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(00helloworld)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_C_STANDARD 11)

# CMAKE_BUILD_TYPE:``Debug``, ``Release``, ``RelWithDebInfo``, ``MinSizeRel``
# set(CMAKE_BUILD_TYPE Debug) # CMAKE_BUILD_TYPE=Debug
# -DCMAKE_BUILD_TYPE=Debug

message(STATUS "WARNING:CMAKE_BUILD_TYPE = " ${CMAKE_BUILD_TYPE})
message(STATUS "EDITOR = $ENV{EDITOR}")

add_executable(helloworld MACOSX_BUNDLE main.c)

# -----------------------------------------------------------
message("CMAKE_C_COMPILER = ${CMAKE_C_COMPILER}")
message("CMAKE_CXX_COMPILER = ${CMAKE_CXX_COMPILER}")
message("CMAKE_C_STANDARD = ${CMAKE_C_STANDARD}")
message("CMAKE_CXX_STANDARD = ${CMAKE_CXX_STANDARD}")

# project(<PROJECT-NAME> [<language-name>...])
# project(<PROJECT-NAME>
#         [VERSION <major>[.<minor>[.<patch>[.<tweak>]]]]
#         [DESCRIPTION <project-description-string>]
#         [HOMEPAGE_URL <url-string>]
#         [LANGUAGES <language-name>...])
project(00helloworld
    VERSION 0.1.2
    DESCRIPTION "demo for learing cmake"
    HOMEPAGE_URL "www.vdiscovery.cn"
    LANGUAGES C
)
message("PROJECT_NAME = ${PROJECT_NAME}")
message("PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}") # CMakeLists.txt
message("PROJECT_BINARY_DIR = ${PROJECT_BINARY_DIR}") # build
message("00helloworld_SOURCE_DIR = ${00helloworld_SOURCE_DIR}")
message("00helloworld_BINARY_DIR = ${00helloworld_BINARY_DIR}")
message("PROJECT_VERSION = ${PROJECT_VERSION}")
message("PROJECT_VERSION_MAJOR = ${PROJECT_VERSION_MAJOR}")
message("PROJECT_VERSION_MINOR = ${PROJECT_VERSION_MINOR}")
message("PROJECT_VERSION_PATCH = ${PROJECT_VERSION_PATCH}")
message("PROJECT_DESCRIPTION = ${PROJECT_DESCRIPTION}")
message("PROJECT_HOMEPAGE_URL = ${PROJECT_HOMEPAGE_URL}")