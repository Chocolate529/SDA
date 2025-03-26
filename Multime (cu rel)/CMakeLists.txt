cmake_minimum_required(VERSION 3.30)
project(Multime__cu_rel_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Multime__cu_rel_
    App.cpp
    IteratorMultime.cpp
    IteratorMultime.h
    Multime.cpp
    Multime.h
        "Teste(cu relatie)/TestExtins.cpp"
        "Teste(cu relatie)/TestExtins.h"
        "Teste(cu relatie)/TestScurt.cpp"
        "Teste(cu relatie)/TestScurt.h")
