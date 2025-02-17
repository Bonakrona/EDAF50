#include <string>
#include <cassert>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include "date.h"
#include "toString.h"


int main()
{
    double d = 1.234;
    Date today;

    std::string sd = toString(d);
    cout << sd << std::endl;
    std::string st = toString(today);
    cout << st << std::endl;

    assert(toString(377) == "377");
    assert(toString(3.1415) == "3.1415");
    assert(toString(true) == "1");
    assert(toString(std::string("Hello Anna & Jona!")) == "Hello Anna & Jona!");

    
    std::cout << "All tests passed!\n";
}