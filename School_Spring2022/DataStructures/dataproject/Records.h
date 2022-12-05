//
// Created by Jared See on 10/15/21.
//
#include<iostream>
#include<string>
#include<cstdint>
#include "Student.h"
#include "dnode.h"
#include "DoublyLinkedList.h"
using namespace std;
#ifndef DATAPROJECT_RECORDS_H
#define DATAPROJECT_RECORDS_H


//template<typename T>
class Records: Student<double> {

private:
    double averageGPA;
    uint32_t numberOfStudents;
    DoublyLinkedList<Student>students;
public:
    double getAverageGpa() const {
        return averageGPA;
    }

    void setAverageGpa(double averageGpa) {
        averageGPA = averageGpa;
    }

    uint32_t getNumberOfStudents() const {
        return numberOfStudents;
    }

    void setNumberOfStudents(uint32_t numberOfStudents) {
        Records::numberOfStudents = numberOfStudents;
    }

};


#endif //DATAPROJECT_RECORDS_H
