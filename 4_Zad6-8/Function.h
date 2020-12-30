#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class Function {
public:
	virtual string functionName() = 0;
	virtual void compute(double ) = 0;
	virtual void show() = 0;
	virtual void input() = 0;
};
