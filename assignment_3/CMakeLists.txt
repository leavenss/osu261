cmake_minimum_required(VERSION 3.8)
project(assignment_3)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(assignment_3 ${SOURCE_FILES})

add_executable(LLDeque LLDeque/linkedListMain.c LLDeque/linkedList.h LLDeque/linkedList.c)
add_executable(CLDeque CLDeque/circularList.c CLDeque/circularList.h CLDeque/circularListMain.c)
add_executable(Timing Timing/dynamicArray.c Timing/dynamicArray.c Timing/dynArray.h)