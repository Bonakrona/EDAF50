#include <gtest/gtest.h>
#include <sstream>
#include <fstream>
#include <string>
#include "RemoveTags.h"

TEST(TestHTML, basicTest)
{
    RemoveTags rt;
    std::string str = "Hello <TAGG> world!";
    std::string res = rt.removeTags(str);
    ASSERT_EQ(res, "Hello world");
}

TEST(TestHTML, newLineTest)
{
    RemoveTags rt;
    std::string str = "Hello <TAGG STARTS on first line \n"
                      "and ends on second line> \n"
                      "Now it's on the third line with no tags";
    std::string res = rt.removeTags(str);
    ASSERT_EQ(res, "Hello \n Now it's on the third line with no tags");
}

TEST(TestHTML, specialCharsTest) {
    RemoveTags rt;
    std::string str = "Hello &lt;&gt;&nbsp;&amp; world!";
    std::string res = rt.removeTags(str);
    ASSERT_EQ(res, "Hello world!");
}

TEST(TestHTML, givenHTMLTest)
{
    RemoveTags rt;
    std::ifstream fs("test.html");
    if (!fs.is_open())
    {
        std::cerr << "File not found" << std::endl;
    }

    
    std::stringstream buffer;
    buffer << fs.rdbuf();
    std::string bufferStr = buffer.str();
    std::string res = rt.removeTags(bufferStr);

    std::string str = "this is a line wothout a tag\n"
                      "This is a line with one tag\n"
                      "And this line has two tags\n"
                      "A line with a starting tag\n"
                      " which finished on thin line"
                      "Special chars: ";
    ASSERT_EQ(res, str);
}