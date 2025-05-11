#include <iostream>
#include <exception>
#include <string>
using namespace std;

class NegativeStockException : public exception
{
};

class OverCapacityException : public exception
{
};

template <typename T>
class InventoryItem
{
    T stock;
    const T maxCapacity;

public:
    InventoryItem(T initialStock, T maxCap) : stock(initialStock), maxCapacity(maxCap) {}

    void setStock(T newStock)
    {
        if (newStock < 0)
        {
            throw NegativeStockException();
        }
        else if (newStock > maxCapacity)
        {
            throw OverCapacityException();
        }
        stock = newStock;
    }

    T getStock() const
    {
        return stock;
    }
};

int main()
{
    try
    {
        InventoryItem<int> karachiStoreItem(10, 100);
        cout << "Attempting to set stock to -5..." << endl;
        karachiStoreItem.setStock(-5);
    }
    catch (const NegativeStockException& e)
    {
        cout << "Caught NegativeStockException - what(): " << e.what() << endl;
    }

    try
    {
        InventoryItem<int> lahoreStoreItem(50, 100);
        cout << "Attempting to set stock to 120 (max 100)..." << endl;
        lahoreStoreItem.setStock(120);
    }
    catch (const OverCapacityException& e)
    {
        cout << "Caught OverCapacityException - what(): " << e.what() << endl;
    }

    return 0;
}
