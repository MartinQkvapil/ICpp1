#include "Vztah.h"

Vztah::Vztah(Osoba* osoba1, Osoba* osoba2, int Iid, std::string Ityp) {
	osoby = new Osoba*[2];
	osoby[0] = osoba1;
	osoby[1] = osoba2;
	pocetPrimychPotomku = 0;
	id = Iid;
	typVztahu = Ityp;
}
Vztah::~Vztah() {
	osoby[0] = nullptr;
	osoby[1] = nullptr;
	delete osoby[0];
	delete osoby[1];
	delete[] osoby;
	for (int i = 0; i < pocetPrimychPotomku; i++)
	{
		potomci[i] = nullptr;
		delete potomci[i];
	}
	
}

int Vztah::getID() const {
	return id;
}

int Vztah::getPocetPrimychPotomku() const {
	return pocetPrimychPotomku;
}

Osoba** Vztah::getPotomci() const {
	return potomci;
}

void Vztah::pridatPotomka(Osoba* os) {
	Osoba** temp = new Osoba*[pocetPrimychPotomku + 1];
	for (int i = 0; i < pocetPrimychPotomku; i++)
	{
		temp[i] = potomci[i];
	}
	temp[pocetPrimychPotomku] = os;
	potomci = temp;
	pocetPrimychPotomku++;
}