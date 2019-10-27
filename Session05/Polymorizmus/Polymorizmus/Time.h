#pragma once
#include "IComparable.h"
class Time : IComparable
{
public:
	Time(int, int, int);
	~Time();

	int compareTo(IComparable* obj) const override;

	std::string ToString() const override;

	void SortArray(IComparable** arr, int arraySize);


private:
	int _hours;
	int _minutes;
	int _seconds;

};

