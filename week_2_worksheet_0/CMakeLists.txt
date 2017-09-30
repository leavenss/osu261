cmake_minimum_required(VERSION 3.8)
project(week_2_worksheet_0)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c arrayBagStack.h)
add_executable(week_2_worksheet_0 ${SOURCE_FILES})

include_directories(.)