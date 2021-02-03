cmake_minimum_required(VERSION 2.9)
project(stack)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-std=c99")
#add_compile_definitions(DEBUG)

set(SOURCE_FILES main.c list.h)
add_executable(stack ${SOURCE_FILES})
