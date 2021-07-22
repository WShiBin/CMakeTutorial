project(math)

add_library(share_library STATIC
    add.c
)

target_sources(share_library
    PRIVATE div.c
)