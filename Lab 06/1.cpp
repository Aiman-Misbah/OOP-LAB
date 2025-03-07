#include <iostream>
using namespace std;

class Employee
{
private:
    string name;
    float salary;

public:
    Employee(string name, float salary)
    {
        this->name = name;
        this->salary = salary;
    }

    virtual void displayDetails() const
    {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }

    string getName() const { return name; }
    float getSalary() const { return salary; }
};

class Manager : public Employee
{
private:
    float bonus;

public:
    Manager(string name, float salary, float bonus) : Employee(name, salary), bonus(bonus) {}

    void displayDetails() const override
    {
        Employee::displayDetails();
        cout << "Bonus: " << bonus << endl;
    }

    float getBonus() const { return bonus; }
};

int main()
{
    Manager manager("Ali", 50000, 10000);
    manager.displayDetails();
    return 0;
}
