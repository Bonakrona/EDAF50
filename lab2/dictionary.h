#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_set>

class Dictionary
{
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
	void Dictionary::add_trigram_suggestions(vector<string> suggestions, const string& word) const;
private:
	//std::unordered_set<std::string> words;
	std::unordered_set<std::string> words_only;
	//constexpr int maxlen{25};
	//std::vector<Word> words[maxlen];
	std::vector<Word> words[25];
};

#endif
