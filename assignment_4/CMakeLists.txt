cmake_minimum_required(VERSION 3.8)
project(assignment_4)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c89")

set(SOURCE_FILES main.c)
add_executable(assignment_4 ${SOURCE_FILES})
add_executable(DynArray dynArray.c dynArray.h type.h)