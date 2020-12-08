#pragma once
#include <iostream>
#include <iomanip>
//#include <vector>
#include <string>

using namespace std;
struct Set
{
	static const int max_power = 100; //������������ ��������
private:
	string set; //���������
    int power; //��������
public:
	Set();
	Set(int ); //����������� � �������������� ��������� � ����������� �������� "�� �������"
	Set(string ); //����������� � �������������� ��������� ���������
	Set( const Set& ); //����������� �����������
	~Set();

	void setElements(const string newName);
	void setPower(int newYear);
	int getPower() const;
	string getElements() const;
	void show();

	Set& operator=( Set&); //�������� ������������
	char& operator[](int );
	//Set& operator+=(const char ); //���������� ��� ������ �������� ���������
	bool In(char ); //�������� �� ���������� �������� �� ���������
	void addElem(char );
	Set operator-(Set& ); //�������� ���� ��������
	Set operator+(Set& ); //����������� ���� ��������
	Set operator*(Set& ); //����������� ���� ��������
	friend istream& operator>>(istream& , Set& ); //����
	friend ostream& operator<<(ostream& , Set& ); //�����
	friend void swap(Set&, Set&);
	friend void printSets(vector<Set>); //����� ������� ��������
	friend Set setOfUniqeElements(Set , Set ); // ������ ���������, ��������� �� ���������, �������� ������ � ���� �� �������� ��������

private:
	void removeDublicates();
};

void readFromFile(vector<Set>&, string);
void writeToFile(vector<Set>, string);
vector<Set> addSet(vector<Set>);
vector<Set> deleteSet(vector<Set>, int);
