cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(01share_library)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_subdirectory(math)

add_executable(shared_exec
    main.c
)

target_include_directories(shared_exec
    PRIVATE ${math_SOURCE_DIR}
)

target_link_libraries(shared_exec PRIVATE
    share_library
)
