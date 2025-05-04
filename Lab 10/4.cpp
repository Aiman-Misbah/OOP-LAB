#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Vehicle {
public:
    string type;
    string id;
    string name;
    string year;
    string extraData;
    string certification;

    void parseLine(const string& line) {
        istringstream ss(line);
        getline(ss, type, ',');
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, year, ',');
        getline(ss, extraData, ',');
        getline(ss, certification, ',');
    }

    void processExtraData() {
        if (type == "AutonomousCar") {
            size_t pos = extraData.find(":");
            if (pos != string::npos) {
                string numStr = extraData.substr(pos + 1);
                float swVersion = stof(numStr);
                cout << "ID: " << id << ", Software Version: " << swVersion << endl;
            }
        } else if (type == "ElectricVenicle") {
            size_t pos = extraData.find(":");
            if (pos != string::npos) {
                string numStr = extraData.substr(pos + 1);
                int batteryCap = stoi(numStr);
                cout << "ID: " << id << ", Battery Capacity: " << batteryCap << endl;
            }
        }
    }
};

int main() {
    ifstream file("vehicles.txt");
    string line;

    if (!file.is_open()) {
        cout << "Error: Could not open vehicles.txt" << endl;
        return 1;
    }

    while (getline(file, line)) {
        if (line.empty() || line[0] == '/') // Ignore comment lines starting with '//'
            continue;

        Vehicle vehicle;
        vehicle.parseLine(line);
        vehicle.processExtraData();
    }

    file.close();
    return 0;
}
