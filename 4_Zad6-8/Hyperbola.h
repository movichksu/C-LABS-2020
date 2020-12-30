#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include "Function.h"

using namespace std;

class Hyperbola : public Function {
private:
	int a;
	int b;
public:
	Hyperbola();
	Hyperbola(int, int);
	Hyperbola(Hyperbola&);
	~Hyperbola();

	void setA(int );
	void setB(int );
	int getA() {return this->a;}
	int getB() {return this->b;}
	virtual string functionName();
	virtual void compute(double);
	virtual void show();
	virtual void input();
};