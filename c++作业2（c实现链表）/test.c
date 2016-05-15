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

