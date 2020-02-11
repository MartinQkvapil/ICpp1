#ifndef DBAPI_H
#define DBAPI_H

#include "Platform.h"
#include <string>
#include <functional>
#include <iostream>
#include <vector>

// lib pro pr�ci se souborem
#include <fstream>
#include <filesystem>
#include <sstream>

#include <ostream>
#include <sstream>



// Typ datov�ho pole
enum struct FieldType {
	Integer,
	Double,
	String,
	Field	
};

class FieldObject;
class Table;
class Object;

// Datab�ze
class DLL_SPEC Db {
public:
	// Otev�e datab�zi
	static Db* open(std::string database);
	// Uzav�e datab�zi (dealokuje pam�ov� prost�edky)
	void close();

	// Vytvo�� novou tabulku
	Table* createTable(std::string name, int fieldsCount, FieldObject** fields);
	// Otev�e existuj�c� tabulku
	Table* openTable(std::string name);
	// Otev�e tabulku (pokud neexistuje, vytvo�� automaticky novou)
	Table* openOrCreateTable(std::string name, int fieldsCount, FieldObject** fields);

	// Alokuje objekt �int�
	static Object* Int(int value);
	// Alokuje objekt �double�
	static Object* Double(double value);
	// Alokuje objekt �string�
	static Object* String(std::string value);
	// Alokuje objekt �field�
	static FieldObject* Field(std::string name, FieldType type);
private:
	std::string _nameOfDatabase; // TODO 
	std::vector<Table*> _tables;  //  list pro uchovani tabulek
};
// --------------------------------------------------------
// Rozhran� definuj�c� podm�nku � pouze pro bonusov� metody
class DLL_SPEC Condition {
	virtual ~Condition() { }
	virtual bool matches(int fieldCount, FieldObject** fields, Object** row) const = 0;
};
// --------------------------------------------------------

// Rozhran� iter�toru (select)
class DLL_SPEC Iterator {
public:
	virtual ~Iterator();

	// Posun na dal�� ��dek (vrac� true, pokud je iter�tor platn�; logika podle Java Iterator)
	virtual bool moveNext() = 0;
	// Vrac� pole Object* obsahuj�c� data ��dku
	virtual Object** getRow() = 0;
	// Vrac� intern� rowId aktu�ln�ho ��dku
	virtual int getRowId() = 0;
	// Uzav�e iter�tor (dealokuje pam�ov� prost�edky)
	virtual void close() = 0;
};

// Tabulka
class DLL_SPEC Table {
public:
	Table(std::string tableName, FieldObject** columns, int rowCount, int columnCount, std::string databaseName) :
		_tableName(tableName), _columns(columns), _rowCount(rowCount), _columnCount(columnCount), _databaseName(databaseName) {
		_data = new Object **[0]; // TODO ud�lat dynamicky!!! 
	};
	Table(std::string tableName, FieldObject** columns, int rowCount, int columnCount, std::string databaseName, Object*** data) :
		_tableName(tableName), _columns(columns), _rowCount(rowCount), _columnCount(columnCount), _databaseName(databaseName), _data(data) {		
	};

	~Table() {};

	// Vlo�en� nov�ho ��dku do tabulky (pole Object* (pro jednotliv� hodnoty sloupe�k�))
	void insert(Object** row);

	// Smaz�n� vyrabn�ho ��dku z tabulky
	void remove(int rowid);

	// Select � vytvo�� iter�tor k proch�zen� tabulky
	Iterator* select();

	// Commit � p�enese zm�ny z pam�ti do datov�ch soubor�
	void commit();

	// Uzav�e tabulku (dealokuje pam�ov� prost�edky)
	void close();

	// Vrac� po�et ��dk� v tabulce
	int getRowCount() const;

	// Vrac� pole FieldObject* popisuj�c� sloupe�ky tabulky
	FieldObject** getFields() const;

	// Vrac� po�et sloupe�k�
	int getFieldCount() const;


	// ============== Bonusov� metody: ================
		// Select s podm�nkou
	Iterator* select(Condition* condition) { throw 0; }
	// Nalezen� rowId s podm�nkou
	int findRowId(Condition* condition) { throw 0; }
	// Update � aktualizuje ��dky vyhovuj�c� podm�nce, aktualizaci prov�d� funkce �callback�
	// callback na vstupu obdr�� data ��dku a vrac� data
	void update(Condition* condition, std::function<void(Object**)> callback) { throw 0; }

	std::string getNameOfTable() {
		return _tableName;
	}

	

private:
	std::string _tableName; // nazev tabulky
	std::string _databaseName; // nazev databaze
	int _rowCount; // pocet radku v tabulce
	int _columnCount; // pocet sloupcu tabulky

	FieldObject** _columns; // pole ukazatl� na FieldObject (jednotliv� sloupce)	
	Object*** _data; // data v tabulce	

	class Iteruj : public Iterator {
	public:
		Iteruj(int rows, Object*** data) {
			dataIter = data;
			rowsOfTable = rows;
			index = 0;
		}

		bool moveNext() {
			if (index < rowsOfTable)
				return true;
			else
				return false;
		} // hasNext

		// Vrac� pole Object* obsahuj�c� data ��dku
		Object** getRow() {
			return dataIter[index++];
		} // next

		// Vrac� intern� rowId aktu�ln�ho ��dku
		int getRowId() {
			return index;
		}
		// Uzav�e iter�tor (dealokuje pam�ov� prost�edky)
		void close();

	private:
		int index;
		int rowsOfTable;
		Object*** dataIter;

	};

};

// Polymorfn� datov� objekt (reprezentuje jednu datovou hodnotu v tabulce)
// Rozhran� vyhovuje z�kladn�m typ�m int, double, string; pro typ �field� je rozhran� roz���eno
class DLL_SPEC Object {
public:
	Object();
	virtual ~Object();

	// Gettery a settery podle typu
	// Jejich funkce je definov�na jen v p��pad�, �e aktu�ln� objekt je odpov�daj�c�ho typu
	// Automatick� konverze v z�kladn�m API nejsou vy�adov�ny
	virtual std::string getString() const;
	virtual void setString(std::string value);

	virtual int getInt() const;
	virtual void setInt(int value);

	virtual double getDouble() const;
	virtual void setDouble(double value);

	// Vrac� true, pokud aktu�ln� objekt p�edstavuje dan� typ
	virtual bool isType(FieldType type) const;
};


class DLL_SPEC IntObject : public Object {
public:
	IntObject() : value(0) {}
	IntObject(int v) : value(v) {}
	~IntObject() {};

	// �
	int getInt() const;
	void setInt(int value);
	bool isType(FieldType type) const;
	
private:
	int value;
};

class DLL_SPEC DoubleObject : public Object {
public:
	DoubleObject() : value(0.0) {}
	DoubleObject(double v) : value(v) {}
	~DoubleObject() {};
	// �
	double getDouble() const;
	void setDouble(double value);
	bool isType(FieldType type) const;
	FieldType getType() const { return FieldType::Double; };
private:
	double value;
};

class DLL_SPEC StringObject : public Object {
public:
	StringObject() : value("") {}
	StringObject(std::string v) : value(v) {}
	~StringObject() {};
	// �
	std::string getString() const;
	void setString(std::string value);
	bool isType(FieldType type) const;
	
private:
	std::string value;
};

// Objekt popisuj�c� sloupe�ek �field�
class DLL_SPEC FieldObject : public Object {
public:
	//FieldObject() {};
	FieldObject(std::string name, FieldType type) :name(name), type(type) {}
	virtual bool isType(FieldType type) const override;
	// N�zev sloupe�ku
	std::string getName() const { return name; }
	// Typ sloupe�ku
	FieldType getType() const { return type; }

	
private:
	std::string name;
	FieldType type;
};

#endif // !DBAPI_H
