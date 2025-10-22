cmake_minimum_required(VERSION 4.0)
project(trabalho)

set(CMAKE_CXX_STANDARD 20)

add_executable(trabalho main.cpp
        solo.h
        solo.cpp
        jardim.h
        jardim.cpp
        planta.h
        jardineiro.h)
