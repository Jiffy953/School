cmake_minimum_required(VERSION 3.20)
project(StackQueue)

set(CMAKE_CXX_STANDARD 14)

add_executable(StackQueue main.cpp Queue.cpp Queue.h Stack.cpp Stack.h)
