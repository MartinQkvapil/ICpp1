#ifndef VZTAH_H
#define VZTAH_H
#include "Osoba.h"

struct Osoba;

struct Vztah
{
private:
	int id;
	Osoba** osoby;
	Osoba** potomci;
	std::string typVztahu;
	int pocetPrimychPotomku;
	
public:
	Vztah(Osoba* osoba1, Osoba* osoba2, int Iid, std::string Ityp);
	~Vztah();
	int getID() const;
	int getPocetPrimychPotomku() const;
	Osoba** getPotomci() const;
	void pridatPotomka(Osoba* os);
};

#endif // VZTAH_H

