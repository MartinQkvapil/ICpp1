#ifndef MATRIX_H
#define MATRIX_H

template<typename T>
class Matrix
{
public:
	Matrix(int rows, int cols);
	Matrix(const Matrix<T>& m);
	~Matrix();

	void setRows(int rows) {
		_rows = rows;
	}
	void setCols(int cols) {
		_cols = cols;
	}
	int getRows() const {
		return _rows;
	}
	int getCols() const {
		return _cols;
	}

	void Print() const;
	void SetZ(T* array);
	void Set(int row, int col, T value);

	template<typename R>
	Matrix<R> ReType() const;

	T& GiveColumn(int row, int col);
	const T& GiveColumn(int radek, int sloupec) const;


	Matrix Transpozice() const;
	/*Matrix Soucin(const Matice& m) const;
	Matrix Soucin(T skalar) const;
	Matrix Soucet(const Matice& m) const;
	Matrix Soucet(T skalar) const;*/

private:
	T** matrix;
	signed _rows;
	signed _cols;
};

template<typename T>
Matrix<T>::Matrix(int rows, int cols) {
	setRows(rows);
	setCols(cols);

	matrix = new T * [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new T[cols];
	}
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& temp_matrix) {
	setRows(temp_matrix.getRows());
	setCols(temp_matrix.getCols());
	matrix = new T * [temp_matrix.getRows()];
	for (int i = 0; i < temp_matrix.getCols(); i++) {
		matrix[i] = new T[temp_matrix.getCols()];
	}

	// copy values
	for (int i = 0; i < temp_matrix.getRows(); i++) {
		for (int j = 0; j < temp_matrix.getCols(); j++) {
			matrix[i][j] = temp_matrix.GiveColumn(i, j);
		}
	}
}



template<typename T>
Matrix<T>::~Matrix() {
	for (int i = 0; i < getRows(); ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

template<typename T>
void Matrix<T>::Print() const {
	for (int i = 0; i < getRows(); i++) {
		for (int j = 0; j < getCols(); j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

template<typename T>
void Matrix<T>::SetZ(T* array) {
	int index = 0;
	for (int i = 0; i < getRows(); i++) {
		for (int j = 0; j < getCols(); j++) {
			matrix[i][j] = array[index];
			index++;
		}
	}
}

template<typename T>
inline void Matrix<T>::Set(int row, int col, T value)
{
	matrix[row][col] = value;
}

template<typename T>
inline T& Matrix<T>::GiveColumn(int row, int col)
{
	if (row < getRows() && col < getCols() && row >= 0 && col >= 0) {
		return matrix[row][col];
	}
	throw std::out_of_range;
}

template<typename T>
inline const T& Matrix<T>::GiveColumn(int row, int col) const
{
	if (row < getRows() && col < getCols() && row >= 0 && col >= 0) {
		return matrix[row][col];
	}
	throw std::out_of_range;
}

template<typename T>
Matrix<T> Matrix<T>::Transpozice() const
{
	Matrix<T>* temp = new Matrix{ getRows(), getCols() };

	for (int i = 0; i < getRows(); ++i)
		for (int j = 0; j < getCols(); ++j)
		{
			temp->Set(j, i, matrix[i][j]);
		}
	return *temp;
}


#endif // MATRIX_H

template<typename T>
template<typename R>
inline Matrix<R> Matrix<T>::ReType() const
{
	Matrix<R>* temp = new Matrix<R>(getRows(), getCols());

	for (int i = 0; i < getRows(); i++) {
		for (int j = 0; j < getCols(); j++) {
			temp->Set(i, j, static_cast<R>(matrix[i][j]));
		}
	}
	return *temp;	
}
	