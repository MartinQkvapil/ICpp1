// Polymorizmus.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "pch.h"
#include <iostream>
#include "Time.h"
#include "IComparable.h"

int main()
{
	IComparable** pole = new IComparable*[3];
	pole[0] = new Time{ 8,0,0 };
	pole[1] = new Time{ 10,0,0 };
	pole[2] = new Time{ 6,0,0 };

	for (size_t i = 0; i < 3; i++) {
		Cas* cs = ((Cas*)pole[i]);
		cs->toString();
	}

	SeraditPole(pole, 3);

	for (size_t i = 0; i < 3; i++) {
		Cas* cs = ((Cas*)pole[i]);
		cs->toString();
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
