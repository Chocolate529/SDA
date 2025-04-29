cmake_minimum_required(VERSION 3.30)
project(Colectie__cu_rel_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories("Teste (cu relatie)")

add_executable(Colectie__cu_rel_
    "Teste (cu relatie)/TestExtins.cpp"
    "Teste (cu relatie)/TestExtins.h"
    "Teste (cu relatie)/TestScurt.cpp"
    "Teste (cu relatie)/TestScurt.h"
    App.cpp
    Colectie.cpp
    Colectie.h
    IteratorColectie.cpp
    IteratorColectie.h)
