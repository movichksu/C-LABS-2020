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
	cout << "�������������� ������� � ";
	BoolMatrix A;
	A.initMatrix();
	cout << "\n�������������� ������� B ";
	BoolMatrix B;
	B.initMatrix();
	cout << "�������������� ������� C ����� ������� A \n";
	BoolMatrix C = A;
	cout << C << "\n";

	cout << "\n���������� ������ � ������� � : " << A.NumberOfUnits() <<"\n";
	cout << "���������� ������ � ������� B : " << B.NumberOfUnits() << "\n";
	cout << "\n������������ ����� ������� �:\n" << A.Canon();
	cout << "\n������������ ����� ������� B:\n" << B.Canon();

	C = A + B;
	cout << "\n������� �������� �����(����������) ������ � � � : \n" << C;
     
	C = A * B;
	cout << "\n������� �������� ������������(����������) ������ � � � : \n"<< C;

	C = A ^ B;
	cout << "\n������� ��������� �������� \"����������� ���\" ��� ������ � � � : \n" << C;

}