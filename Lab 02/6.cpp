#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Student
{
    string name;
    int rollNum;
    int marks[3];
    int average;
};

int main()
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Student *students = new Student[n];
    cout << endl
         << "Input Student Details: " << endl
         << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Name: ";
        getline(cin, students[i].name);
        cout << "Roll Number: ";
        cin >> students[i].rollNum;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input Marks: " << endl;
        for (int j = 0; j < 3; j++)
        {
            cout << "Subject " << (j + 1) << ": ";
            cin >> students[i].marks[j];
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << endl;
    }

    int sum;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += students[i].marks[j];
        }
        students[i].average = sum / 3;
    }
    cout << endl
         << "Average Marks: " << endl
         << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << (i + 1) << ": " << students[i].average << endl;
    }
    delete[] students;
    cout << endl
         << endl
         << "Memory Cleared Successfully! " << endl
         << endl;
    return 0;
}