#include "Set.h"

Set::Set() {
	cout << "\n������� �������� ���������: ";
	cin >> this->power;
	if (power < 1) 
		throw "�������� ������. �������� ��������� ������ ���� ������ ����.\n";
	this->set = new int[power];
	for (int i = 0; i < this->power; i++) {
		this->set[i] = 0;
	}

/*	cout << "������� �������� ���������:\n";
	for (int i = 0; i < this->power; i++) {
		cout << i + 1 << " �������: ";
		cin >> this->set[i];
	}*/
}
Set::Set(const Set& other) {
	this->power = other.getPower();
	this->set = new int[this->power];
	for (int i = 0; i < this->power; i++) this->set[i] = other.getSet()[i];
}
Set::Set(int power) {
	this->power = power;
	this->set = new int[power];
	for (int i = 0; i < power; i++) this->set[i] = 0;
}
Set::Set(int* set, const int power) {
	this->power = power;
	this->set = new int[this->power];
	for (int i = 0; i < this->power; i++) this->set[i] = set[i];
}
Set::Set(string sets)
{
	if (!sets.length()) throw "�������� �� ����� ���� ������ 1.\n";
	if (!(sets.length() % 2)) 
		this->power = sets.length() / 2;
	else 
		this->power = sets.length() / 2 + 1;
	this->set = new int[this->power];
	for (int i = 0, j = 0; i < sets.length(); i += 2, j++)
		this->set[j] = (int)(sets[i] - '0');
}
Set::~Set() {
	delete[] set;
}

void Set::initSet() {
	for (int i = 0; i < this->power; i++) {
		cin >> this->set[i];
	}
}


void Set::setSet(int* set, int power) {
	if (set == NULL) throw "���������� ��������� ��������. ������ ��������� ������.\n";
	else if (power <= 0) throw "�������� ������. �������� ��������� ������ ���� ������ ����.\n";
	else {
		for (int i = 0; i < power; i++) {
			this->set[i] = set[i];
		}
	}
}
void Set::setPower(int power) {
	if (power <= 0) throw "�������� ������. �������� ��������� ������ ���� ������ ����.\n";
	else this->power = power;
}
void Set::setElement(int index, int number) {
	this->set[index] = number;
}
int* Set::getSet() const {
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
	int *buf = new int[bufSize];
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
	int *buf = new int[size];
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
	int *buf = new int[size];
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
int&  Set::operator [] (int index) {
	cout << "������� �" << index << ": ";
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

bool Set::belong(int element) {
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


