
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Pet.h"
using namespace std;

Pet::Pet():
	name(),
	age(0),
	weight(0.5)
{ }
Pet::Pet(string name, int age, double weight)
{
	setName(name);
	setAge(age);
	setWeight(weight);
}

Pet::~Pet(){}

void Pet::setName(string name)
{
	if (name[0] < 'A' || name[0]>'Z') throw "bad arg";
	for (int i = 1; i < name.length(); i++)
	{
		if (name[i] < 'a' || name[i]>'z') throw "bad arg";
	}
	this->name = name;
}
void Pet::setAge(int age)
{
	if (age < 0) throw "bad arg";
	this->age = age;
}
void Pet::setWeight(double weight)
{
	if (weight < 0.2) throw "bad arg";
	this->weight = weight;
}

string Pet::getName() { return name; }
int Pet::getAge() { return age; }
double Pet::getWeight() { return weight; }

 void Pet::sound()
{
	 cout << "this animal speaks ....\n";
}
 void Pet::ration()
{
	 cout << "this animal eats ....\n";
}
 //void Pet::feedMe()
 void Pet::show()
 {
	 cout <<"Name: " << name <<"\n";
	 cout << "Age: " << age << "\n";
	 cout << "Weight: " << weight << "\n";
 }
void showAllInformation(Pet &pet)
{
	cout << "Name: " << pet.getName()<<"\n";
	cout << "Age: " << pet.getAge() << " y.o." << "\n";
	cout << "Weight: " << pet.getWeight() << " kg" << "\n";
	pet.sound();
	pet.ration();
	cout << "\n";
}
