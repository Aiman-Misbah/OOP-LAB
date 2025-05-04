#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream sensorLog("sensor_log.txt");

    if (!sensorLog) {
        cout << "Unable to open the file for writing." << endl;
        return 1;
    }

    sensorLog << "Sensor 1: 25.5 C" << endl;
    cout << "After writing first line, the file position is: " << sensorLog.tellp() << endl;

    sensorLog << "Sensor 2: 98.1 %RH" << endl;
    cout << "After writing second line, the file position is: " << sensorLog.tellp() << endl;

    sensorLog.close();
    return 0;
}
