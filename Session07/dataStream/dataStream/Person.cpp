#include "Person.h"

Person::Person()
{
}

std::string Person::GetName() const
{
	return this->name;
}

std::string Person::GetSurname() const
{
	return this->surname;
}

Address Person::GetAddress() const
{
	return this->address;
}

Date Person::GetDate() const
{
	return this->date;
}

std::ostream& operator<<(std::ostream& os, Person& person)
{
	return os << person.name << " " << person.surname << " " <<  person.address << " " << person.date << " " << std::endl;
}

std::istream& operator>>(std::istream& is, Person& person)
{
	is >> person.name;
	is >> person.surname;
	is >> person.address;
	is >> person.date;
	return is;
}
