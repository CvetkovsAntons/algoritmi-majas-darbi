cmake_minimum_required(VERSION 3.26)
project(MD1)

set(CMAKE_CXX_STANDARD 23)

add_executable(MD1 main.cpp
        QuickSort.h
        QuickSort.cpp
        Menu.h
        Menu.cpp
        GenerateCsv.h
        GenerateCsv.cpp
)
