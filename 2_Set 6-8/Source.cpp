#include <iostream>
#include <string>
#include <Windows.h>
#include "BitString.h"
#include "Set.h"


using namespace std;

void Test1();

int main() {
	setlocale(LC_CTYPE, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Test1();
	return 0;
}

void Test1() {
	BitString bit1;
	cout << "�������������� bit1: \n";
	cin >> bit1;
	BitString bit2;
	cout << "�������������� bit2: \n";
	cin >> bit2;

	Set a(3);
	Set b(3);
	cout << "�������������� set1: \n";
	cin >> a;
	cout << "�������������� set2: \n";
	cin >> b;
	cout << "������ ���������: " << a << "\n";
	cout << "������ ���������: " << b << "\n";
	a += bit1;
	b -= bit2;
	cout << "������ ��������� ����� ���������� bit1: " << a << "\n";
	cout << "������ ��������� ����� ���������� bit2: " << b << "\n";

	Set rez1 = a + b;
	cout << "��������� ����������� �������� � � �: " << rez1 << "\n";
	Set rez2 = a * b;
	cout << "��������� ����������� �������� � � �: " << rez2 << "\n";
	Set rez3 = a - b;
	cout << "��������� �������� �������� � � �: " << rez3 << "\n";
}


