#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


template<typename Type>
class List
{

private:
	// ���� - ������� ������
	template<typename Type>
	struct Node
	{
	public:
		Type data; // ������
		Node* Next; // ��������� �� ���� �������
	public:
		Node() :
			data(Type()),
			Next(nullptr)
		{

		}
		Node(Type data = Type(), Node* Next = nullptr)
		{
			this->data = data;
			this->Next = Next;
		}
	};
	Node<Type>* head;
	int size;
public:
	List();
	List(Type*, int);
	//List(const List& );
	~List();

	int getSize();

	Type operator[](const int);
	//friend ostream& operator<<(ostream&, List<Type>&);
	//template<typename Type>
	friend ostream& operator<<(ostream& out, List<Type>& list) //???????
	{

		for (int i = 0; i < list.getSize(); ++i)
			cout << list[i] << " ";
		cout << "\n";
		return out;
	}
	void popFront();// ������� ������ �������
	void popBack(); // ������� ��������� �������
	void pushFront(Type); // �������� � ������ 
	void pushBack(Type); // �������� � �����
	void insert(Type data, int index); //���������� �������� � ������ �� ���������� �������
	void removeAt(int index); //�������� �������� � ������ �� ���������� �������
	void clearList();//�������� ������

	  // not working????
	//friend void readFromFile(List<Type>&, string);
	//friend void writeToFile(List<Type>&, string);
	//void Show(); // ����������� ������.
};
template<typename Type>
bool areTheSame(List<Type>&, List<Type>&);

template<typename Type>
List<Type>::List() :
	head(nullptr),
	size(0)
{

}

template<typename Type>
List<Type>::List(Type* arr, int n)
{
	size = 0;
	head = nullptr;
	if (!n) { cout << "there is no elements in array\n"; return; }
	for (int i = 0; i < n; i++)
	{
		pushBack(arr[i]);
	}
}

template<typename Type>
List<Type>::~List()
{
	clearList();
}

template<typename Type>
int List<Type>::getSize() { return size; }

template<typename Type>
Type List<Type>::operator[](const int i)
{
	if (i >= this->size || i < 0) { throw "bad index"; }
	Node<Type>* tmp(this->head);
	for (int count = 0; count < this->size; count++)
	{
		if (count == i)
		{
			return tmp->data;
		}
		tmp = tmp->Next;
	}

}

/*template<typename Type>
ostream& operator<<(ostream& out, List<Type>& list) //???????
{

	for (int i = 0; i < list.getSize(); ++i)
		cout << list[i] << " ";
	cout << "\n";
	return out;
}*/

template<typename Type>
void List<Type>::popFront()
{
	if (head != nullptr) {
		Node<Type>* tmp = head;
		head = head->Next;
		delete tmp;
		size--;
	}
}

template<typename Type>
void List<Type>::pushBack(Type data)
{
	if (head == nullptr)
	{
		head = new Node<Type>(data);
	}
	else
	{
		Node<Type>* tmp = this->head; //� ���������� tmp ��������� ��������� �� head
		while ((tmp->Next) != nullptr) // ������� �� ��� ��������� ���� tmp
		{
			tmp = tmp->Next;
		}
		tmp->Next = new Node<Type>(data);
	}
	size++;
}

template<typename Type>
void List<Type>::pushFront(Type data)
{
	head = new Node<Type>(data, head);
	size++;
}

template<typename Type>
void List<Type>::insert(Type data, int index)
{
	if (index > this->size || index < 0) return;
	if (index == 0) { pushFront(data); }
	else
	{
		Node<Type>* tmp = this->head; // previous
		for (int i = 0; i < index - 1; i++)
		{
			tmp = tmp->Next;
		}
		tmp->Next = new Node<Type>(data, tmp->Next);
		size++;
	}

}

template<typename Type>// ????????????????????????????
void List<Type>::removeAt(int index) 
{
	if (index >= this->size || index < 0) return;
	if (index == 0)	{	popFront();	}
	else
	{
		Node<Type>* tmp = this->head; // previous
		for (int i = 0; i < index - 1; i++)
		{
			tmp = tmp->Next;
		}
		Node<Type>* toDelete = tmp->Next;
		tmp->Next = toDelete->Next;
		delete toDelete;
        size--;
	}

}

template<typename Type>
void List<Type>::popBack()
{
	removeAt(size - 1);
}

template<typename Type>
void List<Type>::clearList()
{
	while (size)
	{
		popFront();
	}
}

template<typename Type>
bool areTheSame(List<Type>& list1, List<Type>& list2)
{
	//���������� �� list1 � list2 
	bool boolean = false;
	int N;
	if (list1.getSize() <= list2.getSize()) N = list1.getSize();
	else { cout << "list2 is less then list1\n"; return false; }

	for (int j = 0; j < list2.getSize(); j++)
	{
		if (N + j < list2.getSize())
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

template<typename Type>
void writeToFile(List<Type>& list, string way)
{
	ofstream putInto(way);
	try
	{
		putInto.is_open();
		for (int i = 0; i < list.getSize(); ++i)
			putInto << list[i] << " ";
	}
	catch (...) { cout << " Error of writing.\n"; }
	putInto.close();
}

template<typename Type>
void readFromFile(List<Type>& list, string way)
{
	Type tmp;
	ifstream takeFrom(way);
	try {
		takeFrom.is_open();
		while (!takeFrom.eof())
		{
			takeFrom >> tmp;
			list.pushBack(tmp);
		}
	}
	catch (...)
	{	if (!(takeFrom.eof())) cout << " Error of reading.\n";	}
	takeFrom.close();

}

void testInt()
{
	cout << "\n\n-------- ���� ��� ���� INT ---------\n";
	string way;
	int element;
	int index;
	List<int> lst1;
	List<int> lst2;
	cout << "������� ���� � ����� ��� list1. \n";
	cin >> way;
	readFromFile(lst1, way);
	cout << "������� ���� � ����� ��� list2. \n";
	cin >> way;
	readFromFile(lst2, way);
	cout << "list1 : " << lst1 << "\n";
	cout << "list2 : " << lst2 << "\n";
	if (areTheSame(lst1, lst2)) cout << "list1 ���������� ������ list2\n";
	else cout << "list1 �� ���������� ������ list2\n";

	cout << "��� �������� � �����? \n";
	cin >> element;
	lst1.pushBack(element);
	cout << "��� �������� � ������? \n";
	cin >> element;
	lst1.pushFront(element);
	cout << "��� �������� � ��������? \n";
	cin >> element;
	cout << "� ����� �����? \n";
	cin >> index;
	lst1.insert(element, index);

	cout << "������� �� �����. \n";
	lst2.popBack();
	cout << "������� �� ������. \n";
	lst2.popFront();
	cout << "������� �� ��������. �� ������ �����? \n";
	cin >> index;
	lst2.removeAt(index);
	 
	cout << "list1 : " << lst1 << "\n";
	cout << "list2 : " << lst2 << "\n";
	if (areTheSame(lst1, lst2)) cout << "list1 ���������� ������ list2\n";
	else cout << "list1 �� ���������� ������ list2\n";
}

void testChar()
{
	cout << "\n\n-------- ���� ��� ���� CHAR ---------\n";
	string way;
	char element;
	int index;
	List<char> lst1;
	List<char> lst2;
	cout << "������� ���� � ����� ��� list1. \n";
	cin >> way;
	readFromFile(lst1, way);
	cout << "������� ���� � ����� ��� list2. \n";
	cin >> way;
	readFromFile(lst2, way);
	cout << "list1 : " << lst1 << "\n";
	cout << "list2 : " << lst2 << "\n";
	if (areTheSame(lst1, lst2)) cout << "list1 ���������� ������ list2\n";
	else cout << "list1 �� ���������� ������ list2\n";

	cout << "��� �������� � �����? \n";
	cin >> element;
	lst1.pushBack(element);
	cout << "��� �������� � ������? \n";
	cin >> element;
	lst1.pushFront(element);
	cout << "��� �������� � ��������? \n";
	cin >> element;
	cout << "� ����� �����? \n";
	cin >> index;
	lst1.insert(element, index);

	cout << "������� �� �����. \n";
	lst2.popBack();
	cout << "������� �� ������. \n";
	lst2.popFront();
	cout << "������� �� ��������. �� ������ �����? \n";
	cin >> index;
	lst2.removeAt(index);

	cout << "list1 : " << lst1 << "\n";
	cout << "list2 : " << lst2 << "\n";
	if (areTheSame(lst1, lst2)) cout << "list1 ���������� ������ list2\n";
	else cout << "list1 �� ���������� ������ list2\n";
}


void testDouble()
{
	cout << "\n\n-------- ���� ��� ���� DOUBLE ---------\n";
	string way;
	double element;
	int index;
	List<double> lst1;
	List<double> lst2;
	cout << "������� ���� � ����� ��� list1. \n";
	cin >> way;
	readFromFile(lst1, way);
	cout << "������� ���� � ����� ��� list2. \n";
	cin >> way;
	readFromFile(lst2, way);
	cout << "list1 : " << lst1 << "\n";
	cout << "list2 : " << lst2 << "\n";
	if (areTheSame(lst1, lst2)) cout << "list1 ���������� ������ list2\n";
	else cout << "list1 �� ���������� ������ list2\n";

	cout << "��� �������� � �����? \n";
	cin >> element;
	lst1.pushBack(element);
	cout << "��� �������� � ������? \n";
	cin >> element;
	lst1.pushFront(element);
	cout << "��� �������� � ��������? \n";
	cin >> element;
	cout << "� ����� �����? \n";
	cin >> index;
	lst1.insert(element, index);

	cout << "������� �� �����. \n";
	lst2.popBack();
	cout << "������� �� ������. \n";
	lst2.popFront();
	cout << "������� �� ��������. �� ������ �����? \n";
	cin >> index;
	lst2.removeAt(index);

	cout << "list1 : " << lst1 << "\n";
	cout << "list2 : " << lst2 << "\n";
	if (areTheSame(lst1, lst2)) cout << "list1 ���������� ������ list2\n";
	else cout << "list1 �� ���������� ������ list2\n";
}


int main()
{
	setlocale(LC_ALL, "ru");

	testInt();
	testChar();
	testDouble();

}
