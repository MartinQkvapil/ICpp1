#include <iostream>
#include <ostream>
#include <sstream>

#include "Person.h"
#include "Address.h"
#include "Date.h"

using namespace std;

/*Ve funkci main volejte funkce uloz() a nacti(). Ve funkci uloz() vytvoøte statické pole objektù
Osoba (s alespoò 3 objekty) a zapište jej do souboru. */

static string cteniString(ifstream* soubor)
{
	string str = "";
	char znak;

	do {
		soubor->read((char*)&znak, 1);

		if (znak != '\0') {
			str += znak;
		}

	} while (znak != '\0');

	return str;
}

static string pripravaStringu(string str) {
	char lastChar = *str.rbegin();
	if (lastChar != '\0')
	{
		str += '\0';
	}
	return str;
}

//void saveToBin() {
//	Address address1{ "Ostrov","Letohrad", 56151 };
//	Date date1{ 20,01,1995 };
//
//	Person persons[] = {
//		{ "Martin", "Kvapil", address1 ,date1 },{ "Zdenek", "Kvapil", address1 ,date1 }
//	};
//
//	ofstream soubor("osoby.dat", ios_base::out | ios_base::binary);
//	for (int i = 0; i < sizeof os / sizeof os[0]; i++) {
//		string pom = pripravaStringu(os[i].getJmeno());
//		soubor.write((char*)pom.c_str(), pom.size());
//		pom = pripravaStringu(os[i].getPrijmeni());
//		soubor.write((char*)pom.c_str(), pom.size());
//
//		int c = os[i].getDatum().getDen();
//		soubor.write((char*)&c, sizeof(int));
//		c = os[i].getDatum().getMesic();
//		soubor.write((char*)&c, sizeof(int));
//		c = os[i].getDatum().getRok();
//		soubor.write((char*)&c, sizeof(int));
//	}
//	soubor.close();
//}

void saveToText() {
	Address address1{ "Ostrov","Letohrad", 56151 };
	Date date1{ 20,01,1995 };

	Person persons[] = {
		{ "Martin", "Kvapil", address1 ,date1 },{ "Zdenek", "Kvapil", address1 ,date1 }
	};
	ofstream txtFile{ "persons.txt" };
	for (int i = 0; i < 2; i++) {
		txtFile << persons[i] << endl;
	}
	txtFile.close();

}

void loadFromText() {
	ifstream txtFile{ "persons.txt" };

		Person persons[2];	
			
		for (int i = 0; i < 2; i++) {
			txtFile >> persons[i];
		}
		
		for (int i = 0; i < 2; i++) {
			cout << ">>>: " << persons[i] << endl;
		}
		txtFile.close();
	
	

}

void saveToBin() {}

void loadFromBin() {}

int main()
{
	saveToText();
	loadFromText();

	saveToBin();
	loadFromBin();
}