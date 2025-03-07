#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int **array = new int *[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = new int;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Integer " << (i + 1) << ": ";
        cin >> *array[i];
    }
    cout << endl;
    cout << "Array Of Pointers To Integers: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Integer " << (i + 1) << ": " << *array[i] << endl;
    }
    for (int i = 0; i < n; i++)
    {
        delete array[i];
    }
    delete[] array;
    cout << endl
         << endl
         << "Memory Cleared Successfully!" << endl
         << endl;
    return 0;
}