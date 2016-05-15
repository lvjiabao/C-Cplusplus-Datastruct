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
}List,*pList;

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
void insertnotfirstnode(pList pos, Datetype data);//非头节点前，插一个节点，不遍历
Datetype midnode(pList*phead);//求链表中间节点,遍历一次


#endif