#include "Set.h"

Set::Set() {
	cout << "\nВведите мощность множества: ";
	cin >> this->power;
	if (power < 1) 
		throw "Неверные данные. Мощность множества должна быть больше 0.\n";
	if (power > maxPower)
		throw "Неверные данные. Мощность множества должна меньше 64.\n";
	this->set = new BitString[power];
	BitString a;
	for (int i = 0; i < this->power; i++) {
		this->set[i] = a;
	}
}
Set::Set(const Set& other): Set(other.set, other.power){}

Set::Set(int power) {
	if (power < 1)
		throw "Неверные данные. Мощность множества должна быть больше 0.\n";
	if (power > maxPower)
		throw "Неверные данные. Мощность множества должна меньше 64.\n";
	this->power = power;
	this->set = new BitString[power];
	BitString a;
	for (int i = 0; i < power; i++) 
		this->set[i] = a;
}
Set::Set(BitString* set, const int power) {
	if (power < 1)
		throw "Неверные данные. Мощность множества должна быть больше 0.\n";
	if (power > maxPower)
		throw "Неверные данные. Мощность множества должна меньше 64.\n";
	this->power = power;
	this->set = new BitString[this->power];
	for (int i = 0; i < this->power; i++) 
		this->set[i] = set[i];
}

Set::~Set() {
	delete[] set;
}

void Set::initSet() {
	for (int i = 0; i < this->power; i++) {
		cin >> this->set[i];
	}
}


void Set::setSet(BitString* set, int power) {
	if (set == NULL) throw "Невозможно выполнить операцию. Данное множество пустое.\n";
	else if (power <= 0) throw "Неверные данные. Мощность множества должна быть больше нуля.\n";
	else {
		for (int i = 0; i < power; i++) {
			this->set[i] = set[i];
		}
	}
}
void Set::setPower(int power) {
	if (power <= 0) throw "Неверные данные. Мощность множества должна быть больше нуля.\n";
	else this->power = power;
}
void Set::setElement(int index, BitString element) {
	this->set[index] = element;
}

BitString* Set::getSet() const {
	return this->set;
}
int  Set::getPower() const {
	return this->power;
}

Set  Set::operator + (Set& other) {
	int size = this->getPower() + other.getPower();
	for (int i = 0; i < this->getPower(); i++) {
		for (int j = 0; j < other.getPower(); j++) {
			if (this->getSet()[i] == other.getSet()[j]) --size;
		}
	}
	Set bufer(size);
	int bufSize = this->getPower() + other.getPower() - size;
	BitString* buf = new BitString[bufSize];
	for (int i = 0, k = 0; i < this->getPower(); i++) {
		for (int j = 0; j < other.getPower(); j++) {
			if (this->getSet()[i] == other.getSet()[j]) {
				buf[k] = this->getSet()[i];
				++k;
			}
		}
	}
	bufer.setSet(this->getSet(), this->getPower());
	bool flag = true;
	for (int i = this->getPower(), j = 0; i < size; flag = true, j++) {
		for (int k = 0; k < bufSize; k++) {
			if (other.getSet()[j] == buf[k]) {
				flag = false;
			}
		}
		if (flag) {
			bufer.set[i] = other.getSet()[j];
			++i;
		}
	}
	return bufer;
}
Set  Set::operator * (Set& other) {
	int size = 0;
	for (int i = 0; i < this->getPower(); i++) {
		for (int j = 0; j < other.getPower(); j++) {
			if (this->getSet()[i] == other.getSet()[j]) size++;
		}
	}
	BitString*buf = new BitString[size];
	for (int i = 0, k = 0; i < this->getPower(); i++) {
		for (int j = 0; j < other.getPower(); j++) {
			if (this->getSet()[i] == other.getSet()[j]) {
				buf[k] = this->getSet()[i];
				++k;
			}
		}
	}
	Set bufer(buf, size);
	delete[] buf;
	return bufer;
}
Set  Set::operator - (Set& other) {
	int size = 0;
	for (int i = 0; i < this->getPower(); i++) {
		for (int j = 0; j < other.getPower(); j++) {
			if (this->getSet()[i] == other.getSet()[j]) size++;
		}
	}
	BitString*buf = new BitString[size];
	for (int i = 0, k = 0; i < this->getPower(); i++) {
		for (int j = 0; j < other.getPower(); j++) {
			if (this->getSet()[i] == other.getSet()[j]) {
				buf[k] = this->getSet()[i];
				++k;
			}
		}
	}
	Set bufer(this->getPower() - size);
	bool flag = true;
	for (int i = 0, j = 0; i < bufer.getPower(); j++, flag = true) {
		for (int k = 0; k < size; k++) {
			if (this->getSet()[j] == buf[k]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			bufer.setElement(i, this->getSet()[j]);
			++i;
		}
	}
	delete[] buf;
	return bufer;
}
Set& Set::operator = (Set& other) {
	this->setPower(other.getPower());
	this->setSet(other.getSet(), other.getPower());
	return *this;
}
Set Set::operator += (BitString next)
{
	if (belong(next))
	{
		cout << "Такой элемент уже существует в множестве. \n";
	}
	else {
		int newLen = getPower() + 1;
		Set buffer(newLen);
		for (int i = 0; i < getPower(); i++) {
			buffer.set[i] = this->set[i];
			cout << this->set[i] << "\n";
		}
		buffer.set[getPower()] = next;
		delete[] this->set; set = nullptr;
		this->power = newLen;
		this->set = new BitString[this->power];
		for (int i = 0; i < buffer.getPower(); i++) {
			this->set[i] = buffer.set[i];
		}
		delete[] buffer.set; buffer.set = nullptr;
	}
	return *this;
}
Set Set::operator -= (BitString del)
{
	if (!belong(del)) {
		cout << "Не было найдено элемента, который нужно исключить из множества \n";
	}
	else
	{
		int newLen = getPower() - 1;
		int unity = 0;
		Set buffer(newLen);
		for (int i = 0; i < this->getPower(); i++) {
			if (this->set[i] == del) 
			{
				unity = 1; continue;
			}
			buffer.set[i-unity] = this->set[i];
		}
		delete[] this->set; this->set = nullptr;
		this->power = newLen;
		this->set = new BitString[this->power];
		for (int i = 0; i < buffer.getPower(); i++) {
			this->set[i] = buffer.set[i];
		}
		delete[] buffer.set; buffer.set = nullptr;
	}
	return *this;
}


BitString&  Set::operator [] (int index) {
	cout << "Элемент №" << index << ": ";
	return this->getSet()[index - 1];
}

ostream & operator<<(ostream& out, const Set& set) {
	for (int i = 0; i < set.power; i++)
		out << set.set[i] << " ";
	return out;
}
istream& operator>>(istream& in, Set& set) {
	for (int i = 0; i < set.getPower(); i++)
		cin >> set.set[i];
	return in;
}

bool Set::belong(BitString element) {
	for (int i = 0; i < this->getPower(); i++) {
		if (element == this->getSet()[i]) return true;
	}
	return false;
}
void Set::show() {
	for (int i = 0; i < this->getPower(); i++) {
		cout << this->getSet()[i] << " ";
	}
	cout << "\n";
}


