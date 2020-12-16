#include "Equation.h"

Equation::Equation()
{
	size = 100;
	koefs = new double[size];
	for (int i = 0; i < size; i++) {
		koefs[i] = 0;
	}
}
Equation::Equation(const Equation& rhs):Equation(rhs.koefs, rhs.size){}
Equation::Equation(int size)
{
	if (size >= maxSize)
		throw "\nСлишком большой размер для полинома.\n";
	if (this->koefs) {
		delete[] this->koefs; this->koefs = nullptr;
	}
	this->size = size;
	this->koefs = new double[this->size];
	for (int i = 0; i < this->size; i++) {
		this->koefs[i] = 0;
	}
}
Equation::Equation(double* koefs, int len)
{
	if (len > maxSize)
		throw "\n Вы ввели слишком большой размер полинома.\n";
	/*if (this->koefs) {
		delete[] this->koefs; this->koefs = nullptr;
	}*/
	size = len;
	this->koefs = new double[size];
	for (int i = 0; i < size; i++)
	{
		this->koefs[i] = koefs[i];
	}
}
Equation::~Equation()
{
	delete[] koefs;
	koefs = nullptr;
}

void Equation::show() const
{
	cout << this->koefs[this->size - 1]<<"x^"<<size-1;
	for (int i = size - 2; i > 0; i--) {
		if (koefs[i] < 0) 
			cout << koefs[i] << "x^" << i;
		else 
			if (koefs[i] > 0) 
				cout << "+" << koefs[i] << "x^" << i;
	}

	if (koefs[0] < 0)
		cout << koefs[0] << "=0\n";
	else
		if (koefs[0] > 0)
			cout << "+" << koefs[0] << "=0\n";
		else cout << "=0\n";
}
Equation Equation::derivate()
{
	Equation derivate(this->size - 1);
	for (int i = 0; i < derivate.getSize(); i++)
	{
		derivate.koefs[i] = this->koefs[i + 1] * (i + 1);
	}
	return derivate;
}
double Equation::compute(double x)
{
	double rezult = 0;
	for (int i = 0; i < getSize(); i++)
	{
		rezult += (this->koefs[i] * pow(x, i));
	}
	return rezult;
}


Equation Equation::operator=(const Equation& rhs)
{
	if (this->koefs) {
		delete[] this->koefs; this->koefs = nullptr;
	}
	this->size = rhs.size;
	koefs = new double[size];
	for (int i = 0; i < this->size; i++)
	{
		koefs[i] = rhs.koefs[i];
	}

	return *this;
}
double NewthonMethod(Equation equ, double x0, double eps)
{
	Equation derivate = equ.derivate();
	double y = equ.compute(x0)/derivate.compute(x0);
	while (abs(y) > eps)
	{
		x0 = x0 - y;
		y = equ.compute(x0) / derivate.compute(x0);
	}

	return x0;
}