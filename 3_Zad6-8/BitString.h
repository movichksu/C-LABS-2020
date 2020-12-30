#pragma once
#pragma once
#include "Array.h"
#include <string>

using namespace std;

class BitString : public Array
{
public:
	BitString();
	BitString(int ,const char* );
	BitString(const BitString& other) :BitString(other.size, other.string) {};
	virtual Array operator+(Array& rhs);
};

