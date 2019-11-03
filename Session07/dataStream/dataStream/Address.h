#ifndef ADDRESS_H
#define ADDRESS_H


#include <ostream>
#include <fstream>
#include <iostream>

#include <string>

struct Address {
	std::string _street;
	std::string _town;
	std::string _psc;

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

#endif // !ADDRESS_H

