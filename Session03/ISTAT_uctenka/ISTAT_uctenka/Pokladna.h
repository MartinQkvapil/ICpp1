#pragma once

#ifndef POKLADNA_H
#define POKLADNA_H

#include "Uctenka.h"

class Pokladna {
public:
	Uctenka *pocetVydanychUctenek = new Uctenka[10];
	Pokladna() : citacId(1000) {};


	Uctenka& vystavUctenku(double a, double b) {};
	Uctenka& dejUctenku(int x) {};
	double dejCastku() const {};
	double dejCastkuVcDph() const {};

private:
	int  citacId;


};

#endif // !POKLADNA_H
