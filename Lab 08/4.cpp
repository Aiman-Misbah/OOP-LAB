#include <iostream>
#include <string>
using namespace std;

class Car;

class InventoryManager
{
public:
    void updatePrice(Car &car, double newPrice);
    void displayCarDetails(const Car &car);
};

class Car
{
private:
    string model;
    double price;

public:
    Car(string carModel, double carPrice) : model(carModel), price(carPrice) {}

    friend void InventoryManager::updatePrice(Car &car, double newPrice);
    friend void InventoryManager::displayCarDetails(const Car &car);
    friend void comparePrice(const Car &car1, const Car &car2);
};

void InventoryManager::updatePrice(Car &car, double newPrice)
{
    car.price = newPrice;
}

void InventoryManager::displayCarDetails(const Car &car)
{
    cout << "Car Model: " << car.model << ", Price: " << car.price << endl;
}

void comparePrice(const Car &car1, const Car &car2)
{
    if (car1.price > car2.price)
    {
        cout << car1.model << " is more expensive than " << car2.model << endl;
    }
    else if (car1.price < car2.price)
    {
        cout << car2.model << " is more expensive than " << car1.model << endl;
    }
    else
    {
        cout << "Both " << car1.model << " and " << car2.model << " are priced equally." << endl;
    }
}

int main()
{
    Car car1("Toyota Camry", 25000);
    Car car2("Honda Accord", 24000);
    InventoryManager manager;
    manager.displayCarDetails(car1);
    manager.displayCarDetails(car2);
    manager.updatePrice(car1, 26000);
    cout << endl
         << "After updating the price:" << endl;
    manager.displayCarDetails(car1);
    comparePrice(car1, car2);
    cout << endl;
    return 0;
}
