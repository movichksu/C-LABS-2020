#pragma once
#include <iostream>
using namespace std;

class BitString
{
private:
	int size = 0;
	unsigned* string;
public:
	BitString();
	BitString(const unsigned* str, int strLen);
	BitString(const BitString& other);
	~BitString();
	friend ostream& operator<< (ostream& out, BitString& str);
	friend istream& operator>> (istream& in, BitString& str);
	BitString& operator =(const BitString& str);
	bool operator==(const BitString& str);
	bool operator!=(const BitString str);
};