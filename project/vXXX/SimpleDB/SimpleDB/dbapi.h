#ifndef DBAPI_H
#define DBAPI_H

#include "Platform.h"
#include <string>
#include <functional>
#include <iostream>
#include <vector>

// lib pro práci se souborem
#include <fstream>
#include <filesystem>
#include <sstream>

#include <ostream>
#include <sstream>



// Typ datového pole
enum struct FieldType {
	Integer,
	Double,
	String,
	Field	
};

class FieldObject;
class Table;
class Object;

// Databáze
class DLL_SPEC Db {
public:
	// Otevøe databázi
	static Db* open(std::string database);
	// Uzavøe databázi (dealokuje pamìové prostøedky)
	void close();

	// Vytvoøí novou tabulku
	Table* createTable(std::string name, int fieldsCount, FieldObject** fields);
	// Otevøe existující tabulku
	Table* openTable(std::string name);
	// Otevøe tabulku (pokud neexistuje, vytvoøí automaticky novou)
	Table* openOrCreateTable(std::string name, int fieldsCount, FieldObject** fields);

	// Alokuje objekt „int“
	static Object* Int(int value);
	// Alokuje objekt „double“
	static Object* Double(double value);
	// Alokuje objekt „string“
	static Object* String(std::string value);
	// Alokuje objekt „field“
	static FieldObject* Field(std::string name, FieldType type);
private:
	std::string _nameOfDatabase; // TODO 
	std::vector<Table*> _tables;  //  list pro uchovani tabulek
};
// --------------------------------------------------------
// Rozhraní definující podmínku – pouze pro bonusové metody
class DLL_SPEC Condition {
	virtual ~Condition() { }
	virtual bool matches(int fieldCount, FieldObject** fields, Object** row) const = 0;
};
// --------------------------------------------------------

// Rozhraní iterátoru (select)
class DLL_SPEC Iterator {
public:
	virtual ~Iterator();

	// Posun na další øádek (vrací true, pokud je iterátor platnı; logika podle Java Iterator)
	virtual bool moveNext() = 0;
	// Vrací pole Object* obsahující data øádku
	virtual Object** getRow() = 0;
	// Vrací interní rowId aktuálního øádku
	virtual int getRowId() = 0;
	// Uzavøe iterátor (dealokuje pamìové prostøedky)
	virtual void close() = 0;
};

// Tabulka
class DLL_SPEC Table {
public:
	Table(std::string tableName, FieldObject** columns, int rowCount, int columnCount, std::string databaseName) :
		_tableName(tableName), _columns(columns), _rowCount(rowCount), _columnCount(columnCount), _databaseName(databaseName) {
		_data = new Object **[0]; // TODO udìlat dynamicky!!! 
	};
	Table(std::string tableName, FieldObject** columns, int rowCount, int columnCount, std::string databaseName, Object*** data) :
		_tableName(tableName), _columns(columns), _rowCount(rowCount), _columnCount(columnCount), _databaseName(databaseName), _data(data) {		
	};

	~Table() {};

	// Vloení nového øádku do tabulky (pole Object* (pro jednotlivé hodnoty sloupeèkù))
	void insert(Object** row);

	// Smazání vyrabného øádku z tabulky
	void remove(int rowid);

	// Select – vytvoøí iterátor k procházení tabulky
	Iterator* select();

	// Commit – pøenese zmìny z pamìti do datovıch souborù
	void commit();

	// Uzavøe tabulku (dealokuje pamìové prostøedky)
	void close();

	// Vrací poèet øádkù v tabulce
	int getRowCount() const;

	// Vrací pole FieldObject* popisující sloupeèky tabulky
	FieldObject** getFields() const;

	// Vrací poèet sloupeèkù
	int getFieldCount() const;


	// ============== Bonusové metody: ================
		// Select s podmínkou
	Iterator* select(Condition* condition) { throw 0; }
	// Nalezení rowId s podmínkou
	int findRowId(Condition* condition) { throw 0; }
	// Update – aktualizuje øádky vyhovující podmínce, aktualizaci provádí funkce „callback“
	// callback na vstupu obdrí data øádku a vrací data
	void update(Condition* condition, std::function<void(Object**)> callback) { throw 0; }

	std::string getNameOfTable() {
		return _tableName;
	}

	

private:
	std::string _tableName; // nazev tabulky
	std::string _databaseName; // nazev databaze
	int _rowCount; // pocet radku v tabulce
	int _columnCount; // pocet sloupcu tabulky

	FieldObject** _columns; // pole ukazatlù na FieldObject (jednotlivé sloupce)	
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

		// Vrací pole Object* obsahující data øádku
		Object** getRow() {
			return dataIter[index++];
		} // next

		// Vrací interní rowId aktuálního øádku
		int getRowId() {
			return index;
		}
		// Uzavøe iterátor (dealokuje pamìové prostøedky)
		void close();

	private:
		int index;
		int rowsOfTable;
		Object*** dataIter;

	};

};

// Polymorfní datovı objekt (reprezentuje jednu datovou hodnotu v tabulce)
// Rozhraní vyhovuje základním typùm int, double, string; pro typ „field“ je rozhraní rozšíøeno
class DLL_SPEC Object {
public:
	Object();
	virtual ~Object();

	// Gettery a settery podle typu
	// Jejich funkce je definována jen v pøípadì, e aktuální objekt je odpovídajícího typu
	// Automatické konverze v základním API nejsou vyadovány
	virtual std::string getString() const;
	virtual void setString(std::string value);

	virtual int getInt() const;
	virtual void setInt(int value);

	virtual double getDouble() const;
	virtual void setDouble(double value);

	// Vrací true, pokud aktuální objekt pøedstavuje danı typ
	virtual bool isType(FieldType type) const;
};


class DLL_SPEC IntObject : public Object {
public:
	IntObject() : value(0) {}
	IntObject(int v) : value(v) {}
	~IntObject() {};

	// …
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
	// …
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
	// …
	std::string getString() const;
	void setString(std::string value);
	bool isType(FieldType type) const;
	
private:
	std::string value;
};

// Objekt popisující sloupeèek „field“
class DLL_SPEC FieldObject : public Object {
public:
	//FieldObject() {};
	FieldObject(std::string name, FieldType type) :name(name), type(type) {}
	virtual bool isType(FieldType type) const override;
	// Název sloupeèku
	std::string getName() const { return name; }
	// Typ sloupeèku
	FieldType getType() const { return type; }

	
private:
	std::string name;
	FieldType type;
};

#endif // !DBAPI_H
