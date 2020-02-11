#ifndef RUZNEFUNKCE_H
#define RUZNEFUNKCE_H

//ruznefunkce::bubbleSort(...);

//https://www.algoritmy.net/article/1369/Graf

namespace ruznefunkce {

	void bubbleSort(int arr[], int n)
	{
		int i, j, temp;
		for (i = 0; i < n - 1; i++)

			// Last i elements are already in place  
			for (j = 0; j < n - i - 1; j++)
				if (arr[j] > arr[j + 1])
					temp = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = temp;
		
	}

	int generateNumberInRange(int a, int b) {
		return a + (std::rand() % (b - a + 1));
	}

};


#endif