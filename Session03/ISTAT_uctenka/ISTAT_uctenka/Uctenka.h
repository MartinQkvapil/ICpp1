#pragma once

#ifndef UCTENKA_H
#define UCTENKA_H

class Uctenka {
private:
	int cisloUctenky;
	double castka;
	double dph;
public:
	Uctenka() {};
	Uctenka(int cisloUctenky, double dph, double castka) {};

	//Setters 
	void setCisloUctenky(int a) {};
	void setCastka(double a) {};
	void setDph(double a) {};
	// Getters
	int getCisloUctenky() {};
	double getCastka() {};
	double getDph() {};

	


};

// TODO: 
//Vytvoøte tøídu Uctenka, která obsahuje privátní atributy:
//int cisloUctenky(unikátní identifikátor úètenky), 
//double castka(èástka bez dph),
//double dph(sazba dph v procentech).
//Vytvoøte metody pro ètení a nastavení atributù.

#endif UCTENKA_H