#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct List
{
private:
    // Узел - элемент списка
    struct Node
    {
    public:
        int data; // данные
        Node* Next; // указатель на след элемент
    public:
        Node() :
            data(int()),
            Next(nullptr)
        {

        }
        Node(int data = int(), Node* Next = nullptr)
        {
            this->data = data;
            this->Next = Next;
        }
    };
    Node* head;
    int size;
public:
    List();
    List(int*, int);
    // List(const List& );
    ~List();

    int getSize();

    int operator[](const int);
    friend ostream& operator<<(ostream&, List&);

    void popFront();// удалить первый элемент
    void popBack(); // удалить последний элемент
    void pushFront(int); // вставить в начало 
    void pushBack(int); // вставить в конец
    void insert(int data, int index); // добавление элемента в список по указанному индексу
    void removeAt(int index); // удаление элемента в списке по указанному индексу
    void clearList(); // очистить список

    friend bool areTheSame(List&, List&); // not working????
    friend void readFromFile(List&, string);
    friend void writeToFile(List&, string);
    //void Show(); // отображение списка.
};