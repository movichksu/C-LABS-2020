#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Driver.h"
using namespace std;
struct Bus
{
private:
	Driver driver; //данные водителя
	string busNum; // номер автобуса
	string route; // номер маршрута
	string mark; // марка автобуса
	int year; // год выпуска
	double milage; // пробег в километрах
public:
	Bus(); // конструктор без параметров
	Bus(Driver, string, string, string, int, double); // конструктор с параметрами
	Bus(const Bus&); // конструктор копирования
	~Bus(); // деструктор

	int getYear() const;
	double getMilage() const;
	Driver getDriver() const;
	string getMark() const;
	string getRoute() const;
	string getBusNum() const;
	void setDriver(Driver newDriver);
	void setMark(const string newName);
	void setBusNum(const string newName);
	void setRoute(const string newName);
	void setYear(int newYear);
	void setMilage(double newMilage);
	void show();

	Bus& operator=(Bus); //оператор присваивания
	friend istream& operator>>(istream&, Bus&); //ввод
	friend ostream& operator<<(ostream&, const Bus&); //вывод
	friend void my_swap(Bus&, Bus&);
	friend void printBuses(vector<Bus>); //вывод массива объектов


	friend void getBusesWithMilage(vector<Bus>, double); // выводит список автобусов с пробегом > 10000км
	friend void getBusesOlderThen(vector<Bus>, int); // выводит список автобусов старше 10 лет
	friend void getBusesInRoute(vector<Bus>, string); // выводит список автобусов, которые ходят по заданному маршруту


};
	void readFromFile(vector<Bus>&, string);
	void writeToFile(vector<Bus>, string);
	void addToFile(Bus, string);
