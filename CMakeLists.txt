cmake_minimum_required(VERSION 2.8)
set(PROJECT_NAME guslib)
project(guslib C)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -std=c11")
include_directories(${PROJECT_SOURCE_DIR}/src)

# guslib lib
add_library(guslib SHARED
    src/list.c
    src/queue.c
    )

# guslib test
enable_testing()
add_executable(guslib_test
    test/list_test.c
    test/queue_test.c
    test/main.c
    )
target_link_libraries (guslib_test
    guslib
    )
add_test(test guslib_test)
