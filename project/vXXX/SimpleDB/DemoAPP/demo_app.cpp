#include "dbapi.h"
#include "helpful.h"
#include <limits>

using namespace std;

// TODO deaklokace check!!! --------
#include "crtdbg.h"
// END TODO deaklokace check!!! ----


void printHelp() {
	cout << "=============================================" << endl;
	cout << "VITEJTE V SIMPLEDB." << endl;
	cout << "\tDEMO" << endl;
	cout << "\tPro rychle nacteni demo-dat: test" << endl;
	cout << "\tPro ukonceni programu: end" << endl;
	cout << "\tPro zobrazeni napovedy: help" << endl;
	cout << "\tDATABASE" << endl;
	cout << "\tPro vytvoreni / otevreni nove databaze: opendb" << endl;
	cout << "\tPro uzavreni databaze: closedb" << endl;
	cout << "\tTABLE" << endl;
	cout << "\tPro vytvoreni nove tabulky: openorcreatetable" << endl;
	cout << "\tPro uzavreni tabulky: closetable" << endl;
	cout << "\tPro insert do tabulky: insert" << endl;
	cout << "\tPro select do tabulky: select" << endl;
	cout << "\tPro commit tabulky: commit" << endl;
	cout << "\tPro remove radku tabulky: remove" << endl;
	cout << "=============================================" << endl;
}

bool isActive(vector<Table*> vec, std::string name) {
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec.at(i)->getNameOfTable() == name) {
			return true;
		}
	}
	return false;
}

bool validateString(const std::string& s)
{
	for (const char c : s) {
		if (!isalpha(c) && !isspace(c))
			return false;
	}

	return true;
}

FieldObject** retFieldObject(int colCount, FieldObject** tmp)
{
	FieldObject** fields;
	switch (colCount) {
	case 1:
		fields = combineToDefinition(tmp[0]);
		break;
	case 2:
		fields = combineToDefinition(tmp[0], tmp[1]);
		break;
	case 3:
		fields = combineToDefinition(tmp[0], tmp[1], tmp[2]);
		break;
	case 4:
		fields = combineToDefinition(tmp[0], tmp[1], tmp[2], tmp[3]);
		break;
	case 5:
		fields = combineToDefinition(tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
		break;
	default:
		throw std::exception("Neznamy pocet sloupcu");
	}

	return fields;
}

void printTable(Table* tab) {

	auto it = tab->select();
	for (int i = 0; i < tab->getFieldCount(); i++)
	{
		cout << "\t " << tab->getFields()[i]->getName();
	}
	cout << endl;
	cout << "======================================" << endl;

	while (it->moveNext())
	{
		auto row = it->getRow();
		for (int i = 0; i < tab->getFieldCount(); i++)
		{
			switch (tab->getFields()[i]->getType())
			{
			case FieldType::Integer:
				cout << "\t " << row[i]->getInt();
				break;
			case FieldType::String:
				cout << "\t " << row[i]->getString();
				break;
			case FieldType::Double:
				cout << "\t " << row[i]->getDouble();
				break;

			default:
				cout << "print table bad type" << endl;
				break;
			}
		}
		cout << endl;
	}
	cout << "----------------------------------------" << endl;

	it->close();

}

std::string getString(std::string quote) {
	std::string temp = "";
	std::cout << quote << std::endl;
	while (1) {
		std::cin >> temp;
		if (validateString(temp)) {
			break;
		}
		std::cout << "Nevalidni string, zadejte znovu" << std::endl;
	}
	return temp;
}

FieldType getType(std::string quote) {
	std::string temp = "";
	std::cout << quote << std::endl;
	while (1) {
		std::cin >> temp;
		if (temp == "string") {
			return FieldType::String;
		}
		else if (temp == "double") {
			return FieldType::Double;
		}
		else if (temp == "integer") {
			return FieldType::Integer;
		}
		std::cout << "Nevalidni typ, zadejte znovu" << std::endl;
	}

}

int getInt(std::string quote) {
	int a;

	std::cout << quote << std::endl;
	cin >> a;
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Zadal jsi nesprávnou hodnotu" << endl;
			cin >> a;
		}
		if (!cin.fail())
			break;
	}
	return a;
}

double getDouble(std::string quote) {
	double a;

	std::cout << quote << std::endl;
	cin >> a;
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Zadal jsi nesprávnou hodnotu" << endl;
			cin >> a;
		}
		if (!cin.fail())
			break;
	}
	return a;
}

Object** getRow(int count, FieldObject** fields) {
	Object* tempObj[5];
	for (int i = 0; i < count; i++)
	{
		if (fields[i]->getType() == FieldType::Integer) {
			tempObj[i] = Db::Int((getInt("Zadej int")));
		}
		else if (fields[i]->getType() == FieldType::String) {
			tempObj[i] = Db::String(getString("Zadej string"));
		}
		else if (fields[i]->getType() == FieldType::Double) {
			tempObj[i] = Db::Double(getDouble("Zadej double"));
		}
		else {
			throw std::exception("Neznamy dat type");
		}
	}

	Object** row;
	switch (count) {
	case 1:
		row = combineToRow(tempObj[0]);
		break;
	case 2:
		row = combineToRow(tempObj[0], tempObj[1]);
		break;
	case 3:
		row = combineToRow(tempObj[0], tempObj[1], tempObj[2]);
		break;
	case 4:
		row = combineToRow(tempObj[0], tempObj[1], tempObj[2], tempObj[3]);
		break;
	case 5:
		row = combineToRow(tempObj[0], tempObj[1], tempObj[2], tempObj[3], tempObj[4]);
		break;
	default:
		throw std::exception("Neznamy pocet sloupcu");
	}
	return row;
}

Table* getActiveTableByName(vector<Table*> vec, std::string name) {
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec.at(i)->getNameOfTable() == name) {
			return vec.at(i);
		}
	}
	return nullptr;
}

void testdbFinal() {
	printHelp();
	Db* db = nullptr;
	std::string tmp;
	bool isOpenedDB = false;
	std::string nameOfDatabase;
	std::vector<Table*> active;

	while (1) {
		cout << ":";
		cin >> tmp;

		if (tmp == "end") {
			if (isOpenedDB) {
				for (size_t i = 0; i < active.size(); i++)
				{
					active.at(i)->close();
				}
				db->close();
				break;
			}
			else {
				break;
			}
		}
		else if (tmp == "help") {
			printHelp();
		}
		else if (tmp == "remove") {
			if (isOpenedDB) {
				bool valid = false;
				std::string tabNameClose = getString("Zadejte nazev tabulky pro remove");
				if (!isActive(active, tabNameClose)) {
					cout << "Neni otevrena" << endl;
					continue;
				}
				printTable(getActiveTableByName(active, tabNameClose));
				int rowID = getInt("Zadejte id radku pro odebrani");
				for (size_t i = 0; i < active.size(); i++)
				{
					if (active.at(i)->getNameOfTable() == tabNameClose) {
						active.at(i)->remove(rowID);
						valid = true;
					}
				}
				if (!valid) {
					cout << "tabulka NEexistuje" << endl;
				}
			}
			else {
				std::cout << "Neni otevrena zadna databaze" << std::endl;
			}
		}
		else if (tmp == "test") {
			if (!isOpenedDB) {
				isOpenedDB = true;
				printHelp();
				db = Db::open("carusers");
				Table* users = db->openTable("users");
				Table* cars = db->openTable("cars");
				Table* usercar = db->openTable("usercar");
				active.push_back(users);
				active.push_back(cars);
				active.push_back(usercar);
				printTable(users);
				printTable(cars);
				printTable(usercar);
			}
			else {
				cout << "jina databaze je jiz otevrena" << endl;
			}
		}
		else if (tmp == "commit") {
			if (isOpenedDB) {
				bool valid = false;
				std::string tabNameClose = getString("Zadejte nazev tabulky pro commit");
				for (size_t i = 0; i < active.size(); i++)
				{
					if (active.at(i)->getNameOfTable() == tabNameClose) {
						//printTable(active.at(i));
						active.at(i)->commit();
						valid = true;
					}
				}
				if (!valid) {
					cout << "tabulka NEexistuje" << endl;
				}
			}
			else {
				std::cout << "Neni otevrena zadna databaze" << std::endl;
			}
		}
		else if (tmp == "select") {
			if (isOpenedDB) {
				bool valid = false;
				std::string tabNameClose = getString("Zadejte nazev tabulky pro select");
				for (size_t i = 0; i < active.size(); i++)
				{
					if (active.at(i)->getNameOfTable() == tabNameClose) {
						printTable(active.at(i));
						valid = true;
					}
				}
				if (!valid) {
					cout << "tabulka NEexistuje" << endl;
				}
			}
			else {
				std::cout << "Neni otevrena zadna databaze" << std::endl;
			}
		}
		else if (tmp == "insert") {
			if (isOpenedDB) {
				bool valid = false;
				std::string tabNameClose = getString("Zadejte nazev tabulky do ktere chcete vlozit");
				for (size_t i = 0; i < active.size(); i++)
				{
					if (active.at(i)->getNameOfTable() == tabNameClose) {
						active.at(i)->insert(getRow(active.at(i)->getFieldCount(), active.at(i)->getFields()));
						cout << "radek vlozen do tabulky" << endl;
						valid = true;
					}
				}
				if (!valid) {
					cout << "tabulka NEvlozeno / NEexistuje" << endl;
				}
			}
			else {
				std::cout << "Neni otevrena zadna databaze" << std::endl;
			}
		}
		else if (tmp == "closetable") {
			if (isOpenedDB) {
				bool valid = false;
				std::string tabNameClose = getString("Zadejte nazev zavirane tabulky");
				for (size_t i = 0; i < active.size(); i++)
				{
					if (active.at(i)->getNameOfTable() == tabNameClose) {
						active.at(i)->close();
						active.erase(active.begin() + i);
						cout << "tabulka uzavrena" << endl;
						valid = true;
					}
				}
				if (!valid) {
					cout << "tabulka NEuzavrena / NEexistuje" << endl;
				}
			}
			else {
				std::cout << "Neni otevrena zadna databaze" << std::endl;
			}
		}
		else if (tmp == "openorcreatetable") {
			if (isOpenedDB) {
				std::string tabName = getString("Zadejte nazev tabulky");
				if (isActive(active, tabName)) {
					cout << "Uz je otevrena" << endl;
					break;
				}
				int tapCols = getInt("Zadejte pocet sloupcu tabulky 1-5");
				FieldObject* tmp[5];
				for (int i = 0; i < tapCols; i++)
				{
					tmp[i] = Db::Field(getString("Zadejte nazev sloupce "), getType("Zadejte typ sloupce (integer, string, double)"));
				}
				Table* tempTable = db->openOrCreateTable(
					tabName,
					tapCols, 					
					retFieldObject(tapCols, tmp));

				active.push_back(tempTable);
			}
			else {
				cout << "Nelze vytvorit tabulku bez databaze" << endl;
			}
		}
		else if (tmp == "opendb") {
			if (!isOpenedDB) {
				cout << "Zadejte nazev databaze:\n";
				cin >> nameOfDatabase;
				if (!validateString(tmp)) {
					cout << " Nevalidni nazev databaze\n";
					continue;
				}
				db = Db::open(nameOfDatabase);
				cout << "Databaze s nazvem: " << nameOfDatabase << " byla otevrena\n";
				isOpenedDB = true;
			}
			else {
				cout << "Jiz mate otevrenou databazi: " << nameOfDatabase << endl;
				cout << "Pro uzavreni zadejte: closedb" << nameOfDatabase << endl;
			}
		}
		else if (tmp == "closedb") {
			if (isOpenedDB) {
				//// Uzavøení db
				if (active.size() != 0) {
					for (size_t i = 0; i < active.size(); i++)
					{
						cout << "Nejprve uzavrete tabulky:" << active.at(i)->getNameOfTable() << std::endl;
					}
				}
				else {
					isOpenedDB = false;
					db->close();
				}
			}
			else {
				cout << "Zadna databaze neni otevrena " << endl;
				cout << "Pro otevreni database zadejte: createdb" << endl;
			}
		}
		else {
			cout << "Neznama volba: Pro zobrazeni napovedy zadejte help\n";
		}
	}
}

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // allocation check
	testdbFinal();
	return 0;
}


