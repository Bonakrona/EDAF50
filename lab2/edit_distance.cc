#include <string>
#include <iostream>
#include "edit_distance.h"

#include "dictionary.h"

using std::min;

int edit_distance(std::string x, std::string y)
{
    /*int size1 = x.size();
    int size2 = y.size();
    int verif[size1 + 1][size2 + 1]; // Verification matrix i.e. 2D array which will store the calculated distance.
    */
   
    int d[Dictionary::maxlen+1][Dictionary::maxlen+1];

    // Sets the first row and the first column of the verification matrix with the numerical order from 0 to the length of each word.
    for (int i = 0; i <= x.size(); i++)
        d[i][0] = i;
    for (int j = 0; j <= y.size(); j++)
        d[0][j] = j;

    // Verification step / matrix filling.
    for (int i = 1; i <= x.size(); i++) {
        for (int j = 1; j <= y.size(); j++) {
            // Sets the modification cost.
            // 0 means no modification (i.e. equal letters) and 1 means that a modification is needed (i.e. unequal letters).
            int cost = (y[j - 1] == x[i - 1]) ? 0 : 1;

            // Sets the current position of the matrix as the minimum value between a (deletion), b (insertion) and c (substitution).
            // a = the upper adjacent value plus 1: verif[i - 1][j] + 1
            // b = the left adjacent value plus 1: verif[i][j - 1] + 1
            // c = the upper left adjacent value plus the modification cost: verif[i - 1][j - 1] + cost
            d[i][j] = std::min(std::min(d[i - 1][j] + 1, d[i][j - 1] + 1),d[i - 1][j - 1] + cost);
        }
    }
    int score = d[x.size()][y.size()]; 
    // The last position of the matrix will contain the Levenshtein distance.
    return score;
}