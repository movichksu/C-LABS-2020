#pragma once
#include <iostream>
#include <string>

using namespace std; 
struct Driver
{
private:
	string sureName;
	string initials;
public:
	Driver(); // ����������� ��� ����������
	Driver(string, string); // ����������� � �����������
	Driver(const Driver&); // ����������� �����������
	~Driver(); // ����������

	void setSureName(string);
	void setInitials(string);
	string getSureName();
	string getInitials();


	Driver& operator=(Driver); //�������� ������������
	friend istream& operator>>(istream&, Driver&); //����
	friend ostream& operator<<(ostream&, const Driver&); //�����
	friend void my_swap(Driver&, Driver&);
};