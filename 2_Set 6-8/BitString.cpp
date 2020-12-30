#include "BitString.h"
#include <Windows.h>
#include <iostream>
#include <fstream>

using namespace std;

BitString::BitString() {
	this->size = 8;
	this->string = new unsigned[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->string[i] = 0;
	}
}


BitString::BitString(const BitString& other): BitString(other.string, 8)
{
}

BitString::BitString(const unsigned* str, int strLen)
{
	this->size = 8;
	this->string = new unsigned[this->size];
	if (strLen > this->size)
		throw "Слишком большая длина передаваемой строки";
	int difference = 0;
	if (strLen < this->size)
	{
		difference = this->size - strLen;
		for (int i = 0; i < difference; i++)
			this->string[i] = 0;
	}
	for (int i = 0; i < strLen; i++)
	{
		if (str[i] == 0)
			this->string[i + difference] = str[i];
		else this->string[i + difference] = 1;
	}
}
BitString::~BitString() {
	delete[] this->string;
}

	ostream& operator<<(ostream & out, BitString & str){
		for (int i = 0;  i < str.size; i++)
		{
			out << str.string[i];
		}
		return out;
	}
	istream& operator>>(istream & in, BitString & str) {
		unsigned buf[8];

		str.size = 8;
		str.string = new unsigned[str.size];

		for (int i = 0; i < str.size; i++)
		{
			in >> buf[i];
			if (buf[i] == 0)
				str.string[i] = buf[i];
			else str.string[i] = 1;
		}

		return in;
	}
	BitString& BitString::operator =(const BitString& str) {
		
		if (this->string) {
			delete[] this->string; 
			this->string = nullptr;
		}

		this->size = str.size;
		this->string = new unsigned[str.size];

		for (int i = 0; i < str.size; i++)
		{
			this->string[i] = str.string[i];
		}

		return *this;
	}

	bool BitString::operator==(const BitString& str)
	{
		for (int i = 0; i < str.size; i++)
		{
			if (str.string[i] != this->string[i]) return false;
		}
		return true;
	}
	bool BitString::operator!=(const BitString str)
	{
		return !(*this == str);
	}

