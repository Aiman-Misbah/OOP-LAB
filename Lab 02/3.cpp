#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Employee
{
    string name;
    int hoursWorked;
    double hourlyRate;
};

int main()
{
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Employee *employees = new Employee[n];
    cout << endl
         << "Input Details: ";
    for (int i = 0; i < n; i++)
    {
        cout << endl
             << endl;
        cout << "Employee " << (i + 1) << ":" << endl;
        cout << "Name: ";
        getline(cin, employees[i].name);
        cout << "Hours Worked: ";
        cin >> employees[i].hoursWorked;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Hourly Rate(in $): ";
        cin >> employees[i].hourlyRate;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    double salary[n];
    for (int i = 0; i < n; i++)
    {
        salary[i] = employees[i].hoursWorked * employees[i].hourlyRate;
    }
    cout << endl
         << endl
         << "Salaries Of Employees: " << endl
         << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Employee " << (i + 1) << ": " << salary[i] << endl;
    }
    delete[] employees;
    cout << endl
         << endl
         << "Memory Cleared Successfully!" << endl
         << endl;
    return 0;
}