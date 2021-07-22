cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(04arguments)

add_library(log STATIC
    log.c
)

add_executable(arguments
    main.c
)

# configure_file(<input> <output>)
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h
)

if(${LOG_DEBUG_ENABLE})
    message("FOUND")
else()
    message("NOTFOUND")
    unset(LOG_DEBUG_ENABLE CACHE)
endif()

target_link_libraries(arguments PRIVATE log)
target_include_directories(arguments PRIVATE ${log_SOURCE_DIR})