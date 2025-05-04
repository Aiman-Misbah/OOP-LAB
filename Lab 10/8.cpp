#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream configFile("config.txt");
    if (!configFile) {
        cout << "Failed to open file for writing!" << endl;
        return 1;
    }
    configFile << "AAAAABBBBBCCCCC";
    configFile.close();

    fstream configUpdater("config.txt", ios::in | ios::out);
    if (!configUpdater) {
        cout << "Failed to open file for updating!" << endl;
        return 1;
    }

    configUpdater.seekp(5, ios::beg);
    configUpdater << "XXXXX";
    configUpdater.close();

    ifstream updatedFile("config.txt");
    if (!updatedFile) {
        cout << "Failed to open file for reading!" << endl;
        return 1;
    }
    string updatedContent;
    getline(updatedFile, updatedContent);
    cout << "Content after update: " << updatedContent << endl;
    updatedFile.close();

    return 0;
}
