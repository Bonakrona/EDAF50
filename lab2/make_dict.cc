/////////////////////////////////////////////////
/// Creating a dictionary for spelling checks ///
/////////////////////////////////////////////////

#include"trigrams.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    // import file and see ifit can be openend
    std::ifstream dict ("british-english");
    if (!dict.is_open())
    {
        std::cerr << "Error: Could not open file !";
        return 1;
    }

    ofstream dict_trigram("words.txt");
    // read in every word
    std::string word;
    while(std::getline(dict, word))
    {
        std::string word_lower;
        word_lower = all_lowercase(word);

        // count trigrams
        int nbr_trigrams;
        nbr_trigrams = count_trigrams(word_lower);
        
        if (nbr_trigrams > 0)
        {
            // create trigrams
            std::vector<std::string> trigrams;
            trigrams = create_trigrams(word_lower, nbr_trigrams);

            // sort trigrams alphabetically
            std::vector<std::string> sorted_trigrams;
            sorted_trigrams = sort_trigrams(trigrams);

            // write all information to new file
            dict_trigram << word_lower << " " << nbr_trigrams;
            for (int i=0; i<nbr_trigrams; ++i)
            {
                dict_trigram << " " << sorted_trigrams[i];
            }
            dict_trigram << '\n';
        }
    }

    dict_trigram.close();

    return 0;
}
