// PrvniStruktura.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

//2) První struktura
//Vytvořte strukturu Trojuhelnik, která obsahuje složky int a, b, c.Upravte první program tak,
//aby vytvořil objekt Trojuhelnik a do něj načítal jednotlivé hodnoty.Upravte test
//sestrojitelnosti, tak aby to nyní byla funkce : bool lzeSestrojit(Trojuhelnik t).


//3) První ukazatel
//Vytvořte ukazatel Trojuhelnik* ukazatel, který bude ukazovat na načtený Trojuhelnik.
//Načítejte strany a, b, c přes ukazatel.Vytvořte funkci bool lzeSestrojit(Trojuhelnik* t).
//A vyzkoušejte ji použít.

//5) Pole v dynamické paměti
//Na začátku se zeptejte uživatele, kolik chcete načíst trojúhelníků a na základě jeho volby
//alokujte pole pomocí new[].V cyklu načtěte jednotlivé trojúhelníky a na konci nezapomeňte
//na uvolnění paměti pomocí delete[].

#include "pch.h"
#include <iostream>

using namespace std;

struct Trojuhelnik {
public:
	int a;
	int b;
	int c;

	


	

	Trojuhelnik() {
		cout << "Zadejte strany trojuhelniku\n";
		cout << "a: ";
		cin >> a;
		cout << "\n";

		cout << "b: ";
		cin >> b;
		cout << "\n";

		cout << "c: ";
		cin >> c;
		cout << "\n";

		cout << "Succ: A=" << a << " B=" << b << " C= " << c << "!\n";
	}






};

static bool lzeSestrojit(Trojuhelnik t) {
	//(a + b > c, a + c > b, b + c > a)
	if (t.a + t.b > t.c && t.a + t.c > t.b && t.b + t.c > t.a) {
		//cout << "Trojuhelnik lze setrojit\n";
		cout << "Obvod je " << t.a + t.b + t.c << endl;
		return true;
	}
	else {
		//cout << "Trojuhelnik nelze sestrojit";
		return false;
	}

}

static bool lzeSestrojit(Trojuhelnik *t) {
	//(a + b > c, a + c > b, b + c > a)
	if (t->a + t->b > t->c && t->a + t->c > t->b && t->b + t->c > t->a) {
		//cout << "Trojuhelnik lze setrojit\n";
		cout << "Obvod je " << t->a + t->b + t->c << endl;
		return true;
	}
	else {
		//cout << "Trojuhelnik nelze sestrojit";
		return false;
	}

}



int main()
{
	/*Trojuhelnik tmp;
	cout << "Lze trojuhelnik sestrojit?(0 x 1): " << lzeSestrojit(tmp) << endl;*/

	/*Trojuhelnik * tmp2 = new Trojuhelnik();
	cout << "Lze trojuhelnik sestrojit?(0 x 1): " << lzeSestrojit(tmp2) << endl;

	delete tmp2;*/

	int pocetTroj = 0;
	Trojuhelnik * poleTroj;
	
	// kolik trojuhelniku 
	cout << "Kolik chcete trojuhelniku?" << endl;
	cin >> pocetTroj;

	poleTroj = new Trojuhelnik[pocetTroj]; // alocation

	/*for (size_t i = 0; i < pocetTroj; i++)
	{
		poleTroj[i] = Trojuhelnik();
	}*/
	cout << "Helper: " << poleTroj[1].a << endl;

	delete[] poleTroj;

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
