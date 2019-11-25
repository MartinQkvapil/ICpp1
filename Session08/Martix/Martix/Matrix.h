#ifndef MATRIX_H
#define MATRIX_H

template<typename T>
class Matrix
{
public:
	Matrix(int rows, int cols);
	Matrix(const Matrix<T>& m);
	~Matrix();

	// getters and setters
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

	// printer
	void Print() const;

	//  insert into matrix
	void SetZ(T* array);
	void Set(int row, int col, T value);

	template<typename R>
	Matrix<R> ReType() const;

	T& GiveColumn(int row, int col);
	const T& GiveColumn(int row, int col) const;

	Matrix Transposition() const;
	Matrix MullMatrix(const Matrix& m) const;
	Matrix MullMatrix(T vector) const;
	Matrix AddMatrix(const Matrix& m) const; 
	Matrix AddMatrix(T vector) const;	// TODO

	bool IsEqual(const Matrix& m) const;

private:
	T** matrix;
	int _rows;
	int _cols;
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
	if (row < 0 || col < 0)
		throw "Can not insert into this place";
	matrix[row][col] = value;
}

template<typename T>
inline T& Matrix<T>::GiveColumn(int row, int col)
{
	if (row < getRows() && col < getCols() && row >= 0 && col >= 0) {
		return matrix[row][col];
	}
	throw "Out of boundaries";
}

template<typename T>
inline const T& Matrix<T>::GiveColumn(int row, int col) const
{
	if (row < getRows() && col < getCols() && row >= 0 && col >= 0) {
		return matrix[row][col];
	}
	throw "Out of boundaries";
}

template<typename T>
Matrix<T> Matrix<T>::Transposition() const
{
	Matrix<T>* temp = new Matrix{ getRows(), getCols() };

	for (int i = 0; i < getRows(); ++i)
		for (int j = 0; j < getCols(); ++j)
		{
			temp->Set(j, i, matrix[i][j]);
		}
	return *temp;
}

template<typename T>
inline Matrix<T> Matrix<T>::MullMatrix(const Matrix& m) const
{
	if (m.getRows() != getCols()) {
		throw "U cant multiplicate this matrixes";
	}
	Matrix<T>* temp = new Matrix(getRows(), getCols());
	for (int i = 0; i < getRows(); i++) {
		for (int j = 0; j < getCols(); j++) {
			temp->Set(i, j, 0);
		}
	}

	for (int i = 0; i < getRows(); ++i)
		for (int j = 0; j < m.getCols(); ++j)
			for (int k = 0; k < getCols(); ++k)
			{
				T tmp = temp->GiveColumn(i, j) + matrix[i][k] * m.GiveColumn(k, j);
				temp->Set(i, j, tmp);

			}
	return *temp;
}

template<typename T>
inline Matrix<T> Matrix<T>::MullMatrix(T vector) const
{
	Matrix<T>* temp = new Matrix(getRows(), getCols());
	for (int i = 0; i < getRows(); i++) {
		for (int j = 0; j < getCols(); j++) {
			temp->Set(i, j, matrix[i][j] * vector);
		}
	}
	return *temp;
}

template<typename T>
inline Matrix<T> Matrix<T>::AddMatrix(const Matrix& m) const
{
	if (getRows() != m.getRows() || getCols() != m.getCols()) {
		throw "Not valid size of matrix";
	}
	Matrix<T>* temp = new Matrix(getRows(), getCols());
		for (int i = 0; i < getRows(); i++) {
			for (int j = 0; j < getCols(); j++) {
				temp->Set(i, j, matrix[i][j]+m[i][j]);
			}
		}
		return *temp;
}

template<typename T>
inline Matrix<T> Matrix<T>::AddMatrix(T vector) const
{
	Matrix<T>* temp = new Matrix(getRows(), getCols());
	for (int i = 0; i < getRows(); i++) {
		for (int j = 0; j < getCols(); j++) {
			temp->Set(i, j, matrix[i][j] + vector);
		}
	}
	return *temp;
}

template<typename T>
inline bool Matrix<T>::IsEqual(const Matrix& m) const
{
	if (getRows() != m.getRows() || getCols() != m.getCols())
		return false;

	for (int i = 0; i < getRows(); i++) {
		for (int j = 0; j < getCols(); j++) {
			if (matrix[i][j] != m.GiveColumn(i, j)) {
				return false;
			}
		}
	}
	return true;
}

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

#endif // MATRIX_H