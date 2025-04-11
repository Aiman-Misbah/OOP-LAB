#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumber
{
private:
    double realPart;
    double imaginaryPart;

public:
    ComplexNumber()
    {
        realPart = 0;
        imaginaryPart = 0;
    }

    ComplexNumber(double real, double imaginary)
    {
        realPart = real;
        imaginaryPart = imaginary;
    }

    ComplexNumber operator+(const ComplexNumber &other)
    {
        return ComplexNumber(
            realPart + other.realPart,
            imaginaryPart + other.imaginaryPart);
    }

    ComplexNumber operator-(const ComplexNumber &other)
    {
        return ComplexNumber(
            realPart - other.realPart,
            imaginaryPart - other.imaginaryPart);
    }

    ComplexNumber operator*(const ComplexNumber &other)
    {
        double resultReal = (realPart * other.realPart) - (imaginaryPart * other.imaginaryPart);
        double resultImaginary = (realPart * other.imaginaryPart) + (imaginaryPart * other.realPart);
        return ComplexNumber(resultReal, resultImaginary);
    }

    ComplexNumber operator/(const ComplexNumber &other)
    {
        double denominator = (other.realPart * other.realPart) + (other.imaginaryPart * other.imaginaryPart);

        double resultReal = ((realPart * other.realPart) + (imaginaryPart * other.imaginaryPart)) / denominator;
        double resultImaginary = ((imaginaryPart * other.realPart) - (realPart * other.imaginaryPart)) / denominator;

        return ComplexNumber(resultReal, resultImaginary);
    }

    friend double magnitude(const ComplexNumber &number);

    friend ostream &operator<<(ostream &output, const ComplexNumber &number)
    {
        output << "(" << number.realPart;

        if (number.imaginaryPart >= 0)
            output << " + " << number.imaginaryPart << "i)";
        else
            output << " - " << fabs(number.imaginaryPart) << "i)";

        return output;
    }
};

double magnitude(const ComplexNumber &number)
{
    return sqrt((number.realPart * number.realPart) + (number.imaginaryPart * number.imaginaryPart));
}

int main()
{
    ComplexNumber firstNumber(3, 4);
    ComplexNumber secondNumber(1, -2);
    ComplexNumber sum = firstNumber + secondNumber;
    ComplexNumber difference = firstNumber - secondNumber;
    ComplexNumber product = firstNumber * secondNumber;
    ComplexNumber quotient = firstNumber / secondNumber;
    cout << "First Number:        " << firstNumber << endl;
    cout << "Second Number:       " << secondNumber << endl;
    cout << endl;
    cout << "Sum:                 " << sum << endl;
    cout << "Difference:          " << difference << endl;
    cout << "Product:             " << product << endl;
    cout << "Quotient:            " << quotient << endl;
    cout << endl;
    cout << "Magnitude of First:  " << magnitude(firstNumber) << endl;
    cout << "Magnitude of Second: " << magnitude(secondNumber) << endl
         << endl;
    return 0;
}

