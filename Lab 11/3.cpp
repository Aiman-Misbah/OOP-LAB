#include <iostream>
#include <exception>
using namespace std;

class InvalidTemperatureException : public exception
{
};

template <typename T>
double convertToFahrenheit(T celsius)
{
    if (celsius < -273.15)
    {
        throw InvalidTemperatureException();
    }

    return (celsius * 9.0 / 5.0) + 32.0;
}

int main()
{
    try
    {
        double lahoreMorningTemperature = -300;
        cout << "Attempting to convert " << lahoreMorningTemperature << "C..." << endl;
        double result = convertToFahrenheit(lahoreMorningTemperature);
        cout << "Result in Fahrenheit: " << result << endl;
    }
    catch (const InvalidTemperatureException& e)
    {
        cout << "Caught InvalidTemperatureException - what(): " << e.what() << endl;
    }

    return 0;
}
