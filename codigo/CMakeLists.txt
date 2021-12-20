cmake_minimum_required(VERSION 3.20)
project(TP1 C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES programaPrincipal/main.c processo/processo.h processo/processo.c listaDeProcessos/listaDeProcessos.h listaDeProcessos/listaDeProcessos.c)

add_executable(main ${SOURCE_FILES})