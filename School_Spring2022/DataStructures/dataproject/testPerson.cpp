//
// Created by Jared See on 10/20/21.
//


#include "Person.h"

void testPerson()
{
    Person myPerson;
    myPerson.setAge(30);
    myPerson.setName("testname");

    cout <<
    to_string(myPerson.getAge()) << " " <<
    myPerson.getName();



}