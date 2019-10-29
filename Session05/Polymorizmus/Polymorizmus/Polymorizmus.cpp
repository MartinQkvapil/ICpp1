// Polymorizmus.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "pch.h"
#include <iostream>
#include "Time.h"


// sort arr 
void SortArray(IComparable** arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			int c = ((Time*)arr[j + 1])->compareTo(arr[j]);
			if (c == -1) {
				IComparable* tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int main()
{
	IComparable** array = new IComparable*[3];
	array[0] = new Time{ 8,0,0 };
	array[1] = new Time{ 10,0,0 };
	array[2] = new Time{ 6,0,0 };

	for (size_t i = 0; i < 3; i++) {
		Time* cs = ((Time*)array[i]);
		cs->ToString();
	}

	// sorted!
	SortArray(array, 3);

	for (size_t i = 0; i < 3; i++) {
		Time* cs = ((Time*)array[i]);
		cs->ToString();
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
