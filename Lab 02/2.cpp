#include <iostream>
using namespace std;

int main()
{
    int rows1, cols1, rows2, cols2;
    int rows, cols;
    cout << "Enter the rows of the first matrix: ";
    cin >> rows1;
    cout << "Enter the cols of the first matrix: ";
    cin >> cols1;
    cout << "Enter the rows of the second matrix: ";
    cin >> rows2;
    cout << "Enter the rows of the second matrix: ";
    cin >> rows2;

    if (rows1 != rows2 && cols1 != cols2)
    {
        cout << "Matrices Of Different Order Cannot Be Added Or Subtracted!";
    }
    else
    {
        rows = rows1;
        cols = cols1;

        int **matrix1 = new int *[rows];
        int **matrix2 = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix1[i] = new int[cols];
            matrix2[i] = new int[cols];
        }
        cout << endl
             << endl
             << "Input Details For Matrix 1: " << endl
             << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << "Enter the " << ((i * cols) + j) << " element: ";
                cin >> matrix1[i][j];
            }
        }
        cout << endl
             << endl
             << "Input Details For Matrix 2: " << endl
             << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << "Enter the " << ((i * cols) + j) << " element: ";
                cin >> matrix2[i][j];
            }
        }
        int **result = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            result[i] = new int[cols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        cout << endl
             << endl
             << "Sum Of The Matrices: " << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
        cout << endl
             << endl
             << "Difference Of The Matrices: " << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < rows; i++)
        {
            delete[] matrix1[i];
            delete[] matrix2[i];
            delete[] result[i];
        }

        delete[] matrix1;
        delete[] matrix2;
        delete[] result;
        cout << endl
             << endl
             << "Memory Cleared Successfully!" << endl
             << endl;
    }
    return 0;
}