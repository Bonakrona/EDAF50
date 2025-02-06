#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include "word.h"
#include "dictionary.h"

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
	//rank_suggestions(suggestions, word); // item 2
	//trim_suggestions(suggestions); // item 3
	return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<string> suggestions, const string& word) const
{
	for (size_t i = word.size()-2; i < word.size()+1; ++i){
		for (size_t j=0; j<words[i].size(); ++j){
			
		}
	}
}
