#ifndef POLE_H
#define POLE_H

#define NUM 10

template <typename T>
class Pole
{
public:
	Pole() {};
	Pole(int sizeOfArr1) {

		/*
	KompleniCislo p1{10, 5};
	KompleniCislo p3{12, 5};
	KompleniCislo p2{11, 5};
	KompleniCislo p4{13, 5};

	Pole<KompleniCislo>* temp = new Pole<KompleniCislo>(10);
	temp->Get_arr1()[0] = p1;
	temp->Get_arr1()[1] = p2;
	temp->Get_arr1()[2] = p3;
	temp->Get_arr1()[3] = p4;

	cout << temp->Get_arr1()[3].toString() << endl;
	cout << temp->Get_arr1()[2].toString() << endl;

	

	delete temp;*/
		this->_arr1 = new T[sizeOfArr1];
	};
	Pole(int row, int column) {
		/*KompleniCislo p1{10, 5};
	KompleniCislo p3{12, 5};
	KompleniCislo p2{11, 5};
	KompleniCislo p4{13, 5};

	Pole<KompleniCislo>* temp = new Pole<KompleniCislo>(10,10);
	temp->Get_arr2()[0][0] = p1;
	temp->Get_arr2()[1][1] = p2;
	temp->Get_arr2()[2][0] = p3;
	temp->Get_arr2()[3][2] = p4;

	cout << temp->Get_arr2()[0][0].toString() << endl;
	cout << temp->Get_arr2()[5][0].toString() << endl;

	

	delete temp;*/
		this->_arr2 = new T* [NUM];  //first allocate array of row pointers

		for (int i = 0; i < NUM; ++i)
		{
			_arr2[i] = new T[NUM]; // allocate memory for columns in each row
		}


	};
	Pole(int rows, int columns, bool sol) {
		/*	KompleniCislo p1{10, 5};
	KompleniCislo p3{12, 5};
	KompleniCislo p2{11, 5};
	KompleniCislo p4{13, 5};

	Pole<KompleniCislo>* temp = new Pole<KompleniCislo>(10,10, 1);
	temp->Get_arr3()[0][0][0] = p1;
	temp->Get_arr3()[1][1][0] = p2;
	temp->Get_arr3()[2][0][0] = p3;
	temp->Get_arr3()[3][2][0] = p4;

	cout << temp->Get_arr3()[0][0][0].toString() << endl;
	cout << temp->Get_arr3()[0][0][0].toString() << endl;

	

	delete temp;*/

		 this->_arr3 = new T * *[NUM];

		for (size_t i = 0; i < NUM; i++)
		{
			this->_arr3[i] = new T * [NUM];

			for (size_t j = 0; j < NUM; j++)
			{
				this->_arr3[i][j] = new T;
			}
		}
	};
	
	~Pole() {
		/*delete _arr1;
		this->_arr1 = nullptr;*/

		

		//for (int i = 0; i < NUM; ++i)
		//{
		//	delete _arr2[i]; // allocate memory for columns in each row
		//}
		//delete[] _arr2;
		//this->_arr2 = nullptr;


		for (size_t i = 0; i < NUM; i++)
		{
			for (size_t j = 0; j < NUM; j++)
			{
				delete _arr3[i][j];
			}			
			delete[] _arr3[i];
		}

		delete _arr3;
		this->_arr3 = nullptr;
		
	};

	T* Get_arr1();
	T** Get_arr2();
	T*** Get_arr3();
private:
	
	T* _arr1;
	T** _arr2;
	T*** _arr3;
	static int _size;
};


#endif POLE_H

template<typename T>
inline T* Pole<T>::Get_arr1()
{
	return _arr1;
}

template<typename T>
inline T** Pole<T>::Get_arr2()
{
	return _arr2;
}

template<typename T>
inline T*** Pole<T>::Get_arr3()
{
	return _arr3;
}
