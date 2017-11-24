cmake_minimum_required(VERSION 3.8)
project(assignment_6)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        cutest/CuTest.c
        cutest/CuTest.h
        cutest/CuTestLicense.txt
        deque.c
        deque.h
        dequeTests.c
        graph.c
        graph.h
        graph1.txt
        graph2.txt
        graph3.txt
        graphTests.c
        main.c
        makefile
        tests.c)

add_executable(assignment_6 ${SOURCE_FILES})