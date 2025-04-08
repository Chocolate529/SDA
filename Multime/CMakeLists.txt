cmake_minimum_required(VERSION 3.30)
project(Multime)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Teste)

add_executable(Multime
    Teste/TestExtins.cpp
    Teste/TestExtins.h
    Teste/TestScurt.cpp
    Teste/TestScurt.h
    App.cpp
    IteratorMultime.cpp
    IteratorMultime.h
    Multime.cpp
    Multime.h
        nod.h)
