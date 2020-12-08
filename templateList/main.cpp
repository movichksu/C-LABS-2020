#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


template<typename Type>
class List
{

private:
	// Узел - элемент списка
	template<typename Type>
	struct Node
	{
	public:
		Type data; // данные
		Node* Next; // указатель на след элемент
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
	void popFront();// удалить первый элемент
	void popBack(); // удалить последний элемент
	void pushFront(Type); // вставить в начало 
	void pushBack(Type); // вставить в конец
	void insert(Type data, int index); //добавление элемента в список по указанному индексу
	void removeAt(int index); //удаление элемента в списке по указанному индексу
	void clearList();//очистить список

	  // not working????
	//friend void readFromFile(List<Type>&, string);
	//friend void writeToFile(List<Type>&, string);
	//void Show(); // отображение списка.
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
		Node<Type>* tmp = this->head; //в переменную tmp добавляем указатель на head
		while ((tmp->Next) != nullptr) // смотрим на что указывает поле tmp
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
	//содержится ли list1 в list2 
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
	cout << "\n\n-------- ТЕСТ ДЛЯ ТИПА INT ---------\n";
	string way;
	int element;
	int index;
	List<int> lst1;
	List<int> lst2;
	cout << "Введите путь к файлу для list1. \n";
	cin >> way;
	readFromFile(lst1, way);
	cout << "Введите путь к файлу для list2. \n";
	cin >> way;
	readFromFile(lst2, way);
	cout << "list1 : " << lst1 << "\n";
	cout << "list2 : " << lst2 << "\n";
	if (areTheSame(lst1, lst2)) cout << "list1 содержится внутри list2\n";
	else cout << "list1 не содержится внутри list2\n";

	cout << "что вставить в конец? \n";
	cin >> element;
	lst1.pushBack(element);
	cout << "что вставить в начало? \n";
	cin >> element;
	lst1.pushFront(element);
	cout << "что вставить в середину? \n";
	cin >> element;
	cout << "в какое место? \n";
	cin >> index;
	lst1.insert(element, index);

	cout << "удалить из конца. \n";
	lst2.popBack();
	cout << "удалить из начала. \n";
	lst2.popFront();
	cout << "удалить из середины. из какого места? \n";
	cin >> index;
	lst2.removeAt(index);
	 
	cout << "list1 : " << lst1 << "\n";
	cout << "list2 : " << lst2 << "\n";
	if (areTheSame(lst1, lst2)) cout << "list1 содержится внутри list2\n";
	else cout << "list1 не содержится внутри list2\n";
}

void testChar()
{
	cout << "\n\n-------- ТЕСТ ДЛЯ ТИПА CHAR ---------\n";
	string way;
	char element;
	int index;
	List<char> lst1;
	List<char> lst2;
	cout << "Введите путь к файлу для list1. \n";
	cin >> way;
	readFromFile(lst1, way);
	cout << "Введите путь к файлу для list2. \n";
	cin >> way;
	readFromFile(lst2, way);
	cout << "list1 : " << lst1 << "\n";
	cout << "list2 : " << lst2 << "\n";
	if (areTheSame(lst1, lst2)) cout << "list1 содержится внутри list2\n";
	else cout << "list1 не содержится внутри list2\n";

	cout << "что вставить в конец? \n";
	cin >> element;
	lst1.pushBack(element);
	cout << "что вставить в начало? \n";
	cin >> element;
	lst1.pushFront(element);
	cout << "что вставить в середину? \n";
	cin >> element;
	cout << "в какое место? \n";
	cin >> index;
	lst1.insert(element, index);

	cout << "удалить из конца. \n";
	lst2.popBack();
	cout << "удалить из начала. \n";
	lst2.popFront();
	cout << "удалить из середины. из какого места? \n";
	cin >> index;
	lst2.removeAt(index);

	cout << "list1 : " << lst1 << "\n";
	cout << "list2 : " << lst2 << "\n";
	if (areTheSame(lst1, lst2)) cout << "list1 содержится внутри list2\n";
	else cout << "list1 не содержится внутри list2\n";
}


void testDouble()
{
	cout << "\n\n-------- ТЕСТ ДЛЯ ТИПА DOUBLE ---------\n";
	string way;
	double element;
	int index;
	List<double> lst1;
	List<double> lst2;
	cout << "Введите путь к файлу для list1. \n";
	cin >> way;
	readFromFile(lst1, way);
	cout << "Введите путь к файлу для list2. \n";
	cin >> way;
	readFromFile(lst2, way);
	cout << "list1 : " << lst1 << "\n";
	cout << "list2 : " << lst2 << "\n";
	if (areTheSame(lst1, lst2)) cout << "list1 содержится внутри list2\n";
	else cout << "list1 не содержится внутри list2\n";

	cout << "что вставить в конец? \n";
	cin >> element;
	lst1.pushBack(element);
	cout << "что вставить в начало? \n";
	cin >> element;
	lst1.pushFront(element);
	cout << "что вставить в середину? \n";
	cin >> element;
	cout << "в какое место? \n";
	cin >> index;
	lst1.insert(element, index);

	cout << "удалить из конца. \n";
	lst2.popBack();
	cout << "удалить из начала. \n";
	lst2.popFront();
	cout << "удалить из середины. из какого места? \n";
	cin >> index;
	lst2.removeAt(index);

	cout << "list1 : " << lst1 << "\n";
	cout << "list2 : " << lst2 << "\n";
	if (areTheSame(lst1, lst2)) cout << "list1 содержится внутри list2\n";
	else cout << "list1 не содержится внутри list2\n";
}


int main()
{
	setlocale(LC_ALL, "ru");

	testInt();
	testChar();
	testDouble();

}
