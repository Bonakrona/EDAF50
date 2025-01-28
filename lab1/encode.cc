#include "coding.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    //read in a text file given by the user
    std::string file;
    std::cin >> file;
    std::ifstream text(file);
    if (!text.is_open()) {
        std::cerr << "Error: Could not open file " << file << '\n';
        return 1;
    }

    //iterate over all lines and each character within a line
    //each letter has to be put into encode and assigned to a new file
    // Create and open a text file
    ofstream file_enc("myfile_enc.txt");

    std::string line;
    while(std::getline(text, line))
    {
        for (unsigned char c : line)
        {
            //std::cout << c;
            unsigned char c_enc = encode(c);
            //std::cout << c_enc << '\n';
            file_enc << c_enc;
        }
        file_enc << '\n';
    }

    file_enc.close();
}