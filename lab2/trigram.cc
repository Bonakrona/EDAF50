#include "trigram.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

string wordToTrigram(const string& word) {
    vector<string> trigrams;

    // To lower case
    std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c){ return std::tolower(c); });

    int nbrTrigrams = word.size() - 2;

    if(word.size() >= 3) {
        for(int i = 0; i < nbrTrigrams; ++i) {
            trigrams.push_back(word.substr(i, 3));
        }
    }

    std::sort(trigrams.begin(), trigrams.end());


}