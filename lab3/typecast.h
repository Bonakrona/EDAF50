#ifndef TYPECAST_H
#define TYPECAST_H

#include <sstream>
#include <string>
#include <stdexcept>

template <typename T>

T string_cast(const std::string& s) {
    std::istringstream input_stream(s);
    T val;
    input_stream >> val;

    if(!input_stream.eof() && input_stream.fail()) {
        throw std::invalid_argument("Conversion failed" + s);
    }

    return val;
}

#endif