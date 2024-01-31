//
// Created by Jared See on 10/20/21.
//
#include "Records.h"

void testRecords()
{
    Records myRecords;
    myRecords.setAverageGpa(2);
    myRecords.setNumberOfStudents(43);

    cout <<
    myRecords.getNumberOfStudents() << " " <<
    myRecords.getAverageGpa();
}
