#pragma once
#include <string>

struct Osoba
{
	std::string jmeno;
	std::string prijmeni;
	int id;
//	friend std::istream& operator>>(std::istream& is, Osoba& obj) { is >> obj.re >> obj.jmeno; return is; }
public:
	Osoba();
	Osoba(std::string jmeno, std::string prijmeni, int id) : jmeno(jmeno), prijmeni(prijmeni), id(id) {};
	~Osoba();
};



struct Osoba;
struct Hierarchie {
	Osoba * boss;
	Osoba * podrizeni;
	int pocetPodrizenych;

};