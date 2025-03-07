#include <iostream>
using namespace std;

class Product
{
private:
    int ID;
    string name;
    int quantity;

public:
    Product(int ID = 0, string name = "", int quantity = 0) : ID(ID), name(name), quantity(quantity) {}

    void display() const
    {
        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Quantity: " << quantity << endl
             << endl;
    }

    string getName() const { return name; }
    int getID() const { return ID; }
    int getQuantity() const { return quantity; }
};

void bubbleSort(Product products[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (products[j].getName() > products[j + 1].getName())
            {
                swap(products[j], products[j + 1]);
            }
        }
    }
}

void searchProduct(int id, Product products[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (products[i].getID() == id)
        {
            cout << "Product Found!\n";
            products[i].display();
            return;
        }
    }
    cout << "Product not found!\n";
}

int main()
{
    Product products[3] = {
        Product(101, "Laptop", 5),
        Product(102, "Table", 12),
        Product(103, "Chair", 20)};

    cout << "---------- Products Before Sorting ----------" << endl;
    for (int i = 0; i < 3; i++)
        products[i].display();

    bubbleSort(products, 3);

    cout << "---------- Products After Sorting ----------" << endl;
    for (int i = 0; i < 3; i++)
        products[i].display();

    cout << "---------- Search Product By ID ----------" << endl;
    int searchID;

    cout << "Enter Product ID to search: ";
    while (!(cin >> searchID))
    {
        cout << "Invalid input! Enter a valid product ID: ";
        cin.clear();
        cin.ignore(100, '\n');
    }

    searchProduct(searchID, products, 3);

    return 0;
}

