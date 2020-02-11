#include "DatovySouborLoader.h"
using namespace std;
int DatovySouborLoader::poziceSekci[7];
int DatovySouborLoader::velikostSekci[7];


DatovySouborLoader::DatovySouborLoader() 
{
	
	/*vstup.read(poziceSekci, 7 * sizeof(int));
	vstup.read(velikostSekci, 7 * sizeof(int));
	vstup.*/

	int size;
	char * memblock;
	std::string * text;

	ifstream file("binaryinput06.bin", ios::in | ios::binary );
	if (file.is_open())
	{
		size = file.tellg();
		memblock = new char[size];

		file.seekg(0, ios::beg);

		file.read(memblock, size);
		file.close();

		

		for (size_t i = 0; i < 14; i++)
		{
			if (i < 7) {
				poziceSekci[i] = memblock[i];

			}
			else {
				velikostSekci[i] = memblock[i];
			}

		}

		file.seekg(poziceSekci[6], ios::beg);
		retezce = new char[velikostSekci[6]];
		file.read((char *)retezce, velikostSekci[6]);

		cout << "nacteno vse";
		//cout << retezce;

		delete[] memblock;
	}
	else cout << "neotevru to";



	
	
	

	
	
		
		


}

DatovySouborLoader::~DatovySouborLoader()
{
	
	delete retezce;


}

Osoba * DatovySouborLoader::nactiOsobu(int index)
{
	streampos size;
	char * memblock;
	Osoba * tmp;
	


	ifstream file("binaryinput06.bin", ios::in | ios::binary | ios::ate);
	if (file.is_open())
	{
		
		memblock = new char[velikostSekci[2]];

		file.seekg(poziceSekci[2], ios::beg);

		file.read(memblock, velikostSekci[2]);
		file.close();

		for (size_t i = 0; i < velikostSekci[2]; i+12)
		{
			if (index == i/12)
			{
				int jmeno = memblock[i];
				int prijmeni = memblock[i+1];
				int id = memblock[i+3];	
				retezce[jmeno];
				tmp = new Osoba{ "" ,"" , id };
				break;
			}
		}
		
		
		delete[] memblock;
		
	}
	else cout << "neotevru to";
	return nullptr;
}

Hierarchie * DatovySouborLoader::nactiHierarchii(int index)
{
	return nullptr;
}

int * DatovySouborLoader::najdiVsechnyHierarchie()
{
	return nullptr;
}
