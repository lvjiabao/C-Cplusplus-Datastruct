class Item
{
	friend class List;
public:
	Item(int d = 0)
	{
		data = d;
		next = 0;
	}
private:
	int data;
	Item*next;
};
class List
{
public:
	List()
	{
		list = 0;
	}
	List(int d)
	{
		list = new Item(d);
	}
	void print();
	int insert(int d);
	int append(int d);
	void reverse();
	int length();
	void myreverse();
	void mysort();
	void cat(List&il);
	Item* mycat(List&il);
private:
	Item*list;
	Item*end();
};

void List::print()
{
	if (NULL == list)
	{
		cout << "it is full" << endl;
		exit(EXIT_FAILURE);
	}
	Item*pt = list;
	while (pt)
	{
		cout << pt->data << "->";
		pt = pt->next;
	}
	cout << "NULL"<<endl;
}

//ÄæĞò
void List::myreverse()
{
	Item*pt = list,*ptt=list,*hnew=NULL;
	ptt = pt->next;
	while (ptt)
	{
		pt->next = hnew;
		hnew = pt;
		pt = ptt;
		ptt = ptt->next;
	}
	pt->next = hnew;
	hnew = pt;
	list = hnew;
}
//Ç°²å
int List::append(int d)
{
	Item*pt = new Item(d);
	pt->next = list;
	list = pt;
	return d;
}

Item*List::end()
{
	Item*pt, *prv;
	for (pt = prv = list; pt; prv = pt, pt = pt->next)
	{
		;
	}
	return prv;
}
//ºó²å
int List::insert(int d)
{
	Item*pt = new Item(d);
	if (NULL == list)
	{
		list = pt;
	}
	else
	{
		(end())->next = pt;
	}
	return d;
}

void List::cat(List&il)
{
	Item*pt = il.list;
	while (pt)
	{
		insert(pt->data);
		pt = pt->next;
	}
}



int List::length()
{
	int count = 0;
	Item*pt = list;
	while (pt)
	{
		count++;
		pt = pt->next;
	}
	return count;
}

void List::reverse()
{
	Item*pt, *prv, *tmp;
	prv = 0;
	pt = list;
	list = end();
	while (pt != list)
	{
		tmp = pt->next;
		pt->next = prv;
		prv = pt;
		pt = tmp;
	}
	list->next = prv;
}

//ÅÅĞò
void List::mysort()
{
	Item*pt = list;
	Item*pend = NULL;
	int flag = 0;
	int temp = 0;
	while (list->next!=pend)
	{
		pt = list;
		flag = 1;
		while (pt->next != pend)
		{
			if (pt->data > pt->next->data)
			{
				temp = pt->data;
				pt->data = pt->next->data;
				pt->next->data = temp;
				flag = 0;
			}
			pt = pt->next;
		}
		if (flag == 1)
			return;
		pend = pt;
	}
}

Item* List::mycat(List&il)
{
	Item*ptil = il.list;
	Item*pt = list;
	Item*pnext = NULL;
	Item*phead = NULL;
	if (NULL == list)
		return il.list;
	if (NULL == il.list)
		return list;
	if (il.list->data > list->data)
	{
		phead = pt;
		pt = pt->next;
		pnext = phead;
	}
	else
	{
		phead = ptil;
		ptil = ptil->next;
		pnext = phead;
	}
	while (NULL != pt&&NULL != ptil)
	{
		if (ptil->data > pt->data)
		{
			pnext->next= pt;
			pt = pt->next;
			pnext = pnext->next;
		}
		else
		{
			pnext->next = ptil;
			ptil = ptil->next;
			pnext = pnext->next;
		}
	}
	if (NULL == pt)
		pnext->next = ptil;
	if (NULL == ptil)
		pnext->next = pt;
	list = phead;
	return list;
}

int main()
{
	List t5;
	t5.insert(2);
	t5.insert(4);
	t5.insert(6);
	List t6;
	t6.insert(1);
	t6.insert(3);
	t6.insert(5);
	t6.mycat(t5);
	t6.print();
	return 0;
}