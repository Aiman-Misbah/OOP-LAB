#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class LineProcessor {
public:
    void handleFile(const string& filePath) {
        ifstream input(filePath);
        string current;

        if (!input) {
            cout << "Unable to open " << filePath << endl;
            return;
        }

        while (getline(input, current)) {
            if (current.empty() || current.front() == '#') {
                continue;
            }

            istringstream stream(current);
            string category, code, title, release, detail, approval;

            getline(stream, category, ',');
            getline(stream, code, ',');
            getline(stream, title, ',');
            getline(stream, release, ',');
            getline(stream, detail, ',');
            getline(stream, approval, ',');

            cout << "Category: " << category << endl;
            cout << "Code: " << code << endl;
            cout << "Title: " << title << endl;
            cout << "Release: " << release << endl;
            cout << "Detail: " << detail << endl;
            cout << "Approval: " << approval << endl << endl;
        }

        input.close();
    }
};

int main() {
    LineProcessor parser;
    parser.handleFile("vehicles.txt");
    return 0;
}
