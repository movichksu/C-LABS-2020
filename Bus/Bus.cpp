#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include "Bus.h"
#include "Driver.h"

Bus::Bus() :
	driver(),
	busNum(),
	route(),
	mark(),
	year(2000),
	milage(0)
{

}
Bus::Bus(Driver driver, string busNum, string route, string mark, int year, double milage) : // конструктор с параметрами
	driver(driver),
	busNum(busNum),
	route(route),
	mark(mark),
	year(year),
	milage(milage)
{
	setYear(year);
	setBusNum(busNum);
	setRoute(route);
	setMark(mark);
	setMilage(milage);
}
Bus::Bus(const Bus& bus) :
	driver(bus.driver),
	busNum(bus.busNum),
	route(bus.route),
	mark(bus.mark),
	year(bus.year),
	milage(bus.milage)
{
	this->driver = driver;
	this->busNum = busNum;
	this->route = route;
	this->mark = mark;
	this->year = year;
	this->milage = milage;
}
Bus::~Bus()
{
	
}

int Bus::getYear() const { return year; }
double Bus::getMilage() const { return milage; }
Driver Bus::getDriver() const { return driver; }
string Bus::getMark() const { return mark; }
string Bus::getRoute() const { return route; }
string Bus::getBusNum() const { return busNum; }
void Bus::setDriver(Driver driver)
{
	this->driver = driver;
}
void Bus::setRoute(const string route) {
	if (route.length() > 4) { throw "bad data"; }
	if (route[0] < char(48) || route[0] > char(57)) { throw "bad data"; }
	for (int i = 0; i < route.length() - 1; ++i)
	{
		if ((route[i] < char(48) || route[i] > char(57)) && (route[i + 1] < char(48) || route[i + 1] > char(57)))
			throw "bad data";
	}
	this->route = route;
}
void Bus::setMark(const string mark) {

	for (int i = 0; i < mark.length(); ++i)
	{
		if ((mark[i] >= 'A' && mark[i] <= 'Z') || (mark[i] >= 'А' && mark[i] <= 'Я' || mark[i] == 'Ё')) {}
		else { throw "bad data"; }
	}

	this->mark = mark;
}
void Bus::setBusNum(const string busNum) {
	if (busNum.length() != 4) { throw "bad data"; }
	for (int i = 0; i < busNum.length(); ++i)
	{
		if (busNum[i] < char(48) || busNum[i] > char(57))
			throw "bad data";
	}
	this->busNum = busNum;
}
void Bus::setYear(int year)
{
	if (year < 2000 || year > 2020) throw "Bad data";
    else this->year = year;
}
void Bus::setMilage(double milage)
{
	if (milage < 0) throw "Bad data";

	else this->milage = milage;
}
void Bus::show()
{
	cout << "Водитель:"<< driver <<"\n";
	cout << "Номер автобуса:"<< busNum <<"\n";
	cout << "Маршрут:"<< route <<"\n";
	cout << "Марка автобуса:"<< mark <<"\n";
	cout << "Год выпуска:"<< year <<"\n";
	cout << "Километраж:"<< milage <<"\n";
}


Bus& Bus::operator=(Bus rhs) {

	driver = rhs.driver;
	busNum = rhs.busNum;
	route = rhs.route;
	mark = rhs.mark;
	year = rhs.year;
	milage = rhs.milage;
	return *this;
}
istream& operator>>(istream& in, Bus& bus)
{
	string tmp;
	int y;
	double mil;
	in >> tmp;
	bus.driver.setSureName(tmp);
	in >> tmp; 
	bus.driver.setInitials(tmp);
	in >> tmp;
	bus.setBusNum(tmp);
	in >> tmp;
	bus.setRoute(tmp);
	in >> tmp;
	bus.setMark(tmp);
	in >> y;
	bus.setYear(y);
	in >> mil;
	bus.setMilage(mil);
	return in;
}
ostream& operator<<(ostream& out, const Bus& bus)
{
	if (bus.busNum[0] == '\0') return out;
	//out << bus.driver << " " << setw(5) << bus.busNum << " " << setw(5) << bus.route << " " << setw(12) << bus.mark << " " << setw(7) << bus.year << " " << setw(10) << bus.milage << " ";
	out << bus.driver << bus.busNum << " " << bus.route << " " << bus.mark << " " << bus.year << " " << bus.milage << "\n";
	return out;
}
void my_swap(Bus& a, Bus& b)
{
	using std::swap;

	my_swap(a.driver, b.driver);
	std::swap(a.busNum, b.busNum);
	std::swap(a.route, b.route);
	std::swap(a.mark, b.mark);
	std::swap(a.year, b.year);
	std::swap(a.milage, b.milage);
}

void printBuses(vector<Bus> arr)
{
	if (arr.empty())	{	cout << "Массив пуст.\n";  return;	}
	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i].busNum[0] == '\0') break;
		cout << setw(15) << arr[i].driver << " " << setw(5) << arr[i].busNum << " " << setw(5) << arr[i].route << " " << setw(12) << arr[i].mark << " " << setw(7) << arr[i].year << " " << setw(10) << arr[i].milage << " \n";
	}
}
void getBusesWithMilage(vector<Bus> arr, double milage)
{
	if (arr.empty()) { cout << "Массив пуст.\n";  return; }
	for (int i = 0; i < arr.size(); ++i)
		if (arr[i].milage >= milage)
		{  cout << arr[i] << "\n";	}
}
void getBusesOlderThen(vector<Bus> arr, int age)
{
	if (arr.empty()) { cout << "Массив пуст.\n";  return; }
	for (int i = 0; i < arr.size(); ++i)
		if (2020 - arr[i].year >= age)
		{
			cout << arr[i] << "\n";
		}
}
void getBusesInRoute(vector<Bus> arr, string route)
{
	if (arr.empty()) { cout << "Массив пуст.\n";  return; }
	for (int i = 0; i < arr.size(); ++i)
		if (arr[i].route == route)
		{
			cout << arr[i] << "\n";
		}
}


void readFromFile(vector<Bus>& arr, string way)
{
	if (arr.empty()) { cout << "Нечего записывать...\n"; return; }
	Bus tmpBus;
	size_t size=0;
	ifstream takeFrom(way);
	try {
		takeFrom.is_open();
		for (int i = 0; i < arr.size(); ++i)
		{
			takeFrom >> tmpBus;
			if (takeFrom.eof()) break;
			arr[size] = tmpBus;
			size++;
		}
	}
	catch (...) { 
		if (!(takeFrom.eof())) cout << "Произошла ошибка при выполнении операции\n"; }
	takeFrom.close();
}
void writeToFile(vector<Bus> arr, string way)
{
	if (arr.empty()) { cout << "Нечего записывать...\n"; return; }
	ofstream putInto(way);
	try {
		putInto.is_open();
		for (int i = 0; i < arr.size(); i++)
		{
			putInto << arr[i] << " \n";
		}
	}
	catch (...){ cout << "Произошла ошибка при выполнении операции\n"; }
	putInto.close();
}