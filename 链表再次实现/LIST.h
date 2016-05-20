#ifndef __LIST_H__
#define __LISTH__

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int Datetype;
typedef struct LIST
{
	Datetype data;
	struct LIST*next;
}List, *pList;

void init_list(pList*head);//初始化
void Pushback(pList*phead, Datetype data);//后插
void print_list(pList phead);//打印
void popback(pList*phead);//后删
void pushfront(pList*phead, Datetype data);//前插
void popfront(pList*phead);//前删
pList search(pList*phead, Datetype data);//查找数据为data的节点的地址
void insert(pList*phead, pList pos, Datetype data);//任意位置插入
void deletepos(pList*phead, pList pos);//任意位置删除元素
void deletedata(pList*phead, Datetype data);//删除数据为data的节点
void deletealldata(pList*phead, Datetype data);//删除所有数据为data的节点
void Printbth(pList phead);//逆序打印
void deletenotendnode(pList pos);//删除非尾节点，不许遍历
void insertnotfirstnode(pList phead,pList pos, Datetype data);//非头节点前，插一个节点，不遍历
Datetype midnode(pList*phead);//求链表中间节点,遍历一次
void reverselist(pList*phead);//逆置链表
pList cat(pList*phead, pList*_phead);//合并链表
void freememory(pList*phead);//释放内存
pList search_last_k_node(pList phead, int k);//查找单链表的倒数第k个节点，要求只能遍历一次链表
void sortlistbuble(pList*phead);//冒泡排序
int nodecount(pList*phead);//算节点个数
void UnionSet(pList*phead, pList*_phead);//俩排序好的单链表中是否有相同的数据
int  searchcrash(pList phead1, pList phead2);//俩单向链表是否相交
pList meetnode(pList phead1, pList phead2);//相交单链表的焦点
pList judgecircle(pList phead);//判断单链表是否源环
pList searchmeetnode(pList phead);//寻找单链表环的焦点
pList JosephCircle(pList phead, int k);//约瑟夫环
void deleteendk(pList *phead, int k);//删除第k个节点
void reverseendk(pList*phead, int k);//逆置倒数k个节点



#endif