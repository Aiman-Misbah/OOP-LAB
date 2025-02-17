#include <iostream>
using namespace std;

class Car
{
private:
    string *brand;
    string model;
    bool *status;
    double *revenue;

public:
    Car(string Brand, string Model, bool Status)
    {
        brand = new string(Brand);
        model = Model;
        status = new bool(Status);
        revenue = new double(0);
        cout << "Car Object Created! " << endl;
    }

    void calculateRevenue(int days, double price)
    {
        if (*this->status == true)
        {
            *this->status = false;
            *this->revenue = days * price;
            cout << "Total Revenue" << "(For " << days << " days): " << *this->revenue << endl;
        }
        else
        {
            cout << "Cannot generate Revenue, The car is not available to rent! " << endl;
        }
    }
    void resetAvailability()
    {
        *this->status = true;
        *this->revenue = 0;
    }
    ~Car()
    {
        delete brand;
        delete revenue;
        delete status;
        cout << "Car Object Destroyed! " << endl;
    }
};

int main()
{
    Car *car1 = new Car("Ford", "Mustang", true);
    car1->calculateRevenue(5, 15.66);
    delete car1;
    return 0;
}

