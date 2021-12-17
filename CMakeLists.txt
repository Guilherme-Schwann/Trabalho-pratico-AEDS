cmake_minimum_required(VERSION 3.20)
project(TP1 C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c processo.h processo.c listaDeProcessos.h listaDeProcessos.c)
set(ARQUIVOS TestesTad.c processo.h processo.c listaDeProcessos.h listaDeProcessos.c)

add_executable(main ${SOURCE_FILES})
add_executable(testes ${ARQUIVOS})