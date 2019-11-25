#ifndef DATUM_H
#define DATUM_H

#include <string>
#include <ostream>
#include <fstream>
#include <iostream>


struct Date {
private:
	int _day;
	int _month;
	int _year;
public:	
	Date(){};
	Date(int day, int month, int year) : _day(day), _month(month), _year(year)  {};
	friend std::ostream& operator<<(std::ostream& os, Date& date);	
	friend std::istream& operator>>(std::istream& is, Date& date);
	~Date();
};

#endif // !DATUM_H
