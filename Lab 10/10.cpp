#include <iostream>
#include <fstream>
using namespace std;

int main() {

    fstream file("data_records.txt", ios::out);
    if (!file) {
        cerr << "Unable to open file for writing!" << endl;
        return 1;
    }
    file << "Record 1" << endl;
    file << "Record 2" << endl;
    file << "Record 3" << endl;
    file << "Record 4" << endl;
    file.close();

    fstream fileIn("data_records.txt", ios::in);
    if (!fileIn) {
        cerr << "Unable to open file for reading!" << endl;
        return 1;
    }

    int skipBytes = 10 * 2; 
    fileIn.seekg(skipBytes, ios::beg);
    string lineContent;
    getline(fileIn, lineContent);
    cout << "The third record is: " << lineContent << endl;
    fileIn.close();

    return 0;
}
