#include "Uctenka.h"

Uctenka::Uctenka(int cisloUctenky, double dph, double castka) {
	Uctenka::cisloUctenky = cisloUctenky;
	Uctenka::dph = dph;
	Uctenka::castka = castka;
}

// Getters
int Uctenka::getCisloUctenky() {
	return Uctenka::cisloUctenky;
}

double Uctenka::getCastka() {
	return Uctenka::castka;
};

double Uctenka::getDph() {
	return Uctenka::dph;
};

// Setters
void Uctenka::setCastka(double a) {
	Uctenka::castka = a;
};

void Uctenka::setCisloUctenky(int a) {
	Uctenka::cisloUctenky = a;
};

void Uctenka::setDph(double a) {
	Uctenka::dph = a;
};
