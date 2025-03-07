#include <iostream>
#include <limits>
using namespace std;

struct Product
{
    int ID;
    string name;
    int quantity;
    double price;
    double value;
};

int main()
{
    int n;
    cout << "Enter the number of products: ";
    cin >> n;
    Product *products = new Product[n];
    cout << endl
         << "Input Product Details: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Product " << (i + 1) << " :" << endl;
        cout << "ID: ";
        cin >> products[i].ID;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Name: ";
        getline(cin, products[i].name);
        cout << "Quantity: ";
        cin >> products[i].quantity;
        cout << "Price(In $): ";
        cin >> products[i].price;
        cout << endl;
    }
    double totalInventoryValue = 0;
    for (int i = 0; i < n; i++)
    {
        products[i].value = products[i].quantity * products[i].price;
        totalInventoryValue += products[i].value;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Inventory For Product " << (i + 1) << ": " << products[i].value << endl;
    }
    cout << "Total Value of the Inventory: $" << totalInventoryValue << endl;
    delete[] products;
    cout << endl
         << endl
         << "Memory Cleared Succesfully" << endl
         << endl;
    return 0;
}