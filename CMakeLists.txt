cmake_minimum_required(VERSION 3.29)
project(aho_corasick)

set(CMAKE_CXX_STANDARD 23)

add_executable(aho_corasick main.cpp
        ac-node.cpp
        ac-node.h
        ac-tree.cpp
        ac-tree.h)
