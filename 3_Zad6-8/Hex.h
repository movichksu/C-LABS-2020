#pragma once
#include "Array.h"
#include <string>

using namespace std;

class Hex : public Array
{
public:
	Hex() : Array() {};
	Hex(const int size) : Array(size){};
	Hex(const int size, const char* str) : Array(size, str) {};
	Hex(const Hex& hex) : Hex(hex.size, hex.string) {};
	virtual Array operator+( Array& rhs);

};
int convertToDec(Hex);
Hex convertToHex(int);