#pragma once
#include <iostream>
#include <math.h> 

using namespace std;

class Equation
{
private:
    int size; // размер полинома - maxPower
    int maxSize = 100; // максимально возможная степень полинома
    double* koefs; // коэффициенты полинома
public:
    Equation();
    Equation(const Equation&);
    Equation(double*, int);
    Equation(int);
    ~Equation();
    int getSize() { return this->size; }
    void show() const;
    Equation operator=(const Equation&);
    Equation derivate(); // производная
    double compute(double x);    
};
double NewthonMethod(Equation equ, double x0, double eps);