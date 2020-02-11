#include "dbapi.h"
#include "helpful.h"



static std::string retType(FieldType type) {
	switch (type) {
	case FieldType::Double:
		return "d";
	case FieldType::Integer:
		return "i";
	case FieldType::String:
		return "s";
	case FieldType::Field:
		return "f";
	default:
		throw std::exception("Unknown type");
	}
}

static FieldType goType(char type) {
	switch (type) {
	case 'd':
		return FieldType::Double;
	case 'i':
		return FieldType::Integer;
	case 's':
		return FieldType::String;
	case 'f':
		return FieldType::Field;
	default:
		throw std::exception("Unknown type");
	}
}


Db* Db::open(std::string database)
{
	// Prohlédnout, jestli neexistuje databáze se stejným názvem jinak jí vytvoøit. 
	std::ifstream infile("all-databases.txt");
	std::string line;
	bool app = true;
	while (std::getline(infile, line))
	{
		if (line == database) {
			app = false;
			break;
		}
		else {
			app = true;
		}
	}
	infile.close();

	if (!app) {
		std::cout << "DATABASE ALREADY EXIST" << std::endl;
		Db* db = new Db();
		db->_nameOfDatabase = line;
		return db;
	}
	else {
		std::cout << "CREATING NEW DATABASE" << std::endl;
		Db* db = new Db();
		db->_nameOfDatabase = database;
		return db;
	}
}

void Db::close()
{
	_tables.clear(); // smazu tabulky v db
	delete this;
}

Table* Db::createTable(std::string name, int fieldsCount, FieldObject** fields)
{
	for (size_t i = 0; i < _tables.size(); i++)
	{
		if (_tables[i]->getNameOfTable() == name) {
			std::cout << "TABLE ALREADY EXIST" << std::endl;
			return nullptr;
			//throw std::exception("Table already exist");
		}
	}
	// TODO check jestli existuje v souboru jeste 

	Table* temp = new Table(name, fields, 0, fieldsCount, _nameOfDatabase);
	_tables.push_back(temp);

	return temp;
}


Table* Db::openTable(std::string name)
{
	for (size_t i = 0; i < _tables.size(); i++)
	{
		if (_tables[i]->getNameOfTable() == name) {
			std::cout << "TABLE WITH THIS NAME IS ALREADY OPENED" << std::endl;
			//throw std::exception("Table already exist");
		}
	}

	std::ifstream inFile("database/head/" + _nameOfDatabase + "_" + name + ".table");
	std::string dbname;
	std::string tableName;
	int rowCount;
	int colCount;
	inFile >> dbname >> tableName >> rowCount >> colCount;
	inFile.close();

	if (dbname != _nameOfDatabase) {
		return nullptr;
	}

	std::ifstream inFile2("database/cols/" + _nameOfDatabase + "_" + name + ".cols");
	FieldObject* tmp[6];
	for (int i = 0; i < colCount; i++)
	{
		std::string name2;
		std::string type2;
		inFile2 >> name2 >> type2;
		tmp[i] = Field(name2, goType(type2[0]));
		
	}
	inFile2.close();
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

	// DATA LOAD
	Object*** data = new Object**[rowCount];
	std::ifstream inFile3("database/data/" + _nameOfDatabase + "_" + name + ".data");

	if (!inFile3)
	{
		throw std::exception(" DATA FILE ERROR ");
	}

	Object* tempObj[5];
	for (int i = 0; i < rowCount; i++) // pocet radku v souboru
	{

		for (int j = 0; j < colCount; j++) // 
		{
			std::string names;
			std::string types;
			inFile3 >> names >> types;
			if (types == "i") {
				tempObj[j] = Int(std::stoi(names));
			}
			else if (types == "s") {
				tempObj[j] = String(names);
			}
			else if (types == "d") {
				tempObj[j] = Double(std::stod(names));
			}
			else {
				throw std::exception("Neznamy dat type");
			}
		}

		Object** row;
		switch (colCount) {
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
		data[i] = row;

	}
	inFile3.close();

	Table* temp = new Table(name, fields, rowCount, colCount, dbname, data);
	_tables.push_back(temp);
	return temp;
}

Table* Db::openOrCreateTable(std::string name, int fieldsCount, FieldObject** fields)
{
	std::ifstream inFile("database/head/" + _nameOfDatabase + "_" + name + ".table");
	std::string dbname;
	std::string tableName;
	int rowCount;
	int colCount;
	inFile >> dbname >> tableName >> rowCount >> colCount;
	inFile.close();
	
	if (dbname == _nameOfDatabase && tableName == name) {
		for (int i = 0; i < fieldsCount; i++)
		{
			delete fields[i];
		}
		delete[] fields;
		
		return Db::openTable(name);

	}
	Table* temp = new Table(name, fields, 0, fieldsCount, _nameOfDatabase);
	_tables.push_back(temp);
	return temp;
}

Object* Db::Int(int value)
{
	return new IntObject(value);
}

Object* Db::Double(double value)
{
	return new DoubleObject(value);
}

Object* Db::String(std::string value)
{
	return new StringObject(value);
}

FieldObject* Db::Field(std::string name, FieldType type)
{
	return new FieldObject(name, type);
}

Object::Object()
{
}

Object::~Object()
{
}

std::string Object::getString() const
{
	return std::string();
}

void Object::setString(std::string value)
{
	throw std::exception("Neznamy datovy typ");
}

int Object::getInt() const
{
	throw std::exception("Neznamy datovy typ");
}

void Object::setInt(int value)
{
	throw std::exception("Neznamy datovy typ");
}

double Object::getDouble() const
{
	throw std::exception("Neznamy datovy typ");
}

void Object::setDouble(double value)
{
	throw std::exception("Neznamy datovy typ");
}

bool Object::isType(FieldType type) const
{
	throw std::exception("Neznamy datovy typ");
}



void Table::insert(Object** row)
{
	int tempCount = _rowCount + 1;
	Object*** CP_data = new Object * *[tempCount]; // o jedno zvetsit

	for (int i = 0; i < _rowCount; i++)
	{
		CP_data[i] = new Object * [_columnCount];
		for (int j = 0; j < _columnCount; j++)
		{
			if (_data[i][j]->isType(FieldType::Integer)) {
				CP_data[i][j] = new IntObject(_data[i][j]->getInt());
			}
			else if (_data[i][j]->isType(FieldType::Double)) {
				CP_data[i][j] = new DoubleObject(_data[i][j]->getDouble());
			}
			else if (_data[i][j]->isType(FieldType::String)) {
				CP_data[i][j] = new StringObject(_data[i][j]->getString());
			}
			else {
				throw std::exception("Insert exception");
			}
		}
	}

	for (int i = 0; i < _rowCount; i++)
	{
		for (int j = 0; j < _columnCount; j++)
		{
			delete _data[i][j];
		}
		delete[] _data[i];
	}
	delete[] _data;

	bool flag = true;
	for (int i = 0; i < _columnCount; i++)
	{
		if (flag) {
			CP_data[_rowCount] = row;
			flag = false;
		}
		if (row[i]->isType(FieldType::Integer)) {
			CP_data[_rowCount][i] = dynamic_cast<IntObject*>(row[i]);

			//flag = false;
		}
		else if (row[i]->isType(FieldType::Double)) {
			CP_data[_rowCount][i] = dynamic_cast<DoubleObject*>(row[i]);

			//flag = false;
		}
		else if (row[i]->isType(FieldType::String)) {
			CP_data[_rowCount][i] = dynamic_cast<StringObject*>(row[i]);

			//flag = false;
		}
		else {
			throw std::exception("Insert exception");
		}
	}
	_rowCount++;
	_data = CP_data;
}

void Table::remove(int rowid)
{
	int tempCount = _rowCount + 1;
	Object*** CP_data = new Object * *[tempCount]; // o jedno zvetsit
	bool flag = true;
	for (int i = 0; i < _rowCount; i++)
	{
		
		if (i == rowid && flag) {
			flag = false;
			std::cout << "REMOVE ID" << std::endl;
			for (int j = 0; j < _columnCount; j++)
			{
				delete _data[i][j];
			}
			delete _data[i];	
			continue;
		}
		if (flag) {
			CP_data[i] = new Object * [_columnCount];
			for (int j = 0; j < _columnCount; j++)
			{
				if (_data[i][j]->isType(FieldType::Integer)) {
					CP_data[i][j] = new IntObject(_data[i][j]->getInt());
				}
				else if (_data[i][j]->isType(FieldType::Double)) {
					CP_data[i][j] = new DoubleObject(_data[i][j]->getDouble());
				}
				else if (_data[i][j]->isType(FieldType::String)) {
					CP_data[i][j] = new StringObject(_data[i][j]->getString());
				}
				else {
					throw std::exception("Insert exception");
				}
			}
		}
		else {
			CP_data[i-1] = new Object * [_columnCount];
			for (int j = 0; j < _columnCount; j++)
			{
				if (_data[i][j]->isType(FieldType::Integer)) {
					CP_data[i-1][j] = new IntObject(_data[i][j]->getInt());
				}
				else if (_data[i][j]->isType(FieldType::Double)) {
					CP_data[i-1][j] = new DoubleObject(_data[i][j]->getDouble());
				}
				else if (_data[i][j]->isType(FieldType::String)) {
					CP_data[i-1][j] = new StringObject(_data[i][j]->getString());
				}
				else {
					throw std::exception("Insert exception");
				}
			}
		}
	}
	_rowCount--;
	_data = CP_data;
}

Iterator* Table::select()
{
	return new Iteruj(_rowCount, _data);
}

static std::string cteniString(std::ifstream* soubor)
{
	std::string str = "";
	char znak;

	do {
		soubor->read((char*)&znak, 1);

		if (znak != '\0') {
			str += znak;
		}

	} while (znak != '\0');

	return str;
}


void Table::commit()
{
	std::string fileName = _databaseName + "_" + _tableName + ".table";
	std::string fileNameDATA = _databaseName + "_" + _tableName + ".data";
	std::string fileNameCOLS = _databaseName + "_" + _tableName + ".cols";
	std::string fileDATABASE = "all-databases.txt";

	// FILE WITH NAME OF DATABASEs
	std::ifstream infile(fileDATABASE);
	std::string line;
	bool app = true;
	while (std::getline(infile, line))
	{
		if (line == _databaseName) {
			app = false;
			break;
		}
		else {
			app = true;
		}
	}
	infile.close();
	if (app) {
		std::ofstream fileNAMES(fileDATABASE, std::ios_base::app);
		fileNAMES << _databaseName << std::endl;
		fileNAMES.close();
	}

	// HEAD SAVE
	std::ofstream txtTabNameFile("database/head/" + fileName);
	txtTabNameFile << _databaseName << std::endl;
	txtTabNameFile << _tableName << std::endl;
	txtTabNameFile << _rowCount << std::endl;
	txtTabNameFile << _columnCount << std::endl;
	txtTabNameFile.close();

	// COLS SAVE
	std::ofstream txtTabColsFILE("database/cols/" + fileNameCOLS);
	for (int i = 0; i < _columnCount; i++)
	{
		txtTabColsFILE << getFields()[i]->getName() << std::endl;
		txtTabColsFILE << retType(getFields()[i]->getType()) << std::endl;
	}
	txtTabColsFILE.close();

	// DATA SAVE
	std::ofstream txtTabNameDATAFile("database/data/" + fileNameDATA);
	
	for (int i = 0; i < _rowCount; i++)
	{
		for (int j = 0; j < _columnCount; j++)
		{
			
			if (_data[i][j]->isType(FieldType::String)) {
				txtTabNameDATAFile << _data[i][j]->getString() << " ";
				txtTabNameDATAFile << retType(FieldType::String) << std::endl;
			}
			if (_data[i][j]->isType(FieldType::Integer)) {
				txtTabNameDATAFile << _data[i][j]->getInt() << " ";
				txtTabNameDATAFile << retType(FieldType::Integer) << std::endl;
			}
			if (_data[i][j]->isType(FieldType::Double)) {
				txtTabNameDATAFile << _data[i][j]->getDouble() << " ";
				txtTabNameDATAFile << retType(FieldType::Double) << std::endl;
			}
		}
		txtTabNameDATAFile << std::endl;
	}
	txtTabNameDATAFile.close();





}

void Table::close()
{
	for (int i = 0; i < _columnCount; i++)
	{
		delete _columns[i];
	}
	delete[] _columns;

	for (int i = 0; i < _rowCount; i++)
	{
		for (int j = 0; j < _columnCount; j++)
		{
			delete _data[i][j];
		}
		//std::cout << row[1]->getString() << std::endl;
		delete[] _data[i];
	}

	delete[] _data;
	delete this;
}

int Table::getRowCount() const
{
	return _rowCount;
}

FieldObject** Table::getFields() const
{
	return _columns;
}

int Table::getFieldCount() const
{
	return _columnCount;
}



Iterator::~Iterator()
{
}

std::string StringObject::getString() const
{
	return value;
}

void StringObject::setString(std::string value)
{
	this->value = value;
}

bool StringObject::isType(FieldType type) const
{
	return (FieldType::String == type);
}



int IntObject::getInt() const
{
	return value;
}

void IntObject::setInt(int value)
{
	this->value = value;
}

bool IntObject::isType(FieldType type) const
{
	return (FieldType::Integer == type);
}

double DoubleObject::getDouble() const
{
	return value;
}

void DoubleObject::setDouble(double value)
{
	this->value = value;
}

bool DoubleObject::isType(FieldType type) const
{
	return (FieldType::Double == type);
}


void Table::Iteruj::close()
{
	index = 0;
	delete this;
}

bool FieldObject::isType(FieldType type) const
{
	return (FieldType::Field == type);
}
