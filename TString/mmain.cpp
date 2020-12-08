#define _CRT_SECURE_NO_WARNINGS
#include "BoolMatrix.h"
#include <windows.h>
#include "TString.h"
// getLength возвращает длину строки без учёта \0
int main() {
	setlocale(LC_CTYPE, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

		cout << "Добро пожаловать!\n";
		//int C;
		unsigned char b[] = { 9, '1', '2', '2', '3', 'A', 'F', '7', '\0' };
		unsigned char B[] = { 4,'1','2','\0' };
		
		//C = B;
		TString str = B;
		TString str2 = b;
		TString C;
		C = str + str2;
		cout << B << b << endl;
		cout << str2 << endl;
		cout << str << endl;
		cout << C;
		//cout << C;
}