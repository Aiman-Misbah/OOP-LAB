#include <iostream>
using namespace std;

class Student
{
private:
    int ID;
    string name;
    int *examScores;

public:
    Student(int ID, string name, int examScores[]) : ID(ID), name(name)
    {
        this->examScores = new int[5];
        for (int i = 0; i < 5; i++)
        {
            this->examScores[i] = examScores[i];
        }
    }

    Student(const Student &student)
    {
        ID = student.ID;
        name = student.name;
        examScores = new int[5];
        for (int i = 0; i < 5; i++)
        {
            examScores[i] = student.examScores[i];
        }
    }

    ~Student()
    {
        delete[] examScores;
    }

    void displayDetails()
    {
        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Exam Scores: " << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << (i + 1) << ". " << examScores[i] << endl;
        }
    }
};

int main()
{
    int scores[5] = {80, 78, 90, 64, 50};
    Student student1(100, "Ayesha", scores);
    Student student2 = student1;
    cout << "----------Student 1--------" << endl;
    student1.displayDetails();
    cout << endl;
    cout << "----------Student 2--------" << endl;
    student2.displayDetails();
    cout << endl;
    return 0;
}

