#include <iostream>
using namespace std;

class AlarmSystem
{
private:
    string securityLevel;

public:
    AlarmSystem(string securityLevel) : securityLevel(securityLevel) {}

    void display() const
    {
        cout << "Alarm System Security Level: " << securityLevel << endl;
    }
};

class SmartHome
{
private:
    AlarmSystem alarmSystem;

public:
    SmartHome(string securityLevel) : alarmSystem(securityLevel)
    {
        cout << "Smart Home Created With Alarm System!" << endl;
    }

    void display() const
    {
        alarmSystem.display();
    }

    ~SmartHome()
    {
        cout << "Smart Home and its Alarm System are being destroyed! " << endl;
    }
};

int main()
{
    SmartHome home1("High");
    SmartHome home2("Medium");
    SmartHome home3("Low");
    cout << endl;
    cout << "----------Home 1 Details----------" << endl;
    home1.display();
    cout << endl;
    cout << "----------Home 2 Details----------" << endl;
    home2.display();
    cout << endl;
    cout << "----------Home 3 Details----------" << endl;
    home3.display();
    cout << endl;
    return 0;
}
