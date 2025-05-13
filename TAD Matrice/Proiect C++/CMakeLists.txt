cmake_minimum_required(VERSION 3.30)
project(Proiect_C__)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Teste)

add_executable(Proiect_C__
    Teste/TestExtins.cpp
    Teste/TestExtins.h
    Teste/TestScurt.cpp
    Teste/TestScurt.h
    App.cpp
    Matrice.cpp
    Matrice.h)
