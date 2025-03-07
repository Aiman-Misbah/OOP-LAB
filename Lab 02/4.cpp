#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    string *strings = new string[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << (i + 1) << " string: ";
        cin >> strings[i];
    }
    string temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strings[j] > strings[j + 1])
            {
                temp = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = temp;
            }
        }
    }
    cout << endl
         << "Alphabetically Sorted Strings: ";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            cout << strings[i];
        }
        else
        {
            cout << strings[i];
            cout << ", ";
        }
    }
    delete[] strings;
    cout << endl
         << endl
         << "Memory Cleared Successfully!" << endl
         << endl;
    return 0;
}