#pragma once
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class Array {
protected:
	int size;
	char* string;
public:
	Array();
	Array(const int);
	Array(const int, const char*);
	Array(const Array&);
	~Array();

	int getSize();
	char* getString();
	void show();
	char operator[](const int);
	virtual Array operator+( Array&);
};