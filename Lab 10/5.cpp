#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ifstream file("vehicles.txt");
    string line;

    if (!file.is_open()) {
        cout << "Error: Could not open vehicles.txt" << endl;
        return 1;
    }

    getline(file, line);

    while (getline(file, line)) {
        if (line.empty() || line[0] == '#')
            continue;

        istringstream ss(line);
        string type, id, name, year, extraData, certification;
        getline(ss, type, ',');
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, year, ',');
        getline(ss, extraData, ',');
        getline(ss, certification, ',');

        if (type == "AutonomousCar") {
            size_t pos = extraData.find(":");
            if (pos != string::npos) {
                string numStr = extraData.substr(pos + 1);
                float swVersion = stof(numStr);
                cout << "ID: " << id << ", Software Version: " << swVersion << endl;
            }
        } else if (type == "ElectricVehicle") {
            size_t pos = extraData.find(":");
            if (pos != string::npos) {
                string numStr = extraData.substr(pos + 1);
                int batteryCap = stoi(numStr);
                cout << "ID: " << id << ", Battery Capacity: " << batteryCap << endl;
            }
        } else if (type == "HybridTruck") {
            size_t colonPos = extraData.find("Cargo:");
            size_t batteryPos = extraData.find("Battery:");

            if (colonPos != string::npos && batteryPos != string::npos) {
                string cargoStr = extraData.substr(colonPos + 6, batteryPos - (colonPos + 6));
                int cargoVal = stoi(cargoStr);

                string batteryStr = extraData.substr(batteryPos + 8);
                int batteryVal = stoi(batteryStr);

                cout << "ID: " << id << ", Cargo: " << cargoVal << ", Battery: " << batteryVal << endl;
            }
        } else {
            cout << "ID: " << id << ", Unknown vehicle type: " << type << endl;
        }
    }

    file.close();
    return 0;
}
