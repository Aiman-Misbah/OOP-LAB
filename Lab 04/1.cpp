#include <iostream>
using namespace std;

class Car
{
private:
    string brand;
    string model;
    double price;
    bool status;

public:
    Car()
    {
        brand = "Unknown";
        model = "Generic";
        price = 0.0;
        status = true;
    }
    void updateDetails(string Brand, string Model, bool Status)
    {
        brand = Brand;
        model = Model;
        status = Status;
    }
    void resetAvailability()
    {
        status = true;
    }
    void rentalRequest(double rental)
    {
        if (rental > 0)
        {
            if (status)
            {
                price = rental;
                status = false;
                cout << "Rental Request Processed Successfully! " << endl;
            }
            else
            {
                cout << "The car is already rented(Not Available)!" << endl;
            }
        }
        else
        {
            cout << "Please enter a valid rental amount" << endl;
        }
    }
    void displayDetails()
    {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        if (status)
        {
            cout << "Status: Available To Rent" << endl;
        }
        else
        {
            cout << "Status: Unavailable To Rent Now" << endl;
        }
    }
};

int main()
{
    Car car;
    car.updateDetails("Toytota", "New", true);
    car.rentalRequest(1456.00);
    cout << "----------Displaying Car Details----------" << endl;
    car.displayDetails();
}

