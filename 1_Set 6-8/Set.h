#pragma once
#include <iostream>
#include <string>
using namespace std;

class Set {
private:
	int* set;
	int  power;
public:
	Set();
	Set(const Set&);
	Set(int);
	Set(int*, const int);
	Set(string);
	~Set();

	void initSet();
	void setSet(int*, int);
	void setPower(int);
	void setElement(int, int);
	int  getPower() const;
	int* getSet() const;

	Set  operator + (Set&); //объединение
	Set  operator * (Set&); //пересечение
	Set  operator - (Set&); //разность
	Set& operator = (Set&);
	int&  operator [] (int);

	friend ostream& operator << (ostream&, const Set&);
	friend istream& operator >> (istream&, Set&);

	bool belong(int);
	void show();
};