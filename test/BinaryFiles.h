#ifndef BINFILES_H
#define BINFILES_H

#include <iostream>
#include <fstream>
#include <string>
#include "Podminka.h"


//BinaryFiles* temp = new BinaryFiles();
//temp->testZapisACteniBinarne();
//temp->testZapisACteniBinarne2();
//temp->testZapisACteniBinarne3();
//temp->testZapisACteniBinarne4();
//temp->testZapisACteniBinarne5();
//
//
//delete temp;

struct JednoduchaStruktura { int a; int b; int c; std::string name; };
struct SlozitejsiStruktura { JednoduchaStruktura& ref; JednoduchaStruktura* ptr; };
struct NevyrovnanaStruktura { char a; int b; char c; double d; };

struct Struktura { std::string retezec; };


struct Zvire {
	int pocetOci;
	std::string jmeno;
	std::string prijmeni;

	Zvire(std::string jmeno, std::string prijmeni, int pocetOci) : jmeno(jmeno), prijmeni(prijmeni), pocetOci(pocetOci) {};
	~Zvire() {};
};

class BinaryFiles
{
public:
	void testZapisZvirate() {

		Zvire* zv2 = new Zvire("Klokan", "Maly", 1);
		Zvire* zv1 = new Zvire("Ondatra", "Velka", 2);

		std::ofstream binFile;
		binFile.open("datas.bin", std::ios_base::binary);

		if (binFile.is_open()) {
			binFile.write((char*)zv1, sizeof(Zvire));
			binFile.write((char*)zv2, sizeof(Zvire));
		}
		else {
			throw Podminka("Nelze zapsat...");
		}

	}


	void testZapisACteniBinarne() {
		JednoduchaStruktura abc{ 1, 2, 3, "Martin" };
		JednoduchaStruktura abcd{ 4, 5, 6, "Ales" };

		std::ofstream binFile{ "out.bin", std::ios_base::binary };
		if (binFile.is_open()) {
			binFile.write((char*)&abc, sizeof abc);
			binFile.write((char*)&abcd, sizeof abc);
			binFile.close();
		}
		else {
			std::cerr << "Error opening file" << std::endl;
		}
	}


	void testZapisACteniBinarne2() {
		JednoduchaStruktura abc{ 1, 2, 3 };
		SlozitejsiStruktura structure{ abc, &abc };
		std::ofstream binFile{ "out.bin" };
		binFile.write((const char*)&structure, sizeof structure);
		binFile.close();
	}

	void testZapisACteniBinarne3() {
		NevyrovnanaStruktura structure{ 0x99, 0x12345678, 0x99, 3.14 };
		std::ofstream binFile{ "out.bin" }; binFile.write((const char*)&structure, sizeof structure);
		binFile.close();
	}


	void testZapisACteniBinarne4() {
		Struktura structure{ "ahoj svete" };
		std::ofstream binFile{ "out.bin" };
		binFile.write((const char*)&structure, sizeof structure);
		binFile.close();
	}

	/*špatně!!! s textem je nutné uložit nejprve jeho velikost*/
	void testZapisACteniBinarne5() {
		Struktura structure{ "ahoj svete, dneska je moc pekne!" };
		std::ofstream binFile{ "out.bin" }; binFile.write((const char*)&structure, sizeof structure); binFile.close();
	}

};



#endif
