#include <iostream>
#include <fstream>
#include <string>
#include "trigram.h"

using namespace std;

int main()
{
    string filename = "/usr/share/dict/words";

    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    ofstream outfile("words.txt");
    if (!outfile.is_open()) {
        cerr << "Error opening the output file!" << endl;
        return 1;
    }

    string s;
    while(getline(infile, s)) {
        outfile << wordToTrigram(s) << endl;
    }

    cout << "Trigrams completed. Output written to " << "words.txt" << endl;

    infile.close();
    outfile.close();

    return 0;
}
