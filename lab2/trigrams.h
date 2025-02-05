#ifndef TRIGRAMS_H
#define TRIGRAMS_H

#include <string>
#include <vector>
#include<algorithm>

std::string all_lowercase(const std::string word);
int count_trigrams(const std::string& word);
std::vector<std::string> create_trigrams(const std::string& word, int nbr_trigrams);
std::vector<std::string> sort_trigrams(const std::vector<std::string>& trigrams);
#endif