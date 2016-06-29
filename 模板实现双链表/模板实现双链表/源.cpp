#include<iostream>
using namespace std;
template<typename T>
struct Node
{
	Node(T _data) :pnext(NULL), pfront(NULL),data(_data){}
	Node<T>*pnext;
	Node<T>*pfront;
	T data;
};


template<typename T>
class SeqList
{
public:
	SeqList() :phead(NULL), pend(NULL), size(0)
	{}
	~SeqList()
	{
		clear();
	}
	void clear()
	{
		Node<T>*pt = phead;
		while (phead)
		{
			pt = pt->pnext;
			delete phead;
			phead = pt;
		}
		phead = pend = NULL;
	}
	void print();
	void PushBack(const T&_data);
	void PopBack();
	void PushFront(const T&_data);
	void PopFront();
private:
	Node<T>*phead;
	Node<T>*pend;
	size_t size;//????
};



template<typename T>
void SeqList<T>::print()
{
	Node<T>*pt = phead;
	while (pt)
	{
		cout << pt->data << "->";
		pt = pt->pnext;
	}
	cout << "NULL\n";
}

template<typename T>
void SeqList<T>::PushBack(const T&_data)
{
	Node<T>*pt = new Node<T>(_data);
	if (NULL == phead)
	{
		phead = pend = pt;
	}
	else
	{
		pend->pnext = pt;
		pt->pfront = pend;
		pend = pt;
	}
	size++;
}

template<typename T>
void SeqList<T>::PopBack()
{
	if (NULL == phead)
		return;
	else if (phead == pend)
	{
		delete phead;
		phead = NULL;
	}
	else
	{
		pend = pend->pfront;
		delete pend->pnext;
		pend->pnext = NULL;
	}
	size--;
}

template<typename T>
void SeqList<T>::PushFront(const T&_data)
{
	Node<T>*pt = new Node<T>(_data);
	if (NULL == phead)
	{
		phead = pend = pt;
	}
	else
	{
		pt->pnext=phead;
		phead->pfront = pt;
		phead = pt;
	}
	size++;
}
template<typename T>
void SeqList<T>::PopFront()
{
	if (NULL == phead)
		return;
	else if (phead == pend)
	{
		delete phead;
		phead = pend = NULL;
	}
	else
	{
		phead = phead->pnext;
		delete phead->pfront;
		phead->pfront = NULL;
	}
	size--;
}

int main()
{
	SeqList<int> s;
	s.PushBack(1);
	s.PushBack(2);
	s.PushBack(3);
	s.PopBack();
	s.PopBack();
	s.PopBack();
	s.PushFront(3);
	s.PushFront(2);
	s.PushFront(1);
	s.PopFront();
	s.PopFront();
	s.PopFront();
	s.print();
	return 0;
}
