#include "BitString.h"

BitString::BitString() : Array() {
	this->size = 8;
	this->string = new char[this->size];
	for (int i = 0; i < this->size; i++)
	{
			this->string[i] == '0';
	}
}
BitString::BitString(int size, const char* str) : Array(size,str)
{
	
	for (int i = 0; i < this->size; i++)
	{
		if (this->string[i] != '0')
			this->string[i] == '1';
		else this->string[i] == '0';
	}
}

Array BitString::operator+(Array& rhs)
{
	BitString other(rhs.getSize(), rhs.getString());
	BitString buffer;
	for (int i = 0; i < 8; i++)
	{
		if (this->string[i] == '1' || rhs.getString()[i] == '1')
			buffer.string[i] = '1';
		else buffer.string[i] = '0';
	}
	return buffer;
}