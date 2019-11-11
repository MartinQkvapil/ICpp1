#include "Date.h"

std::ostream& operator<<(std::ostream& os, Date& date)
{
	return os << date._day << " " << date._month << " " << date._year << std::endl;
}

std::istream& operator>>(std::istream& is, Date& date)
{
	is >> date._day;
	is >> date._month;
	is >> date._year;
	return is;
}
