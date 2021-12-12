cmake_minimum_required(VERSION 3.21)
project(TP1 C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c processo.h processo.c)

add_executable(main ${SOURCE_FILES})
