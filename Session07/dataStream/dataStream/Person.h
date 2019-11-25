#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Address.h"
#include "Date.h"

#include <ostream>
#include <fstream>
#include <iostream>


struct Person {
public:
	Person();
	Person(std::string name, std::string surname, Address adr, Date date) : name(name), surname(surname), address(adr), date(date) {};

	std::string GetName() const;
	std::string GetSurname() const;
	Address GetAddress() const;
	Date GetDate() const;
	~Person();

	friend std::ostream& operator<<(std::ostream& os, Person& person);
	friend std::istream& operator>>(std::istream& is, Person& person);

private:
	std::string name;
	std::string surname;
	Address address;
	Date date;
};

#endif // !PERSON_H
