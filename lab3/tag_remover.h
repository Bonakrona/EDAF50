#ifndef TAG_REMOVER_H
#define TAG_REMOVER_H

#include <string>
#include <iostream>
#include <unordered_map>

class TagRemover {
    public:
        TagRemover(std::istream& input); //class constructor takes an input
        void print(std::ostream& output) const; //prints the cleaned version
        void remove_tags();

    private:
        std::string html;
        std::string cleaned;
};

static const std::unordered_map<std::string, char> html_entities;

void test_tags();
void test_spec_expr();
void test_line_break();

#endif