#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}

    virtual void displayDetails() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Teacher : virtual public Person
{
protected:
    string subject;

public:
    Teacher(string name, int age, string subject) : Person(name, age), subject(subject) {}

    void displayDetails() const override
    {
        Person::displayDetails();
        cout << "Subject Expertise: " << subject << endl;
    }
};

class Researcher : virtual public Person
{
protected:
    string researchArea;

public:
    Researcher(string name, int age, string researchArea) : Person(name, age), researchArea(researchArea) {}

    void displayDetails() const override
    {
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor : public Teacher, public Researcher
{
private:
    int publications;

public:
    Professor(string name, int age, string subject, string researchArea, int publications)
        : Person(name, age), Teacher(name, age, subject), Researcher(name, age, researchArea), publications(publications) {}

    void displayDetails() const override
    {
        Teacher::displayDetails();
        Researcher::displayDetails();
        cout << "Publications: " << publications << " Papers" << endl;
    }
};

int main()
{
    Professor professor("Professor Leonard", 52, "Multivariable Calculus", "Level Curves", 37);
    cout << endl;
    cout << "----------Details Of Professor Leonard---------" << endl;
    professor.displayDetails();
    cout << endl;
    return 0;
}
