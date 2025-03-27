#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // --- Writing to a File ---
    // Create an output file stream (ofstream) object
    ofstream outFile("example.txt");

    // Check if the file was opened successfully
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    // Write data to the file
    outFile << "File Handling in C++\n";
    outFile << "This is an example of writing to a file.\n";
    outFile << "We are learning file I/O using fstream library." << endl;

    // Close the output file stream
    outFile.close();

    // --- Reading from a File ---
    // Create an input file stream (ifstream) object
    ifstream inFile("example.txt");

    // Check if the file was opened successfully
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }

    // Read the file content line by line
    string line;
    cout << "Contents of example.txt:" << endl;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    // Close the input file stream
    inFile.close();

    return 0;
}
