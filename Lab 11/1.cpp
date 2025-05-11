#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <sstream>

using namespace std;

class DimensionMismatchException : public exception
{
    int rowsA, colsA, rowsB, colsB;
    string message;

public:
    DimensionMismatchException(int rA, int cA, int rB, int cB)
    {
        rowsA = rA;
        colsA = cA;
        rowsB = rB;
        colsB = cB;
        stringstream ss;
        ss << "DimensionMismatchException - Matrices must have same dimensions (" 
           << rowsA << "x" << colsA << " vs " << rowsB << "x" << colsB << ")!";
        message = ss.str();
    }

    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

template <typename T>
class Matrix
{
    vector<vector<T>> values;
    int totalRows, totalCols;

public:
    Matrix(int rows, int cols)
    {
        totalRows = rows;
        totalCols = cols;
        values = vector<vector<T>>(rows, vector<T>(cols));
    }

    void setElement(int row, int col, T element)
    {
        values[row][col] = element;
    }

    T getElement(int row, int col) const
    {
        return values[row][col];
    }

    int getRowCount() const
    {
        return totalRows;
    }

    int getColumnCount() const
    {
        return totalCols;
    }

    Matrix<T> add(const Matrix<T>& other) const
    {
        if (totalRows != other.totalRows || totalCols != other.totalCols)
        {
            throw DimensionMismatchException(totalRows, totalCols, other.totalRows, other.totalCols);
        }

        Matrix<T> result(totalRows, totalCols);

        for (int i = 0; i < totalRows; i++)
        {
            for (int j = 0; j < totalCols; j++)
            {
                result.setElement(i, j, values[i][j] + other.getElement(i, j));
            }
        }

        return result;
    }

    void printMatrix() const
    {
        for (int i = 0; i < totalRows; i++)
        {
            for (int j = 0; j < totalCols; j++)
            {
                cout << values[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    try
    {
        Matrix<int> matrixOfLahoreStudents(2, 2);
        matrixOfLahoreStudents.setElement(0, 0, 4);
        matrixOfLahoreStudents.setElement(0, 1, 5);
        matrixOfLahoreStudents.setElement(1, 0, 6);
        matrixOfLahoreStudents.setElement(1, 1, 7);

        Matrix<int> matrixOfKarachiStudents(3, 3);
        matrixOfKarachiStudents.setElement(0, 0, 1);
        matrixOfKarachiStudents.setElement(0, 1, 2);
        matrixOfKarachiStudents.setElement(0, 2, 3);
        matrixOfKarachiStudents.setElement(1, 0, 4);
        matrixOfKarachiStudents.setElement(1, 1, 5);
        matrixOfKarachiStudents.setElement(1, 2, 6);
        matrixOfKarachiStudents.setElement(2, 0, 7);
        matrixOfKarachiStudents.setElement(2, 1, 8);
        matrixOfKarachiStudents.setElement(2, 2, 9);

        Matrix<int> combinedMatrix = matrixOfLahoreStudents.add(matrixOfKarachiStudents);
        combinedMatrix.printMatrix();
    }
    catch (const DimensionMismatchException& problem)
    {
        cout << problem.what() << endl;
    }

    return 0;
}

