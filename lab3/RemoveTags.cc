#include "RemoveTags.h"
#include <regex>
#include <string>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>

std::string RemoveTags::RemoveTags(const std::string& in) {
    std::string out = in;

    out = std::regex_replace(output, std::refex(---------), "");
}