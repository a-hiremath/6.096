cmake_minimum_required(VERSION 4.0)
project(6.096)

set(CMAKE_CXX_STANDARD 20)

add_executable(mit_6_096_lab2 main.cpp

)

add_executable(mit_6096_lab3 ../mit_6.096_lab3/geometry.cpp
        ../mit_6.096_lab3/geometry.h)