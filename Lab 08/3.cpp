#include <iostream>
using namespace std;

class Vector2D
{
private:
    double x, y;

public:
    Vector2D(double xVal, double yVal) : x(xVal), y(yVal) {}

    friend double dotProduct(const Vector2D &v1, const Vector2D &v2);

    Vector2D operator+(const Vector2D &other)
    {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D &other)
    {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(double scalar)
    {
        return Vector2D(x * scalar, y * scalar);
    }

    friend ostream &operator<<(ostream &out, const Vector2D &v)
    {
        out << "(" << v.x << ", " << v.y << ")";
        return out;
    }
};

double dotProduct(const Vector2D &v1, const Vector2D &v2)
{
    return (v1.x * v2.x + v1.y * v2.y);
}

int main()
{
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);
    cout << "Vector 1: " << v1 << endl;
    cout << "Vector 2: " << v2 << endl;
    Vector2D sum = v1 + v2;
    Vector2D diff = v1 - v2;
    Vector2D scaled = v1 * 2;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Scaled by 2: " << scaled << endl;
    double dotProd = dotProduct(v1, v2);
    cout << "Dot Product: " << dotProd << endl;
    return 0;
}
