#include <iostream>
using namespace std;

class Apartment
{
private:
    int ID;
    string address;
    string *ownerName;

public:
    Apartment(int ID, string address, string ownerName) : ID(ID), address(address)
    {
        this->ownerName = new string(ownerName);
    }

    Apartment(const Apartment &apartment)
    {
        ID = apartment.ID;
        address = apartment.address;
        ownerName = new string(*(apartment.ownerName));
    }

    ~Apartment()
    {
        delete ownerName;
    }

    void displayDetails() const
    {
        cout << "ID: " << ID << endl;
        cout << "Address: " << address << endl;
        cout << "Owner Name: " << *ownerName << endl;
    }
};

int main()
{
    Apartment apartment1(1011, "123 Main St", "John Doe");
    cout << "----------Original Apartment--------" << endl;
    apartment1.displayDetails();
    cout << endl;
    Apartment apartment2 = apartment1;
    cout << "----------Copied Apartment----------" << endl;
    apartment2.displayDetails();
    cout << endl;
    return 0;
}

