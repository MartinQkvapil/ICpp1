#include "Address.h"

Address::~Address()
{
}

std::string Address::get_street()
{
	return this->_street;
}

std::string Address::get_town()
{
	return this->_town;
}

//std::string Address::get_psc()
//{
//	return this->_psc;
//}
//
//void Address::set_street(std::string street)
//{
//	this->_street = street;
//}
//
//void Address::set_town(std::string town)
//{
//	this->_town = town;
//}
//
//void Address::set_psc(std::string psc)
//{
//	this->_psc = psc;
//}

std::ostream& operator<<(std::ostream& os, const Address& address)
{
	return os << address._street << " " << address._town << " " << address._psc << " " << std::endl;
	//	return os;
}

std::istream& operator>>(std::istream& is, Address& address)
{
	is >> address._street;
	is >> address._town;
	is >> address._psc;
	return is;	
}
