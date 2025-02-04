// Write a program that reads the file and creates a new file words.txt in the current directory. Each line in
// the file shall contain a word, the number of trigrams in the word, and the trigrams. The
// trigrams shall be sorted in alphabetical order; upper case letters shall be changed to lower
// case. Example:
// ...
// hand 2 and han
// handbag 5 and bag dba han ndb
// handbook 6 and boo dbo han ndb ook

#include <iostream>
#include <fstream>
#include <string>
#include "trigram.h"

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

    ofstream outfile("words.txt", ios::binary);
    if (!outfile.is_open()) {
        cerr << "Error opening the output file!" << endl;
        return 1;
    }

    string s;
    while (getline(infile, s)) {
        outfile << wordToTrigram(s) << endl;
    }

    cout << "Trigrams completed. Output written to " << "words.txt" << endl;

    infile.close();
    outfile.close();

    return 0;
}
