#pragma once
#include <iostream>
#include <math.h> 

using namespace std;

class Matrix {
protected:
	int& GetIJ(int, int);
	int** matrix;
	int rows;
	int columns;
public:
	Matrix();
	Matrix(int**, int, int);
	Matrix(const Matrix&); // конструктор копирования
	~Matrix();

	void initMatrix();
	int GetRows() { return this->rows; }
	int GetColumns() { return this->columns; }
	int** GetMatrix() { return this->matrix; }

	Matrix operator + (const Matrix&);
	Matrix operator * (const Matrix&);
	Matrix& operator = (const Matrix&);
	friend ostream& operator << (ostream&, const Matrix&);

};