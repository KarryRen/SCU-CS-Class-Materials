cmake_minimum_required(VERSION 3.26)
project(BST_Graph)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BST_Graph
        binary_tree.cpp
        binary_tree.h
        graph.cpp
        graph.h
        main.cpp)
