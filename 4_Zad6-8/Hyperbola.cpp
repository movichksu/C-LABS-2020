#include "Hyperbola.h"
#include<math.h>
using namespace std;

Hyperbola::Hyperbola() :
	a(1),
	b(1)
{ }
Hyperbola::Hyperbola(int a, int b)
{
	setA(a);
	setB(b);
}
Hyperbola::Hyperbola(Hyperbola& f) : Hyperbola(f.a,f.b)
{}
Hyperbola::~Hyperbola() {}

void Hyperbola::setA(int a)
{
	if (a <= 0)
		throw "������� �������� �� ��������� ���������. \n";
	this->a = a;
}
void Hyperbola::setB(int b)
{
	if (b <= 0)
		throw "������� �������� �� ��������� ���������. \n";
	this->b = b;
}

string Hyperbola::functionName() {

	return "���������";
}
void Hyperbola::compute(double x) {
	if ((x / this->a) * (x / this->a) - 1 < 0)
	{
		cout << "������ ������ �� ����� ������������ � ������ �����������.\n";
		return;
	}
	else if (1 - (x / this->a) * (x / this->a) == 0) {
		cout << "�������� y: " << 0 << " \n";
		return;
	}
	double y1 = sqrt(((x / this->a) * (x / this->a) - 1) * (this->b) * (this->b));
	double y2 = -sqrt(((x / this->a) * (x / this->a) - 1) * (this->b) * (this->b));
	cout << "������� �������� y:  " << y1 << " \n";
	cout << "������ �������� y: " << y2 << " \n";
}
void Hyperbola::show() {
	cout << "x^2/" << this->a << "^2 - y^2/" << this->b << "^2 = 1";
}
void Hyperbola::input() {
	int a, b;
	cout << "������� ����������� a: \n";
	cin >> a;
	cout << "������� ����������� b: \n";
	cin >> b;
	setA(a);
	setB(b);
}
