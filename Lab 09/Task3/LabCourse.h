#ifndef LABCOURSE_H
#define LABCOURSE_H

#include "Course.h"
#include <iostream>

class LabCourse : public Course
{
private:
    double labPerformanceScore;

public:
    LabCourse(string code, int c, double score) : Course(code, c), labPerformanceScore(score) {}

    void calculateGrade()
    {
        if (labPerformanceScore >= 80)
        {
            cout << "Grade: A+" << endl;
        }
        else if (labPerformanceScore >= 65)
        {
            cout << "Grade: A" << endl;
        }
        else if (labPerformanceScore >= 45)
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
        cout << "Course Type: Lab Course" << endl;
    }
};

#endif
