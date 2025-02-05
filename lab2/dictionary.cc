#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <unordered_set>

using std::string;
using std::vector;

// The constructor should read words.txt and
// store the words in an unordered_set<std::string>.


Dictionary::Dictionary()
{
	std::ifstream infile("words.txt");
	if(!infile) {
		std::cerr << "Error: could not open wrods.txt" << std::endl;
		return;
	}
	string s;
	while (getline(infile, s))
	{
		words.insert(s.substr(0, s.find_first_of(" ")));
	}
}

bool Dictionary::contains(const string &word) const
{
	return words.find(word) != words.end();
}

vector<string> Dictionary::get_suggestions(const string &word) const
{
	vector<string> suggestions;
	return suggestions;
}
