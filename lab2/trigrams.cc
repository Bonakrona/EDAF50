#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include"trigrams.h"

std::string all_lowercase(const std::string word)
{
    std::string word_lower = word;
    for(size_t i = 0; i<word.length(); ++i)
    {
        //check for capital letters and turn every letter into non-capitalized
        if (word[i] >= 'A' && word [i] <= 'Z')
        {
            unsigned char capital = word[i];
            word_lower[i] = capital + 32; //+32 shifts the value from between 65 and 90 (capital letters), to the equivalent lower case letter
        }
    }
    return word_lower;
}

int count_trigrams(const std::string& word)
{
    int nbr_letters = word.size();

    if (nbr_letters > 1 && word.substr(nbr_letters - 2) == "'s")
    {
        nbr_letters = nbr_letters -2;
    }

    int nbr_trigrams;
    if (nbr_letters < 3)
    {
       nbr_trigrams = 0;
    }
    else
    {
        nbr_trigrams = nbr_letters - 2;
    }

    return nbr_trigrams;
}

std::vector<std::string> create_trigrams(const std::string& word, int nbr_trigrams)
{
    std::vector<std::string> trigrams(nbr_trigrams);
    for (int i=0; i< nbr_trigrams; ++i)
    {
        trigrams[i] = word.substr(i, 3);
    }

    return trigrams;
}

std::vector<std::string> sort_trigrams(const std::vector<std::string>& trigrams)
{
    std::vector<std::string> sorted_trigrams = trigrams;
    sort(sorted_trigrams.begin(), sorted_trigrams.end());
    return sorted_trigrams;
}