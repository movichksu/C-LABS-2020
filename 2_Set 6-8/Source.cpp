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
	cout << "Инициализируем bit1: \n";
	cin >> bit1;
	BitString bit2;
	cout << "Инициализируем bit2: \n";
	cin >> bit2;

	Set a(3);
	Set b(3);
	cout << "Инициализируем set1: \n";
	cin >> a;
	cout << "Инициализируем set2: \n";
	cin >> b;
	cout << "Первое множество: " << a << "\n";
	cout << "Второе множество: " << b << "\n";
	a += bit1;
	b -= bit2;
	cout << "Первое множество после добавления bit1: " << a << "\n";
	cout << "Второе множество после исключения bit2: " << b << "\n";

	Set rez1 = a + b;
	cout << "Результат объединения множеств А и В: " << rez1 << "\n";
	Set rez2 = a * b;
	cout << "Результат пересечения множеств А и В: " << rez2 << "\n";
	Set rez3 = a - b;
	cout << "Результат разности множеств А и В: " << rez3 << "\n";
}


