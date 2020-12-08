#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <vector>
#include "Driver.h"
#include "Bus.h"
using namespace std;


int main() {
    setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int  N(21);
	string way;
	vector<Bus> buses(N);
	Bus b;
	b={ {"Василевич", "АГ" }, "1212", "13a", "МАЗ", 2003, 1000000 };

	cout << "\nДобро пожаловать!\n";
	cout << "Все зарегистрированные в списке авьлбусы не старше 2000 года выпуска.\n";
	cout << "В фамилии водитилей не предусмотрена запись буквы \"ё\". Заменяйте данную букву на \"е\".\n";
	cout << "Инициалы водителей пишутся как две заглавные буквы, без точек.\n";
	cout << "Названия марок принимаются только заглавными буквами.\n";
	cout << "\n\n";
	while (true)
	{
		cout << "\nВыберите то, что вы хотите сделать:\n";
		cout << "1.Вывести имеющийся список автобусов на экран.\n";
		cout << "2.Вывести список автобусов в файл.\n";
		cout << "3.Считать список автобусов из файла.\n";
		cout << "4.Показать элемент из списка.\n";
		cout << "5.Найти автобусы с пробегом более 10000 км\n";
		cout << "6.Найти автобусы, которые эксплуатируются больше 10 лет.\n";
		cout << "7.Найти автобусы, идущие по заданному маршруту.\n";
		cout << "0.Выход из программы.\n";
		int choice;
		cin >> choice;
		switch (choice) {
		case 0: return 0;
		case 1: if (buses.empty()) { cout << "В списке ещё нет автобусов\n"; break; }
			    cout << setw(20) << "Водитель: |" << setw(6) << " №А: |" << setw(6) <<  " №М: |" << setw(13) << "  Марка: |" << setw(8) << "Год: |" << setw(11) << " Пробег в км:|\n";
			    printBuses(buses);
			    break; 
		case 2: if (buses.empty()) { cout << "В списке ещё нет автобусов\n"; break; }
			    cout << "Введите путь, куда записать список\n";
			    cin >> way;
				writeToFile(buses, way);
			    break;
		case 3: cout << "Введите путь, откуда взять список\n";
			    cin >> way; 
				readFromFile(buses, way);
			    break;
		case 4: if (buses.empty()) { cout << "В списке ещё нет автобусов\n"; break; }
			    cout << "Введите номер элемента, который вы хотите показать\n";
			    int n;
				cin >> n;
				if (buses.size() <= n || n < 0) { cout << "в списке нет такого номера.\n"; break; }
				buses[n].show();
			    break;
		case 5: if (buses.empty()) { cout << "В списке ещё нет автобусов\n"; break; }
			    cout << "Введите значение пробега, выше которого хотите отобрать автобусы\n";
			    double mil;
			    cin >> mil;
			    getBusesWithMilage(buses, mil);
			    break;
		case 6: if (buses.empty()) { cout << "В списке ещё нет автобусов\n"; break; }
			    cout << "Сколько лет эксплуатирующиеся автобусы вы хотите отобрать?\n";
			    int yo;
				cin >> yo;
			    getBusesOlderThen(buses, yo); 
			    break;
		case 7:  if (buses.empty()) { cout << "В списке ещё нет автобусов\n"; break; }
			     cout << "Введите маршрут, по которому хотите отобрать автобусы.\n";
			     string r;
			     cin >> r;
				 getBusesInRoute(buses, r);
			     break;
		}

	}
}


