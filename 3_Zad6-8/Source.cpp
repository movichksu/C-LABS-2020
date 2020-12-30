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
    cout << "������ ������ �������� : "; arr1.show(); 
    cout << "������ ������ �������� : "; arr2.show(); 
    cout << "������� ������ ������ ������� ������� :" << arr1[8]<<"\n";
    cout << "������� ������ ������ ������� ������� :" << arr2[2] << "\n";
    cout << "����� ���� ��������: "; 
    (arr1 + arr2).show(); cout << "\n";

    cout << "\n\n";
}
void Test2()
{
    Hex hex1(2, "A3");
    Hex hex2(3, "34B");
    cout << "������ ������ �������� : "; hex1.show(); 
    cout << "������ ������ �������� : "; hex2.show(); 
    cout << "����� ���� ����������������� �����: ";
    (hex1 + hex2).show(); cout << "\n";

    cout << "\n\n";
}
void Test3()
{
    Hex bit1(8, "00001101");
    Hex bit2(8, "10110000");
    cout << "������ ������ �������� : "; bit1.show(); 
    cout << "������ ������ �������� : "; bit2.show(); 
    cout << "����� ���� ������� �����: ";
    (bit1 + bit2).show(); cout << "\n";

    cout << "\n\n";
}