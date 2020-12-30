#pragma once
#include <iostream>
#include <string>
#include "BitString.h"
using namespace std;

class Set {
private:
	BitString* set;
	int  power;
	int maxPower = 64;
public:
	Set();
	Set(const Set&);
	Set(int);
	Set(BitString*, const int);
	~Set();

	void initSet();
	void setSet(BitString*, int);
	void setPower(int);
	void setElement(int, BitString);
	int  getPower() const;
	BitString* getSet() const;

	Set  operator + (Set&); //объединение
	Set  operator * (Set&); //пересечение
	Set  operator - (Set&); //разность
	Set& operator = (Set&);
	Set operator += (BitString);
	Set operator-= (BitString);
	BitString&  operator [] (int);

	friend ostream& operator << (ostream&, const Set&);
	friend istream& operator >> (istream&, Set&);

	bool belong(BitString);
	void show();
};