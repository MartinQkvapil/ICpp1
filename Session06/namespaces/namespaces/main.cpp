// namespaces.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "pch.h"
#include <iostream>
#include <string>

namespace Entity {
	class Person {
	public:
		Person() {};
		~Person() {};
		std::string getName() {
			return this->name;
		}
		std::string getTel() {
			return this->telefon;
		}
		int getId() {
			return this->id;
		}
	private:
		//string jmeno, string telefon, int id
		std::string name;
		std::string telefon;
		int id;

		

	};
}

//vytvořte třídu telefonniseznam(jmenný prostor model), která realizuje ads tabulka, kde klíčem je
//id / jméno osoby a hledanou hodnotou je telefon.pro implementaci tabulky vytvořte strukturu
//spojový seznam.
namespace Model {
	
	struct node
	{
		Entity::Person data;
		node *next;
	};

	class linked_list
	{
	
	private: 
		Model::node *head, *tail;
	public:
		
		linked_list()
		{
			head = NULL;
			tail = NULL;
		}

		void pridejOsobu(Entity::Person person) {
			node *tmp = new node;
			tmp->data = person;
			tmp->next = NULL;

			if (head == NULL)
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
		std::string najdiTelefon(std::string name) const {
			node * tmp = head;
			while (tmp != nullptr) {
				if (tmp->data.getName() == name) {
					return tmp->data.getTel();
				}				
				tmp = tmp->next;
			}
			
		}
		std::string najdiTelefon(int id) const {
			node * tmp = head;
			while (tmp != nullptr) {
				if (tmp->data.getId() == id) {
					return tmp->data.getTel();
				}
				tmp = tmp->next;
			}
		}
		//o Pokud je jméno osoby prázdné nebo id záporné je vyvolána výjimky oznamující	neplatný vstupní parametr.
		//o Pokud zadaná osoba není v seznamu, metody vyvolají výjimku.
	};
	
	class TelList {

		


	};
}


int main()
{



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
