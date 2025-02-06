#include <string>
#include <vector>
#include "word.h"

using std::vector;
using std::string;

Word::Word(const string& w, const vector<string>& t)
{
	word = w;
	trigrams = t;
}

string Word::get_word() const
{
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const
{
	unsigned int matches = 0;
	auto i_t = t.begin(); // is an iterator, not the object!!
	auto i_trigrams = trigrams.begin(); // is an iterator, not the object!!

	while(i_t < t.end() && i_trigrams < trigrams.end())
	{
		if(*i_t == *i_trigrams)
		{
			++matches;
			++i_t;
			++i_trigrams;
		}
		else if (*i_t < *i_trigrams)
		{
			++i_t;
		}
		else
		{
			++i_trigrams;
		}
		
	}
	return matches;
}
