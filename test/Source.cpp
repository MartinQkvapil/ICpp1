#include <iostream>
#include <string>
#include <sstream>

#include "ReaderStream.h"
#include "Person.h"
#include "Lecture01.h"
#include "KompleniCislo.h"
#include "SingleLinkedList.h"
#include "DoublyLindedList.h"
#include "BinaryFiles.h"
#include "RuzneFunkce.h"
#include "Podminka.h"
#include "Pole.h"
#include "HashTable.h"
#include "Entity.h"

#include "crtdbg.h"

//https://www.algoritmy.net/

#ifdef _DEBUG
#define DEBUG_NEW   new( _NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define DEBUG_NEW
#endif


using namespace std;

int main() {
	int index = 0;

	//Lecture01 lec{};
	//lec.testNamespace();
	//lec.callException(5);


	//KompleniCislo* kc = new KompleniCislo(10, 2);
	//cout << "Komplexni cislo je: " << kc;
	//kc->writeBinString("datstring.dat", "Martin je borec");
	//std::cout << kc->readBinString("datstring.dat") << std::endl;

	//std::ostringstream oss{}; oss << "vystupni" << ' ' << "datovy" << ' ' << "proud" << ' '  << 12345;
	//std::string s = oss.str(); cout << s << endl;

	string s = "jan maly 123456";
	istringstream iss{ s };
	string jmeno;
	string prijmeni;
	int id;
	iss >> jmeno >> prijmeni >> id;
	std::cout << "J:" << jmeno << " P:" << prijmeni << " I:" << id;

	std::cout << endl;


	
	

	BinaryFiles* temp = new BinaryFiles;

	temp->testZapisZvirate();


	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	system("pause");
	return 0;
}

/// https://github.com/st52550/Cplusplus // PLAŠIL
/// https://github.com/Ben811/ICpp1/blob // BEN

/// https://docs.google.com/document/d/1UJQUnN8jxzRu3uHei9I1-TTBPpovrhcj2dfWeqjKte0/edit

/// https://github.com/aozturk/HashMap/tree/master/hashmap // hash map!!!
/// https://gist.github.com/jizhilong/6774742 // heap!!!
/// https://gist.github.com/miguelgazela/4428700 // Graf!!!


