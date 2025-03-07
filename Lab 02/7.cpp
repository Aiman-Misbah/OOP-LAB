#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int rows1, cols1, rows2, cols2;
    cout << "Enter the dimensions of the first matrix: ";
    cin >> rows1 >> cols1;
    cout << "Enter the dimensions of the second matrix: ";
    cin >> rows2 >> cols2;
    if (cols1 != rows2)
    {
        cout << "Matrix Multiplication Is Not Possible!";
        return 1;
    }
    int rows3 = rows1;
    int cols3 = cols2;
    int **matrix1 = new int *[rows1];
    int **matrix2 = new int *[rows2];
    int **product = new int *[rows3];
    for (int i = 0; i < rows1; i++)
    {
        matrix1[i] = new int[cols1];
    }
    for (int i = 0; i < rows2; i++)
    {
        matrix2[i] = new int[cols2];
    }
    for (int i = 0; i < rows3; i++)
    {
        product[i] = new int[cols3];
    }
    cout << endl
         << "Input Elements For Matrix 1" << endl;
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            cout << "Element " << "[" << i << "]" << "[" << j << "]: ";
            cin >> *(*(matrix1 + i) + j);
        }
    }
    cout << endl
         << endl
         << "Input Elements For Matrix 2" << endl;
    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            cout << "Element " << "[" << i << "]" << "[" << j << "]: ";
            cin >> *(*(matrix2 + i) + j);
        }
    }
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            *(*(product + i) + j) = 0;
            for (int k = 0; k < cols1; k++)
            {
                *(*(product + i) + j) += *(*(matrix1 + i) + k) * (*(*(matrix2 + k) + j));
            }
        }
    }
    cout << endl
         << "Product Of The Two Matrices: " << endl;
    for (int i = 0; i < rows3; i++)
    {
        for (int j = 0; j < cols3; j++)
        {
            cout << *(*(product + i) + j) << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < rows1; i++)
    {
        delete[] matrix1[i];
    }
    delete[] matrix1;

    for (int i = 0; i < rows2; i++)
    {
        delete[] matrix2[i];
    }
    delete[] matrix2;

    for (int i = 0; i < rows3; i++)
    {
        delete[] product[i];
    }
    delete[] product;

    cout << endl
         << endl
         << "Memory Cleared Successfully!" << endl
         << endl;
    return 0;
}