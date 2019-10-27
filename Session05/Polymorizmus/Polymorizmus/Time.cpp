#include "pch.h"
#include "Time.h"
#include <iostream>

Time::Time(int hours, int minutes, int seconds)
{
	this->_hours = hours;
	this->_minutes = minutes;
	this->_seconds = seconds;
}


Time::~Time()
{
}

int Time::compareTo(IComparable * obj) const
{

	int casL = this->_hours * 3600 + this->_minutes * 60 + this->_seconds;
	int casP = ((Time*)obj)->_hours * 3600 + ((Time*)obj)->_minutes * 60 + ((Time*)obj)->_seconds;
	int cislo = -2;
	if (casL == casP) {
		cislo = 0;
	}
	else if (casL < casP) {
		cislo = -1;
	}
	else if (casL > casP) {
		cislo = 1;
	}
	return cislo;
}

std::string Time::ToString() const
{
	std::cout << _hours << " hodin " << _minutes << " minut" << _seconds << " sekund" << std::endl;
	return "toString Cas";
}
