#include <iostream>
#include <iomanip> // for setw and setfill

#include "date.h"

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::setfill;

/*
 * Prints the date d in the format yyyy-mm-dd. You shall replace this
 * function with an overloaded operator<<, and add an overloaded operator>>.
 *
 void print(const Date& d) {
	cout << setw(4) << setfill('0') << d.getYear() << '-';
	cout << setw(2) << setfill('0') << d.getMonth() << '-';
	cout << setw(2) << setfill('0') << d.getDay();
}
*/

std::ostream& operator<<(std::ostream& os, const Date& dt)
{
	os << std::setw(4) << std::setfill('0') << dt.year << '-'
	<< std::setw(2) << std::setfill('0') << dt.month << '-'
	<< std::setw(2) << std::setfill('0') << dt.day;
 	return os;
}

std::istream& operator>>(std::istream& is, Date& dt)
{
	int y, m, d;
    char char1, char2; // To store the '-' characters
    if(is >> y >> char1 >> m >> char2 >> d)
	{
		if (char1 != '-' || char2 != '-') {
            is.setstate(std::ios::failbit);
		}
		else if (m < 1 || m > 12 || d < 1 || d > dt.daysPerMonth[m-1])
		{
			// the date has right format but makes no sense
			is.setstate(std::ios::failbit);
		}
		else
		{
			dt.day = d;
			dt.month = m;
			dt.year = y;
		}
	}
	else
	{
		is.setstate(std::ios::failbit);
	}
    
    return is;
}

int main() {
	// Check input and output of dates. Uncomment the following when you 
	// have added operator>> and operator<<.
	
	bool cont = true;
	while (cont) {
		cout << "Type a date: ";
		Date aDate;
		cin >> aDate;
		if (cin.eof()) {
			cont = false;
		} else if (!cin.good()) {
			cout << "Wrong input format" << endl;
			// restore stream state and ignore the rest of the line
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else {
			cout << "Output: " << aDate << endl;
		}
	};
	
	// Check 'next' by creating an object describing today's date, then
	// printing dates more than a month ahead
	cout << "--- Today and more than a month ahead:" << endl;
	Date d1;
	//print(d1);
	cout << endl;
	for (int i = 1; i <= 35 ; ++i) {
		d1.next();
		//print(d1);
		cout << endl;
	}
	
	// Check so 'next' functions correctly from one year to the next
	cout << "--- New Year's Eve and the next day:" << endl;
	Date d2(2013, 12, 31);
	//print(d2);
	cout << endl;
	d2.next();
	//print(d2);
	cout << endl;
}
