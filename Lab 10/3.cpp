#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Vehicle {
public:
    string Type;
    string ID;
    string Name;
    string Year;
    string ExtraData;
    string Certification;

    void extractData(const string& line) {
        istringstream ss(line);
        getline(ss, Type, ',');
        getline(ss, ID, ',');
        getline(ss, Name, ',');
        getline(ss, Year, ',');
        getline(ss, ExtraData, ',');
        getline(ss, Certification, ',');
    }

    int getYearAsInt() {
        try {
            return stoi(Year);
        } catch (const invalid_argument&) {
            return -1;
        } catch (const out_of_range&) {
            return -1;
        }
    }

    void display() {
        int yearInt = getYearAsInt();
        cout << "Year (as integer): " << yearInt << endl;
        cout << "Type: " << Type << endl;
        cout << "ID: " << ID << endl;
        cout << "Name: " << Name << endl;
        cout << "Year (string): " << Year << endl;
        cout << "ExtraData: " << ExtraData << endl;
        cout << "Certification: " << Certification << endl;
        cout << "-------------------------" << endl;
    }
};

int main() {
    ifstream File("vehicles.txt");
    string line;

    if (!File.is_open()) {
        cout << "Error: Could not open vehicles.txt" << endl;
        return 1;
    }

    while (getline(File, line)) {
        if (line.empty() || line.find("//") == 0)
            continue;

        Vehicle vehicle;
        vehicle.extractData(line);
        vehicle.display();
    }

    File.close();
    return 0;
}
