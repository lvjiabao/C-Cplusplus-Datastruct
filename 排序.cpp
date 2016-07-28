//#include<iostream>
//using namespace std;
//#include<assert.h>
//
////11111归并排序
////归并排序(将已有序的子序列合并，得到完全有序的序列)
////对一个数组的前后俩有序部分合并
//void megearray(int*arr, int start, int mid,int end ,int*combin)
//{
//	int ileft = start;
//	int iright = mid+1;
//	int icombin = 0;
//	while (ileft < mid+1&&iright < end+1)
//	{
//		if (arr[ileft] < arr[iright])
//			combin[icombin++] = arr[ileft++];
//		else
//			combin[icombin++] = arr[iright++];
//	}
//	while (ileft < mid+1)
//		combin[icombin++] = arr[ileft++];
//	while (iright < end+1)
//		combin[icombin++] = arr[iright++];
//	for (int i = 0; i < icombin; i++)
//		arr[start+i] = combin[i];//////注意这一步
//}
//
////把一个大的数组分成小部分排序（递归）
//void megesort(int*arr, int start, int end, int*p)
//{
//	if (start < end)
//	{
//		int mid = start + (end - start) / 2;
//		megesort(arr, start, mid, p);
//		megesort(arr, mid + 1, end, p);
//		megearray(arr,start,mid,end, p);
//	}
//}
//
//void MegeSort(int*arr, int n)
//{
//	assert(arr&&n > 0);
//	int*p = new int[n];
//	int start = 0;
//	int end = n - 1;
//	megesort(arr, start, end, p);
//	delete[]p;
//	p = NULL;
//}
//
////22222冒泡排序
////版本1（有标志位）
//void BubleSort(int*arr, int len)
//{
//	assert(arr&&len > 0);
//	int flag = 0;
//	for (int i = 0; i < len - 1; i++)
//	{
//		flag = 0;
//		for (int j = 0; j < len - i - 1; ++j)
//		{
//			if (arr[j]>arr[j + 1])
//			{
//				swap(arr[j], arr[j + 1]);
//				flag = 1;
//			}
//		}
//		if (0 == flag)
//			break;
//	}
//}
////版本2（改进版，可以只对前十个排序（后面90个已有序））
//void BubbleSort(int*arr, int n)
//{
//	assert(arr&&n > 0);
//	int flag = n;
//	while (flag>0)
//	{
//		int pos = flag;
//		flag = 0;
//		for (int i = 1; i < pos;++i)
//		if (arr[i-1]>arr[i])
//		{
//			swap(arr[i-1], arr[i]);
//			flag = i;
//		}
//	}
//}
//
//
////33333快速排序(模拟实现)
//int Rand(int start, int end)
//{
//	assert(start <= end);
//	int num = 0;
//	while (1)
//	{
//		num = rand() % (end + 1);
//		if (num >= start)
//			return num;
//	}
//	return -1;
//}
//
//int Partion(int*arr, int start,int end,int length)
//{
//	assert(arr&&length > 0&&start>=0&&end>=0&&end>=start);
//	int index = Rand(start,end);
//	swap(arr[index], arr[end]);
//	int small=start-1;
//	for (int i = start; i < end; i++)
//	{
//		if (arr[i] < arr[end])
//		{
//			++small;
//			swap(arr[i], arr[small]);
//		}
//	}
//	swap(arr[++small], arr[end]);
//	return small;
//}
//void Qsort(int*arr, int start,int end,int length)
//{
//	assert(arr&&start >= 0 && end >= 0 && length > 0);
//	int index = Partion(arr, start, end, length);
//	if (index > start)
//		Qsort(arr, start, index - 1, length);
//	if (index < end)
//		Qsort(arr, index + 1, end, length);
//}
//
//
////444444插入排序
////版本1
//void InsertSort(int*arr, int n)
//{
//	assert(arr&&n>0);
//	for (int i = 1; i < n; i++)
//	{
//		int j = i - 1;
//		for ( j = i - 1; j >= 0;--j)
//		if (arr[j] < arr[i])
//			break;
//		int temp = arr[i];
//		int k = 0;
//		if (j != i - 1)
//		{
//			for ( k = i-1; k>j; --k)
//				arr[k + 1] = arr[k];
//		}
//		arr[j+1] = temp;
//	}
//}
//
//
////版本2
//void InsertSort2(int*arr, int n)
//{
//	assert(arr&&n > 0);
//	int i = 0, j = 0;
//	for (i = 1; i < n; i++)
//	{
//		if (arr[i] < arr[i - 1])
//		{
//			int temp = arr[i];
//			for (j = i - 1; j >= 0 && temp<arr[j]; j--)
//				arr[j + 1] = arr[j];
//			arr[j + 1] = temp;
//		}
//	}
//}
//
////版本3
//void InsertSort3(int*arr, int n)
//{
//	assert(arr&&n>0);
//	for (int i = 1; i < n;++i)
//	for (int j = i - 1; j >= 0 && arr[j]>arr[j + 1]; j--)
//		swap(arr[j], arr[j + 1]);
//}
//
////选择排序
//void Swap(int&a, int&b)
//{
//	if (a != b)
//	{
//		a ^= b;
//		b ^= a;
//		a ^= b;
//	}
//}
//
//void ChooseSort(int*arr, int n)
//{
//	assert(arr&&n > 0);
//	for (int i = 0; i < n; i++)
//	{
//		int iMin = i;
//		for (int j = i; j < n;j++)
//		if (arr[j] < arr[iMin])
//			iMin = j;
//		swap(arr[i], arr[iMin]);
//	}
//}
//
//
////11111哈希表查找（O（1）需要借助额外的空间）
////22222二分法查找（O（logn））
//
//
//
//
//void testmegesort()
//{
//	int str[] = { 3, 2, 1, 4 };
//	int *p = new int[4];
//	megearray(str, 0, 1, 3, p);
//	MegeSort(str, 4);
//	for (int i = 0; i < 4; i++)
//		cout << str[i] << " ";
//}
//
//void testbubble()
//{
//	int arr[] = { 3, 5, 63, 2, 567, 87, 2 };
//	BubleSort(arr, 7);
//	for (int i = 0; i < 7; ++i)
//		cout << arr[i] << " ";
//}
//
//void testqsort()
//{
//	int arr[] = { 4,3,2,1 };
//	Qsort(arr, 0, 3, 4);
//	for (int i = 0; i < 4; ++i)
//		cout << arr[i] << " ";
//}
//
//void testinsert()
//{
//	int arr[] = { 4, 3, 2, 1 };
//	InsertSort3(arr, 4);
//	for (int i = 0; i < 4; i++)
//		cout << arr[i] << " ";
//}
//
//void testchoose()
//{
//	int arr[] = { 4, 3, 2, 1 };
//	ChooseSort(arr, 4);
//	for (int i = 0; i < 4; i++)
//		cout << arr[i] << " ";
//}
//
//
