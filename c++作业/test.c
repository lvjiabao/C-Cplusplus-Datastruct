#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

// 初始化顺序表
void InitSeqList(PSeqList pSeqList)
{
	assert(pSeqList);
	pSeqList->size = 0;
	memset(pSeqList->array, 0, sizeof(int)*MAX_SIZE);
}

// 顺序表尾插
// 设计函数原型
// 参数检测
// 边界条件考虑
// 逻辑操作

// 尾插
void PushBack(PSeqList pSeqList, DataType data)
{
	assert(pSeqList);
	if (pSeqList->size >= MAX_SIZE)
	{
		printf("列表已满，无法插入\n");
		exit(EXIT_FAILURE);
	}
	pSeqList->array[pSeqList->size] = data;
	pSeqList->size++;
}
// 尾删
void PopBack(PSeqList pSeqList)
{
	assert(pSeqList);
	if (pSeqList->size == 0)
	{
		printf("列表已空，无法删除\n");
		exit(EXIT_FAILURE);
	}
	pSeqList->array[pSeqList->size - 1] = 0;
	pSeqList->size--;
}

// 打印顺序表
void PrintSeqList(PSeqList pSeqList)
{
	assert(pSeqList);
	int i = 0;
	if (pSeqList->size == 0)
	{
		printf("列表为空\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < (int)pSeqList->size; ++i)
		printf("%d ", pSeqList->array[i]);
	printf("\n");
}

// 头插
void PushFront(PSeqList pSeqList, DataType data)
{
	assert(pSeqList);
	int i = 0;
	if (pSeqList->size >= MAX_SIZE)
	{
		printf("列表已满，无法插入\n");
		exit(EXIT_FAILURE);
	}
	for (i = pSeqList->size - 1; i >= 0; i--)
		pSeqList->array[i + 1] = pSeqList->array[i];
	pSeqList->array[0] = data;
	pSeqList->size++;
}

// 头删
void PopFront(PSeqList pSeqList)
{
	assert(pSeqList);
	int i = 0;
	if (pSeqList->size == 0)
	{
		printf("列表为空，无法删除\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < (int)pSeqList->size - 1; i++)
		pSeqList->array[i] = pSeqList->array[i + 1];
	pSeqList->size--;
}

// 任意位置插入
void Insert(PSeqList pSeqList, int pos, DataType data)
{
	assert(pSeqList);
	int i = 0;
	if (pos > (int)pSeqList->size || pos < 0)
	{
		printf("插入非法\n");
		exit(EXIT_FAILURE);
	}
	for (i = pSeqList->size - 1; i >= pos; i--)
		pSeqList->array[i + 1] = pSeqList->array[i];
	pSeqList->array[pos] = data;
	pSeqList->size++;
}

// 在顺序表中查找元素data
int Find(PSeqList pSeqList, DataType data)
{
	assert(pSeqList);
	int i = 0;
	for (i = 0; i < (int)pSeqList->size; i++)
	if (data == pSeqList->array[i])
		return i;
	return -1;
}

// 删除顺序表中pos位置上的元素
void Erase(PSeqList pSeqList, int pos)
{
	assert(pSeqList);
	int i = 0;
	if (pos < 0 || pos >= (int)pSeqList->size)
	{
		printf("删除非法\n");
		exit(EXIT_FAILURE);
	}
	for (i = pos; i < (int)pSeqList->size - 1; i++)
		pSeqList->array[i] = pSeqList->array[i + 1];
	pSeqList->size--;
}

//移除顺序表中的元素data
void Remove(PSeqList pSeqList, DataType data)
{
	if (Find(pSeqList, data)>0)
		Erase(pSeqList, Find(pSeqList, data));
}

// 移除顺序表中所有元素data
void RemoveAll(PSeqList pSeqList, DataType data)
{
	assert(pSeqList);
	int i = 0;
	int temp = 0;
	for (i = 0; i < (int)pSeqList->size; i++)
	{
		if (pSeqList->array[i] == data)
		{
			Erase(pSeqList, i);
			i--;
		}
	}
}





