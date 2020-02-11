#ifndef OSOBA_H
#define OSOBA_H
#include <iostream>
#include "Vztah.h"

struct Vztah;

struct Osoba
{
private:
	int id;
	std::string jmeno;
	char pohlavi;
	Vztah** vztahy;
	int pocetVztahu;
	
public:
	bool pocitan;
	Osoba(int Iid, char Ipohlavi, std::string Ijmeno);
	~Osoba();
	int getId() const;
	int getPocetVztahu() const;
	Vztah** getVztahy() const;
	void pridatVztah(int id, Osoba* o, std::string popis);
	int getVsechnyPotomky();
};

#endif // OSOBA_H

