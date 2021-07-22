project(01share_library)

add_subdirectory(math)

add_executable(shared_exec
    main.c
)

target_include_directories(shared_exec
    PRIVATE ${math_SOURCE_DIR}
)

target_link_libraries(shared_exec
    PRIVATE share_library
)
