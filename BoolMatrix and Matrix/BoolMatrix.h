#pragma once
#include <iostream>
#include <math.h> 
#include "Matrix.h"

class BoolMatrix : public Matrix {
public:
	BoolMatrix();
	BoolMatrix(int**, int, int);
	BoolMatrix(const BoolMatrix&);
	~BoolMatrix();
	int NumberOfUnits();
	BoolMatrix Canon();
	void initMatrix();

	BoolMatrix operator & (const BoolMatrix&); // ������������ ���������
	BoolMatrix operator | (const BoolMatrix&); // ������������ ����������
	BoolMatrix operator ^ (const BoolMatrix&); // ������������ ����������� ���
	BoolMatrix operator + (const BoolMatrix&); // �������� ������
	BoolMatrix operator * (const BoolMatrix&); // ������������ ������
	BoolMatrix& operator = (const BoolMatrix&);

private:
	void Convert(int**, int, int);
	void Swap(int&, int&);
	void Swap(int*&, int*&);
	void RemoveRow(int, int);
	void BuffCanon();
};
