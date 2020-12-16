#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "Equation.h"

using namespace std;
void Test1();
void Test2();

void main() {
    setlocale(LC_CTYPE, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //Test1();
    Test2();
}

void Test1()
{
    cout << "\nВычислить многочлен методом Ньютона.\n";
    cout << "_______________________________________\n\n";
    Equation equ(new double[4]{ -1,1,3,5 }, 4);
    Equation deriv = equ.derivate();
    double rez = 0;
    cout << "Исходное уравнение: "; equ.show();
    cout << "Производная: "; deriv.show();
    rez = NewthonMethod(equ, 1.5, 0.001);
    cout << "Решим уравнение с начальным значением х0=1.5 и приближением eps=0.001. \n";
    cout << "Результат решения уравнения методом Ньютона: " << rez;
    cout << "\n\n";
}
void Test2()
{
    cout << "\nВычислить многочлен методом Ньютона.\n";
    cout << "_______________________________________\n\n";
    Equation equ(new double[4]{ 3,2,-4,1 }, 4);
    Equation deriv = equ.derivate();
    double rez = 0;
    cout << "Исходное уравнение: "; equ.show();
    cout << "Производная: "; deriv.show();
    rez = NewthonMethod(equ, 1.5, 0.0001);
    cout << "Решим уравнение с начальным значением х0=1.5 и приближением eps=0.001. \n";
    cout << "Результат решения уравнения методом Ньютона: " << rez;
    cout << "\n\n";
}







