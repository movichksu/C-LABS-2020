#include <iostream>
#include <windows.h>
#include <vector>
#include <fstream>
#include "Set.h"

using namespace std;
void myFunction(Set&, Set&);
Set myFunction1(Set&, Set&);
void WorkWithConsole();
void WorkWithFile();
void Test();
int main() {
	setlocale(LC_CTYPE, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Test();




}

void Test() {
	cout << "Введём множество натуральных чисел А: ";
	Set A;
	cin >> A;
	cout << A << "\n";

	cout << "Введём множество натуральных чисел В: ";
	Set B;
	cin >> B;
	cout << B << "\n";

	cout << "Объединение множеств А и В: ";
	Set buff1 = A + B;
	cout << buff1 << "\n";
	cout << "Пересечение множеств А и В: ";
	Set buff2 = A * B;
	cout << buff2 << "\n";
	cout << "Разность множеств А и В: ";
	Set buff3 = A - B;
	cout << buff3 << "\n";
}
