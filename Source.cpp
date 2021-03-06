#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class ForwardList
{
	class Element
	{
		int Data;
		Element* pNext;
		static int count;
	public:
		Element(int Data, Element* pNext = nullptr)
		{
			this->Data = Data;
			this->pNext = pNext;
			count++;
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			count--;
			cout << "EDesconstructor:\t" << this << endl;
		}
		friend class ForwardList;
	};

	Element* Head;
	int size;
public:
	ForwardList()
	{
		this->Head = nullptr;
		this->size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}
	//    Methods:
	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Element* New = new Element(Data);
		Temp->pNext = New;
		size++;
	}
	void push_front(int Data)
	{
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
		size++;
	}
	void insert(int Index, int Data)
	{
		if (Index == 0)
		{
			push_front(Data); 
			return;
		}
		if (Index > size)
		{
			cout << "Error: Out of Range" << endl; 
			return;
		}
		//1) ������ �������:
		Element* New = new Element(Data);
		//2) ������� �� ������ ������� � ������:
		Element* Temp = Head;
		for (int i = 0; i < Index-1; i++)
		{
			Temp = Temp->pNext;
		}
		//3) ��������� ����� ������� � ������:
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}
	void pop_front()
	{
		Element* Temp = Head;
		Head = Head->pNext;

		delete Temp;
		size--;

	}

	void pop_back()
	{
		//�������� � ����� ������.
		Element*Temp = Head;
		while (Temp->pNext->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}
	void erase(int index)
	{
		if (index == 0)
		{
			pop_front();
			return;
		}
		if (index > size)
		{
			cout << "Error: Out of Range" << endl;
			return;
		}
		Element* Temp = Head;
		for(int i = 0; i < index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		Element* Buffer = Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;
		delete Buffer;
		size--;

	}

	void print()
	{
		Element* Temp = Head;   //Temp = ��������.
		while (Temp != nullptr)
		{
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
			Temp = Temp->pNext; //������� �� ��������� �������.
		}
		cout << "List size:\t" << size << endl;
	}
};

int ForwardList::Element::count = 0;

void main()
{
	setlocale(LC_ALL, "");

	int n;
	cout << "Input list size: ";
	cin >> n;
	cout << endl;

	ForwardList fl;
	fl.push_back(22);
	fl.print();
	for (size_t i = 0; i < n; i++)
	{
		fl.push_front(rand() % 100);
	}
	fl.push_back(123);
	fl.print();
	fl.pop_front();
	fl.print();
	int index;
	int data;
	/*cout << "Input index: "; cin >> index; cout << endl;
	cout << "Input value: "; cin >> data; cout << endl;
	fl.insert(index, data);*/
	fl.pop_back();
	fl.print();
	cout << "Input index: "; cin >> index; cout << endl;
	fl.erase(index);
	fl.print();
	
}