#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class Pet{
protected:
	string name;
	int age;
	double weight;
public:
	Pet();
	Pet(string, int, double);
	~Pet();
	//Pet(const Pet&);

	void setName(string);
	void setAge(int);
	void setWeight(double);
	string getName();
	int getAge();
	double getWeight();

	virtual void sound();
	virtual void ration();
	virtual void feedMe() = 0;
	void show();


};
void showAllInformation(Pet &pet);