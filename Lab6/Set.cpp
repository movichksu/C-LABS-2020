#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include "Set.h"


Set::Set() :
	set(),
	power(0)
{

}
 
Set::Set(int p) :
	set(),
	power(p)
{
	if (p > max_power)
	{
		power = max_power;
		return;
	}
}
 
Set::Set(string str) :
	set(str),
	power(0)
{
	removeDublicates();
	int p = set.length();
	if (p > max_power) { throw "this set is too large"; };
	power = p;
}
Set::Set(const Set& rhs) :
	power(rhs.power),
	set(rhs.set)
{
	this->set = set;
	this->power = power;//don't need to do it bc you already init values
}
Set::~Set()
{}

void Set::setElements(string newSet)
{
	removeDublicates();
	int p = newSet.length();
	if (p > max_power) { throw "this set is too large"; };
	set = newSet;
}
void Set::setPower(int newPower)
{
	if (newPower > max_power)
	{
		power = max_power;
		return;
	}
	power = newPower;
}
int Set::getPower() const { return power; }
string Set::getElements() const { return set; }
void Set::show()
{
	if (set[0] == '\0') return;
	cout << "{";
	for (int i = 0; i < power - 1; ++i)
		cout << set[i] << ", ";
	cout << set[power - 1] << " }";
}

Set& Set::operator=( Set& rhs) {
	power = rhs.power;
	set = rhs.set;
	return *this;
}

char& Set::operator[]( int i)
{
	if (i>=power) { throw "this index is too large"; };
	return set[i];
}
void Set::addElem(char el)
{
	if (this->power + 1 > max_power || In(el)) return;
	set.push_back(el);
	power++;
}
bool Set::In(char el)
{
	for (int i = 0; i < power; ++i)
		if (set[i] == el) return true; 
	return false;
}
Set Set::operator-(Set& rhs)
{
	Set tmp;
	for (int i = 0; i < this->power; ++i)
		if (!rhs.In(this->set[i]))
			tmp.addElem(this->set[i]);
	return tmp;
}
Set Set::operator+(Set& rhs)
{
	Set tmp;
	for (int i = 0; i < this->power; ++i)
		tmp.addElem(this->set[i]);
	for (int i = 0; i < rhs.power; ++i)
		tmp.addElem(rhs.set[i]);
	return tmp;
}
Set Set::operator*(Set& rhs)
{
	Set tmp;
	for (int i = 0; i < this->power; ++i)
		if (rhs.In(this->set[i]))
			tmp.addElem(this->set[i]); 
	return tmp;
}

istream& operator>>(istream& in, Set& s)
{
	string tmp;
	int p;

	in >> tmp;
	s.setElements(tmp);
	p = tmp.length();
	s.setPower(p);

	return in;
}
ostream& operator<<(ostream& out, Set& s)
{
	if (s.set[0] == '\0') return out;
	out << s.set << "\n";
	return out;
}

void swap(Set& a, Set& b)
{
	using std::swap;
	std::swap(a.set, b.set);
	std::swap(a.power, b.power);
}
void printSets(vector<Set> arr)
{
	if (arr.empty()) { cout << "В массиве множеств пусто.\n"; return; }
	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i].set[0] == '\0') continue;
		arr[i].show();  cout << "\n";
	}
}

Set setOfUniqeElements(Set s1, Set s2)
{
	Set Union = s1 + s2;
	Set Crossing = s1 * s2;
	return (Union - Crossing);
}

void Set::removeDublicates()
{
	int i, m, N=set.length();
	char a;
	for (i = 0; i < set.size(); ++i)
	{
		a = set[i];
		for (m = i+1; m < set.size(); ++m)
		{
			if (a == set[m])
			{
				set.erase(m, 1);
				m--;
			}
		}
	}

}

void readFromFile(vector<Set>& arr, string way)
{
	if (arr.empty()) { cout << "Нечего записывать...\n"; return; }
	Set tmp;
	size_t size = 0;
	ifstream takeFrom(way);
	try {
		takeFrom.is_open();
		for (int i = 0; i < arr.size(); ++i)
		{
			takeFrom >> tmp;
			if (takeFrom.eof()) break;
			arr[size] = tmp;
			size++;
		}
	}
	catch (...) {
		if (!(takeFrom.eof())) cout << "Произошла ошибка при выполнении операции\n";
	}
	takeFrom.close();
}
void writeToFile(vector<Set> arr, string way)
{
	if (arr.empty()) { cout << "Нечего записывать...\n"; return; }
	ofstream putInto(way);
	try {
		putInto.is_open();
		for (int i = 0; i < arr.size(); i++)
		{
			putInto << arr[i] << " \n";
		}
	}
	catch (...) { cout << "Произошла ошибка при выполнении операции\n"; }
	putInto.close();
}


void addToFile(Set set, string way)
{
	if (way == " ")
		throw std::invalid_argument("Не указан путь.");
	ofstream out(way, ios::app);
	try {
		out << set;
	}
	catch (...)
	{
		cout << "Ошибка открытия файла\n";
	}
	out.close();
}
vector<Set> addSet(vector<Set> arr)
{
	vector<Set> tmp(arr.size() + 1);
	for (int i = 0; i < arr.size(); ++i) tmp[i] = arr[i];
	cout << "Введите строку с элементами множества: \n";
	cin >> tmp[arr.size()];
	cout << "Множество добавлено успешно\n";
	return tmp;
}
vector<Set> deleteSet(vector<Set> arr, int num)
{
	if (num >= arr.size() || num < 0) { cout << "Такого номера не существует!\n"; return arr; }
	swap(arr[num], arr[arr.size() - 1]);
	vector<Set> tmp(arr.size() - 1);
	for (int i = 0; i < arr.size() - 1; ++i) tmp[i] = arr[i];
	return tmp;
}

