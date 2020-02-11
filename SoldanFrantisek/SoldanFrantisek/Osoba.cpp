#include "Osoba.h"

Osoba::Osoba(int Iid, char Ipohlavi, std::string Ijmeno) {
	id = Iid;
	pohlavi = Ipohlavi;
	jmeno = Ijmeno;
	pocetVztahu = 0;
	vztahy = new Vztah*[0];
	pocitan = false;
}
Osoba::~Osoba() {
	for (int i = 0; i < pocetVztahu; i++)
	{
		delete vztahy[i];
	}
	delete[] vztahy;
}

int Osoba::getId() const {
	return id;
}

int Osoba::getPocetVztahu() const {
	return pocetVztahu;
}

Vztah** Osoba::getVztahy() const {
	return vztahy;
}

void Osoba::pridatVztah(int id, Osoba* o, std::string popis) {
	Vztah** temp = new Vztah*[pocetVztahu+1];
	for (int i = 0; i < pocetVztahu; i++)
	{
		temp[i] = vztahy[i];
	}
	temp[pocetVztahu] = new Vztah(this, o, id, popis);
	vztahy = temp;
	pocetVztahu++;
}

int Osoba::getVsechnyPotomky() {
	int pocet = 0;
	if (!pocitan) {
		for (int i = 0; i < pocetVztahu; i++)
		{
			pocet += vztahy[i]->getPocetPrimychPotomku();
			for (int j = 0; j < vztahy[i]->getPocetPrimychPotomku(); j++) {
					pocet += vztahy[i]->getPotomci()[j]->getVsechnyPotomky();

			}
		}
	}
	
	return pocet;
}