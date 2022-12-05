//
// Created by Jared See on 10/20/21.
//

#include "Course.h"


void testCourse()
{
    Course myCourse;
    myCourse.setCode("1331");
    myCourse.setCreditHour(3);
    myCourse.setGrade(90);
    myCourse.setTitle("test title");

    cout << myCourse.getCode() << " " <<
    to_string(myCourse.getCreditHour()) << " " <<
    myCourse.getGrade() << " " <<
    myCourse.getTitle() << endl;


    myCourse.setAll("2134", "test", 80, 3);  //code title grade credithour

    cout << myCourse.getCode() << " " <<
         to_string(myCourse.getCreditHour()) << " " <<
         myCourse.getGrade() << " " <<
         myCourse.getTitle();

}
