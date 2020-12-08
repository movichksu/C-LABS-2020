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
	b={ {"���������", "��" }, "1212", "13a", "���", 2003, 1000000 };

	cout << "\n����� ����������!\n";
	cout << "��� ������������������ � ������ �������� �� ������ 2000 ���� �������.\n";
	cout << "� ������� ��������� �� ������������� ������ ����� \"�\". ��������� ������ ����� �� \"�\".\n";
	cout << "�������� ��������� ������� ��� ��� ��������� �����, ��� �����.\n";
	cout << "�������� ����� ����������� ������ ���������� �������.\n";
	cout << "\n\n";
	while (true)
	{
		cout << "\n�������� ��, ��� �� ������ �������:\n";
		cout << "1.������� ��������� ������ ��������� �� �����.\n";
		cout << "2.������� ������ ��������� � ����.\n";
		cout << "3.������� ������ ��������� �� �����.\n";
		cout << "4.�������� ������� �� ������.\n";
		cout << "5.����� �������� � �������� ����� 10000 ��\n";
		cout << "6.����� ��������, ������� ��������������� ������ 10 ���.\n";
		cout << "7.����� ��������, ������ �� ��������� ��������.\n";
		cout << "0.����� �� ���������.\n";
		int choice;
		cin >> choice;
		switch (choice) {
		case 0: return 0;
		case 1: if (buses.empty()) { cout << "� ������ ��� ��� ���������\n"; break; }
			    cout << setw(20) << "��������: |" << setw(6) << " ��: |" << setw(6) <<  " ��: |" << setw(13) << "  �����: |" << setw(8) << "���: |" << setw(11) << " ������ � ��:|\n";
			    printBuses(buses);
			    break; 
		case 2: if (buses.empty()) { cout << "� ������ ��� ��� ���������\n"; break; }
			    cout << "������� ����, ���� �������� ������\n";
			    cin >> way;
				writeToFile(buses, way);
			    break;
		case 3: cout << "������� ����, ������ ����� ������\n";
			    cin >> way; 
				readFromFile(buses, way);
			    break;
		case 4: if (buses.empty()) { cout << "� ������ ��� ��� ���������\n"; break; }
			    cout << "������� ����� ��������, ������� �� ������ ��������\n";
			    int n;
				cin >> n;
				if (buses.size() <= n || n < 0) { cout << "� ������ ��� ������ ������.\n"; break; }
				buses[n].show();
			    break;
		case 5: if (buses.empty()) { cout << "� ������ ��� ��� ���������\n"; break; }
			    cout << "������� �������� �������, ���� �������� ������ �������� ��������\n";
			    double mil;
			    cin >> mil;
			    getBusesWithMilage(buses, mil);
			    break;
		case 6: if (buses.empty()) { cout << "� ������ ��� ��� ���������\n"; break; }
			    cout << "������� ��� ����������������� �������� �� ������ ��������?\n";
			    int yo;
				cin >> yo;
			    getBusesOlderThen(buses, yo); 
			    break;
		case 7:  if (buses.empty()) { cout << "� ������ ��� ��� ���������\n"; break; }
			     cout << "������� �������, �� �������� ������ �������� ��������.\n";
			     string r;
			     cin >> r;
				 getBusesInRoute(buses, r);
			     break;
		}

	}
}


