#ifndef PERSON_H
#define PERSON_H


#include <iostream>
#include <string>

class Person {
public:
	Person();
	Person(std::string name, std::string surname, int age) : _name(name), _surname(surname), _age(age) {};
	~Person();
private:
	std::string _name;
	std::string _surname;
	int _age;


};


#endif // !PERSON_H
