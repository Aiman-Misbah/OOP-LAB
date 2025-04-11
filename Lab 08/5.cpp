#include <iostream>
using namespace std;

class MatrixHelper;

class Matrix2x2
{
private:
    int matrix[2][2];

public:
    Matrix2x2(int a, int b, int c, int d)
    {
        matrix[0][0] = a;
        matrix[0][1] = b;
        matrix[1][0] = c;
        matrix[1][1] = d;
    }

    friend Matrix2x2 operator+(const Matrix2x2 &m1, const Matrix2x2 &m2);
    friend Matrix2x2 operator-(const Matrix2x2 &m1, const Matrix2x2 &m2);
    friend Matrix2x2 operator*(const Matrix2x2 &m1, const Matrix2x2 &m2);
    friend int determinant(const Matrix2x2 &m);
    friend class MatrixHelper;
    friend ostream &operator<<(ostream &os, const Matrix2x2 &m);
};

Matrix2x2 operator+(const Matrix2x2 &m1, const Matrix2x2 &m2)
{
    return Matrix2x2(
        m1.matrix[0][0] + m2.matrix[0][0], m1.matrix[0][1] + m2.matrix[0][1],
        m1.matrix[1][0] + m2.matrix[1][0], m1.matrix[1][1] + m2.matrix[1][1]);
}

Matrix2x2 operator-(const Matrix2x2 &m1, const Matrix2x2 &m2)
{
    return Matrix2x2(
        m1.matrix[0][0] - m2.matrix[0][0], m1.matrix[0][1] - m2.matrix[0][1],
        m1.matrix[1][0] - m2.matrix[1][0], m1.matrix[1][1] - m2.matrix[1][1]);
}

Matrix2x2 operator*(const Matrix2x2 &m1, const Matrix2x2 &m2)
{
    return Matrix2x2(
        m1.matrix[0][0] * m2.matrix[0][0] + m1.matrix[0][1] * m2.matrix[1][0],
        m1.matrix[0][0] * m2.matrix[0][1] + m1.matrix[0][1] * m2.matrix[1][1],
        m1.matrix[1][0] * m2.matrix[0][0] + m1.matrix[1][1] * m2.matrix[1][0],
        m1.matrix[1][0] * m2.matrix[0][1] + m1.matrix[1][1] * m2.matrix[1][1]);
}

int determinant(const Matrix2x2 &m)
{
    return m.matrix[0][0] * m.matrix[1][1] - m.matrix[0][1] * m.matrix[1][0];
}

class MatrixHelper
{
public:
    void updateElement(Matrix2x2 &m, int row, int col, int newValue)
    {
        m.matrix[row][col] = newValue;
    }
};

ostream &operator<<(ostream &os, const Matrix2x2 &m)
{
    os << "[" << m.matrix[0][0] << " " << m.matrix[0][1] << "]" << endl;
    os << "[" << m.matrix[1][0] << " " << m.matrix[1][1] << "]";
    return os;
}

int main()
{
    Matrix2x2 matrix1(1, 2, 3, 4);
    Matrix2x2 matrix2(5, 6, 7, 8);
    MatrixHelper helper;
    cout << "Matrix 1: " << endl
         << matrix1 << endl
         << endl;
    cout << "Matrix 2: " << endl
         << matrix2 << endl
         << endl;
    Matrix2x2 sum = matrix1 + matrix2;
    Matrix2x2 diff = matrix1 - matrix2;
    Matrix2x2 product = matrix1 * matrix2;
    cout << "Matrix1 + Matrix2: " << endl
         << sum << endl
         << endl;
    cout << "Matrix1 - Matrix2: " << endl
         << diff << endl
         << endl;
    cout << "Matrix1 * Matrix2: " << endl
         << product << endl
         << endl;
    cout << "Determinant of Matrix 1: " << determinant(matrix1) << endl
         << endl;
    helper.updateElement(matrix1, 0, 1, 9);
    cout << "Matrix 1 after updating element (0,1): " << endl
         << matrix1 << endl
         << endl;
    return 0;
}
