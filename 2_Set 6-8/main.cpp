#include <iostream>
#include <string>
#include <Windows.h>
#include "BitString.h"
#include "Set.h"


using namespace std;

int menu();

int main() {
	setlocale(LC_CTYPE, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
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


	/*cout << "Вот и наши строки: \n";
	cout << bit1 << "\n";
	cout << bit2 << "\n";

    bool cont = true;
	int n = 0;
	string str1 = "10011010";
	string str2 = "01001100";
	BitString bit1(str1.c_str()), bit2(str2.c_str()), rezult;
	cout << "Первая бит-строка: " << bit1 << "\n";
	cout << "Вторая бит-строка: " << bit2 << "\n";
	*/


	/*BitString a(defVal.c_str()), tmp; 

	while (cont) {
		switch (menu())
		{
		case 1:
			cout << "Enter string for operation: ";
			cin >> defVal;
			tmp = defVal.c_str();
			cout << tmp << endl << a << endl;
			tmp = tmp & a;
			cout << tmp << endl;
			break;
		case 2:
			cout << "Enter string for operation: ";
			cin >> defVal;
			tmp = defVal.c_str();
			cout << tmp << endl << a << endl;
			tmp = tmp | a;
			cout << tmp << endl;
			break;
		case 3:
			cout << "Enter string for operation: ";
			cin >> defVal;
			tmp = defVal.c_str();
			cout << tmp << endl << a << endl;
			tmp = tmp ^ a;
			cout << tmp << endl;
			break;
		case 4:
			cout << a << endl;
			tmp = !a;
			cout << tmp << endl;
			break;
		case 5:
			cout << "Enter n byte to move: ";
			cin >> n;
			while (cin.fail() || n < 0) {
				cout << "n must be greater then 0"<<endl;
				cout << "Enter n byte to move: ";
				cin >> n;
			}
			cout << a << endl;
			tmp = a << n;
			cout << tmp << endl;
			break;
		case 6:
			cout << "Enter n byte to move: ";
			cin >> n;
			while (cin.fail() || n < 0) {
				cout << "n must be greater then 0" << endl;
				cout << "Enter n byte to move: ";
				cin >> n;
			}
			cout << a << endl;
			tmp = a >> n;
			cout << tmp << endl;
			break;
		case 7:
			cout << a << endl;
			break;
		default:
			cont = false;
			break;
		}
	}*/

	return 0;
}

int menu() {
	cout << "1. And" << endl
		<< "2. Or" << endl
		<< "3.XOR" << endl
		<< "4.NOT" << endl
		<< "5. << n" << endl
		<< "6. >> n" << endl
		<< "7. show" << endl
		<< "0. end" << endl;

	int a;
	cout << "Select number: ";
	cin >> a;

	while (cin.fail() || a > 7 || a < 0) {
		cout << "Select number: ";
		cin >> a;
	}

	return a;
}