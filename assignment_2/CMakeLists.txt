cmake_minimum_required(VERSION 3.8)
project(assignment_2)

set(CMAKE_C_STANDARD 99)

add_executable(dynamicArray dynamicArray.c dynArray.h)
add_executable(stackapp stackapp.c dynArray.h)
add_executable(testDynArray testDynArray.c dynArray.h)