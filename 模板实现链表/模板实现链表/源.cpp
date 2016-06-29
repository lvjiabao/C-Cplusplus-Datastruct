#include<iostream>
using namespace std;

class Node
{
	friend class SeqList;
public:
	Node(int _data=0) :next(NULL)
	{
		data = _data;
	}
private:
	Node*next;
	int data;
};

class SeqList
{
public:
	SeqList() :phead(NULL), pend(NULL){}
	~SeqList()
	{
		Node*pt = phead;
		while (pt)
		{
			pt = pt->next;
			delete phead;
			phead = pt;
		}
	}

	void print();
	void PushBack(int _data);
	void PopBack();
	void PushFront(int _data);
	void PopFront();
	void insert(int _data, const Node*pos);
	Node*searchpos(int _data);
	void deleteanypos(const Node*pos);
	void deletedata(int _data);
	void deletealldata(int _data);
private:
	void CheckList();
private:
	Node*phead;
	Node*pend;
};

void SeqList::print()
{
	Node*pt = phead;
	while (pt)
	{
		cout << pt->data << "->";
		pt = pt->next;
	}
	cout << "NULL\n";
}
void SeqList::PushBack(int _data)
{
	Node*pt = new Node(_data);
	if (phead == NULL)
		phead = pend = pt;
	else
	{
		pend->next = pt;
		pend = pt;
	}
}

void SeqList::PopBack()
{
	if (phead == NULL)
		return;
	else if (phead->next == NULL)
	{
		delete phead;
		phead = pend = NULL;
	}
	else
	{
		Node*pt = phead;
		while (pt->next->next)
		{
			pt = pt->next;
		}
		delete pt->next;
		pt->next = NULL;
		pend = pt;
	}
}

void SeqList::PushFront(int _data)
{
	Node*pt = new Node(_data);
	if (NULL == phead)
	{
		phead = pend = pt;
	}
	else
	{
		pt->next = phead;
		phead = pt;
	}
}

void SeqList::PopFront()
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
		Node*pt = phead->next;
		delete phead;
		phead = pt;
	}
}

Node*SeqList::searchpos(int _data)
{
	Node*pt = phead;
	while (pt)
	{
		if (pt->data == _data)
			return pt;
		pt = pt->next;
	}
	return NULL;
}

void SeqList::insert(int _data, const Node*pos)
{
	Node*pt = phead;
	while (pt)
	{
		if (pt == pos)
		{
			Node*node = new Node(_data);//找到地址再开辟，否则不好收场
			node->next = pt->next;
			pt->next = node;
			if (pt == pend)//确定尾节点（尾插的情况下）
				pend = node;
		}
		pt = pt->next;
	}
}

void SeqList::deleteanypos(const Node*pos)
{
	Node*pt = phead;
	while (pt)
	{
		if (pt == pos)
		{
			if (pt == phead)
				PopFront();
			else if (pt == pend)
				PopBack();
			else
			{
				Node*pnextnode = pt->next;
				if (pnextnode == pend)//如果没有，pend不变，会引起崩溃
					pend = pt;
				pt->data = pt->next->data;
				pt->next = pnextnode->next;
				delete pnextnode;
				pnextnode = NULL;
			}
			return;
		}
		pt = pt->next;
	}
}

void SeqList::deletedata(int _data)
{
	deleteanypos(searchpos(_data));
}

void SeqList::deletealldata(int _data)
{
	while (searchpos(_data))
	{
		deleteanypos(searchpos(_data));
	}
}



void test()
{
	SeqList f;
	f.PushBack(1);
	f.PushBack(2);
	f.PushBack(3);
	f.PopBack();
	f.PopBack();
	f.PopBack();
	f.print();
}

void test1()
{
	SeqList f1;
	f1.PushFront(1);
	f1.PushFront(2);
	f1.PushFront(3);
	f1.PushFront(4);
	f1.PopFront();
	f1.PopFront();
	f1.PopFront();
	f1.PopFront();
	f1.print();
}

void test2()
{
	SeqList f2;
	f2.PushBack(2);
	f2.PushBack(2);
	f2.PushBack(2);
	//f2.insert(0, f2.searchpos(4));
	//f2.deleteanypos(f2.searchpos(4));
	//f2.deletedata(8);
	f2.deletealldata(2);
	f2.print();
}
int main()
{
	//test();
	//test1();
	test2();
	return 0;
}