#include <iostream>
using namespace std;

class Employee;

class Project
{
private:
    string title;
    string deadline;
    Employee *employees[3];
    int countEmployees = 0;

public:
    Project(string title, string deadline) : title(title), deadline(deadline) {}

    void addEmployee(Employee *employee);

    void displayProjectDetails()
    {
        cout << "Title: " << title << endl;
        cout << "Deadline: " << deadline << endl;
    }

    void displayAllDetails();
};

class Employee
{
private:
    string name;
    string designation;
    Project *projects[3];
    int projectCount = 0;

public:
    Employee(string name, string designation) : name(name), designation(designation) {}

    void displayEmployeeDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Designation: " << designation << endl;
    }

    void addProject(Project *project)
    {
        if (projectCount < 3)
        {
            projects[projectCount++] = project;
        }
        else
        {
            cout << "Cannot Add More Projects, Limit Reached!" << endl;
        }
    }

    void displayProjectDetails()
    {
        cout << "Employee " << name << " is working on the following projects: " << endl;
        for (int i = 0; i < projectCount; i++)
        {
            projects[i]->displayProjectDetails();
        }
    }
};

void Project::addEmployee(Employee *employee)
{
    if (countEmployees < 3)
    {
        employees[countEmployees++] = employee;
        employee->addProject(this);
    }
    else
    {
        cout << "Cannot Add More Employees, Limit Reached!" << endl;
    }
}

void Project::displayAllDetails()
{
    displayProjectDetails();
    cout << "Number Of Employees: " << countEmployees << endl;
    for (int i = 0; i < countEmployees; i++)
    {
        employees[i]->displayEmployeeDetails();
    }
}

int main()
{
    Employee employee1("Aiman", "Game Developer");
    Employee employee2("Urooj", "Data Analyst");

    Project project1("Web Development", "30 June 2025");
    Project project2("AI Development", "30 July 2025");

    project1.addEmployee(&employee1);
    project1.addEmployee(&employee2);
    project2.addEmployee(&employee1);

    cout << "----------Displaying Details Of All Projects-----------" << endl;
    project1.displayAllDetails();
    cout << endl;
    project2.displayAllDetails();
    cout << endl;

    cout << "----------Displaying Details Of All Employees-----------" << endl;
    employee1.displayProjectDetails();
    cout << endl;
    employee2.displayProjectDetails();
    cout << endl;

    return 0;
}
