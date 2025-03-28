#include <iostream>
#include <string>
using namespace std;

class Device
{
protected:
    int deviceID;
    string deviceName;
    bool status;
    string location;

public:
    Device(int id, string name, string loc = "Unknown")
        : deviceID(id), deviceName(name), location(loc), status(false) {}

    virtual void turnOn()
    {
        status = true;
        cout << deviceName << " is now ON" << endl;
    }

    virtual void turnOff()
    {
        status = false;
        cout << deviceName << " is now OFF" << endl;
    }

    virtual void getStatus() const
    {
        cout << deviceName << " is currently " << (status ? "ON" : "OFF") << endl;
    }

    virtual void displayInfo() const
    {
        cout << "Device ID: " << deviceID << "\n";
        cout << "Name: " << deviceName << "\n";
        cout << "Status: " << (status ? "ON" : "OFF") << endl;
        cout << "Location: " << location << endl;
    }

    virtual ~Device() {}
};

class Light : public Device
{
private:
    int brightnessLevel;
    string colorMode;

public:
    Light(int id, string name, string loc, int brightness, string color)
        : Device(id, name, loc), brightnessLevel(brightness), colorMode(color) {}

    void displayInfo() const override
    {
        Device::displayInfo();
        cout << "Brightness Level: " << brightnessLevel << endl;
        cout << "Color Mode: " << colorMode << endl;
    }
};

class Thermostat : public Device
{
private:
    float temperature;
    string mode;
    float targetTemperature;

public:
    Thermostat(int id, string name, string loc, float temp, string mod, float targetTemp)
        : Device(id, name, loc), temperature(temp), mode(mod), targetTemperature(targetTemp) {}

    void getStatus() const override
    {
        cout << deviceName << " is set to " << mode << " mode" << endl;
        cout << "Current Temperature: " << temperature << " Celsius" << endl;
        cout << "Target Temperature: " << targetTemperature << " Celsius" << endl;
    }
};

class SecurityCamera : public Device
{
private:
    string resolution;
    bool recordingStatus;
    bool nightVisionEnabled;

public:
    SecurityCamera(int id, string name, string loc, string res, bool nightVision)
        : Device(id, name, loc), resolution(res), nightVisionEnabled(nightVision), recordingStatus(false) {}

    void turnOn() override
    {
        recordingStatus = true;
        Device::turnOn();
        cout << "Recording started at " << resolution << " resolution" << endl;
    }

    void turnOff() override
    {
        recordingStatus = false;
        Device::turnOff();
        cout << "Recording stopped." << endl;
    }
};

class SmartPlug : public Device
{
private:
    float powerConsumption;
    int timerSetting;

public:
    SmartPlug(int id, string name, string loc, float power, int timer)
        : Device(id, name, loc), powerConsumption(power), timerSetting(timer) {}

    void turnOff() override
    {
        Device::turnOff();
        cout << "Power usage logged: " << powerConsumption << " kWh" << endl;
    }
};

int main()
{
    Light kitchenLight(10, "Kitchen Light", "Kitchen", 80, "Cool White");
    Thermostat officeThermostat(20, "Office Thermostat", "Office", 21.0, "Heating", 23.0);
    SecurityCamera backyardCamera(30, "Backyard Camera", "Garden", "4K", false);
    SmartPlug tvPlug(40, "TV Plug", "Living Room", 2.2, 60);

    kitchenLight.turnOn();
    cout << endl;
    kitchenLight.displayInfo();
    cout << endl;

    officeThermostat.getStatus();
    cout << endl;

    backyardCamera.turnOn();
    cout << endl;
    backyardCamera.turnOff();
    cout << endl;

    tvPlug.turnOff();
    cout << endl;

    return 0;
}

