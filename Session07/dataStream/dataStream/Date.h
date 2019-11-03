#ifndef DATUM_H
#define DATUM_H

#include <string>
#include <ostream>
#include <fstream>
#include <iostream>


struct Date {
	int _day;
	int _month;
	int _year;

	//std::ostream& operator<<(std::ostream& os, const Person osoba) {
	std::ostream& operator<<(std::ostream& os) {
		//std::cout << osoba.getId << std::endl;
		return os;
	}

	//std::istream& operator>>(std::istream& is, Person& osoba) {
	std::istream& operator>>(std::istream& is) {
		//std::cin << // set id;
		return is;
	}


};

#endif // !DATUM_H
