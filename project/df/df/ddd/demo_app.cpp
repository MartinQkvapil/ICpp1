#include "dbapi.h"
#include "helpful.h"


using namespace std;


// TODO deaklokace check!!! --------
#include "crtdbg.h"
// END TODO deaklokace check!!! ----

void testDB() {
	// Vytvo�en� db
	Db* db = Db::open("testdb");

	// Vytvo�en� tabulky
	auto idField = Db::Field("id", FieldType::Integer);
	auto nameField = Db::Field("name", FieldType::String);
	auto userFields = combineToDefinition(idField, nameField);

	Table* users = db->openOrCreateTable("users", 2, userFields);

	// Vlo�en� ��dku do tabulky	
	auto id = Db::Int(15);
	auto name = Db::String("Josef");
	auto row = combineToRow(id, name);
	users->insert(row);

	// Vlo�en� ��dku do tabulky	
	auto idd = Db::Int(16);
	auto namee = Db::String("Martin");
	auto roww = combineToRow(id, name);
	users->insert(row);



	// Select
	auto it = users->select();
	while (it->moveNext())
	{
		auto row = it->getRow();

		cout << row[0]->getInt() << ": " << row[1]->getString() << endl;
	}
	it->close();

	//// Ulo�en� tabulky na disk
	//users->commit();

	//// Uzav�en� tabulky
	users->close();

	//// Uzav�en� db
	db->close();

	//cin.get();

	delete id;
	delete name;
	delete row;

	delete idd;
	delete namee;
	delete roww;

	delete db;

}

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // allocation check
	
	testDB();

	return 0;
}