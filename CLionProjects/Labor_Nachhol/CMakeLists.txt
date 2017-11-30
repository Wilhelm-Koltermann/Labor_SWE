cmake_minimum_required(VERSION 3.8)
project(Labor_Nachhol)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(Labor_Nachhol ${SOURCE_FILES})

target_link_libraries(Labor_Nachhol m)