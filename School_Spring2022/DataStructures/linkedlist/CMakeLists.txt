cmake_minimum_required(VERSION 3.20)
project(linkedlist)

set(CMAKE_CXX_STANDARD 23)

add_executable(linkedlist main.cpp node.cpp node.h LinkList.cpp LinkList.h)
