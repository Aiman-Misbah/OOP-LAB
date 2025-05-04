#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class VehicleReader {
public:
    void processFile(const string& fileName) {
        ifstream source(fileName);
        string entry;

        if (!source) {
            cout << "Unable to access " << fileName << endl;
            return;
        }

        while (getline(source, entry)) {
            if (entry.empty() || entry.front() == '#') {
                continue;
            }
            cout << entry << endl;
        }

        source.close();
    }
};

int main() {
    VehicleReader loader;
    loader.processFile("vehicles.txt");
    return 0;
}

