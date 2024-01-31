#include <iostream>
//#include "node.h"
//#include "LinkedList.h"
#include "Student.h"
#include "Course.h"
#include "import.h"
#include "Records.h"
using namespace std;
int main() {
    Course myCourse;
    Student<Course> myStudent;
    myCourse.setAll("1134", "test course", 90, 19);
    myStudent.addCourse(myCourse);
    myStudent.setNumberOfCourses(1);
    myStudent.setTotalCreditHour(40);
    myStudent.setGpa(4);

    cout << " " <<
         to_string(myStudent.getGpa()) << " " <<
         myStudent.getNumberOfCourses() << " " <<
         myStudent.getTotalCreditHour() << " " <<
         myStudent.getUid();

}
