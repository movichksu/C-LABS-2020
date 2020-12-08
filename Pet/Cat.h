#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Pet.h"
using namespace std;

class Cat : public Pet {
public:
	Cat();
	Cat(string, int, double);
	~Cat();
	virtual void sound();
	virtual void ration();
	virtual void feedMe();
	string whoIs();

};
