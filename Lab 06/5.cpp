#include <iostream>
using namespace std;

class Device
{
private:
    int deviceID;
    bool status;

public:
    Device(int deviceID, bool status) : deviceID(deviceID), status(status) {}

    virtual void displayDetails()
    {
        cout << "ID: " << deviceID << endl;
        cout << "Status (ON or OFF): " << (status ? "ON" : "OFF") << endl;
    }

    virtual ~Device() {}
};

class SmartPhone : virtual public Device
{
protected:
    float screenSize;

public:
    SmartPhone(int deviceID, bool status, float screenSize) : Device(deviceID, status), screenSize(screenSize) {}

    void displayDetails() override
    {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " Inches" << endl;
    }
};

class SmartWatch : virtual public Device
{
protected:
    bool heartRateMonitor;

public:
    SmartWatch(int deviceID, bool status, bool heartRateMonitor) : Device(deviceID, status), heartRateMonitor(heartRateMonitor) {}

    void displayDetails() override
    {
        cout << "Heart Rate Monitor(Availability): " << (heartRateMonitor ? "Available" : "Not Available") << endl;
    }
};

class SmartWearable : public SmartPhone, public SmartWatch
{
private:
    int stepCounter;

public:
    SmartWearable(int deviceID, bool status, float screenSize, bool heartRateMonitor, int stepCounter)
        : Device(deviceID, status), SmartPhone(deviceID, status, screenSize), SmartWatch(deviceID, status, heartRateMonitor), stepCounter(stepCounter) {}

    void displayDetails() override
    {
        SmartPhone::displayDetails();
        SmartWatch::displayDetails();
        cout << "Step Counter: " << stepCounter << " Steps" << endl;
    }
};

int main()
{
    SmartWearable smart(1001, true, 5.5, true, 12345);
    cout << endl;
    cout << "----------Smart Wearable Device-----------" << endl;
    smart.displayDetails();
    cout << endl;
    return 0;
}
