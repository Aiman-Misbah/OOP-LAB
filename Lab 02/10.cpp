#include <iostream>
using namespace std;

int main()
{
    int depth, rows, cols;
    cout << "Enter the depth of the 3D Array: ";
    cin >> depth;
    cout << "Enter the rows of the 3D Array: ";
    cin >> rows;
    cout << "Enter the columns of the 3D Array: ";
    cin >> cols;
    int ***array = new int **[depth];
    for (int i = 0; i < depth; i++)
    {
        array[i] = new int *[rows];
        for (int j = 0; j < rows; j++)
        {
            array[i][j] = new int[cols];
        }
    }
    for (int i = 0; i < depth; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            for (int k = 0; k < cols; k++)
            {
                cout << "Enter Element " << ((i * rows * cols) + (j * cols) + k) << ": ";
                cin >> array[i][j][k];
            }
        }
    }
    cout << endl;
    for (int i = 0; i < depth; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            for (int k = 0; k < cols; k++)
            {
                cout << "Element " << ((i * rows * cols) + (j * cols) + k) << ": " << array[i][j][k] << endl;
            }
        }
    }
    for (int i = 0; i < depth; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete[] array;
    cout << endl
         << endl
         << "Memory Cleared Succesfully!" << endl
         << endl;
    return 0;
}