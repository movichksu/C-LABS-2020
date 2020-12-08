#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <vector>
#include "Set.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string way;
	int N(10);
	int s1, s2;
	vector<Set> sets(N);
	Set rezult, rezult1, rezult2, rezult3;
	Set set{ "ajfhrbvhkvre" };

	cout << "\nДобро пожаловать!\n";
	cout << "Максимальная мощность множества в программе - 100 элементов.\n";
	cout << "Пробел не может являться элементом множества, учтите это.\n";
	cout << "\n\n";
	while (true)
	{
		cout << "\nВыберите то, что вы хотите сделать:\n";
		cout << "1.Вывести имеющийся список множеств на экран.\n"; 
		cout << "2.Вывести множества в файл.\n"; 
		cout << "3.Считать множества из файла.\n";
		cout << "4.Создать множество.\n"; 
		cout << "5.Удалить множество из массива.\n";
		cout << "6.результат выборки уникальных членов двух множеств.\n"; 
		cout << "7.результат разности двух множеств\n"; 
		cout << "8.результат объединения двух множеств.\n"; 
		cout << "9.результат пересечения двух множеств.\n";
		cout << "10.принадлежность символа множеству.\n";
		cout << "11.операция индексации(i-ый элемент).\n";
		cout << "0.Выход из программы.\n"; 
		int choice;
		char sym;
		cin >> choice;
		switch (choice) {
		case 0: return 0;
		case 1: if (sets.empty()) { cout << "В массиве множеств пусто.\n"; break; }
			    printSets(sets);
			    break;
		case 2: if (sets.empty()) { cout << "В массиве множеств пусто.\n"; break; }
			    cout << "Введите путь, куда записать список\n";
			    cin >> way;
			    writeToFile(sets, way);
			    break;
		case 3: cout << "Введите путь, откуда взять список\n";
			    cin >> way;
			    readFromFile(sets, way);
			    break;
		case 4: sets = addSet(sets);
			    break;
		case 5: if (sets.empty()) { cout << "В массиве множеств пусто.\n"; break; }
		   	    cout << "Введите порядковый номер множества.\n";
			    int num; cin >> num;
			    sets = deleteSet(sets, num);
			    break;
		case 6: if (sets.empty()) { cout << "В массиве множеств пусто.\n"; break; }
			    cout << "Введите индексы множеств для выполнения операции.\n";
				cin >> s1 >> s2;
				rezult = setOfUniqeElements(sets[s1], sets[s2]);
				cout << "Множество из уникальных элементов:\n" << rezult << "\n";
			    break;
		case 7: if (sets.empty()) { cout << "В массиве множеств пусто.\n"; break; }
			    cout << "Введите индексы множеств для выполнения операции.\n";
				cin >> s1; cin >> s2;
			    rezult1 = sets[s1] - sets[s2];
				cout << "Разность множеств:\n";
				rezult1.show();
				cout << "\n";
			    break;
		case 8: if (sets.empty()) { cout << "В массиве множеств пусто.\n"; break; }
			    cout << "Введите индексы множеств для выполнения операции.\n";
			    cin >> s1>>s2;
			    rezult2 = sets[s1] + sets[s2];
				cout << "Объединение множеств:\n";
				rezult2.show();
				cout << "\n";
			    break;
		case 9: if (sets.empty()) { cout << "В массиве множеств пусто.\n"; break; }
			    cout << "Введите индексы множеств для выполнения операции.\n";
			    cin >> s1 >> s2;
			    rezult3 = sets[s1] * sets[s2];
				cout << "Пересечение множеств:\n";
				rezult3.show();
				cout << "\n";
			    break;
		case 10: if (sets.empty()) { cout << "В массиве множеств пусто.\n"; break; }
			   cout << "Введите номер множества, в котором хотите найти символ.\n";
			   cin >> s1;
			   if (s1 >= sets.size()) break;
			   sets[s1].show(); cout << "\n";
			   cout << "Введите символ, который нужно найти.\n";
			   cin >> sym;
			   if (sets[s1].In(sym)) cout << "Символ есть в множестве\n";
			   cout << "В множестве символ отсутствует.\n";
			   break;
		case 11:  if (sets.empty()) { cout << "В массиве множеств пусто.\n"; break; }
			   cout << "Введите индекс элемента, который хотите увидеть.\n";
			   cin >> s1;
			   sym = set[s1];
			   if (s1 >= sets.size()) break;
			   set.show(); cout << "\n";
			   cout << "Ваш символ:"<< sym<<"\n";
			   break;
		}
	}

}
