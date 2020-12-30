#include "BoolMatrix.h"
#include <windows.h>
void Test();

int main() {
	setlocale(LC_CTYPE, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Test();
}

void Test() {
	cout << "Инициализируем матрицу А ";
	BoolMatrix A;
	A.initMatrix();
	cout << "\nИнициализируем матрицу B ";
	BoolMatrix B;
	B.initMatrix();
	cout << "Инициализируем матрицу C через матрицу A \n";
	BoolMatrix C = A;
	cout << C << "\n";

	cout << "\nКоличество единиц в матрице А : " << A.NumberOfUnits() <<"\n";
	cout << "Количество единиц в матрице B : " << B.NumberOfUnits() << "\n";
	cout << "\nКаноническая форма матрицы А:\n" << A.Canon();
	cout << "\nКаноническая форма матрицы B:\n" << B.Canon();

	C = A + B;
	cout << "\nВыведем операции сумма(дизъюнкцию) матриц А и В : \n" << C;
     
	C = A * B;
	cout << "\nВыведем операции произведение(конъюнкцию) матриц А и В : \n"<< C;

	C = A ^ B;
	cout << "\nВыведем результат операции \"исключающее или\" для матриц А и В : \n" << C;

}