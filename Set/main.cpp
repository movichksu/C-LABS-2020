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

	cout << "\n����� ����������!\n";
	cout << "������������ �������� ��������� � ��������� - 100 ���������.\n";
	cout << "������ �� ����� �������� ��������� ���������, ������ ���.\n";
	cout << "\n\n";
	while (true)
	{
		cout << "\n�������� ��, ��� �� ������ �������:\n";
		cout << "1.������� ��������� ������ �������� �� �����.\n"; 
		cout << "2.������� ��������� � ����.\n"; 
		cout << "3.������� ��������� �� �����.\n";
		cout << "4.������� ���������.\n"; 
		cout << "5.������� ��������� �� �������.\n";
		cout << "6.��������� ������� ���������� ������ ���� ��������.\n"; 
		cout << "7.��������� �������� ���� ��������\n"; 
		cout << "8.��������� ����������� ���� ��������.\n"; 
		cout << "9.��������� ����������� ���� ��������.\n";
		cout << "10.�������������� ������� ���������.\n";
		cout << "11.�������� ����������(i-�� �������).\n";
		cout << "0.����� �� ���������.\n"; 
		int choice;
		char sym;
		cin >> choice;
		switch (choice) {
		case 0: return 0;
		case 1: if (sets.empty()) { cout << "� ������� �������� �����.\n"; break; }
			    printSets(sets);
			    break;
		case 2: if (sets.empty()) { cout << "� ������� �������� �����.\n"; break; }
			    cout << "������� ����, ���� �������� ������\n";
			    cin >> way;
			    writeToFile(sets, way);
			    break;
		case 3: cout << "������� ����, ������ ����� ������\n";
			    cin >> way;
			    readFromFile(sets, way);
			    break;
		case 4: sets = addSet(sets);
			    break;
		case 5: if (sets.empty()) { cout << "� ������� �������� �����.\n"; break; }
		   	    cout << "������� ���������� ����� ���������.\n";
			    int num; cin >> num;
			    sets = deleteSet(sets, num);
			    break;
		case 6: if (sets.empty()) { cout << "� ������� �������� �����.\n"; break; }
			    cout << "������� ������� �������� ��� ���������� ��������.\n";
				cin >> s1 >> s2;
				rezult = setOfUniqeElements(sets[s1], sets[s2]);
				cout << "��������� �� ���������� ���������:\n" << rezult << "\n";
			    break;
		case 7: if (sets.empty()) { cout << "� ������� �������� �����.\n"; break; }
			    cout << "������� ������� �������� ��� ���������� ��������.\n";
				cin >> s1; cin >> s2;
			    rezult1 = sets[s1] - sets[s2];
				cout << "�������� ��������:\n";
				rezult1.show();
				cout << "\n";
			    break;
		case 8: if (sets.empty()) { cout << "� ������� �������� �����.\n"; break; }
			    cout << "������� ������� �������� ��� ���������� ��������.\n";
			    cin >> s1>>s2;
			    rezult2 = sets[s1] + sets[s2];
				cout << "����������� ��������:\n";
				rezult2.show();
				cout << "\n";
			    break;
		case 9: if (sets.empty()) { cout << "� ������� �������� �����.\n"; break; }
			    cout << "������� ������� �������� ��� ���������� ��������.\n";
			    cin >> s1 >> s2;
			    rezult3 = sets[s1] * sets[s2];
				cout << "����������� ��������:\n";
				rezult3.show();
				cout << "\n";
			    break;
		case 10: if (sets.empty()) { cout << "� ������� �������� �����.\n"; break; }
			   cout << "������� ����� ���������, � ������� ������ ����� ������.\n";
			   cin >> s1;
			   if (s1 >= sets.size()) break;
			   sets[s1].show(); cout << "\n";
			   cout << "������� ������, ������� ����� �����.\n";
			   cin >> sym;
			   if (sets[s1].In(sym)) cout << "������ ���� � ���������\n";
			   cout << "� ��������� ������ �����������.\n";
			   break;
		case 11:  if (sets.empty()) { cout << "� ������� �������� �����.\n"; break; }
			   cout << "������� ������ ��������, ������� ������ �������.\n";
			   cin >> s1;
			   sym = set[s1];
			   if (s1 >= sets.size()) break;
			   set.show(); cout << "\n";
			   cout << "��� ������:"<< sym<<"\n";
			   break;
		}
	}

}
