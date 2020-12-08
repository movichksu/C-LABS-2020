
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Cat.h"
using namespace std;

Cat::Cat() : Pet()
{ }
Cat::Cat(string name, int age, double weight) : Pet(name, age, weight)
{ }

Cat::~Cat() {}

void Cat::sound()
{
	cout << name << " speaks meow \n";
}
void Cat::ration()
{
	cout << name << " eats fish\n";
}

string Cat::whoIs()
{
	return "Cat";
}
void Cat::feedMe()
{
	cout << name << ": I'm a " << whoIs();
	cout << " and I want some milk!";
}