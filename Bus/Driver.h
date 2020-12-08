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
	Driver(); // конструктор без параметров
	Driver(string, string); // конструктор с параметрами
	Driver(const Driver&); // конструктор копирования
	~Driver(); // деструктор

	void setSureName(string);
	void setInitials(string);
	string getSureName();
	string getInitials();


	Driver& operator=(Driver); //оператор присваивания
	friend istream& operator>>(istream&, Driver&); //ввод
	friend ostream& operator<<(ostream&, const Driver&); //вывод
	friend void my_swap(Driver&, Driver&);
};