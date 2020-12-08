
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Parrot.h"
using namespace std;

Parrot::Parrot() : Pet()
{ }
Parrot::Parrot(string name, int age, double weight) : Pet(name, age, weight)
{ }

Parrot::~Parrot() {}

void Parrot::sound()
{
	cout << name <<" speaks chirik-chirik \n";
}
void Parrot::ration()
{
	cout << name << " eats fruits\n";
}
string Parrot::whoIs()
{
	return "Parrot";
}

void Parrot::feedMe()
{
	cout <<name<< ": I'm a " << whoIs();
	cout << " and I want some fruits!";
}
