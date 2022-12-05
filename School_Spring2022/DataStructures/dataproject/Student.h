//
// Created by Jared See on 10/15/21.
//
#include<iostream>
#include<string>
#include<cstdint>
#include "Person.h"
#include "node.h"
#include "LinkedList.h"
#include "Course.h"


using namespace std;
#ifndef DATAPROJECT_STUDENT_H
#define DATAPROJECT_STUDENT_H

template<typename T>
class Student: Person{
private:
    uint32_t totalCreditHour;
    uint32_t numberOfCourses;
    uint32_t uid;
    double gpa;
    LinkedList<Course> courses;
    node<Course> *head;
public:
    Course data;
    void addCourse(Course data)
    {
        this->data = data;
        courses.add(data);
    }

    void deleteCourse()
    {
        courses.remove(&head, 1);
    }


    uint32_t getTotalCreditHour() const {
        return totalCreditHour;
    }

    void setTotalCreditHour(uint32_t totalCreditHour) {
        Student::totalCreditHour = totalCreditHour;
    }

    uint32_t getNumberOfCourses() const {
        return numberOfCourses;
    }

    void setNumberOfCourses(uint32_t numberOfCourses) {
        Student::numberOfCourses = numberOfCourses;
    }

    uint32_t getUid() const {
        return uid;
    }

    void setUid(uint32_t uid) {
        Student::uid = uid;
    }

    double getGpa() const {
        return gpa;
    }

    void setGpa(double grade) {
        Student::gpa = gpa;
    }


};


#endif //DATAPROJECT_STUDENT_H
