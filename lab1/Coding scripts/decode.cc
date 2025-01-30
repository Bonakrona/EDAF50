#include <iostream>
#include <fstream>
#include <string>
#include "coding.h"

using namespace std;

int main()
{
    string filename;
    
    cout << "Enter filename: ";
    cin >> filename;

    ifstream infile(filename, ios::binary);
    if (!infile.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    ofstream outfile(filename + ".dec", ios::binary);
    if (!outfile.is_open()) {
        cerr << "Error opening the output file!" << endl;
        return 1;
    }

    char ch;
    while (infile.get(ch)) {
        outfile.put(decode(ch));
    }

    cout << "Decoding complete. Output written to " << filename << ".dec" << endl;

    infile.close();
    outfile.close();

    return 0;
}
