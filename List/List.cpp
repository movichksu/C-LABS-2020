#include "List.h"
#include <iostream>
#include <iomanip>


List::List() :
	head(nullptr),
	size(0)
{

}
List::List(int* arr, int n)
{
    size = 0;
	head = nullptr;
	if (!n) { cout << "there is no elements in array\n"; return; }
	for (int i = 0; i < n; i++)
	{
		pushBack(arr[i]);
	}
}
List::~List()
{
	clearList();
}

int List::getSize() { return size; }

int List::operator[](const int i)
{
	if (i >= this->size || i < 0) { throw "bad index"; }
	Node* tmp(this->head);
	for (int count = 0; count < this->size; count++)
	{
		if (count == i)
		{
			return tmp->data;
		}
		tmp = tmp->Next;
	}

}
ostream& operator<<(ostream& out, List& list) //???????
{
	
	for (int i = 0; i < list.getSize(); ++i)
		cout << list[i] << " ";
	cout << "\n"; 
	return out;
}

void List::popFront()
{
	if (head != nullptr) {
		Node* tmp = head;
		head = head->Next;
		delete tmp;
		size--;
	}
}
void List::pushBack(int data)
{
	if (head == nullptr)
	{
		head = new Node(data);
	}
	else
	{
		Node* tmp = this->head; //в переменную tmp добавляем указатель на head
		while ((tmp->Next) != nullptr) // смотрим на что указывает поле tmp
		{
			tmp = tmp->Next;
		}
		tmp->Next = new Node(data);
	}
	size++;
}
void List::pushFront(int data)
{
	head = new Node(data, head);
	size++;
}


void List::insert(int data, int index)
{
	if (index > this->size || index < 0) return;
	if (index == 0) { pushFront(data); }
	else
	{
		Node* tmp = this->head; // previous
		for (int i = 0; i < index - 1; i++)
		{
			tmp = tmp->Next;
		}
		tmp->Next = new Node(data, tmp->Next);
		size++;
	}

}

void List::removeAt(int index)
{
	if (index >= this->size || index < 0) return;
	if (index == 0) { popFront(); }
	else
	{
		Node* tmp = this->head; // previous
		for (int i = 0; i < index - 1; i++)
		{
			tmp = tmp->Next;
		}
		Node* toDelete = tmp->Next;
		tmp->Next = toDelete->Next;
		delete toDelete;
		size--;
	}

}

void List::popBack()
{
	removeAt(size - 1);
}


void List::clearList()
{
	while (size)
	{
		popFront();
	}
}

bool areTheSame(List& list1, List& list2)
{
	//содержится ли list1 в list2 
	bool boolean = false;
	int N;
	if (list1.size <= list2.size) N = list1.size;
	else { cout << "list2 is less then list1\n"; return false; }
	
		for (int j = 0; j < list2.size; j++)
		{
			if (N + j < list2.size)
			{
				if (list1[0] == list2[j])
				{
					for (int i = 0; i < N; i++)
					{
						if (list1[i] == list2[i + j])
						{
							boolean = true;
						}
						else { boolean = false; break; }
					}
				}
				//else break;
				if (boolean == true) break;
			}
		}	
		return boolean;
}

void writeToFile(List& list, string way)
{
	ofstream putInto(way);
	try
	{
		putInto.is_open();
		for (int i = 0; i < list.getSize(); ++i)
			putInto << list[i] << " ";
	}
	catch(...) 	{	cout << " Error of writing.\n";	}
	putInto.close();
}
void readFromFile(List& list, string way)
{
	int tmp;
	ifstream takeFrom(way);
	try {
		takeFrom.is_open();
		while (!takeFrom.eof())
		{
			takeFrom >> tmp;
			list.pushBack(tmp);
		}
	}
	catch(...)
	{	if (!(takeFrom.eof())) cout << " Error of reading.\n";	}
	takeFrom.close();

}

