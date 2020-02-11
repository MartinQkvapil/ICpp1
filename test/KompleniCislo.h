#ifndef KOMPLEX_H
#define KOMPLEX_H


#include <iostream>
#include <ostream>
#include <fstream>
#include <string>

class KompleniCislo
{
public:
	KompleniCislo() {};
	KompleniCislo(double r, double i) : re(r), im(i) { }

	friend std::ostream& operator<<(std::ostream& os, const KompleniCislo& obj) { os << obj.re << " " << obj.im; return os; }

	friend std::istream& operator>>(std::istream& is, KompleniCislo& obj) { is >> obj.re >> obj.im; return is; }

	

	std::string  toString() {
		return std::to_string(this->re) + " " +  std::to_string(this->im);
	}

	void writeIntoTxtFileLine() {
		std::ofstream out{};
		out.open("pokus.txt");

		KompleniCislo kc{ 5,2 };

		if (out.is_open()) {
			out << "radka textu";
			out << kc;

			out.close();
		}
		else std::cerr << "Soubor se nepodarilo otevrit...";
	}
	void writeIntoTxtFileObject() {
		std::ofstream out{};
		out.open("pokus.txt");

		KompleniCislo kc{ 5,2 };

		if (out.is_open()) {
			//	out << "radka textu";
			out << kc;

			out.close();
		}
		else std::cerr << "Soubor se nepodarilo otevrit...";
	}
	void writeIntoTxtFileCSV() {
		std::ofstream file;
		file.open("pokus.txt");
		if (file.is_open()) {
			file << "a" << "b" << "c" << std::endl;
		}
		std::cerr << "error";
	}

	void readFromTxtCSV() {

	}
	void readFromTxtLine() {
		std::string line;
		std::ifstream in{};
		in.open("pokus.txt");
		if (in.is_open()) {
			while (in >> line) {
				std::cout << line << " ";
				std::cout << std::endl;
			}
		}

	}
	void readFromTxtObject() {
		KompleniCislo kc{ 5,4 };
		std::ifstream in{};
		in.open("pokus.txt");
		if (in.is_open()) {
			while (in >> kc) {
				std::cout << kc << " ";
				std::cout << std::endl;
			}
		}

	}

	/* KOPIE SOUBORU PO ZNACICH */
	void copyFiles(std::string path1, std::string path2) {
		std::ifstream from{ path1 };
		std::ofstream to{ path2 }; 
		char ch;
		while (from.get(ch)) to.put(ch);
		from.close(); to.close();

	}

	void writeBinObject() {
		KompleniCislo* num = new KompleniCislo(10, 3);
		std::ofstream out;
		out.open("pokus.dat", std::ios_base::binary);
		if (out.is_open()) {
			out.write((char*)num, sizeof(KompleniCislo));
		}
		else {
			std::cerr << "error writeBinary" << std::endl;
		}
	}

	int generateNumberInRange(int a, int b) {
		return a + (std::rand() % (b - a + 1));
	}

	void writeBinObjects() {
		KompleniCislo* array[10];
		for (int i = 0; i < 10; i++)
		{
			array[i] = new KompleniCislo(generateNumberInRange(1, 10), generateNumberInRange(0, 5));
		}

		
		std::ofstream out;
		out.open("datdat.dat", std::ios_base::binary);
		if (out.is_open()) {
			std::cout << "Zapisovane cisla" << std::endl;
			for (int i = 0; i < 10; i++)
			{
				out.write((char*)array[i], sizeof(KompleniCislo));
				std::cout << array[i]->toString() << std::endl;
			}
			out.close();
		}
		else {
			 std::cerr << "Error writing to bin file" << std::endl;
		}
		
	}
	/*seekg(pozice, vychoziBod = ios_base::beg)
	(seek get)  posun £tecího kurzoru
	seekp	(pozice, vychoziBod = ios_base::beg) 
	(seek put)  posun zapisovacího kurzoru
		výchozí bod
		ios_base::beg  po£et bajt· od po£átku souboru ios_base::end  po£et bajt· od konce souboru ios_base::cur  po£et bajt· od aktuální pozice kurzoru*/

	

	void writeBinString(std::string fileName, std::string name) {
		std::ofstream out;

	

		out.open(fileName, std::ios_base::binary);
		if (out.is_open()) {
			size_t size = name.size();
			out.write((char *)&size, sizeof(size_t));
			out.write(name.c_str(), size);	

			
			out.close();
		}
		else {
			throw std::exception("Chyba string");
		}
	};

	std::string readBinString(std::string fileName) {
		
		std::string str;
		
		std::ifstream in;
		in.open(fileName, std::ios_base::binary);
		if (in.is_open()) {
			size_t size;
			in.read((char*)&size, sizeof(size_t));
			str.resize(size);
			in.read((char*) &str[0], size);
			return str;
		}
		else {
			std::cerr << "Chyba string" << std::endl;
		}
		return "";
	};


	void readBinObjects() {
		KompleniCislo* nums[10];
		for (int i = 0; i < 10; i++)
		{
			nums[i] = new KompleniCislo();
		}
		std::ifstream in;
		in.open("datdat.dat", std::ios_base::binary);
		//in.seekg(0, std::ios::end);
		int file_size = in.tellg();
		std::cout << "Size of file: " << in.tellg() << std::endl;
		in.seekg(0, std::ios::beg); 
		in.seekg(16, std::ios::beg);
		if (in.is_open()) {
			for (int i = 0; i < 10; i++)
			{
				in.read((char*)nums[i], sizeof(KompleniCislo));
				std::cout << nums[i]->toString() << std::endl;
			}
		}
		else {
			std::cerr << "Unable to readObjects" << std::endl;
		}
	}

	/*ostringstream  výstupní (lze do n¥j zapisovat) pam¥´ový proud 
	istringstream  vstupní (lze z n¥j £íst) pam¥´ový prou*/

	 void readBinObject() {
		KompleniCislo* temp = new KompleniCislo(0,0);
		std::ifstream in;
		in.open("pokus.dat", std::ios_base::binary);
		if (in.is_open()) {
			in.read((char*)temp, sizeof(KompleniCislo));
		}
		std::cout << "From Bin KomplexNumber: " << temp->toString() << std::endl;
	}
	

	/*ZÁPIS DO BINÁRNÍHO SOUBORU */
	void writeIntoBinaryFile() {
		int pole[4] = { 5, 1, 3, 2 };
		std::ofstream out{};
		out.open("datfile.dat", std::ios_base::binary);

		if (out.is_open()) { 
			out.write((char *)pole, sizeof(pole));
			out.close(); 
		}
		else std::cerr << "Nepodarilo se otevrit!" << std::endl;
	}

	/*ČTENÍ Z BINÁRNÍHO SOUBORU */
	void readIntoBinaryFile() {
		const int num = 4;
		int pole[num];
		std::ifstream in{};
		in.open("datfile.dat", std::ios_base::binary);

		if (in.is_open()) {
			in.read((char *)pole, sizeof(pole));
			for (int i = 0; i < num; i++)
			{
				std::cout << num << ":" << pole[i] << std::endl;
			}
			in.close();
		}
		else std::cerr << "Nepodarilo se otevrit!" << std::endl;
	}




private:
	double re; double im;

};

#endif 
