#include <exception>
#include <iostream>
#include "typecast.h"
#include "date.h"

using namespace std;
using std::string;


void int_test() {
    string s = "99994444";
    int i = string_cast<int>(s);
    cout << (i == 99994444) << endl;
}

void double_test() {
    string s = "3.14";
    double d = string_cast<double>(s);
    cout << (d == 3.14) << endl;
}

void date_test() {
    string s = "2022-01-04";
    Date d = string_cast<Date>(s);
    cout << (d.getYear() == 2022) && (d.getMonth() == 01) && (d.getDay() == 04);
}


int main() {
    cout << "Running int test: " << endl;
    int_test();

    cout << "Running double test: " << endl;
    double_test();

    cout << "Running date test: " << endl;
    date_test();

    return 0;
}