#ifndef ADDRESS_H
#define ADDRESS_H


#include <ostream>
#include <fstream>
#include <iostream>
#include <string>

struct Address {
private:
	std::string _street;
	std::string _town;
	int _psc;
public:
	Address() {};
	Address(std::string street, std::string town, int psc) : _street(street), _town(town), _psc(psc) {};

	std::string get_street();
	std::string get_town();


	friend std::ostream& operator<<(std::ostream& os, const Address& address);
	friend std::istream& operator>>(std::istream& is, Address& address);
};

#endif // !ADDRESS_H

