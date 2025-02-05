#include "trigram.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

string wordToTrigram(const string &word)
{
    vector<string> trigrams;

    // To lower case
    string lowerWord = word;
    std::transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), [](unsigned char c)
                   { return std::tolower(c); });

    int nbrTrigrams = lowerWord.size() - 2;

    if (nbrTrigrams < 1)
    {
        return "";
    }

    for (int i = 0; i < nbrTrigrams; ++i)
    {
        trigrams.push_back(lowerWord.substr(i, 3));
    }

    std::sort(trigrams.begin(), trigrams.end());

    string res = lowerWord + " " + std::to_string(nbrTrigrams);

    for (const auto &trigram : trigrams)
    {
        res += " " + trigram;
    }

    return res;
}