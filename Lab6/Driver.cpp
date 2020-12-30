#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string> 
#include <fstream>
#include "Driver.h"

Driver::Driver() :
	sureName(),
	initials()
{

}
Driver::Driver(string sureName, string initials) : // ����������� � �����������
	sureName(sureName),
	initials(initials)
{
	setSureName(sureName);
	setInitials(initials);
}
Driver::Driver(const Driver& driver) :
	sureName(driver.sureName),
	initials(driver.initials)
{
	this->sureName = sureName;
	this->initials = initials;
}
Driver::~Driver()
{
	
}

void Driver::setSureName(string sureName)
{
	if (sureName[0] < '�' || sureName[0] > '�') { throw "bad data"; }
	for (int i = 1; i < sureName.length(); ++i)
	{
		if ((sureName[i] >= '�' && sureName[i] <= '�') || (sureName[i] >= '�' && sureName[i] <= '�' || sureName[i] == '�')) {}
		else { throw "bad data"; }
	}
	this->sureName = sureName;
}
void Driver::setInitials(string initials)
{
	if (initials.length() != 2) { throw "bad data"; }
	if ((initials[0] >= '�' && initials[0] <= '�') && (initials[1] >= '�' && initials[1] <= '�')){}
	else { throw "bad data"; }
	this->initials = initials;
}
string Driver::getSureName(){return sureName;}
string Driver::getInitials(){return initials;}

Driver& Driver::operator=(Driver rhs) {

	sureName = rhs.sureName; 
	initials = rhs.initials;
	return *this;
}
istream& operator>>(istream& in, Driver& driver)
{
	string tmp;
	in >> tmp;
	driver.setSureName(tmp);
	in >> tmp;
	driver.setInitials(tmp);
	return in;
}
ostream& operator<<(ostream& out, const Driver& driver)
{
	//out << setw(15) << driver.sureName << " " << setw(3) << driver.initials << " ";
	out  << driver.sureName << " " << driver.initials << " ";
	return out;
}
void my_swap(Driver& a, Driver& b)
{
	using std::swap;
	std::swap(a.sureName, b.sureName);
	std::swap(a.initials, b.initials);
}