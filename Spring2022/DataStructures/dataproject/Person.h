//
// Created by Jared See on 10/15/21.
//
#include<iostream>
#include<string>
#include<cstdint>
using namespace std;
#ifndef DATAPROJECT_PERSON_H
#define DATAPROJECT_PERSON_H


class Person {


private:
    uint8_t age;
    string name;
public:
    uint8_t getAge() const {
        return age;
    }

    void setAge(uint8_t age) {
        Person::age = age;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Person::name = name;
    }
};


#endif //DATAPROJECT_PERSON_H
