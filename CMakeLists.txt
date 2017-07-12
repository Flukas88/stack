cmake_minimum_required(VERSION 3.2)
project(stack)

set(CMAKE_C_STANDARD 99)


set(SOURCE_FILES main.c list.h)
add_executable(stack ${SOURCE_FILES})