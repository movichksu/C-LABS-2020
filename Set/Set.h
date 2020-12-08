#pragma once
#include <iostream>
#include <iomanip>
//#include <vector>
#include <string>

using namespace std;
struct Set
{
	static const int max_power = 100; //максимальная мощность
private:
	string set; //множество
    int power; //мощность
public:
	Set();
	Set(int ); //конструктор с инициализацией множество и заполнением значений "по порядку"
	Set(string ); //конструктор с инициализацией элементов множества
	Set( const Set& ); //конструктор копирования
	~Set();

	void setElements(const string newName);
	void setPower(int newYear);
	int getPower() const;
	string getElements() const;
	void show();

	Set& operator=( Set&); //оператор присваивания
	char& operator[](int );
	//Set& operator+=(const char ); //добавление ещё одного элемента множества
	bool In(char ); //проверка на содержание элемента во множестве
	void addElem(char );
	Set operator-(Set& ); //разность двух множеств
	Set operator+(Set& ); //объединение двух множеств
	Set operator*(Set& ); //пересечение двух множеств
	friend istream& operator>>(istream& , Set& ); //ввод
	friend ostream& operator<<(ostream& , Set& ); //вывод
	friend void swap(Set&, Set&);
	friend void printSets(vector<Set>); //вывод массива объектов
	friend Set setOfUniqeElements(Set , Set ); // строит множество, состоящее из элементов, входящих только в одно из заданных множеств

private:
	void removeDublicates();
};

void readFromFile(vector<Set>&, string);
void writeToFile(vector<Set>, string);
vector<Set> addSet(vector<Set>);
vector<Set> deleteSet(vector<Set>, int);
