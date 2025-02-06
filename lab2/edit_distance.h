#ifndef EDIT_DISTANCE_H
#define EDIT_DISTANCE_H

#include "dictionary.h"
#include <string>
#include <vector>

int edit_distance(const std::string &word, const std::string &spelled_word);
extern int d[Dictionary::maxlen + 1][Dictionary::maxlen + 1];


#endif