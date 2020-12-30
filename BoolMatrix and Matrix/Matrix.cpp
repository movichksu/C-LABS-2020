#include "Matrix.h"


Matrix::Matrix() {
	int n = 0, m = 0;
	cout << "\nВведите количество строк: ";
	cin >> n;
	if (n < 1) throw "\nНеверные данные! Число строк должно быть больше 0.\n";
	cout << "Введите количество столбцов: ";
	cin >> m;
	if (m < 1) throw "\nНеверные данные! Число столбцов должно быть больше 0.\n";
	this->rows = n;
	this->columns = m;
	matrix = new int* [rows];
	for (int i = 0; i < rows; i++) matrix[i] = new int[columns];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (i == j) this->matrix[i][j] = 1;
			else this->matrix[i][j] = 0;
		}
	}
}
Matrix::Matrix(int** arr, int rows, int columns) {
	if (rows < 1) throw "\nНеверные данные! Число строк должно быть больше 0.\n";
	if (columns < 1) throw "\nНеверные данные! Число столбцов должно быть больше 0.\n";
	if (!arr) throw "\nМатрицa не существует.\n";
	this->rows = rows;
	this->columns = columns;
	this->matrix = new int* [this->rows];
	for (int i = 0; i < this->rows; i++)  this->matrix[i] = new int[this->columns];
	for (int i = 0; i < this->rows; i++)
		for (int j = 0; j < this->columns; j++)
			this->matrix[i][j] = arr[i][j];
}
Matrix::Matrix(const Matrix& matrix) : Matrix(matrix.matrix, matrix.rows, matrix.columns) {}
Matrix::~Matrix() {
	for (int i = 0; i < rows; i++)
		delete matrix[i];
	delete[] matrix;
	matrix = nullptr;
}
void Matrix::initMatrix() {
	cout << "Инициализация матрицы: " << this->rows << " x " << this->columns<<"\n";
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			cin >> this->matrix[i][j];
		}
	}
}
int& Matrix::GetIJ(int i, int j) {
	return matrix[i][j];
}

Matrix Matrix::operator + (const Matrix& other) {
	if (rows != other.rows || columns != other.columns)
		throw "\nНевозможно выполнить операцию сложения. Размеры матриц не совпадают.\n";
	int** buff = new int* [rows];
	for (int i = 0; i < rows; i++)
		buff[i] = new int[columns];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			buff[i][j] = matrix[i][j] + other.matrix[i][j];
	Matrix buffer(buff, rows, columns);
	for (int i = 0; i < rows; i++)	delete buff[i];
	delete[] buff;
	return buffer;
}
Matrix Matrix::operator * (const Matrix& other) {
	if (columns != other.rows)
		throw "\nНевозможно выполнить операцию умножения.\n";
	int data = 0;
	int** buff = new int* [rows];
	for (int i = 0; i < rows; i++)
		buff[i] = new int[other.columns];
	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < other.columns; k++, data = 0) {
			for (int j = 0; j < columns; j++)
				data += matrix[i][j] * other.matrix[j][k];
			buff[i][k] = data;
		}
		data = 0;
	}
	Matrix matrix(buff, rows, other.columns);
	for (int i = 0; i < rows; i++)
		delete buff[i];
	delete[] buff;
	return matrix;
}
Matrix& Matrix::operator = (const Matrix& other) {
	this->rows = other.rows;
	this->columns = other.columns;
	for (int i = 0; i < rows; i++)
		delete matrix[i];
	delete[] matrix;
	this->matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
		matrix[i] = new int[columns];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] = other.matrix[i][j];
	return *this;
}

ostream& operator << (ostream& out, const Matrix& matrix) {
	for (int i = 0; i < matrix.rows; i++) {
		for (int j = 0; j < matrix.columns; j++)
			out << " " << matrix.matrix[i][j];
		out << endl;
	}
	return out;
}