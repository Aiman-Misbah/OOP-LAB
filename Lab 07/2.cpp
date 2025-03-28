#include <iostream>
#include <string>
using namespace std;

class Product
{
protected:
    int productID;
    string productName;
    double price;
    int stockQuantity;

public:
    Product(int id, string name, double p, int stock = 0)
        : productID(id), productName(name), price(p), stockQuantity(stock) {}

    virtual void applyDiscount(double percentage)
    {
        price -= price * (percentage / 100);
    }

    virtual double calculateTotalPrice(int quantity)
    {
        return price * quantity;
    }

    virtual void displayProductInfo() const
    {
        cout << "Product ID: " << productID << endl;
        cout << "Name: " << productName << endl;
        cout << "Price: $" << price << endl;
        cout << "Stock: " << stockQuantity << " units" << endl;
    }

    friend Product operator+(const Product &p1, const Product &p2)
    {
        return Product(0, "Bulk Purchase", p1.price + p2.price);
    }

    friend ostream &operator<<(ostream &out, const Product &p)
    {
        out << "Product: " << p.productName << " | Price: $" << p.price << endl;
        return out;
    }

    virtual ~Product() {}
};

class Electronics : public Product
{
private:
    int warrantyPeriod;
    string brand;

public:
    Electronics(int id, string name, double p, int stock, int warranty, string b)
        : Product(id, name, p, stock), warrantyPeriod(warranty), brand(b) {}

    void displayProductInfo() const override
    {
        Product::displayProductInfo();
        cout << "Brand: " << brand << endl;
        cout << "Warranty: " << warrantyPeriod << " years" << endl;
    }
};

class Clothing : public Product
{
private:
    string size;
    string color;
    string fabricMaterial;

public:
    Clothing(int id, string name, double p, int stock, string s, string c, string fabric)
        : Product(id, name, p, stock), size(s), color(c), fabricMaterial(fabric) {}

    void applyDiscount(double percentage) override
    {
        price -= price * (percentage / 100);
    }
};

class FoodItem : public Product
{
private:
    string expirationDate;
    int calories;

public:
    FoodItem(int id, string name, double p, int stock, string exp, int cal)
        : Product(id, name, p, stock), expirationDate(exp), calories(cal) {}

    double calculateTotalPrice(int quantity) override
    {
        double total = price * quantity;
        if (quantity > 10)
            total *= 0.9;
        return total;
    }
};

class Book : public Product
{
private:
    string author;
    string genre;

public:
    Book(int id, string name, double p, int stock, string a, string g)
        : Product(id, name, p, stock), author(a), genre(g) {}

    void displayProductInfo() const override
    {
        Product::displayProductInfo();
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
    }
};

int main()
{
    Electronics phone(101, "Smartphone", 1200.0, 10, 1, "GadgetPro");
    Clothing hoodie(202, "Winter Hoodie", 45.0, 30, "L", "Black", "Fleece");
    FoodItem chocolate(303, "Dark Chocolate", 3.5, 200, "2024-12-15", 250);
    Book novel(404, "Mystery Thriller", 18.0, 15, "Jane Doe", "Thriller");

    phone.displayProductInfo();
    hoodie.applyDiscount(15);
    cout << endl;
    cout << hoodie;
    cout << endl;
    cout << "Total Price for 15 chocolates: $" << chocolate.calculateTotalPrice(15) << endl
         << endl;
    novel.displayProductInfo();

    Product bulkDeal = phone + hoodie;
    cout << endl;
    cout << bulkDeal;
    cout << endl;
    return 0;
}
