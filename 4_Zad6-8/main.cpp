#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "Function.h"
#include "Hyperbola.h"
#include "Ellips.h"
using namespace std;
void Test();

int main() {
    setlocale(LC_CTYPE, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Test();

    return 0;
}

void Test()
{
    Function* functions[4]{
        new Hyperbola(),
        new Hyperbola(),
        new Ellips(),
        new Ellips()
    };
    int x = 1;
    cout << "Инициализируем гиперболу: \n";
    functions[1]->input();
    cout << "Инициализируем эллипс: \n";
    functions[3]->input();
    cout << "\n";

    for (int i = 0; i < 4; i++) {
        cout << "Для функции " << functions[i]->functionName()<<": "; functions[i]->show(); cout << "\n";
        functions[i]->compute(x);
        cout << "\n";
    }


}

