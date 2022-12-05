cmake_minimum_required(VERSION 3.20)
project(dataproject)

set(CMAKE_CXX_STANDARD 23)

add_executable(dataproject main.cpp Person.h Course.h Student.h Records.h node.h LinkedList.h dnode.h DoublyLinkedList.h import.h testCourse.cpp testStudent.cpp testPerson.cpp testRecords.cpp)
