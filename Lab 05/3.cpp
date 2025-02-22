#include <iostream>
using namespace std;

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
        cout << "Name: " << endl;
        cout << "Designation: " << endl
             << endl;
    }
    void addProjects(Project *p)
    {
        if(projectCount>0)
        if (projectCount < 3)
        {
            projects[projectCount++] = p;
        }
        else
        {
            cout << "Projects Capacity Full, Cannot Add More Projects";
        }
        else{
            cout<<"Invalid Project Number! "<<endl;
        }
    }
    void displayProjectDetails(){
        for(int i=0;i<projectCount;i++){
            projects[i].displayProjectDetails();
        }
    }
};

class Project
{
private:
    string title;
    string deadline;
    int countEmployees = 0;
    Employee *employees[3];

public:
    Project(string title, string deadline) : title(title), deadline(deadline) {}
    void addEmployee(Employee *e)
    {
        employees[countEmployees++] = e;
    }
    void displayProjectDetails(){

    }
    void displayAllDetails()
    {
        cout << "----------Displaying Project Details---------" << endl;
        cout << "Title: " << title << endl;
        cout << "Deadline: " << deadline << endl;
        cout << "Number Of Employees: " << countEmployees << endl;
        for (int i = 0; i < countEmployees; i++)
        {
            employees[i]->displayEmployeeDetails();
        }
    }
};

int main()
{
    return 0;
}
