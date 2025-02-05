#include <string>
#include <vector>
#include "word.h"

using std::string;
using std::vector;

Word::Word(const string &w, const vector<string> &t) : word(w), trigrams(t) {}

string Word::get_word() const
{
	return word;
}

unsigned int Word::get_matches(const vector<string> &t) const
{
	unsigned int matches = 0;
	int i = 0;
	int j = 0;

	while (i < trigrams.size() && j < t.size())
	{
		if(trigrams[i] == t[j]) {
			matches++;
			i++;
			j++;
		} else if(trigrams[i] < t[j]) {
			i++;
		} else {
			j++;
		}
	}
	return matches;
}
