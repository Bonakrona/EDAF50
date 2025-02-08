#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include "trigrams.h"
#include "word.h"
#include "dictionary.h"
#include "edit_distance.h"
using std::string;
using std::vector;

Dictionary::Dictionary()
{
	std::ifstream file("words.txt");

	/*std::string word;
	while(file >> word)
	{
		words.insert(word);
	}*/

	std::string word;
	int nbr_trigrams;
	std::vector<std::string> word_trigrams;
	std::string trigram;


	std::string word_line;

	while (std::getline(file, word_line))
	{
		std::istringstream stream(word_line); // seperate line into words

		if (stream >> word) // is the first element as expected a string
		{
			words_only.insert(word);
			if (stream >> nbr_trigrams) // is the second element as expected an int
			{
				word_trigrams.clear();
				while (stream >> trigram) // treat all remaining elements as trigrams
				{
					word_trigrams.push_back(trigram);
				}
			}
		}
		words[nbr_trigrams+1].push_back(Word(word, word_trigrams));
	}
}

bool Dictionary::contains(const string& word) const {
	return words_only.count(word);
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word); // item 1 in the above list
	rank_suggestions(suggestions, word); // item 2
	trim_suggestions(suggestions); // item 3
	return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<string>& suggestions, const string& word) const
{
	int nbr_trigrams = count_trigrams(word);
	std::vector<std::string> t = create_trigrams(word, nbr_trigrams);
	std::vector<std::string> trigrams = sort_trigrams(t);

	if (nbr_trigrams < 1) return;

	for (int i = 2; i < nbr_trigrams+2; ++i) //only for words that even have trigrams
	{
		for (const Word &w : words[i]) 
		{
			unsigned int matches = w.get_matches(trigrams);
			if (matches >= nbr_trigrams/2)
			{
				suggestions.push_back(w.get_word());
			}

		}
	}
	return;
}

void Dictionary::rank_suggestions(std::vector<std::string>& suggestions, const std::string& word) const
{
	std::vector<std::pair<int, std::string>> scored;

	for (const string &candidate : suggestions)
	{
		int score = edit_distance(candidate, word);
		scored.emplace_back(score, candidate);
	}

	std::sort(scored.begin(), scored.end());
	suggestions.clear();
	
	for (const auto& pair : scored) {
    	suggestions.push_back(pair.second);
	}
}

void Dictionary::trim_suggestions(std::vector<std::string>& suggestions)const
{
	suggestions = std::vector<std::string>(suggestions.begin(), suggestions.begin() + std::min(5, (int)suggestions.size()));
}