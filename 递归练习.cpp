#include<iostream>
using namespace std;

//ǰN���
int sum(int n)
{
	if (n > 0)
		return n + sum(n - 1);
	return 0;
}

//����


//n�Ľ׳�
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


//������Ѱ�ҽڵ�
//Node*search(Node*phead, int data)
//{
//	if (NULL == phead || phead->data == data)
//		return phead;
//	return search(phead->next, data);
//}

//�ͷ�����Ľڵ�
//void Free(Node*&phead)
//{
//	if (NULL != phead)
//	{
//		Free(phead->next);
//		delete phead;
//		phead = NULL;
//	}
//}

//���������ӡ
void printarr(int*arr, int len)
{
	if (len>0)
	{
		cout << arr[--len] << " ";
		printarr(arr,len);
	}
}


//�жϻ���
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


//����
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


//ȫ����
void sortall(int *arr,int size,int n)//ʱ�临�ӶȽ׳�
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
			std::swap(arr[i], arr[n]);//Ϊ�˱�֤��ѭ���н�����һ�ε�����Ϊԭ����
		}
	}
}

void Sortall(char *arr, int size, int n)//ʱ�临�ӶȽ׳�
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
			std::swap(arr[i], arr[n]);//Ϊ�˱�֤��ѭ���н�����һ�ε�����Ϊԭ����
		}
	}
}

//���ݷ�
//�ѵ�ͼѶϢ�浽�ļ���
//��ͼ��Ҫ��̬����
//�Թ�
//�ݹ�ʵ��

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
	bool IsPass(const seat&entry);//����Ƿ�Ϊ��
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

		// ��ǰ
		seat newEntry(entry);
		newEntry.x -= 1;
		if (PathMaze(newEntry))
			return true;

		// ����
		newEntry=entry;
		newEntry.y -= 1;
		if (PathMaze(newEntry))
			return true;
		
		// ����
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
