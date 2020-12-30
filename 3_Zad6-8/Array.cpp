#include "Array.h"

Array::Array() :
    size(1), 
    string(new char[size])
{
    string[0] = 0;
}
Array::Array(const int size, const char* str) : 
    size(size), 
    string(new char[this->size])
{
    for (int i = 0; i < this->size; i++)
    {
        string[i] = str[i];
    }
}
Array::Array(const Array& arr) : Array(arr.size, arr.string)
{}
Array::Array(const int size) :
    size(size), 
    string(new char[this->size])
{
    for (int i = 0; i < size; i++)
    {
        string[i] = 0;
    }
}
Array::~Array()
{
    delete[] string;
}

int Array::getSize()
{
    return size;
}
char* Array::getString()
{
    return string;
}
void Array::show()
{
    for (int i = 0; i < this->size; i++) {
        cout << string[i];
    }
    cout << "\n";
}
char Array::operator[](const int i)
{
    char rez;
    try {
        if (i < 0 || i >= this->size)
            throw "Invalid index\n";
        rez = string[i];
    }
    catch (...)
    {
        cout << "Invalid index\n";
        exit(0);
    }
    return rez;
   /* if (i < 0 || i >= this->size)
    {
       // throw "Invalid index";
        cout << "Invalid index";
        return ' ';
    }
    return this->string[i];*/
}
Array Array::operator+( Array& rhs)
{
    Array res(std::fmax(size, rhs.size));
    if (size > rhs.size)
    {
        for (int i = 0; i < rhs.size; i++)
        {
            res.string[i] = string[i] + rhs.string[i];
        }
        for (size_t i = rhs.size; i < size; i++)
        {
            res.string[i] = string[i];
        }
    }
    else {
        for (int i = 0; i < size; i++)
        {
            res.string[i] = string[i] + rhs.string[i];
        }
        for (size_t i = size; i < rhs.size; i++)
        {
            res.string[i] = rhs.string[i];
        }
    }
    return res;
}


