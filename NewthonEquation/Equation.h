#pragma once
#include <iostream>
#include <math.h> 

using namespace std;

class Equation
{
private:
    int size; // ������ �������� - maxPower
    int maxSize = 100; // ����������� ��������� ������� ��������
    double* koefs; // ������������ ��������
public:
    Equation();
    Equation(const Equation&);
    Equation(double*, int);
    Equation(int);
    ~Equation();
    int getSize() { return this->size; }
    void show() const;
    Equation operator=(const Equation&);
    Equation derivate(); // �����������
    double compute(double x);    
};
double NewthonMethod(Equation equ, double x0, double eps);