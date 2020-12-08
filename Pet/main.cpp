
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "Parrot.h"

using namespace std;

int main()
{
	int N = 5;
	Dog dog = { "Hatiko", 8, 10 };
	Pet* animals[5] = {
		new Cat("Musya", 1, 3.2),
		new Cat("Kitty", 7, 4.6),
		new Parrot("Kesha", 2, 0.8),
		new Cat("Murzik", 5, 10.0),
		new Dog("Rex", 6, 12.5),
	};

	cout << "Some information about our animals: \n";

	for (int i = 0; i < 5; i++)
	{
		showAllInformation(*animals[i]);
	}

	cout << "Let's feed animals: \n";
	for (int i = 0; i < 5; i++)
	{
		animals[i]->feedMe();
		cout << "\n";
	}

	return 0;
}