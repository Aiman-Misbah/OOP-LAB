#include <iostream>
#include "LectureCourse.h"
#include "LabCourse.h"

using namespace std;

int main()
{
    Course *course1 = new LectureCourse("CS101", 3, 88.5); // Lecture Course
    Course *course2 = new LabCourse("BIO101", 4, 72.0);    // Lab Course

    cout << "=== University Course Management ===" << endl
         << endl;

    cout << "=== Course 1 ===" << endl;
    course1->displayInfo();
    course1->calculateGrade();

    cout << endl
         << "---------------------------" << endl
         << endl;

    cout << "=== Course 2 ===" << endl
         << endl;
    course2->displayInfo();
    course2->calculateGrade();

    delete course1;
    delete course2;

    return 0;
}
