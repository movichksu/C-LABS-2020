
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Dog.h"
using namespace std;

Dog::Dog() : Pet()
{ }
Dog::Dog(string name, int age, double weight) : Pet(name, age, weight)
{ }

Dog::~Dog() {}

void Dog::sound()
{
	cout << name << " speaks wof-wof! \n";
}
void Dog::ration()
{
	cout << name << " eats meat\n";
}

string Dog::whoIs()
{
	return "Dog";
}

void Dog::feedMe()
{
	cout << name << ": I'm a " << whoIs();
	cout << " and I want some meet!";
}
