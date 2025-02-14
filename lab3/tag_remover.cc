#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <fstream>
#include <sstream>
#include "tag_remover.h"

static const std::unordered_map<std::string, char> spec_expr = {
    {"&lt;", '<'}, {"&gt;", '>'}, {"&nbsp;", ' '}, {"&amp;", '&'}
};

TagRemover::TagRemover(std::istream& input) {
    std::ostringstream tmp;
    tmp << input.rdbuf(); // read into a string
    html = tmp.str(); // assign to member
    remove_tags();
}

void TagRemover::print(std::ostream& output) const{
    output << cleaned;
}

void TagRemover::remove_tags()
{   
    std::string cleaning;
    std::size_t i = 0;

    while (i < html.size())
    {
        // handling tags and skip them/don't write to cleaning
        if (html[i] == '<')
        {
            std::size_t j = i;
            while (j < html.size() && html[j] != '>')
            {
                j++;
            }

            if (j < html.size())
            { 
                i = j+1;
            }
            else
            { 
                // how to handle if there is a tag beginning but no end thingy?
                cleaning += html[i];
                i++;
            }
        }
        //handling special characters in html
        else if (html[i] == '&')
        {
            std::string check_expr;
            std::size_t j = i;
            while (j < html.size() && html[j] != ';')
            {
                check_expr += html[j];
                j++;
            }
            if (j < html.size()) {
                check_expr += ';';
            }
            if(spec_expr.count(check_expr))
            {
                cleaning += spec_expr.at(check_expr);
                i = j+1;
            }
            else
            {
                cleaning += html[i];
                i++;
            }
        }
        else
        {
            cleaning += html[i];
            i++;
        };
    }
    cleaned = cleaning;
}

void test_tags()
{
    std::istringstream test("This is <confusing> text");
    TagRemover t(test);
    std::ostringstream test_cleaned;
    t.print(test_cleaned);

    std::string expected("This is  text");
    assert(expected == test_cleaned.str());

    std::istringstream test2("This is <confusing text");
    TagRemover t2(test2);
    std::ostringstream test2_cleaned;
    t2.print(test2_cleaned);

    std::string expected2("This is <confusing text");
    assert(expected2 == test2_cleaned.str());

    std::cout << "Tags removed: All tests passed!\n";

    return;
}

void test_line_break()
{
    std::istringstream test("This is a &lt;tag&gt;\nand a new line");
    TagRemover t(test);
    std::ostringstream test_cleaned;
    t.print(test_cleaned);

    std::string expected("This is a <tag>\nand a new line");
    assert(expected == test_cleaned.str());

    std::istringstream test2("This tag <lalala/nlala>hides a line break");
    TagRemover t2(test2);
    std::ostringstream test2_cleaned;
    t2.print(test2_cleaned);

    std::string expected2("This tag hides a line break");
    assert(expected2 == test2_cleaned.str());

    std::cout << "Line breaks: All tests passed!\n";

    return;
}

void test_spec_expr()
{
    std::istringstream test("This is a &lt;tag&gt;");
    TagRemover t(test);
    std::ostringstream test_cleaned;
    t.print(test_cleaned);

    std::string expected("This is a <tag>");
    assert(expected == test_cleaned.str());

    std::istringstream test2("This &amp;&nbsp;this!");
    TagRemover t2(test2);
    std::ostringstream test2_cleaned;
    t2.print(test2_cleaned);

    std::string expected2("This & this!");
    assert(expected2 == test2_cleaned.str());

    std::cout << "Special expressions: All tests passed!\n";

    return;
}