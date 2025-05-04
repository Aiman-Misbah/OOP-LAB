#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream writer("large_log.txt");
    if (!writer) {
        cout << "Unable to open file for writing." << endl;
        return 1;
    }
    writer << "This is the first part of the log." << endl;
    writer << "This is the second part of the log." << endl;
    writer << "And the third part.";
    writer.close();

    ifstream reader("large_log.txt");
    if (!reader) {
        cout << "Unable to open file for reading." << endl;
        return 1;
    }

    char chunk[11];
    reader.read(chunk, 10);
    chunk[10] = '\0';
    cout << "First chunk: '" << chunk << "'" << endl;
    cout << "Position after reading 10 chars: " << reader.tellg() << endl;

    reader.read(chunk, 10);
    chunk[10] = '\0';
    cout << "Second chunk: '" << chunk << "'" << endl;
    cout << "Position after next 10 chars: " << reader.tellg() << endl;

    reader.close();
    return 0;
}
