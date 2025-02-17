#include <ctime>  // time and localtime
#include <iostream>
#include <iomanip> // for setw and setfill
#include "date.h"

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	if (day == daysPerMonth[month-1])
	{
		if(month == 12)
		{
			year++;
			month = 1;
		}
		else
		{
			month++;
		}
		day = 1;
	}
	else
	{
		day++;
	}
	return;
}

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

