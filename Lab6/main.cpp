#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <vector>
#include "Driver.h"
#include "Bus.h"
#include "Set.h"
#include "List.h"

using namespace std;

void Test1();
void Test2();
void Test3();
int main() {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int  N(21);
	string wayIN;
	string wayOut;
	vector<Bus> buses(N);
	Test3();

}

void Test1() {
	int  N(10);
	string wayIN;
	string wayOut;
	vector<Bus> buses(N);
	cout << "�� ������� ������ ��������� �� �����. ������� ��������: \n";
	cin >> wayIN;
	readFromFile(buses, wayIN);
	if (buses.empty()) { cout << "� ������ ��� ��� ���������\n"; return; }
	cout << setw(20) << "��������: |" << setw(6) << " ��: |" << setw(6) << " ��: |" << setw(13) << "  �����: |" << setw(8) << "���: |" << setw(11) << " ������ � ��:|\n";
	printBuses(buses);
	cout << "������ ������� �������� � ����. ������� ��� ��������: \n";
	cin >> wayOut;
	writeToFile(buses, wayOut);

	cout << "������� ����� ������ � ����. \n";
	cout << "������� �������, �� �������� ������ �������� ��������.\n";
	string r;
	cin >> r;
	getBusesInRoute(buses, r);

	cout << "������� ��� ����������������� �������� �� ������ ��������?\n";
	int yo;
	cin >> yo;
	getBusesOlderThen(buses, yo);
	cout << "\n";
}
void Test2() {
	vector<Set> arr(5);
	string wayIN;
	string wayOut;
	cout << "��������� ��������� �������� �� �����: \n";
	cin >> wayIN;
	readFromFile(arr, wayIN);
	printSets(arr);
	cout << "������� �������� �����, ���� ������� ��������� ��������, ���������, �������� ��������: \n";
	cin >> wayOut;
	Set rez1 = arr[0] + arr[1];
	addToFile(rez1, wayOut);
	cout << "\n";
	Set rez2 = arr[0] * arr[1];
	addToFile(rez2, wayOut);
	cout << "\n";
	Set rez3 = arr[0] - arr[1];
	addToFile(rez3, wayOut);
}
void Test3() {
	List list;
	string way;
	cout << "������� �������� �����, ������ ����� ������: \n";
	cin >> way;
	readFromFile(list, way);
	cout <<"�������������� ������: "<< list << "\n";
	cout << "������� ����, ���� ������� ����������:\n";
	cin >> way;
	list.pushBack(0); 
	list.pushBack(0); 
	list.pushBack(0);
	addToFile(list, way);
	list.pushFront(1);
	list.pushFront(1);
	list.pushFront(1);
	addToFile(list, way);
	list.popFront();
	list.popFront();
	list.popFront();
	list.popBack();
	list.popBack(); 
	list.popBack();
	addToFile(list, way);
}
