#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Driver.h"
using namespace std;
struct Bus
{
private:
	Driver driver; //������ ��������
	string busNum; // ����� ��������
	string route; // ����� ��������
	string mark; // ����� ��������
	int year; // ��� �������
	double milage; // ������ � ����������
public:
	Bus(); // ����������� ��� ����������
	Bus(Driver, string, string, string, int, double); // ����������� � �����������
	Bus(const Bus&); // ����������� �����������
	~Bus(); // ����������

	int getYear() const;
	double getMilage() const;
	Driver getDriver() const;
	string getMark() const;
	string getRoute() const;
	string getBusNum() const;
	void setDriver(Driver newDriver);
	void setMark(const string newName);
	void setBusNum(const string newName);
	void setRoute(const string newName);
	void setYear(int newYear);
	void setMilage(double newMilage);
	void show();

	Bus& operator=(Bus); //�������� ������������
	friend istream& operator>>(istream&, Bus&); //����
	friend ostream& operator<<(ostream&, const Bus&); //�����
	friend void my_swap(Bus&, Bus&);
	friend void printBuses(vector<Bus>); //����� ������� ��������


	friend void getBusesWithMilage(vector<Bus>, double); // ������� ������ ��������� � �������� > 10000��
	friend void getBusesOlderThen(vector<Bus>, int); // ������� ������ ��������� ������ 10 ���
	friend void getBusesInRoute(vector<Bus>, string); // ������� ������ ���������, ������� ����� �� ��������� ��������


};
	void readFromFile(vector<Bus>&, string);
	void writeToFile(vector<Bus>, string);
	void addToFile(Bus, string);
