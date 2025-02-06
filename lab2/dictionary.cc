#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include "trigram.h"
#include <unordered_set>

using std::string;
using std::vector;

Dictionary::Dictionary()
{
	std::ifstream infile("words.txt");
	if (!infile)
	{
		std::cerr << "Error: could not open wrods.txt" << std::endl;
		return;
	}
	string s;
	while (getline(infile, s))
	{
		string word = s.substr(0, s.find_first_of(" "));
		vector<string> trigrams = wordToTrigram(word);

		if (word.length() < maxlen)
		{
			wordsWithTrigrams[word.length()].push_back(Word(word, trigrams));
		}

		words.insert(word);
	}
}

bool Dictionary::contains(const string &word) const
{
	return words.find(word) != words.end();
}


void Dictionary::add_trigram_suggestions(vector<string> &suggestions, const vector<std::string> &trigrams, int wordlen) const
{

	vector<int> candidate_lengths = {wordlen};
	if(wordlen > 1) {
		candidate_lengths.push_back(wordlen - 1);
	}
	if(wordlen + 1 < maxlen) {
		candidate_lengths.push_back(wordlen + 1);
	}

	for (int len : candidate_lengths) {
		for (const Word &w: wordsWithTrigrams[len]) {
			unsigned int matches = w.get_matches(trigrams);

			if(matches >= trigrams.size() / 2) {
				suggestions.push_back(w.get_word());
			}
		}
	}


	// const vector<Word> &candidates = wordsWithTrigrams[wordlen];

	// for(const Word &w : candidates) {
	// 	if(w.get_matches(trigrams) > 0) {
	// 		suggestions.push_back(w.get_word());
	// 	}
	// }
}

vector<string> Dictionary::get_suggestions(const string &word) const
{
	vector<string> suggestions;
	vector<string> trigrams = wordToTrigram(word);

	if(word.length() < maxlen ) {
		add_trigram_suggestions(suggestions, trigrams, word.length());
	}
	return suggestions;
}