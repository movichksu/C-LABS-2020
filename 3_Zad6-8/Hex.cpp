#include "Hex.h"

using namespace std;

int convertToDec(Hex hex)
{
    int rez = 0, 
        temp = 0,
        power = hex.getSize() - 1,
        n = hex.getSize();
    for (int i = 0; i < hex.getSize(); i++)
    {
        switch (toupper(hex.getString()[i]))
        {
        case 'A': temp = 10; break;
        case 'B': temp = 11; break;
        case 'C': temp = 12; break;
        case 'D': temp = 13; break;
        case 'E': temp = 14; break;
        case 'F': temp = 15; break;
        case '1': temp = 1; break;
        case '2': temp = 2; break;
        case '3': temp = 3; break;
        case '4': temp = 4; break;
        case '5': temp = 5; break;
        case '6': temp = 6; break;
        case '7': temp = 7; break;
        case '8': temp = 8; break;
        case '9': temp = 9; break;
        case '0': temp = 0; break;
        }
        rez = rez + temp * pow(16, power);
        power--;
    }
    return rez;
}

Hex convertToHex(int dec) {
        string tmp("");
        int size = 0;
        do
        {
            int r(dec % 16);
            if (r > 9) { r += (int)'A' - 10; }
            else  { r += (int)'0'; };
            tmp = (char)r + tmp;
            size++;
            dec /= 16;
        } while (dec);

        char* rez = new char[size];
        for (int i = 0; i < size; i++) {
            rez[i] = tmp[i];
        }
        //rez[size] = '\0';
        Hex rezult(size, rez);
        delete[] rez; rez = nullptr;
        return rezult;
	}

Array Hex::operator+( Array& rhs)
    {
        int dec1 = convertToDec(*this);
        Hex other(rhs.getSize(), rhs.getString());
        int dec2 = convertToDec(other);
        int decRez = dec1 + dec2;
        Hex rez(convertToHex(decRez));

        return rez;
    }
