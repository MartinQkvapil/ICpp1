#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Address.h"
#include "Date.h"

#include <ostream>
#include <fstream>
#include <iostream>


struct Person {
	std::string name;
	std::string surname;
	Address address;
	Date date;

	//std::ostream& operator<<(std::ostream& os, const Person osoba) {
	std::ostream& operator<<(std::ostream& os){
		//std::cout << osoba.getId << std::endl;
		return os;
	}

	//std::istream& operator>>(std::istream& is, Person& osoba) {
	std::istream& operator>>(std::istream& is) {
		//std::cin << // set id;
		return is;
	}

	

};

#endif // !PERSON_H
