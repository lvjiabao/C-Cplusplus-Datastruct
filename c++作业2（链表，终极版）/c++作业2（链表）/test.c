#include "List.h"


void init_list(pList*phead)
{
	assert(phead);//是否这里检测了，下面就可以不用检测了
	*phead = NULL;
}

pList openarea()////
{
	/*assert(phead);*/////
	pList pt = NULL;
	pt = (pList)malloc(sizeof(List));
	if (NULL == pt)
	{
		printf("开辟空间失败\n");
		exit(EXIT_FAILURE);
	}
	pt->data = 0;
	pt->next = NULL;
	return pt;
}

//输出链表
//参数为pList类型，如果为pList*就是对实际的pHead操作，pHead会后移，如果要两次输出，就不能完整地输出了
void print_list(pList phead)
{
	pList pt = NULL;
	//assert(phead);//这里并不需要加，因为有空链表的情况
	if (NULL == phead)
	{
		printf("空链表\n");
		return;
	}
	pt = phead;
	while (pt)
	{
		printf("%d->", pt->data);
		pt = pt->next;
	}
	printf("NULL\n");
}
//后插
void Pushback(pList*phead,Datetype data)
{
	pList pt = NULL;
	assert(phead);
	pt = openarea();
	pList pphead = *phead;//无需pList*，否则创建临时变量无意义，变成对pHead的操作
	if (NULL == *phead)
	{
		*phead = pt;
		(*phead)->data = data;
		(*phead)->next = NULL;
	}
	else
	{
		while (pphead->next)
		{
			pphead = pphead->next;
		}
		pphead->next = pt;
		pt->data = data;
		pt->next = NULL;
	}
}

//后删
void popback(pList*phead)
{
	pList pt = NULL;
	assert(phead);
	if (NULL == *phead)
	{
		printf("列表为空\n");
		exit(EXIT_FAILURE);
	}
	else if (NULL == (*phead)->next)
	{
		free(*phead);
		*phead = NULL;
	}
	else
	{
		pt = *phead;
		while (pt->next->next)
		{
			pt = pt->next;
		}
		free(pt->next);
		pt->next = NULL;
	}
}

//前插
void pushfront(pList*phead,Datetype data)
{
	pList pt = NULL;
	assert(phead);
	pt = openarea();
	if (NULL == *phead)
	{
		*phead = pt;
		pt->next = NULL;
		pt->data = data;
	}
	else
	{
		pt->next = *phead;
		*phead = pt;
		pt->data = data;
	}
}


//前删
void popfront(pList*phead)
{
	pList pt = NULL;
	assert(phead);
	if (NULL == *phead)
	{
		printf("链表为空\n");
		exit(EXIT_FAILURE);
	}
	pt = *phead;
	(*phead) = (*phead)->next;
	free(pt);
	pt = NULL;
}

//查找
pList search(pList*phead, Datetype data)
{
	pList pt = NULL;
	assert(phead);
	if (NULL == *phead)
	{
		printf("链表为空\n");
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

//任意位置插入
void insert(pList*phead,pList pos,Datetype data)
{
	/*pList pt = NULL;*/
	pList pphead = NULL;
	assert(phead);
	//首先运行查找函数，如果没找到，pos就是NULL。
	if (NULL == pos)
	{
		printf("插入不合法\n");
		exit(EXIT_FAILURE);
	}
	//pt = search(phead, pos->data);//如果找到了pos就=pt,无需再算一遍
		pphead = (pList)malloc(sizeof(List));
		pphead->data = data;
		pphead->next = pos->next;
		pos->next = pphead;
}

//任意位置删除元素
void deletepos(pList*phead, pList pos)
{
	pList pt = NULL;
	pList pphead = NULL;
	assert(phead);
	/*if (NULL == *phead)         //search 中有
	{
	printf("链表为空\n");
	exit(EXIT_FAILURE);
	}*/
	if (NULL == pos)
	{
		printf("删除不合法\n");
		exit(EXIT_FAILURE);
	}
	//pt = search(phead, pos->data);//与上面同理
	pphead = *phead;
	if (pos == *phead)//注意考虑要删的节点是第一个
		popfront(phead);
	else
	{
		while (/*NULL != pphead->next&&*/pphead->next != pos)
		{
			pphead = pphead->next;
		}
		//其实也没有必要判断，因为pos肯定在，while的跳出也一定是因为到了pos位置
		/*if (pphead->next == pos)*/
			pphead->next = pos->next;
			free(pos);
			pt = NULL;
	}
}

//删除数据为data的节点
//也可以通过上面search的方法找到位置，但是麻烦因为还要重新找一下data前面的位置
void deletedata(pList*phead, Datetype data)
{
	//方法1
	deletepos(phead, search(phead, data));
	//方法2
	//pList pt = NULL;
	//pList ptt = NULL;
	//assert(phead);
	//if (NULL == *phead)
	//{
	//	printf("列表为空\n");
	//	exit(EXIT_FAILURE);
	//}
	//pt = *phead;
	//if (pt->data == data)
	//{
	//	popfront(phead);
	//}
	//else
	//{
	//	while (NULL != pt->next&&pt->next->data != data)
	//	{
	//		pt = pt->next;
	//	}
	//	if (pt->next == NULL)//找不到该节点
	//	{
	//		printf("没有该节点\n");
	//	}
	//	else //找到该节点
	//	{
	//		ptt = pt->next;
	//		pt->next = pt->next->next;
	//		free(ptt);
	//		ptt = NULL;
	//	}
	//}
}


//删除所有数据为data的节点
void deletealldata(pList*phead, Datetype data)
{
	while (search(phead, data))
	{
		deletedata(phead, data);
	}
}

//逆序打印
void Printbth(pList phead)
{
	if (phead == NULL)
	{
		return;
	}
	else
	{
		Printbth(phead->next);
		printf("%d->", phead->data);
	}
}



//删除非尾节点，不能遍历
void deletenotendnode(pList pos)
{
	pList pt = NULL;
	if (NULL == pos || NULL == pos->next)
		return;
	pos->data = pos->next->data;
	pt = pos->next;
	pos->next = pos->next->next;
	free(pt);
	pt = NULL;
}

void insertnotfirstnode(pList pos,Datetype data)///////////
{
	pList pt = NULL;
	pList pnew = NULL;
	if (NULL == pos)
		return;
	pnew = openarea();
	
	int temp=0;
	pnew->next = pos->next;
	pos->next = pnew;
	temp = pos->data;
	pos->data = data;
	pnew->data = temp;
}

//求中间的节点，只需遍历一次（需要知道返回俩中节点中的哪个）
Datetype midnode(pList*phead)
{
	pList p1 = NULL,p2=NULL;
	assert(phead);
	p1 = p2 = *phead;
	while (p2!=NULL&&p2->next!=NULL)
	{
		p1 = p1->next;
		p2 = p2->next->next;
	}
	return p1->data;
}

//找最后一个节点
pList getend(pList*phead)
{
	pList pt = NULL;
	pList pend = NULL;
	assert(phead);
	pt = *phead;
	for (; pt; pend = pt, pt = pt->next)
		;
	return pend;
}
//逆置链表  自己写的
//void reverselist(pList*phead)
//{
//	pList pt = NULL,prv=NULL,tmp=NULL;
//	assert(phead);
//	pt = *phead;
//	*phead = getend(phead);
//	while (pt != *phead)
//	{
//		tmp = pt->next;
//		pt->next = prv;
//		prv = pt;
//		pt = tmp;
//	}
//	(*phead)->next = prv;
//}

//逆置链表    三个指针逐步后移
//void reverselist(pList*phead)
//{
//	pList pfro = *phead;
//	pList pcur = NULL;
//	pList pnext = NULL;
//	if (pfro == NULL || pfro->next == NULL)
//		return;
//	pcur= pfro->next;
//	pnext= pcur->next;
//	pfro->next = NULL;
//	while (pnext)
//	{
//		pcur->next = pfro;
//		pfro = pcur;
//		pcur = pnext;
//		pnext = pnext->next;
//	}
//	pcur->next = pfro;
//	*phead = pcur;
//}

//翻转链表   头插
void reverselist(pList*phead)
{
	pList pt = NULL, ptt = NULL, pnewh = NULL;
	assert(phead);
	
	pt = *phead;
	ptt = pt->next;
	if (NULL == pt || NULL == pt->next)
		return;
	while (ptt)
	{
		pt->next = pnewh;
		pnewh = pt;
		pt = ptt;
		ptt = ptt->next;
	}
	pt->next = pnewh;
	pnewh = pt;
	*phead = pnewh;
}

//节点个数
int nodecount(pList*phead)
{
	pList pt = *phead;
	int count = 0;
	while (pt)
	{
		pt=pt->next;
		count++;
	}
	return count;
}


//链表排序   冒泡(自己写的)
//void sortlistbuble(pList*phead)
//{
//	pList pt = *phead,ptt=*phead,tmp=*phead;
//	int temp = 0;
//	int count = 0;
//	int ccount = 0;
//	count=nodecount(phead) - 1;
//	for (; pt->next; pt = pt->next,count--)
//	{
//		ptt = *phead;
//		ccount = count;
//		for (;(ccount--)!=0;ptt=ptt->next)
//		if (ptt->data > ptt->next->data)
//		{
//			temp = ptt->data;
//			ptt->data = ptt->next->data;
//			ptt->next->data = temp;
//		}
//	}
//}


void  sortlistbuble(pList*phead)
{
	pList pt = NULL;
	pList pend = NULL;
	int temp = 0;
	int flag = 0;
	if (NULL == *phead || NULL == (*phead)->next)
		return;
	pt = *phead;
	while ((*phead)->next != pend)
	{
		pt = *phead;
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

//合并链表  自己写的
//void cat(pList*phead, pList*_phead)
//{
//	pList pt = getend(phead);
//	pt->next = *_phead;
//}

pList cat(pList*phead1, pList*phead2)
{
	pList pnext=NULL,ph1 = NULL, ph2 = NULL, ph3 = NULL;
	assert(phead1&&phead2);
	ph1 = *phead1;
	ph2 = *phead2;
	if (ph1 == NULL)
		return ph2;
	if (ph2 == NULL)
		return ph1;
	if (ph1->data > ph2->data)
	{
		ph3 = ph2;
		pnext = ph3;
		ph2 = ph2->next;
	}
	else
	{
		ph3 = ph1;
		pnext = ph3;
		ph1 = ph1->next;
	}
	while (ph1 != NULL&&ph2 != NULL)
	{
		if (ph1->data > ph2->data)
		{
			pnext->next = ph2;
			pnext = pnext->next;
			ph2 = ph2->next;
		}
		else
		{
			pnext->next = ph1;
			pnext = pnext->next;
			ph1 = ph1->next;
		}
	}
	if (ph1 == NULL)
		pnext->next = ph2;
	if (ph2 == NULL)
		pnext->next = ph1;
	return ph3;
}

//释放内存，防止内存泄漏
void freememory(pList*phead)
{
	assert(phead);
	pList pt = *phead,ptt=NULL;
	while (pt)
	{
		ptt = pt;
		free(ptt);
		pt = pt->next;
	}
}

//查找单链表的倒数第k个节点，要求只能遍历一次链表
pList search_last_k_node(pList phead,int k)
{
	pList pf = NULL, ps = NULL;
	int count = 0;
	if (phead == NULL || k <= 0)
		return NULL;
	ps = phead;
	pf = phead;
	while (pf)
	{
		pf = pf->next;
		count++;
		if (count > k)
			ps = ps->next;
	}
	if (count < k)
		return NULL;
	else
		return ps;
}


//删除第k个节点
void deleteendk(pList *phead, int k)
{
	pList pf = NULL, ps = NULL, pt = NULL;
	int count = 0,t = 0;
	assert(phead);
	pf = *phead;
	ps = *phead;
	t = k + 1;
	if (*phead == NULL || t < 2)
		return;
	while (pf)
	{
		pf = pf->next;
		count++;
		if (count>t)
			ps = ps->next;
	}
	if (count == t - 1)
	{
		*phead = ps->next;
		free(ps);
		ps = NULL;
	}
	else if (count >= t)
	{
		pt = ps->next;
		ps->next = pt->next;
		free(pt);
		pt = NULL;
	}
	else
		return;
}

 //约瑟夫环
pList JosephCircle(pList phead, int k)
{
	pList pt = NULL,pnext=NULL;
	int count = 0;
	if (phead == NULL || k < 1)
		return NULL;
	pt = phead;        
	while (pt->next != pt)
	{
		count = k;
		while (--count)
		{
			pt = pt->next;
		}
		pnext = pt->next;//后删，代替删除当前的节点
		pt->next = pnext->next;
		pt->data = pnext->data;
	}
	return pt;
}

//求俩已排序单链表中相同的数据(输出数据即可)
void UnionSet(pList*phead, pList*_phead)
{
	pList pt = *phead, _pt = *_phead;
	if (NULL == pt || NULL == _pt)
		return;
	while (pt!=NULL&&_pt!=NULL)
	{
		if (pt->data > _pt->data)
			_pt = _pt->next;
		else if (pt->data < _pt->data)
			pt = pt->next;
		else
		{
			printf("%d ", pt->data);
			//跳过值相同点，防止下一跳为空(下一跳为空的话就是非法访问了)
			while (pt->next!=NULL&&pt->data == pt->next->data)
				pt = pt->next;
			while (_pt->next!=NULL&&_pt->data == _pt->next->data)
				_pt = _pt->next;
			pt = pt->next;
			_pt = _pt->next;
		}
	}
}

//俩单向链表是否相交
int  searchcrash(pList phead1, pList phead2)
{
	pList ph1 = NULL, ph2 = NULL;
	assert(phead1&&phead2);
	ph1 = phead1;
	ph2 = phead2;
	if (ph1 == NULL || ph2 == NULL)
		return -1;
	while (ph1->next)
	{
		ph1 = ph1->next;
	}
	while (ph2->next)
	{
		ph2 = ph2->next;
	}
	if (ph1 == ph2)
		return 1;
	return -1;
}


//相交单链表的交点
pList meetnode(pList phead1, pList phead2)
{
	int countleft = 0, countright = 0, count = 0;
	pList pleft = NULL, pright = NULL;
	if (searchcrash(phead1, phead2) <= 0)
		return NULL;
	pleft = phead1;
	pright = phead2;
	while (pleft)
	{
		countleft++;
		pleft = pleft->next;
	}
	while (pright)
	{
		countright++;
		pright = pright->next;
	}
	count = countleft - countright;
	pleft = phead1;
	pright = phead2;
	if (count>0)
	while (count--)
		pleft = pleft->next;
	if (count<0)
	while (count++)
		pright = pright->next;
	while (pleft)
	{
		pleft = pleft->next;
		pright = pright->next;
		if (pleft == pright)
			return pleft;
	}
	return NULL;
}

//判断单链表是否有圆环
pList judgecircle(pList phead)
{
	pList pf = NULL;
	pList ps = NULL;
	if (NULL == phead)
		return NULL;
	pf = phead;
	ps = phead;
	while (pf != NULL&&pf->next != NULL)
	{
		pf = pf->next->next;
		ps = ps->next;
		if (pf == ps)
			return pf;
	}
	return NULL;
}

//寻找环的焦点
pList searchmeetnode(pList phead)
{
	pList pt = NULL;
	pList pstart = NULL,pmid=NULL;
	if (NULL == judgecircle(phead))
		return NULL;
	pt = judgecircle(phead);
	pmid = pt;
	pstart = phead;
	while (pstart != pmid)
	{
		pstart = pstart->next;
		pmid = pmid->next;
	}
	return pmid;
}


//逆置倒数k个节点
void reverseendk(pList*phead, int k)
{
	int nodecount = 0,t = 0;
	pList ph = NULL;
	pList pt = NULL;
	assert(phead);
	if (*phead == NULL || k < 2)
		return;
	ph = *phead;
	pt = *phead;
	while (pt)
	{
		pt = pt->next;
		nodecount++;
	}
	t =  nodecount-k;
	if (t <= 0)
		reverselist(phead);
	else
	{
		while (--t)
			ph = ph->next;
		reverselist(&(ph->next));////注意点
	}
}

//
//int hascrosswithcircle(pList phead1, pList phead2)
//{
//	pList pmeetnode1 = NULL;
//	pList pmeetnode2 = NULL;
//	pList pnodeend1 = NULL;
//	pList pnodeend2 = NULL;
//	if (NULL == phead1 || NULL == phead2)
//		return 0;
//	pmeetnode1 = judgecircle(phead1);
//	pmeetnode2 = judgecircle(phead2);
//    //俩都不带环
//	if (pmeetnode1 != NULL&&pmeetnode2 != NULL)
//	{
//		pnodeend1 = phead1;
//		pnodeend2 = phead2;
//		while (pnodeend1->next)
//		{
//			pnodeend1=pnodeend1->next;
//		}
//		while (pnodeend2->next)
//		{
//			pnodeend2 = pnodeend2->next;
//		}
//		if (pnodeend1 == pnodeend2)
//			return 1;
//	}
//	//俩都带环
//
//
//}