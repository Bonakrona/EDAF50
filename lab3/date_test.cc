#include <iostream>
#include <iomanip> // for setw and setfill
#include "date.h"
#include <ostream>
#include <istream>
#include "typecast.h"


using std::cin;
using std::cout;
using std::endl;
using std::setfill;
using std::setw;
using std::string;

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

std::ostream &operator<<(std::ostream &os, const Date &dt)
{
	os << dt.getYear() << '-' << dt.getMonth() << '-' << dt.getDay();
	return os;
}

std::istream &operator>>(std::istream &is, Date &dt)
{
	int y, m, d;
	char ch1, ch2;
	if (is >> y >> ch1 >> m >> ch2 >> d)
	{
		if (ch1 == '-' && ch2 == '-')
		{
			if (m >= 1 && m <= 12 && d >= 1 && d <= Date::daysPerMonth[m - 1])
			{
				dt = Date(y, m, d);
			}
			else
			{
				is.setstate(std::ios::failbit);
			}
		}
		else
		{
			is.setstate(std::ios::failbit);
		}
	}
	else
	{
		is.setstate(std::ios::failbit);
	}
	return is;
}

void int_test()
{
	string s = "99994444";
	int i = string_cast<int>(s);
	cout << (i == 99994444) << endl;
}

void double_test()
{
	string s = "3.14";
	double d = string_cast<double>(s);
	cout << (d == 3.14) << endl;
}

void date_test()
{
	string s = "2022-01-04";
	Date d = string_cast<Date>(s);
	cout << (d.getYear() == 2022) && (d.getMonth() == 01) && (d.getDay() == 04);
}

int main()
{
	bool cont = true;
	int count = 0;
	while (cont)
	{
		count++;
		cout << "Type a date: ";
		Date aDate;
		cin >> aDate;
		if (cin.eof() || count == 2)
		{
			cont = false;
		}
		else if (!cin.good())
		{
			cout << "Wrong input format" << endl;
			// restore stream state and ignore the rest of the line
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else
		{
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
	for (int i = 1; i <= 35; ++i)
	{
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

	cout << "Running int test: " << endl;
	int_test();

	cout << "Running double test: " << endl;
	double_test();

	cout << "Running date test: " << endl;
	date_test();

	return 0;
}
