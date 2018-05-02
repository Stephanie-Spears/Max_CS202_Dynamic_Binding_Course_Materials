cmake_minimum_required(VERSION 3.10)
project(Max_CS202_Dynamic_Binding_Class_Materials)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Max_CS202_Dynamic_Binding_Class_Materials
        list.cpp
        list.h
        main.cpp
        materials.cpp
        materials.h)
