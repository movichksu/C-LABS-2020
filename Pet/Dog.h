#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Pet.h"
using namespace std;

class Dog : public Pet {
public:
	Dog();
	Dog(string, int, double);
	~Dog();
	virtual void sound();
	virtual void ration();
	virtual void feedMe();
	string whoIs();
};
