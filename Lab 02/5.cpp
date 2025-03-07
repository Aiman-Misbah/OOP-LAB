#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of integers: ";
    cin >> n;
    int *array = new int[n];
    int *ptr = array;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << (i + 1) << " Element: ";
        cin >> array[i];
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << (i + 1) << ": " << *(ptr + i) << endl;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *(ptr + i);
    }
    cout << endl
         << "Sum Of The Array: " << sum;
    delete[] array;
    cout << endl
         << endl
         << "Memory Cleared Successfully! " << endl
         << endl;
    return 0;
}