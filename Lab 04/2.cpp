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
    Car(string Brand, string Model, double rental, bool Status)
    {
        brand = Brand;
        price = rental;
        model = Model;
        status = Status;
    }
    void resetAvailability()
    {
        status = true;
    }
    void applyDiscount(int days)
    {
        double discount;
        if (status)
        {
            if (days > 5 && days < 10)
            {
                discount = 0.05 * price;
                price -= discount;
                status = false;
                cout << "Car Rented Successfully For " << days << " Days" << endl;
                cout << "Rental Amount Now: " << price << endl;
                cout << "Discount: " << discount << endl;
            }
            else if (days > 10)
            {
                discount = 0.10 * price;
                price -= discount;
                status = false;
                cout << "Car Rented Successfully For " << days << " Days" << endl;
                cout << "Rental Amount Now: " << price << endl;
                cout << "Discount: " << discount << endl;
            }
            else
            {
                cout << "Invalid Day Number! " << endl;
            }
        }
        else
        {
            cout << "Car is not available for rent! " << endl;
        }
    }
};

int main()
{
    Car car("Toyota", "Corolla", 17892.67, true);
    car.applyDiscount(16);
    return 0;
}

