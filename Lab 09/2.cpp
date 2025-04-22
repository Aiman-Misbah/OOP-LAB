#include <iostream>
using namespace std;

class MenuItem
{
protected:
    string dishName;
    double price;

public:
    MenuItem(string name, double p)
    {
        dishName = name;
        price = p;
    }

    virtual void showDetails() = 0;
    virtual void prepare() = 0;
};

class Appetizer : public MenuItem
{
public:
    Appetizer(string name, double p) : MenuItem(name, p) {}

    void showDetails()
    {
        cout << "Appetizer: " << dishName << endl;
        cout << "Price: $" << price << endl;
    }

    void prepare()
    {
        cout << "Preparing " << dishName << ":" << endl;
        cout << "- Chop fresh vegetables" << endl;
        cout << "- Mix with dressing" << endl;
        cout << "- Serve chilled on platter" << endl;
    }
};

class MainCourse : public MenuItem
{
public:
    MainCourse(string name, double p) : MenuItem(name, p) {}

    void showDetails()
    {
        cout << "Main Course: " << dishName << endl;
        cout << "Price: $" << price << endl;
    }

    void prepare()
    {
        cout << "Preparing " << dishName << ":" << endl;
        cout << "- Marinate meat for 2 hours" << endl;
        cout << "- Cook in oven at 180°C for 45 minutes" << endl;
        cout << "- Garnish with herbs and serve hot" << endl;
    }
};

int main()
{
    MenuItem *item1 = new Appetizer("Stuffed Mushrooms", 550.00);
    MenuItem *item2 = new MainCourse("Grilled Salmon with Asparagus", 2200.00);

    cout << "=== Restaurant Menu System ===" << endl
         << endl;

    item1->showDetails();
    item1->prepare();

    cout << endl
         << "---------------------------" << endl
         << endl;

    item2->showDetails();
    item2->prepare();

    delete item1;
    delete item2;

    return 0;
}
