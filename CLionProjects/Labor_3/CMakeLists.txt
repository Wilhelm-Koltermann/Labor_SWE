cmake_minimum_required(VERSION 3.8)
project(Labor_3)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(Labor_3 ${SOURCE_FILES})

target_link_libraries(Labor_3 m)