#include <iostream>
using namespace std;

class Car
{
private:
    string registration;
    string *brand;
    string model;
    double *price;
    bool *status;
    double *revenue;
    int days;

public:
    Car(string Registration) : registration(Registration) {}

    void setDetails(string Brand, string Model, double rental, bool Status)
    {
        brand = new string(Brand);
        price = new double(rental);
        model = Model;
        status = new bool(Status);
        revenue = new double(0);
    }

    void resetAvailability()
    {
        *status = true;
    }

    void calculateRevenue(int Days)
    {
        days = Days;
        if (*status == true)
        {
            *status = false;
            *revenue = days * (*price);
        }
    }

    void displayDetails()
    {
        cout << "Brand: " << *brand << endl;
        cout << "Model: " << model << endl;
        cout << "Rental Price: " << *price << endl;
        if (*revenue > 0)
        {
            cout << "Status: Already Rented For " << days << " Days(Not Available To Rent Now)" << endl;
            cout << "Total Revenue Generated: " << *revenue << endl
                 << endl;
            ;
        }
        else
        {
            cout << "Status: Available To Rent Right Now" << endl;
            cout << "Cannot Generate Revenue, The Car has not been rented yet! " << endl
                 << endl;
        }
    }

    ~Car()
    {
        delete brand;
        delete revenue;
        delete status;
        delete price;
        cout << "Car Object Destroyed! " << endl;
    }
};

int main()
{
    Car car1("PKR-2025-ABC");
    Car car2("PKR-2025-XYZ");
    car1.setDetails("Toyota", "Corolla", 25000.0, false);
    car2.setDetails("Honda", "Civic", 28000.0, true);

    car1.calculateRevenue(5);
    car2.calculateRevenue(8);

    cout << "----------Displaying Details----------" << endl;
    cout << "Car 1: " << endl;
    car1.displayDetails();
    cout << "Car 2: " << endl;
    car2.displayDetails();
    return 0;
}
