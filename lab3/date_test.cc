#include <iostream>
#include <iomanip> // for setw and setfill
#include "date.h"
#include <ostream>
#include <istream>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::setfill;

/*
 * Prints the date d in the format yyyy-mm-dd. You shall replace this
 * function with an overloaded operator<<, and add an overloaded operator>>.
 *
 */
// void print(const Date& d) {
// 	cout << setw(4) << setfill('0') << d.getYear() << '-';
// 	cout << setw(2) << setfill('0') << d.getMonth() << '-';
// 	cout << setw(2) << setfill('0') << d.getDay();
// }

std::ostream& operator<<(std::ostream& os, const Date& dt) {
	os << dt.getYear() << '-' << dt.getMonth() << '-' << dt.getDay();
	return os;
}

std::istream& operator>>(std::istream& is, Date& dt) {
	int y, m, d;
	char ch1, ch2;
	if(is >> y >> ch1 >> m >> ch2 >> d) {
		if(ch1 == '-' && ch2 == '-') {
			if(m >= 1 && m <= 12 && d >= 1 && d <= Date::daysPerMonth[m-1]) {
				dt = Date(y, m, d);
			} else {
				is.setstate(std::ios::failbit);
			}
		} else {
			is.setstate(std::ios::failbit);
		}
	} else {
		is.setstate(std::ios::failbit);
	}
	return is;
}

int main() {
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
	}
	
	// Check 'next' by creating an object describing today's date, then
	// printing dates more than a month ahead
	cout << "--- Today and more than a month ahead:" << endl;
	Date d1;
	// print(d1);
	cout << d1;
	cout << endl;
	for (int i = 1; i <= 35 ; ++i) {
		d1.next();
		cout << d1;
		// print(d1);
		cout << endl;
	}
	
	// Check so 'next' functions correctly from one year to the next
	cout << "--- New Year's Eve and the next day:" << endl;
	Date d2(2013, 12, 31);
	// print(d2);
	cout << d2;
	cout << endl;
	d2.next();
	// print(d2);
	cout << d2;
	cout << endl;
}
