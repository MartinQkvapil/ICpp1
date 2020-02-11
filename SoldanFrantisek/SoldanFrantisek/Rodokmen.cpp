#include "Rodokmen.h"

Rodokmen::Rodokmen(std::istream& is) {
	std::string radek;
	std::string token;
	int pozice;
	pocetOsob = 0;
	while (getline(is, radek))
	{
		pozice = radek.find(" ");
		token = radek.substr(0, pozice);
		// smazani tokenu + mezery
		radek.erase(0, pozice + 1);

		if (token == "OSOBA") {
			// ID
			int id;
			pozice = radek.find(" ");
			token = radek.substr(0, pozice);
			try {
				id = stoi(token);
			}
			catch(...) {
				std::cout << "id neni cislo" << std::endl;
			}
			// smazani tokenu + mezery
			radek.erase(0, pozice + 1);
			// pohlavi
			char pohlavi;
			pozice = radek.find(" ");
			token = radek.substr(0, pozice);
			if (token.length() > 1) {
				throw "Neplatne pohlavi";
			}
			pohlavi = token.at(0);
			// smazani tokenu + mezery
			radek.erase(0, pozice + 1);
			Osoba** temp = new Osoba*[pocetOsob+1];
			for (int i = 0; i < pocetOsob; i++)
			{
				temp[i] = osoby[i];
			}
			temp[pocetOsob] = new Osoba(id, pohlavi, radek);
			pocetOsob++;
			osoby = temp;
		}
		else if (token == "VZTAH") {
			Osoba* os1 = nullptr;
			Osoba* os2 = nullptr;
			//VZTAH 18 19 11 partneri
			// osoba1
			int osoba1;
			pozice = radek.find(" ");
			token = radek.substr(0, pozice);
			try {
				osoba1 = stoi(token);
			}
			catch (...) {
				std::cout << "id neni cislo" << std::endl;
			}
			radek.erase(0, pozice + 1);
			// osoba2
			int osoba2;
			pozice = radek.find(" ");
			token = radek.substr(0, pozice);
			try {
				osoba2 = stoi(token);
			}
			catch (...) {
				std::cout << "id neni cislo" << std::endl;
			}
			radek.erase(0, pozice + 1);
			// id
			int id;
			pozice = radek.find(" ");
			token = radek.substr(0, pozice);
			try {
				id = stoi(token);
			}
			catch (...) {
				std::cout << "id neni cislo" << std::endl;
			}
			radek.erase(0, pozice + 1);
			// nalezeni osob a prirazeni vztahu
			for (int i = 0; i < pocetOsob; i++)
			{
				if (osoby[i]->getId() == osoba1) {
					os1 = osoby[i];
				} else if (osoby[i]->getId() == osoba2) {
					os2 = osoby[i];
				}
			}
			if (os1 != nullptr && os2 != nullptr) {
				os1->pridatVztah(id, os2, radek);
				os2->pridatVztah(id, os1, radek);
			}
		}
		else if (token == "POTOMEK") {
			
			// id
			int idVztah;
			pozice = radek.find(" ");
			token = radek.substr(0, pozice);
			try {
				idVztah = stoi(token);
			}
			catch (...) {
				std::cout << "id neni cislo" << std::endl;
			}
			radek.erase(0, pozice + 1);
			// id
			int id;
			try {
				id = stoi(radek);
			}
			catch (...) {
				std::cout << "id neni cislo" << std::endl;
			}
			Osoba* os = nullptr;
			for (int i = 0; i < pocetOsob; i++)
			{
				if (osoby[i]->getId() == id) {
					os = osoby[i];
				}
			}
			if (os != nullptr) {
				// pridani potomkù do vztahù
				for (int i = 0; i < pocetOsob; i++)
				{
					for (int j = 0; j < osoby[i]->getPocetVztahu(); j++)
					{
						if (osoby[i]->getVztahy()[j]->getID() == idVztah) {
							osoby[i]->getVztahy()[j]->pridatPotomka(os);
						}

					}
				}
			}
			
		}
		else {
			throw "Neplatny identifikator";
		}
	}
}
int Rodokmen::dejPocetPrimychPotomku(int idOsoby) {
	int pocet = 0;
	for (int i = 0; i < pocetOsob; i++)
	{
		if (osoby[i]->getId() == idOsoby) {
			
			for (int j = 0; j < osoby[i]->getPocetVztahu(); j++)
			{
				pocet += osoby[i]->getVztahy()[j]->getPocetPrimychPotomku();
			}
		}
	}
	return pocet;
}
int Rodokmen::dejPocetVsechPotomku(int idOsoby) {
	int pocet = 0;
	for (int i = 0; i < pocetOsob; i++)
	{
		if (osoby[i]->getId() == idOsoby) {
			pocet = osoby[i]->getVsechnyPotomky();
		}
		
	}
	for (int j = 0; j < pocetOsob; j++)
	{
		osoby[j]->pocitan = false;
	}
	return pocet;
}

Rodokmen::~Rodokmen() {
	for (int i = 0; i < pocetOsob; i++)
	{
		delete osoby[i];
	}
	delete[] osoby;
}