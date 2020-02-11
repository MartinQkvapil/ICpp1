#ifndef RODOKMEN_H
#define RODOKMEN_H
#include "Osoba.h"
#include "Vztah.h"
#include <istream>
#include <fstream>
#include <string>

struct Rodokmen
{
private:
	Osoba** osoby;
	int pocetOsob;
public:
	Rodokmen(std::istream& is);
	int dejPocetPrimychPotomku(int idOsoby);
	int dejPocetVsechPotomku(int idOsoby);
	~Rodokmen();
};


#endif // RODOKMEN_H