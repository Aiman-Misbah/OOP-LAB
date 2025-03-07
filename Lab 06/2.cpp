#include <iostream>
using namespace std;

class Vehicle
{
private:
    string brand;
    int speed;

public:
    Vehicle(string brand, int speed) : brand(brand), speed(speed) {}

    void displayDetails() const
    {
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << " m/s" << endl;
    }
};

class Car : public Vehicle
{
private:
    int seats;

public:
    Car(string brand, int speed, int seats) : Vehicle(brand, speed), seats(seats) {}

    void displayDetails() const
    {
        Vehicle::displayDetails();
        cout << "Seating Capacity: " << seats << " Seats" << endl;
    }
};

class ElectricCar : public Car
{
private:
    int batteryLife;

public:
    ElectricCar(string brand, int speed, int seats, int batteryLife) : Car(brand, speed, seats), batteryLife(batteryLife) {}

    void displayDetails() const
    {
        Car::displayDetails();
        cout << "Battery Life: " << batteryLife << " Hours" << endl;
    }
};

int main()
{
    ElectricCar car("Toyota", 70, 7, 12);
    cout << "----------Details Of Electric Car----------" << endl;
    car.displayDetails();
    cout << endl;
    return 0;
}
