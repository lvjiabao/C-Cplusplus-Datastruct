#include<iostream>
using namespace std;

//前N项和
int sum(int n)
{
	if (n > 0)
		return n + sum(n - 1);
	return 0;
}

//二分


//n的阶乘
int fun(int n)
{
	if (n > 1)
		return n*fun(n - 1);
	return 1;
}

//febonaqi
int febonaqi(int n)
{
	return (n<3) ? 1 : febonaqi(n - 1) + febonaqi(n - 2);
}

int febonaqi(int first, int second, int n)
{
	if (n < 3)
		return 1;
	if (n == 3)
		return first+second;
	return febonaqi(second, first + second, n - 1);
}


//链表中寻找节点
//Node*search(Node*phead, int data)
//{
//	if (NULL == phead || phead->data == data)
//		return phead;
//	return search(phead->next, data);
//}

//释放链表的节点
//void Free(Node*&phead)
//{
//	if (NULL != phead)
//	{
//		Free(phead->next);
//		delete phead;
//		phead = NULL;
//	}
//}

//数组逆序打印
void printarr(int*arr, int len)
{
	if (len>0)
	{
		cout << arr[--len] << " ";
		printarr(arr,len);
	}
}


//判断回文
bool IsPr(char*arr ,int size)
{
	char *arrlen = arr + size - 1;
	if (*arrlen != *arr)
		return false;
	if (size>0)
		IsPr(++arr, size - 2);
	return true;
}


int sumfun(int n)
{
	if (n > 0)
		return n+sumfun(n - 1);
	return 0;
}

int addfun(int n)
{
	if (n > 1)
		return n*addfun(n - 1);
	return 1;
}

int feibonaqi(int first,int second,int n)
{
	if (n < 3)
		return 1;
	else if (n == 3)
		return first + second;
	else
		return feibonaqi(second, first + second, n - 1);
}

int binarya(int*arr,int num, int left, int right)
{
	int mid = (left&right) + ((left^right) >> 1);
	if (left > right)
		return -1;
	if (num > arr[mid])
		return binarya(arr, num, mid + 1, right);
	else if (num < arr[mid])
		return binarya(arr, num, left, mid - 1);
	else
		return mid;
}

//void destroy(Node*phead)
//{
//	if (phead != NULL)
//	{
//		destroy(phead->next);
//		delete phead;
//		phead=NULL:
//	}
//}


void reversearr(int*arr, int size)
{
	if (size >= 0)
	{
		cout << arr[--size];
		reversearr(arr, size);
	}
}


//回文
bool ispr(char*arr, int size)
{
	char*right = arr + size - 1;
	if (*arr != *right)
		return false;
	if (size > 0)
	{
		ispr(arr++, size - 2);
	}
	return true;
}


//全排列
void sortall(int *arr,int size,int n)//时间复杂度阶乘
{
	if (n==size)
	{
		for (int i = 0; i < size; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = n; i < size; i++)
		{
			std::swap(arr[i], arr[n]);
			sortall(arr, size, n + 1);
			std::swap(arr[i], arr[n]);//为了保证大循环中进入下一次的序列为原序列
		}
	}
}

void Sortall(char *arr, int size, int n)//时间复杂度阶乘
{
	if (n == size)
	{
		cout << arr<<endl;
		cout << endl;
	}
	else
	{
		for (int i = n; i < size; i++)
		{
			std::swap(arr[i], arr[n]);
			Sortall(arr, size, n + 1);
			std::swap(arr[i], arr[n]);//为了保证大循环中进入下一次的序列为原序列
		}
	}
}

//回溯法
//把地图讯息存到文件中
//地图需要动态传入
//迷宫
//递归实现

#include<stack>
#define MAX_COL 10
#define MAX_ROW 10
struct seat
{
	seat(int _x, int _y) :x(_x), y(_y)
	{}
	int x;
	int y;
};
class maze
{
public:
	maze(int arr[MAX_COL][MAX_ROW])  
	{
		for (int i = 0; i < MAX_COL;i++)
		for (int j = 0; j < MAX_ROW; j++)
		{
			_map[i][j] = arr[i][j];
		}
	}

	void MazeMap();
	bool IsPass(const seat&entry);//检测是否为空
	bool PathMaze(seat entry);
	void PathMaze2(seat entry);
private:
	int _map[MAX_COL][MAX_ROW];

};

void maze::MazeMap()
{
	for (int i = 0; i < MAX_COL; i++)
	{
		for (int j = 0; j < MAX_ROW; j++)
		{
			cout << _map[i][j] << " ";
		}
		cout << endl;
	}
}
bool maze::PathMaze(seat entry)
{
	if (entry.x < 0 || entry.y < 0 || entry.y >= MAX_COL)
	{
		return true;
	}

	if (IsPass(entry))
	{
		_map[entry.x][entry.y] = 2;

		// 超前
		seat newEntry(entry);
		newEntry.x -= 1;
		if (PathMaze(newEntry))
			return true;

		// 超左
		newEntry=entry;
		newEntry.y -= 1;
		if (PathMaze(newEntry))
			return true;
		
		// 超右
		newEntry=entry;
		newEntry.y += 1;
		if (PathMaze(newEntry))
			return true;

		_map[entry.x][entry.y] = 3;

	}
	return false;
}
void maze::PathMaze2(seat entry)
{

	stack<seat>s;
	s.push(entry);
	while (!s.empty())
	{
		_map[entry.x][entry.y] = 2;
		if (entry.x-1 < 0 || entry.y-1 < 0 || entry.y+1 >= MAX_COL)
		{
			return;
		}
		seat newentry = entry;
		newentry.x -= 1;
		if (IsPass(newentry))
		{
			s.push(newentry);
			entry = newentry;
			continue;
		}

		newentry = entry;
		newentry.y -= 1;
		if (IsPass(newentry))
		{
			s.push(newentry);
			entry = newentry;
			continue;
		}

		newentry = entry;
		newentry.y += 1;
		if (IsPass(newentry))
		{
			s.push(newentry);
			entry = newentry;
			continue;
		}
		_map[entry.x][entry.y] = 3;
		s.pop();
		if (s.size()!=0)
			entry = s.top();
	}
}


bool maze::IsPass(const seat&entry)
{
	if (_map[entry.x][entry.y] == 1)
		return true;
	return false;
}

void testmaze()
{
	int arr[10][10] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0, 1, 1, 0, 0 },
		{ 0, 0, 1, 1, 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 } };
	maze maze1(arr);
	seat entry(9, 6);
	maze1.MazeMap();
	maze1.PathMaze2(entry);
	cout << endl;
	maze1.MazeMap();

	cout << endl;
}

int main()
{
	/*cout << sum(100);
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	cout << binarya(arr, 10, 0, 9) << endl;
	cout << fun(5) << endl;
	cout << febonaqi(8) << endl;
	cout << febonaqi(1, 1, 8) << endl;
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	printarr(a, 10);
	cout << endl;
	char*arr1 = "1234321";
	cout << IsPr(arr1, 7);*/
	//char arr[4] = "abc";
	//Sortall(arr, 3, 0);
	//
	testmaze();
	return 0;
}
