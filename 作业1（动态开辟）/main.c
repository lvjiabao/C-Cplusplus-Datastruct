#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//冒泡
//选择
//二分
int main()
{
	int data = 0;
	int input = 1;
	int pos = 0;
	SeqList seqList;
	InitSeqList(&seqList);
	while (input)
	{
		menu();
		printf("please input your choice:\n");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			printf("please input data:");
			scanf("%d",&data);
			// 尾插
			PushBack(&seqList, data);
			break;
		case 2:
			// 尾删
			PopBack(&seqList);
			break;
		case 3:
			// 头插
			printf("please input data:");
			scanf("%d", &data);
			PushFront(&seqList,data);
			break;
		case 4:
			// 头删
			PopFront(&seqList);
			break;
		case 5:
			//移除顺序表中的元素data
			printf("please input data:");
			scanf("%d",&data);
			Remove(&seqList,data);
		    break;
		case 6:
			// 打印顺序表
			PrintSeqList(&seqList);
			break;
		case 7:
			// 移除顺序表中所有元素data
			printf("please input data:");
			scanf("%d",&data);
			RemoveAll(&seqList,data);
			break;
		case 8:
			// 删除顺序表中pos位置上的元素
			printf("please input pos:");
			scanf("%d",&pos);
			Erase(&seqList,pos);
			break;
		case 9:
			// 任意位置插入
			printf("please input pos:");
			scanf("%d", &pos);
			printf("please input data:");
			scanf("%d", &data);
			Insert(&seqList,pos,data);
			break;
		case 10:
			// 在顺序表中查找元素data
			printf("please input data:");
			scanf("%d", &data);
			if (Find(&seqList, data) >= 0)
				printf("is in\n");
			else
				printf("not in\n");
			break;
		case 11:
			bubble_sort(&seqList);
			break;
		default:
			break;
		}
	}
	return 0;
}