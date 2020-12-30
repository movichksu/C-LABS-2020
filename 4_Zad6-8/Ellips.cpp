#include "Ellips.h"
#include<math.h>
using namespace std;

Ellips::Ellips() :
	a(1),
	b(1)
{ }
Ellips::Ellips(int a, int b)
{
	setA(a);
	setB(b);
}
Ellips::Ellips(Ellips& f) : Ellips(f.a, f.b)
{}
Ellips::~Ellips() {}

void Ellips::setA(int a)
{
	if (a <= 0)
		throw "������� �������� �� ��������� ���������. \n";
	this->a = a;
}
void Ellips::setB(int b)
{
	if (b <= 0)
		throw "������� �������� �� ��������� ���������. \n";
	this->b = b;
}

string Ellips::functionName() {
	
	return "������";
}
void Ellips::compute(double x) {
	if (1 - (x / this->a) * (x / this->a) < 0) {
		cout << "������ ������ �� ����� ������������ � ������ �����������.\n";
		return;
	}
	else if (1 - (x / this->a) * (x / this->a) == 0) {
		cout << "�������� y: " << 0 << " \n";
		return;
	}
	double y1 = sqrt((1 - (x / this->a) * (x / this->a)) * (this->b) * (this->b));
	double y2 = - sqrt((1 - (x / this->a) * (x / this->a)) * (this->b) * (this->b));
	cout << "������� �������� y:  " << y1 << " \n";
	cout << "������ �������� y: " << y2 << " \n";
}
void Ellips::show() {
	cout << "x^2/" << this->a << "^2 + y^2/" << this->b << "^2 = 1";
}
void Ellips::input() {
	int a, b;
	cout << "������� ����������� a: \n";
	cin >> a;
	cout << "������� ����������� b: \n";
	cin >> b;
	setA(a);
	setB(b);
}
