cmake_minimum_required(VERSION 3.12)
project(stack
  DESCRIPTION "A Reverse Polish notation calculator in C"
  VERSION "0.1"
  LANGUAGES C
  )

set(CMAKE_C_STANDARD 99)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        )

add_executable(cstack ${all_SRCS} main.c)
