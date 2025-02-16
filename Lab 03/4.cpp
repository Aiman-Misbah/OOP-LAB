#include <iostream>
using namespace std;

class Car
{
private:
    string brand;
    int model;
    int fuelCapacity;
    double fuelLevel;

public:
    Car(string Brand, int Model, int FuelCapacity)
    {
        brand = Brand;
        model = Model;
        fuelCapacity = FuelCapacity;
        fuelLevel = FuelCapacity;
    }

    void carDrives(int distance) // distance in kilometres
    {
        double fuelLostPerKm = 0.06;
        double fuelConsumption = fuelLostPerKm * distance;
        if (fuelLevel >= fuelConsumption)
        {
            fuelLevel -= fuelConsumption;
            cout << "Distance Travelled(In Km): " << distance << endl;
            cout << "Fuel Consumed(In Litres): " << fuelConsumption << endl;
            cout << "Current Fuel Level(In Litres): " << fuelLevel << endl
                 << endl;
        }
        else
        {
            cout << "Not enough fuel for this trip! Please refuel." << endl
                 << endl;
        }
        checkFuelStatus();
    }

    void checkFuelStatus()
    {
        if (fuelLevel < 5)
        {
            cout << "WARNING, Vehicle Fuel Critically Low!" << endl
                 << endl;
        }
    }
    void refuelCar(double fuel)
    {
        if (fuel > 0)
        {

            if ((fuelLevel + fuel) <= fuelCapacity)
            {
                fuelLevel += fuel;
                cout << "Car Refueled By(In Litres): " << fuel << endl;
                cout << "Current Fuel Level(In Litres): " << fuelLevel << endl
                     << endl;
            }
            else
            {
                fuelLevel = fuelCapacity;
                cout << "Tank is now full!" << endl
                     << endl;
            }
        }
        else
        {
            cout << "Invalid fuel amount!" << endl
                 << endl;
        }
    }
};

int main()
{
    Car Zoya("Toyota Corolla", 2024, 50);
    Zoya.carDrives(200);
    Zoya.refuelCar(25);
    Zoya.carDrives(820);
    Zoya.carDrives(10);
    Zoya.carDrives(10);
    Zoya.refuelCar(-5);
    Zoya.refuelCar(100);
    return 0;
}
