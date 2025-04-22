#include <iostream>
using namespace std;

class WeatherSensor
{
public:
    virtual void readData() = 0;
    virtual void displayReport() = 0;
    virtual ~WeatherSensor() {}
};

class Thermometer : public WeatherSensor
{
private:
    float temperature;

public:
    void readData() override
    {
        temperature = 25.6;
    }

    void displayReport() override
    {
        cout << "Thermometer Report: " << endl;
        cout << "Temperature: " << temperature << " °C" << endl;
    }
};

class Barometer : public WeatherSensor
{
private:
    float pressure;

public:
    void readData() override
    {
        pressure = 1012.5;
    }

    void displayReport() override
    {
        cout << "Barometer Report: " << endl;
        cout << "Pressure: " << pressure << " hPa" << endl;
    }
};

int main()
{
    Thermometer thermometer;
    Barometer barometer;

    WeatherSensor *sensors[2];
    sensors[0] = &thermometer;
    sensors[1] = &barometer;

    for (int i = 0; i < 2; i++)
    {
        sensors[i]->readData();
    }

    for (int i = 0; i < 2; i++)
    {
        sensors[i]->displayReport();
    }

    return 0;
}
