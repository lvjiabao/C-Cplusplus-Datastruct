#include "List.h"

void test1()
{
	//后
	/*Pushback(&pHead, 1);
	Pushback(&pHead, 2);
	popback(&pHead);
	popback(&pHead);
	print_list(pHead);*/

	//前
	/*pushfront(&pHead, 1);
	pushfront(&pHead, 2);
	popfront(&pHead);
	popfront(&pHead);
	popfront(&pHead);
	print_list(pHead);*/

	//任意插
	/*Pushback(&pHead, 1);
	Pushback(&pHead, 2);
	Pushback(&pHead, 3);
	Pushback(&pHead, 4);
	insert(&pHead, search(&pHead, 3), 5);
	print_list(pHead);*/

	//任意位置删
	/*Pushback(&pHead, 1);
	Pushback(&pHead, 2);
	Pushback(&pHead, 3);
	Pushback(&pHead, 4);
	deletepos(&pHead, search(&pHead, 4));
	print_list(pHead);*/

	//删数据为data的
	//Pushback(&pHead, 1);
	//Pushback(&pHead, 2);
	//Pushback(&pHead, 3);
	//Pushback(&pHead, 4);
	//deletedata(&pHead, 5);
	//print_list(pHead);

	//删除所有数据为data的
	/*Pushback(&pHead, 3);
	Pushback(&pHead, 1);
	Pushback(&pHead, 3);
	Pushback(&pHead, 3);
	Pushback(&pHead, 2);
	Pushback(&pHead, 3);
	Pushback(&pHead, 4);
	deletealldata(&pHead, 3);
	print_list(pHead);*/

	//倒输出
	/*Pushback(&pHead, 1);
	Pushback(&pHead, 2);
	Pushback(&pHead, 3);
	Pushback(&pHead, 4);
	Printbth(pHead);*/

	//删除非尾节点，不许遍历
	//Pushback(&pHead, 1);
	//Pushback(&pHead, 2);
	//Pushback(&pHead, 3);
	//Pushback(&pHead, 4);
	//deletenotendnode(search(&pHead, 0));
	//print_list(pHead);

	//非头节点前，插一个节点，不遍历
	//Pushback(&pHead, 1);
	//Pushback(&pHead, 2);
	//Pushback(&pHead, 3);
	//Pushback(&pHead, 4);
	//insertnotfirstnode(pHead, search(&pHead, 3), 11);
	//print_list(pHead);

	////求链表中间节点,遍历一次
	//Pushback(&pHead, 1);
	//Pushback(&pHead, 2);
	//Pushback(&pHead, 3);
	//Pushback(&pHead, 4);
	//printf("%d",midnode(&pHead));

	//逆置链表
	//Pushback(&pHead, 1);
	//Pushback(&pHead, 2);
	//Pushback(&pHead, 3);
	//Pushback(&pHead, 4);
	//reverselist(&pHead);
	//print_list(pHead);
	//合并链表
	//Pushback(&pHead, 1);
	//Pushback(&pHead, 3);
	//Pushback(&pHead, 5);
	//Pushback(&pHead, 7);
	//Pushback(&_pHead, 2);
	//Pushback(&_pHead, 4);
	//Pushback(&_pHead, 6);
	//Pushback(&_pHead, 8);
	//cat(&pHead, &_pHead);
	//print_list(pHead);

	//找倒数第k个节点
	//Pushback(&pHead, 1);
	//Pushback(&pHead, 2);
	//Pushback(&pHead, 3);
	//Pushback(&pHead, 4);
	//Pushback(&pHead, 5);
	//printf("%d\n",search_last_k_node(pHead, 1)->data);
}

int main()
{
	pList pHead;
	init_list(&pHead);
	pList _pHead;
	init_list(&_pHead);
	
	//冒泡
	//Pushback(&pHead, 1);
	//Pushback(&pHead, 5);
	//Pushback(&pHead, 7);
	//Pushback(&pHead, 2);
	//Pushback(&pHead, 4);
	//sortlistbuble(&pHead);
	//print_list(pHead);

	//俩排序好的单链表中所有相同的数据
	//Pushback(&pHead, 1);
	//Pushback(&pHead, 3);
	//Pushback(&pHead, 5);
	//Pushback(&pHead, 5);
	//Pushback(&pHead, 5);
	//Pushback(&pHead, 7);
	//Pushback(&_pHead, 1);
	//Pushback(&_pHead, 4);
	//Pushback(&_pHead, 5);
	//Pushback(&_pHead, 7);
	//Pushback(&_pHead, 7);
	//Pushback(&_pHead, 7);
	//UnionSet(&pHead, &_pHead);

	//俩单链表的无环焦点
	//pList p1 = NULL, p2 = NULL;
	//Pushback(&pHead, 1);
	//Pushback(&pHead, 3);
	//Pushback(&pHead, 5);
	//Pushback(&_pHead, 1);
	//Pushback(&_pHead, 4);
	//Pushback(&_pHead, 5);
	//Pushback(&_pHead, 7);
	//p1 = search(&pHead, 5);
	//p2 = search(&_pHead, 4);
	//p1->next = p2;
	//printf("%d ",meetnode(pHead, _pHead)->data);

	//单链表有环结点
	/*pList p1 = NULL, p2 = NULL;
	Pushback(&pHead, 1);
	Pushback(&pHead, 2);
	Pushback(&pHead, 3);
	Pushback(&pHead, 4);
	Pushback(&pHead, 5);
	p1 = search(&pHead, 5);
	p2 = search(&pHead, 3);
	p1->next = p2;
	printf("%d",searchmeetnode(pHead)->data);*/

	//约瑟夫环
	/*pList p1 = NULL, p2 = NULL;
	Pushback(&pHead, 1);
	Pushback(&pHead, 2);
	Pushback(&pHead, 3);
	Pushback(&pHead, 4);
	Pushback(&pHead, 5);
	p1 = search(&pHead, 5);
	p2 = search(&pHead, 1);
	p1->next = p2;
	printf("%d",JosephCircle(pHead, 3)->data);*/


	//删除倒数第k个节点
	//Pushback(&pHead, 1);
	//Pushback(&pHead, 2);
	//Pushback(&pHead, 3);
	//Pushback(&pHead, 4);
	//Pushback(&pHead, 5);
	//deleteendk(&pHead, 0);
	//print_list(pHead);

	//逆序倒数k个节点
	Pushback(&pHead, 1);
	Pushback(&pHead, 2);
	Pushback(&pHead, 3);
	Pushback(&pHead, 4);
	Pushback(&pHead, 5);
	reverseendk(&pHead, 3);
	print_list(pHead);
	return 0;
}