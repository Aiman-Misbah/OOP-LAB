#include <iostream>
using namespace std;

class Car
{
private:
    string *brand;
    string model;
    double *price;
    bool *status;

public:
    Car(string Brand, string Model, double rental, bool Status)
    {
        brand = new string(Brand);
        price = new double(rental);
        model = Model;
        status = new bool(Status);
        cout << "Car Object Created! " << endl;
    }

    Car(const Car &obj1)
    {
        brand = new string(*obj1.brand);
        price = new double(*obj1.price);
        model = obj1.model;
        status = new bool(*obj1.status);
    }

    void modifyDetails(string Brand, string Model, double rental, bool Status)
    {
        *brand = Brand;
        *price = rental;
        model = Model;
        *status = Status;
    }
    void resetAvailability()
    {
        *status = true;
    }

    void displayDetails()
    {
        cout << "Brand: " << *brand << endl;
        cout << "Model: " << model << endl;
        cout << "Price: " << *price << endl;
        cout << "Status: " << *status << endl
             << endl;
    }

    ~Car()
    {
        delete brand;
        delete price;
        delete status;
        cout << "Car Object Destroyed! " << endl;
    }
};

int main()
{
    Car car1("Toyota", "Corolla", 17892.67, true);
    Car car2 = car1;
    cout << "----------Original Car Details---------" << endl;
    cout << "Car 1: " << endl;
    car1.displayDetails();
    cout << "Car 2: " << endl;
    car2.displayDetails();
    car1.modifyDetails("Honda", "Civic", 60.0, false);
    cout << "----------Modified Car Details----------" << endl;
    cout << "Car 1: " << endl;
    car1.displayDetails();
    cout << "Car 2: " << endl;
    car2.displayDetails();
    cout << endl;

    cout << "Using Dynamic Memory Allocation: " << endl;
    Car *car3 = new Car("Ford", "Mustang", 150.0, true);
    Car *car4 = new Car(*car3);
    cout << "----------Original Car Details---------" << endl;
    cout << "Car 1: " << endl;
    car3->displayDetails();
    cout << "Car 2: " << endl;
    car3->displayDetails();
    car3->modifyDetails("Honda", "Civic", 60.0, false);
    cout << "----------Modified Car Details----------" << endl;
    cout << "Car 3(Dynamic): " << endl;
    car3->displayDetails();
    cout << "Car 4(Dynamic): " << endl;
    car4->displayDetails();
    cout << endl;

    delete car3;
    delete car4;

    return 0;
}

