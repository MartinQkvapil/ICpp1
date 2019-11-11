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
