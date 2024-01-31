//
// Created by Jared See on 10/15/21.
//
#include<iostream>
#include<string>
#include<cstdint>
using namespace std;
#ifndef DATAPROJECT_COURSE_H
#define DATAPROJECT_COURSE_H


class Course {
public:
    string code;
    string title;
    double grade;
    uint8_t creditHour;


    const string &getCode() const {
        return code;
    }

    void setCode(const string &code) {
        Course::code = code;
    }

    const string &getTitle() const {
        return title;
    }

    void setTitle(const string &title) {
        Course::title = title;
    }

    double getGrade() const {
        return grade;
    }

    void setGrade(double grade) {
        Course::grade = grade;
    }

    uint8_t getCreditHour() const {
        return creditHour;
    }

    void setCreditHour(uint8_t creditHour) {
        Course::creditHour = creditHour;
    }




    void setAll(string code, string title, double grade, uint8_t creditHour)
    {
        this->code=code;
        this->title=title;
        this->grade=grade;
        this->creditHour=creditHour;
    }

};


#endif //DATAPROJECT_COURSE_H
