#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void test1(PSeqList pSeqList)
{
	// 尾插
	PushBack(pSeqList, 1);
	PushBack(pSeqList, 2);
	PushBack(pSeqList, 3);
	PushBack(pSeqList, 4);
	PushBack(pSeqList, 4);
	PushBack(pSeqList, 4);
	PushBack(pSeqList, 4);
	PushBack(pSeqList, 4);
	// 尾删
	//PopBack(pSeqList);
	//PopBack(pSeqList);
	//////移除顺序表中的元素data
	//Remove(pSeqList, 2);
	//Remove(pSeqList, 3);
	//// 打印顺序表
	//PrintSeqList(pSeqList);
	//// 移除顺序表中所有元素data
	RemoveAll(pSeqList, 4);
	PrintSeqList(pSeqList);
}

void test2(PSeqList pSeqList)
{
	//// 头插
	PushFront(pSeqList, 1);
	PushFront(pSeqList, 2);
	PushFront(pSeqList, 3);
	PushFront(pSeqList, 4);
	PushFront(pSeqList, 5);
	//// 头删
	PopFront(pSeqList);
	PopFront(pSeqList);
	PopFront(pSeqList);
	PrintSeqList(pSeqList);
}

void test3(PSeqList pSeqList)
{
	PushFront(pSeqList, 1);
	PushFront(pSeqList, 2);
	PushFront(pSeqList, 3);
	PushFront(pSeqList, 4);
	//// 任意位置插入
	Insert(pSeqList,2,5);
	//// 删除顺序表中pos位置上的元素
	Erase(pSeqList, 2);
	//// 在顺序表中查找元素data
	printf("%d\n",Find(pSeqList, 5));
}

int main()
{
	SeqList seqList;
	InitSeqList(&seqList);
	test1(&seqList);
	//test2(&seqList);
	//test3(&seqList);
	return 0;
}