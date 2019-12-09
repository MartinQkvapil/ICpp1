#ifndef ZPRAVA_H
#define ZPRAVA_H

#include <string>
#include <iostream>

using namespace std;

struct Zprava {
	int id;
	string adrZdroj;
	string adrCil;
	string obsah;

	Zprava() { }
	Zprava(int id, string adrZdroj, string adrCil, string obsah) :
		id(id), adrZdroj(adrZdroj), adrCil(adrCil), obsah(obsah) {
	}
};

#endif ZPRAVA_H