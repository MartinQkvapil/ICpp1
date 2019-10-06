// 01 cviko.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//
//

//1) První program
//Vytvořte program, který z klávesnice načte strany trojúhelníka a, b, c. Provede test, zda jde
//sestrojit(a + b > c, a + c > b, b + c > a).Pokud jde sestrojit, pak vypište jeho obvod.
//V opačném případě oznamte uživateli, že takový trojúhelník sestrojit nelze.


#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	cout << "Zadejte strany trojúhelníku\n";
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

	//(a + b > c, a + c > b, b + c > a)
	if (a + b > c && a + c > b && b + c > a) {
		cout << "Trojuhelnik lze setrojit\n";
		cout << "Obvod je " << a + b + c;

	}
	else {
		cout << "Trojuhelnik nelze sestrojit";
	}


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
