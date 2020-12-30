#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "Array.h"
#include "Hex.h"
#include "BitString.h"

using namespace std;

void Test1();
void Test2();
void Test3();

int main() {
    setlocale(LC_CTYPE, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Test1();
    Test2();
    Test3();

    return 0;
}

void Test1()
{
    Array arr1(4, "0@A0");
    Array arr2(7, "904AABC");
    cout << "Первый массив символов : "; arr1.show(); 
    cout << "Второй массив символов : "; arr2.show(); 
    cout << "Выведем первый индекс первого массива :" << arr1[8]<<"\n";
    cout << "Выведем второй индекс второго массива :" << arr2[2] << "\n";
    cout << "Сумма двух массивов: "; 
    (arr1 + arr2).show(); cout << "\n";

    cout << "\n\n";
}
void Test2()
{
    Hex hex1(2, "A3");
    Hex hex2(3, "34B");
    cout << "Первый массив символов : "; hex1.show(); 
    cout << "Второй массив символов : "; hex2.show(); 
    cout << "Сумма двух шестнадцатиричных чисел: ";
    (hex1 + hex2).show(); cout << "\n";

    cout << "\n\n";
}
void Test3()
{
    Hex bit1(8, "00001101");
    Hex bit2(8, "10110000");
    cout << "Первый массив символов : "; bit1.show(); 
    cout << "Второй массив символов : "; bit2.show(); 
    cout << "Сумма двух битовых строк: ";
    (bit1 + bit2).show(); cout << "\n";

    cout << "\n\n";
}