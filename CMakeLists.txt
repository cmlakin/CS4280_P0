cmake_minimum_required(VERSION 3.21)
project(CS4280_P0)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CS4280_P0
        buildtree.cpp
        buildtree.h
        main.cpp
        node.h
        traversals.cpp
        traversals.h)
