//
// Created by Jared See on 10/20/21.
//

#include "Student.h"
#include "Course.h"

void testStudent()
{
    Course myCourse;
    Student<Course> myStudent;
    myCourse.setAll("1134", "test course", 90, 19);
    myStudent.addCourse(myCourse);
    myStudent.setNumberOfCourses(1);
    myStudent.setTotalCreditHour(40);
    myStudent.setGpa(4);

    cout << " " <<
    myStudent.getGpa() << " " <<
    myStudent.getNumberOfCourses() << " " <<
    myStudent.getTotalCreditHour() << " " <<
    myStudent.getUid();
}

