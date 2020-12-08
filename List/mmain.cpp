#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include "List.h"
#include <Windows.h>
#include <vector>
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string way;
	int N = 3, number=0;
	int index = 0;
	vector<List> arr(N);
	cout << "\nДобро пожаловать!\n";
	cout << " Enter the way to read list0:\n";
	cin >> way;
	readFromFile(arr[0], way);
	cout << " Enter the way to read list1:\n";
	cin >> way;
	readFromFile(arr[1], way);

	while (true)
	{
		cout << "\nВыберите то, что вы хотите сделать:\n";
		cout << "1.Вывести на экран имеющиеся списки.\n";
		cout << "2.Считать список из файла.\n";
		cout << "3.Вывести список в файл.\n";
		cout << "4.Добавить элемент в конец списка.\n";
		cout << "5.Добавить элемент в начало списка.\n";
		cout << "6.Добавить элемент в заданное место списка.\n";
		cout << "7.Удалить элемент в конеце списка.\n";
		cout << "8.Удалить элемент в начале списка.\n";
		cout << "9.Удалить элемент в заданном месте списка.\n";
		cout << "10.Очистить список.\n";
		cout << "11.Вывести заданный элемент списка.\n";
		cout << "12.Задание.\n";
		cout << "0.Выход из программы.\n";
		int choice;
		cin >> choice;
		switch (choice) {
		case 0: return 0;
		case 1: if (arr.empty()) { cout << "В массиве списков пусто.\n"; break; }
			    for (int i = 0; i < N; i++)
			    {
				    cout << arr[i];
			    }
			    break;
		case 2: cout << "Введите номер списка\n";
			    cin >> index;
			    cout << "Введите путь, куда записать список\n";
			    cin >> way;
			    readFromFile(arr[index], way);
			    break;
		case 3: cout << "Введите номер списка\n";
			    cin >> index;
				cout << "Введите путь, откуда взять список\n";
				cin >> way;
			    writeToFile(arr[index], way);
			    break;
		case 4: cout << "Что вставить\n";
				cin >> number;
			    arr[2].pushBack(number);
			    break;
		case 5: cout << "Что вставить\n";
			    cin >> number;
			    arr[2].pushBack(number);
			    break;
		case 6: cout << "Что вставить\n";
			    cin >> number;
				cout << "Куда вставить\n";
				cin >> index;
			    arr[2].insert(index,number);
			    break;
		case 7: cout << "Из какого списка удалить\n";
			    cin >> index;
			    arr[index].popBack();
			    break;
		case 8: cout << "Из какого списка удалить\n";
			    cin >> index;
			    arr[index].popFront();
			    break;
		case 9: cout << "Из какого списка удалить\n";
			    cin >> index;
				cout << "Какой номер удалить\n";
				cin >> number;
			    arr[index].removeAt(number);
			    break;
		case 10: cout << "Какой список очистить?\n";
			     cin >> index;
			     arr[index].clearList();
			     break;
		case 11: cout << "Из какого списка \n";
			     cin >> index;
			     cout << "Какой элемент вывести\n";
			     cin >> number;
			     cout << arr[index][number] << "\n"; //????????????
			     break;
		case 12: if (arr.empty()) { cout << "В массиве списков пусто.\n"; break; }
			   if (areTheSame(arr[0], arr[1])) cout << " СОдержится \n";
			   else cout << " Не содержится \n";
			   break;

		}
	
	
	}

	/*
	// для оригинального лист
	int array[3] = { 1, 2, 3 };
	List list(array, 3);
	List list2;
	List list3;
	string way;
	list2.pushBack(1);
	list2.pushBack(2);
	list2.pushBack(3);
	list2.pushBack(4);
	list2.insert(5,3);
	list2.removeAt(0);
	list2.pushBack(6);
	list2.pushBack(7);
	list2.pushBack(8);

	//list.pushBack(1);
	//list.pushBack(3);
	//list.pushBack(3);
	//list.pushBack(4);
	cout << list;
	cout << list2;
	if ((areTheSame(list, list2))) cout << "+\n";
	else cout << "-\n";
	cout << " Enter the way\n";
	cin >> way;
	writeToFile(list2, way);
	cout << " Enter the way\n";
	cin >> way;
	readFromFile(list3, way);
	cout << list3;
	*/
}
