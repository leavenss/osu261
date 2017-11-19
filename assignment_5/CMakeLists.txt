cmake_minimum_required(VERSION 3.8)
project(assignment_5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        CuTest.c
        CuTest.h
        CuTestLicense.txt
        dictionary.txt
        hashMap.c
        hashMap.h
        input1.txt
        input2.txt
        input3.txt
        main.c
        makefile
        spellChecker.c
        tests.c)

add_executable(assignment_5 ${SOURCE_FILES})