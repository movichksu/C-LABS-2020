#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Pet.h"
using namespace std;

class Parrot : public Pet {
public:
	Parrot();
	Parrot(string, int, double);
	~Parrot();
	 virtual void sound();
	 virtual void ration();
	 virtual void feedMe();
	 string whoIs();
};
