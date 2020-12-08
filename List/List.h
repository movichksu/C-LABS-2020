#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct List
{
private:
    // ���� - ������� ������
    struct Node
    {
    public:
        int data; // ������
        Node* Next; // ��������� �� ���� �������
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

    void popFront();// ������� ������ �������
    void popBack(); // ������� ��������� �������
    void pushFront(int); // �������� � ������ 
    void pushBack(int); // �������� � �����
    void insert(int data, int index); // ���������� �������� � ������ �� ���������� �������
    void removeAt(int index); // �������� �������� � ������ �� ���������� �������
    void clearList(); // �������� ������

    friend bool areTheSame(List&, List&); // not working????
    friend void readFromFile(List&, string);
    friend void writeToFile(List&, string);
    //void Show(); // ����������� ������.
};