#include <string>
#include <vector>
#include "edit_distance.h"

using std::string;
using std::vector;

int d[Dictionary::maxlen + 1][Dictionary::maxlen + 1];

int edit_distance(const string &word, const string &spelled_word)
{
    for (int i = 0; i <= word.size(); ++i) 
        d[i][0] = i;
    for (int j = 0; j <= spelled_word.size(); ++j) 
        d[0][j] = j;

    for (int i = 1; i <= word.size(); ++i)
    {
        for (int j = 1; j <= spelled_word.size(); ++j)
        {
            int cost = (spelled_word[j - 1] == word[i - 1]) ? 0 : 1;
            d[i][j] = std::min(std::min(d[i - 1][j] + 1, d[i][j - 1] + 1), d[i - 1][j - 1] + cost);
        }
    }

    return d[word.size()][spelled_word.size()];
}
