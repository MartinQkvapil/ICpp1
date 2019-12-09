#ifndef UZEL_H
#define UZEL_H

#include "ASitovyPrvek.h"
#include <string>



struct Uzel : ASitovyPrvek
{
private:
	std::string adresa;
	ASitovyPrvek* pripojenyPrvek;
	Fronta<Zprava*> odchoziZpravy;
	void ZpracujPrichoziZpravu(ZpravaPort zp);
public:
	Uzel(std::string adresa) {
		adresa = adresa;
	};
	void Pripoj(ASitovyPrvek* sitovyPrvek);
	void Provadej();
	void PripravZpravuKOdeslani(std::string cil, std::string obsah);
};

#endif // !UZEL_H