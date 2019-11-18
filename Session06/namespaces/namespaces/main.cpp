// namespaces.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <ostream>
#include <fstream>

#include <exception>

#define _CRTDBG_MAP_ALLOC
#include <string>
#include <crtdbg.h>


namespace Entity {
	class Person {
	public:
		Person() {};
		Person(std::string name, std::string phone) {
			this->phone = phone;
			this->name = name;
		};
		~Person() {};
		std::string GetName() {
			return this->name;
		}
		std::string GetPhone() {
			return this->phone;
		}
		int GetId() {
			return this->id;
		}
	private:
		std::string name;
		std::string phone;
		int id;

	};
}

//vytvořte třídu telefonniseznam(jmenný prostor model), která realizuje ads tabulka, kde klíčem je
//id / jméno osoby a hledanou hodnotou je telefon.pro implementaci tabulky vytvořte strukturu
//spojový seznam.
namespace Model {

	struct PersonNode
	{
		Entity::Person data;
		PersonNode *next;
	};

	class PhoneList
	{

	private:
		Model::PersonNode *head, *tail;
	public:
		~PhoneList()
		{
			PersonNode * tmp = head;
			while (tmp != nullptr) {
				delete tmp;
				tmp = tmp->next;
			}
			delete head;
			delete tail;
		}
		PhoneList()
		{
			head = nullptr;
			tail = nullptr;
		}

		void pridejOsobu(Entity::Person person) {
			PersonNode *tmp = new PersonNode();
			tmp->data = person;
			tmp->next = nullptr;

			if (head == nullptr)
			{
				head = tmp;
				tail = tmp;
			}
			else
			{
				tail->next = tmp;
				tail = tail->next;
			}
		}
		//o Přidá osobu do seznamu
		std::string findPhone(std::string name) const {
			if (head == nullptr) {
				throw std::out_of_range("empty list");
			}
			PersonNode * tmp = head;
			while (tmp != nullptr) {
				if (tmp->data.GetName() == name) {
					return tmp->data.GetPhone();
				}
				tmp = tmp->next;
			}

			throw std::logic_error("By name phone not found");
		}
		std::string findPhone(int id) const {
			if (head == nullptr) {
				throw std::out_of_range("empty list");
			}
			PersonNode * tmp = head;
			while (tmp != nullptr) {
				if (tmp->data.GetId() == id) {
					return tmp->data.GetPhone();
				}
				tmp = tmp->next;
			}
			throw std::logic_error("By id, phone not found");
		}
		//o Pokud je jméno osoby prázdné nebo id záporné je vyvolána výjimky oznamující	neplatný vstupní parametr.
		//o Pokud zadaná osoba není v seznamu, metody vyvolají výjimku.
	};



}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // allocation check 
	Entity::Person p0 = Entity::Person("Martin", "774993772");
	Entity::Person p1 = Entity::Person("Olda", "774993776");

	Model::PhoneList *list = new Model::PhoneList();
	list->pridejOsobu(p0);
	list->pridejOsobu(p1);

	
}




// Spuštění programu: Ctrl+F5 nebo nabídka Ladit > Spustit bez ladění
// Ladění programu: F5 nebo nabídka Ladit > Spustit ladění

// Tipy pro zahájení práce:
//   1. K přidání nebo správě souborů použijte okno Průzkumník řešení.
//   2. Pro připojení ke správě zdrojového kódu použijte okno Team Explorer.
//   3. K zobrazení výstupu sestavení a dalších zpráv použijte okno Výstup.
//   4. K zobrazení chyb použijte okno Seznam chyb.
//   5. Pokud chcete vytvořit nové soubory kódu, přejděte na Projekt > Přidat novou položku. Pokud chcete přidat do projektu existující soubory kódu, přejděte na Projekt > Přidat existující položku.
//   6. Pokud budete chtít v budoucnu znovu otevřít tento projekt, přejděte na Soubor > Otevřít > Projekt a vyberte příslušný soubor .sln.
