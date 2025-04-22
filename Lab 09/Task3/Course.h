#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course
{
protected:
    string courseCode;
    int credits;

public:
    Course(string code, int c) : courseCode(code), credits(c) {}
    virtual void calculateGrade() = 0; // Pure virtual function
    virtual void displayInfo() = 0;    // Pure virtual function
    virtual ~Course() {}
};

#endif

