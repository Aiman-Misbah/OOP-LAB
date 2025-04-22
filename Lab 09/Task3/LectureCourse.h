#ifndef LECTURECOURSE_H
#define LECTURECOURSE_H

#include "Course.h"
#include <iostream>

class LectureCourse : public Course
{
private:
    double examScore;

public:
    LectureCourse(string code, int c, double score) : Course(code, c), examScore(score) {}

    void calculateGrade()
    {
        if (examScore >= 85)
        {
            cout << "Grade: A+" << endl;
        }
        else if (examScore >= 70)
        {
            cout << "Grade: A" << endl;
        }
        else if (examScore >= 50)
        {
            cout << "Grade: B" << endl;
        }
        else
        {
            cout << "Grade: F" << endl;
        }
    }

    void displayInfo()
    {
        cout << "Course Code: " << courseCode << endl;
        cout << "Credits: " << credits << endl;
        cout << "Course Type: Lecture Course" << endl;
    }
};

#endif
