#include "List.h"

void init_list(pList*phead)//初始化
{
	assert(phead);
	*phead = NULL;
}

pList openarea(Datetype data)
{
	pList pt = (pList)malloc(sizeof(List));
	if (NULL == pt)
	{
		printf("failure\n");
		exit(EXIT_FAILURE);
	}
	pt->data = data;
	pt->next = NULL;
	return pt;
}
void Pushback(pList*phead, Datetype data)//后插
{
	pList pt = NULL,pend=NULL;
	assert(phead);
	pt = openarea(data);
	pend = *phead;
	if (NULL == *phead)
	{
		*phead = pt;
	}
	else
	{
		while (pend->next)
		{
			pend = pend->next;
		}
		pend->next = pt;
	}
}
void print_list(pList phead)//打印
{
	pList pt = NULL;
	if (NULL == phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pt = phead;
	while (pt)
	{
		printf("%d->", pt->data);
		pt = pt->next;
	}
	printf("NULL\n");
}
void popback(pList*phead)//后删
{
	pList pt = NULL, pend = NULL;
	assert(phead);
	pt = *phead;
	if (NULL == *phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	else if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	else
	{
		while (pt->next->next)
		{
			pt = pt->next;
		}
		pend = pt->next;
		pt->next = NULL;
		free(pend);
		pend = NULL;
	}
}
void pushfront(pList*phead, Datetype data)//前插
{
	pList pt = NULL;
	assert(phead);
	pt = openarea(data);
	pt->next = *phead;
	*phead = pt;
}
void popfront(pList*phead)//前删
{
	pList pt = NULL;
	assert(phead);
	pt = *phead;
	if (NULL == pt)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	*phead = pt->next;
	free(pt);
	pt = NULL;
}
pList search(pList*phead, Datetype data)//查找数据为data的节点的地址
{
	pList pt = NULL;
	assert(phead);
	if (NULL == *phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pt = *phead;
	while (pt)
	{
		if (pt->data == data)
			return pt;
		pt = pt->next;
	}
	return NULL;
}

void insert(pList*phead, pList pos, Datetype data)//任意位置插入(后插)0位置没插
{
	pList pinsert=NULL;
	assert(phead);
	if (NULL == *phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pinsert = openarea(data);
	if (NULL == pos)
	{
		printf("failure\n");
		exit(EXIT_FAILURE);
	}
	pinsert->next = pos->next;
	pos->next=pinsert;
}
void deletepos(pList*phead, pList pos)//任意位置删除元素
{
	pList pt = NULL;
	assert(phead);
	pt = *phead;
	if (NULL == *phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	if (NULL == pos)
	{
		printf("failure\n");
		exit(EXIT_FAILURE);
	}
	else if (pos == *phead)
	{
		*phead = pos->next;
		free(pos);
		pos = NULL;
	}
	else
	{
		while (pt->next != pos)
		{
			pt = pt->next;
		}
		pt->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
void deletedata(pList*phead, Datetype data)//删除数据为data的节点
{
	pList pt = NULL;
	assert(phead);
	if (NULL == *phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pt = search(phead, data);
	deletepos(phead, pt);
}
void deletealldata(pList*phead, Datetype data)//删除所有数据为data的节点
{
	pList pos = NULL;
	assert(phead);
	if (NULL == *phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	while (pos = search(phead, data))
		deletepos(phead, pos);
}
void Printbth(pList phead)//逆序打印
{
	if (phead)
	{
		Printbth(phead->next);
		printf("%d->", phead->data);
	}
	else
		return;//exit会把整个程序结束掉，而return会一步步返回去
}

void deletenotendnode(pList pos)//删除非尾节点，不许遍历
{
	pList pt = NULL;
	if (NULL == pos)
	{
		printf("failure\n");
		exit(EXIT_FAILURE);
	}
	pt = pos->next;
	pos->data=pos->next->data;
	pos->next = pos->next->next;
	free(pt);
	pt = NULL;
}
void insertnotfirstnode(pList phead,pList pos, Datetype data)//非头节点前，插一个节点，不遍历
{
	pList pinsert = NULL;
	int temp = 0;
	if (pos == NULL || pos == phead)
	{
		printf("failure\n");
		exit(EXIT_FAILURE);
	}
	pinsert = openarea(data);
	pinsert->next=pos->next;
	pos->next = pinsert;
	temp = pos->data;
	pos->data = data;
	pos->next->data = temp;
}
Datetype midnode(pList*phead)//求链表中间节点,遍历一次
{
	pList pf = NULL, ps = NULL;
	assert(phead);
	if (NULL == *phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pf = *phead;
	ps = *phead;
	while (NULL != pf&&NULL != pf->next)
	{
		ps = ps->next;
		pf = pf->next->next;
	}
	return ps->data;
}

void reverselist(pList*phead)//逆置链表
{
	pList pcur = NULL,pnext=NULL,pnewhead=NULL;
	assert(phead);
	if (NULL==*phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pcur = *phead;
	pnext = pcur->next;
	while (pnext)
	{
		pcur->next = pnewhead;
		pnewhead = pcur;
		pcur = pnext;
		pnext = pnext->next;
	}
	pcur->next = pnewhead;
	pnewhead = pcur;
	*phead = pnewhead;
}
pList cat(pList*phead, pList*_phead)//合并链表
{
	pList pnewhead = NULL,ph=NULL,_ph=NULL,pnext=NULL;
	assert(phead);
	assert(_phead);
	if (NULL == *phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	if (NULL == *_phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	ph = *phead;
	_ph = *_phead;
	if (NULL == *phead)
		return *_phead;
	if (NULL == *_phead)
		return *phead;
	if (ph->data > _ph->data)
	{
		pnewhead = _ph;
		pnext = pnewhead;
		_ph = _ph->next;
	}
	else
	{
		pnewhead = ph;
		pnext = pnewhead;
		ph = ph->next;
	}
	while (NULL != ph&&NULL != _ph)
	{
		if (ph->data > _ph->data)
		{
			pnext->next = _ph;
			pnext = pnext->next;
			_ph = _ph->next;
		}
		else
		{
			pnext->next = ph;
			pnext = pnext->next;
			ph = ph->next;
		}
	}
	if (NULL == ph)
	{
		pnext->next = _ph;
	}
	if (NULL == _ph)
	{
		pnext->next = ph;
	}
	*phead = pnewhead;
	return *phead;
}
void freememory(pList*phead)//释放内存
{
	pList pt = NULL,ptnext=NULL;
	assert(phead);
	if (NULL == *phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pt=ptnext = *phead;
	while (ptnext)
	{
		ptnext = pt->next;
		free(pt);
		pt = ptnext;
	}
}

pList search_last_k_node(pList phead, int k)//查找单链表的倒数第k个节点，要求只能遍历一次链表
{
	pList pf = NULL, ps = NULL;
	int count = 0;
	if (NULL == phead||k < 1)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pf = ps = phead;
	while (pf)
	{
		pf = pf->next;
		count++;
		if (count > k)
		{
			ps = ps->next;
		}
	}
	if (count >= k)
		return ps;
	else
		return NULL;
}
void sortlistbuble(pList*phead)//冒泡排序
{
	pList pend = NULL,pt=NULL;
	int temp = 0,flag=0;
	assert(phead);
	if (NULL == phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pt = *phead;
	while ((*phead)->next != pend)
	{
		flag = 1;
		pt = *phead;
		while (pt->next!= pend)
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
		pend = pt;
		if (flag == 1)
			return;
	}
}
int nodecount(pList*phead)//算节点个数
{
	int count = 0;
	pList pt = NULL;
	assert(phead);
	pt = *phead;
	while (pt)
	{
		count++;
		pt = pt->next;
	}
	return count;
}
void UnionSet(pList*phead, pList*_phead)//俩排序好的单链表中所有相同的数据
{
	pList ph = NULL, _ph = NULL;
	assert(phead);
	assert(_phead);
	if (NULL == *phead || NULL == *_phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	ph = *phead;
	_ph = *_phead;
	while (NULL != ph&&NULL != _ph)
	{
		if (ph->data > _ph->data)
		{
			_ph = _ph->next;
		}
		else if (ph->data < _ph->data)
		{
			ph = ph->next;
		}
		else
		{
			printf("%d ", ph->data);
			while (ph->next!=NULL&&ph->next->data == ph->data)
				ph = ph->next;
			while (_ph->next != NULL&&_ph->next->data == _ph->data)
				_ph = _ph->next;
			_ph = _ph->next;
			ph = ph->next;
		}
	}
}
int  searchcrash(pList phead1, pList phead2)//俩单向链表是否相交
{
	pList p1 = NULL, p2 = NULL;
	if (NULL == phead1 || NULL == phead2)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	p1 = phead1;
	p2 = phead2;
	while (p1->next)
	{
		p1 = p1->next;
	}
	while (p2->next)
	{
		p2 = p2->next;
	}
	if (p1 == p2)
		return 1;
	return -1;
}
pList meetnode(pList phead1, pList phead2)//相交单链表的焦点
{
	int count1 = 0, count2 = 0, count = 0;
	pList p1 = NULL, p2 = NULL;
	if (searchcrash(phead1, phead2) < 0)
	{
		printf("failure\n");
		exit(EXIT_FAILURE);
	}
	count1 = nodecount(&phead1);
	count2 = nodecount(&phead2);
	count = count1 - count2;
	p1 = phead1;
	p2 = phead2;
	if (count>0)
	{
		while (count--)
			p1 = p1->next;
	}
	else if (count < 0)
	{
		while (count++)
			p2 = p2->next;
	}
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}
pList judgecircle(pList phead)//判断单链表是否源环
{
	pList pf = NULL, ps = NULL;
	if (NULL == phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pf = phead;
	ps = phead;
	while (pf != NULL&&pf->next != NULL)
	{
		
		pf = pf->next->next;
		ps = ps->next;
		if (ps == pf)//上面判断不了放在里面判断
			return pf;
	}
	return NULL;
}
pList searchmeetnode(pList phead)//寻找单链表环的焦点
{
	pList pstart = NULL, pmid = NULL;
	if (NULL == judgecircle(phead))
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pmid = judgecircle(phead);
	pstart = phead;
	while (pstart != pmid)
	{
		pstart = pstart->next;
		pmid = pmid->next;
	}
	return pmid;
}
pList JosephCircle(pList phead, int k)//约瑟夫环
{
	int count = 0;
	pList pt = NULL;
	if (NULL == phead||k < 1)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pt = phead;
	while (pt->next != pt)
	{
		count = k;
		while (--count)
		{
			pt = pt->next;
		}
		deletenotendnode(pt);
	}
	return pt;
}
void deleteendk(pList *phead, int k)//删除倒数第k个节点
{
	pList pf = NULL, ps = NULL,pdel=NULL;
	int count = 0, t = 0;
	assert(phead);
	t = k + 1;
	if (NULL == *phead || t < 2)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pf = ps = *phead;
	while (pf)
	{
		pf = pf->next;
		count++;
		if (count > t)
		{
			ps = ps->next;
		}
	}
	if (count == t - 1)
	{
		*phead= ps->next;
		free(ps);
	}
	else if (count >= t)
	{
		pdel = ps->next;
		ps->next = pdel->next;
		free(pdel);
		pdel = NULL;
	}
	else
		return;
}
void reverseendk(pList*phead, int k)//逆置倒数k个节点
{
	int count = 0, poscount = 0;
	pList pt = NULL;
	assert(phead);
	if (NULL == *phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pt = *phead;
	count = nodecount(phead);
	poscount = count - k;
	while (--poscount)
	{
		pt = pt->next;
	}
	reverselist(&(pt->next));//为了连接俩段
}
