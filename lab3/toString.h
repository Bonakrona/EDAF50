#ifndef TOSTRING_H
#define TOSTRING_H

#include <string>
#include <sstream>

template <typename T>

//std::string toString(const T& input);
std::string toString(const T& input)
{
    std::ostringstream tmp;
    tmp << input;
    return tmp.str();
}

//void test_toString();

#endif