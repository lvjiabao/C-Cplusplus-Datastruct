#include<iostream>
using namespace std;

#include<assert.h>
//替换空格
void ReplaceSpace(char*arr, int length)
{
	assert(arr&&length > 0);
	int newlen = length;
	char*ptmp = arr;
	while (*ptmp)
	{
		if (' ' == *ptmp)
			newlen+=2;
		ptmp++;
	}
	int end=length - 1;
	int newend = newlen - 1;
	while (end != newend)
	{
		if (arr[end] == ' ')
		{
			arr[newend--] = '0';
			arr[newend--] = '2';
			arr[newend--] = '%';
		}
		else
			arr[newend--] = arr[end];
		end--;
	}
}

//选择排序
void InsertSort(int*arr, int len)
{
	assert(arr&&len > 0);
	for (int i = 0; i < len; i++)
	{
		int iMin = i;
		for (int j = i; j < len;j++)
		if (arr[j] < arr[iMin])
			iMin = j;
		swap(arr[i], arr[iMin]);
	}
}

//俩栈实现队列
#include<stack>
template<typename T>
class Queue
{
public:
	Queue()
	{}
	void Push(const T&data)
	{
		s1.push(data);
	}
	void Pop()
	{
		if (s2.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		if (s2.empty())
			throw new expection("queue is null");
		s2.pop();
	}
private:
	stack<T>s1;
	stack<T>s2;
};

//求旋转有序数组的最小值
int Minpos(int*arr, int len)
{
	assert(arr&&len > 1);
	int left = 0;
	int right = len - 1;
	int mid = left;
	while (arr[left] >= arr[right])
	{
		if (right - left == 1)
		{
			mid = right;
			break;
		}
		mid = left + (right - left) / 2;
		//如果arr[left]==arr[right]==arr[mid]则顺序查找
		if (arr[mid] >= arr[left])
			left = mid;
		else if (arr[mid] <= arr[right])
			right = mid;
	}
	return arr[mid];
}

//模拟实现pow
bool IsInvaild = true;
bool Equal(double num1, double num2)
{
	if (num1 - num2 <= 0.0000001&&num1 - num2 >= -0.0000001)
		return true;
	return false;
}
double PowNum(double base, unsigned int Exception)
{
	if (Exception == 1)
		return base;
	if (Exception == 0)
		return 1;
	double result = PowNum(base, Exception >> 1);
	result *= result;
	if ((Exception & 0x1) == 1)
		result *= base;
	return result;
}
double Pow(double base, int expection)
{
	if (Equal(base,0.0) && expection < 0)
	{
		IsInvaild = false;
		return 0;
	}
	unsigned int Expection = (unsigned int)expection;
	if (expection < 0)
		Expection = -1 * expection;
	double ret = PowNum(base, Expection);
	if (expection>0)
		return ret;
	else
		return 1.0 / ret;
}

//完成1到n位最大值的输出

bool Increase(char*p)
{
	bool isover = false;
	int len = strlen(p);
	int step = 1;
	for (int i = len - 1; i >= 0; i--)
	{
		p[i] += step;
		if (p[i] > '9')
		{
			p[i] -= 10;
			step = 1;
			if (i == 0)
				isover = true;
		}
		else
		{
			step = 0;
			return isover;
		}
	}
	return isover;
}

void PrintNum(char*p)
{
	bool flag = false;
	while (*p)
	{
		if (*p!='0')
			break;
		p++;
	}
	cout << p << " ";
}

void Print(int n)
{
	if (n < 1)
		return;
	char*p = new char[n + 1];
	memset(p, '0', n*sizeof(char));
	p[n] = '\0';
	while (!Increase(p))
	{
		PrintNum(p);
	}
	delete[]p;
}

//解法二，递归实现


void Fun(char*p, int n, int index)
{
	if (index == n - 1)
	{
		PrintNum(p);
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		p[index+1] = i+'0';
		Fun(p, n, index+1);
	}
}

void Print2(int n)
{
	if (n < 1)
		return;
	char*p = new char[n + 1];
	memset(p, '0', n*sizeof(char));
	p[n] = '\0';
	for (int i = 0; i < 10; i++)
	{
		p[0] = i+'0';
		Fun(p, n, 0);
	}
	delete[]p;
}

//使数组中的奇数在前偶数在后(为了适用各种情况，可将判断作为函数指针传入)
void ReorderOddEven(int*arr, int len)
{
	assert(arr&&len > 0);
	int start = 0;
	int end = len - 1;
	while (start < end)
	{
		while (start < end && (arr[start] & 0x1) == 1)
			start++;
		while (start < end && (arr[start] & 0x1) == 0)
			end--;
		if (start < end)
			swap(arr[start], arr[end]);
	}
}

//判断子树
template<typename T>
struct BinaryNode
{
	BinaryNode(const T&value)
	:m_value(value)
	, m_left(NULL)
	, m_right(NULL)
	{}
	T m_value;
	BinaryNode<T>*m_left;
	BinaryNode<T>*m_right;
};
template<typename T>
bool DoesAHasBTree(BinaryNode<T>*node1, BinaryNode<T>*node2)
{
	if (node1 == NULL)
		return false;
	if (node2 == NULL)
		return true;
	if (node1->m_value != node2->m_value)
		return false;
	return DoesAHasBTree(node1->m_left, node2->m_left) && DoesAHasBTree(node1->m_right, node2->m_right);
}

template<typename T>
bool DoesHas(BinaryNode<T>*node1, BinaryNode<T>*node2)
{
	bool result = false;
	if (NULL != node1 || NULL != node2)
	{
		if (node1->m_value == node2->m_value)
			result = DoesAHasBTree(node1, node2);
		if (!result)
			result = DoesHas(node1->m_left, node2);
		if (!result)
			result = DoesHas(node1->m_right, node2);
	}
	return result;
}

//顺时针打印矩阵
void PrintMatrix(int**arr, int x, int y, int start)
{
	int endx = x - start - 1;
	int endy = y - start - 1;
	for (int i = start; i <= endx; i++)
		cout << arr[start][i] << " ";
	for (int i = start + 1; i <= endy; i++)
		cout << arr[i][endx]<<" ";
	if (endy>start)
	for (int i = endx - 1; i >= start; i--)
		cout << arr[endy][i] << " ";
	if (endx>start)
	for (int i = endy - 1; i > start; i--)
		cout << arr[i][start] << " ";
}

void Print(int**arr, int x, int y)
{
	if (NULL == arr || x < 1 || y < 1)
		return;
	int start = 0;
	while (x>2 * start&&y>2 * start)
	{
		PrintMatrix(arr, x, y, start);
		start++;
	}
}


//栈的压入和弹出序列
bool IsOrder(const int*Push, const int*Pop, size_t len)
{
	assert(Push&&Pop&&len > 0);
	const int*nextpush = Push;
	const int*nextpop = Pop;
	stack<int>s;
	bool ret = false;
	while (nextpop - Pop < len)
	{
		while (s.size() == 0 || *nextpop != s.top())
		{
			if (nextpush - Push == len)
				break;
			s.push(*nextpush);
			nextpush++;
		}
		if (*nextpop != s.top())
			break;
		s.pop();
		nextpop++;
	}
	if (s.empty() && nextpop - Pop == len)
		ret = true;
	return ret;
}


//判断数组序列是否满足搜索二叉树的后续遍历
bool IsBackOrder(int *arr, int len)
{
	if (arr == NULL || len < 1)
		return false;
	int root = arr[len - 1];
	int i = 0;
	for (; i < len - 1;i++)
	if (arr[i]>root)
		break;
	int j = i;
	for (; j < len - 1;j++)
	if (arr[j] < root)
		return false;
	bool left = true, right = true;
	if (i>0)
		left = IsBackOrder(arr, i);
	if (j < len - 1)
		right = IsBackOrder(arr + i, len - i - 1);
	return (left&&right);
}


//打印和为给定数的路径
void Printstack(stack<int>s)
{
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}

template<typename T>
void PrintNum(BinaryNode<T>*root, int num, int&curnum, stack<int>s)
{
	s.push(root->m_value);
	curnum += root->m_value;
	if (curnum == num&&root->m_left == NULL&&root->m_right == NULL)
		Printstack(s);
	if (curnum < num&&root->m_left)
		PrintNum(root->m_left, num, curnum, s);
	if (curnum < num&&root->m_right)
		PrintNum(root->m_right, num, curnum, s);
	curnum -= s.top();
	s.pop();
}

template<typename T>
void PrintPath(BinaryNode<T>*root, int num)
{
	if (NULL == root)
		return;
	int curnum = 0;
	stack<int>s;
	PrintNum(root, num, curnum, s);
}

//复杂链表的复制
template<typename T>
struct ListNode
{
	ListNode(const T&value)
	:m_value(value)
	, m_next(NULL)
	, m_sb(NULL)
	{}
	T m_value;
	ListNode<T>*m_next;
	ListNode<T>*m_sb;
};
template<typename T>
void CreatComplexListNext(ListNode<T>*&root)
{
	if (NULL == root)
		return;
	ListNode<T>*pnode = root;
	while (pnode)
	{
		ListNode<T>*clone = new ListNode<T>(pnode->m_value);
		clone->m_next = pnode->m_next;
		pnode->m_next = clone;
		pnode = clone->m_next;
	}
}

template<typename T>
void CreatComplexListSb(ListNode<T>*&root)
{
	if (NULL == root)
		return;
	ListNode<T>*pnode = root;
	while (pnode)
	{
		ListNode<T>*pclone = pnode->m_next;
		if (pclone)
			pclone->m_sb = pnode->m_sb->m_next;
		pnode = pnode->m_next->m_next;
	}
}

template<typename T>
ListNode<T>*Detach(ListNode<T>*&root)
{
	if (NULL == root)
		return;
	ListNode<T>*pnode = root;
	ListNode<T>*pt = pnode->m_next;
	ListNode<T>*temp = pt;
	if (pnode)
	{
		pnode->m_next = pt->m_next;
		pnode = pnode->m_next;
	}
	while (pnode)
	{
		temp->m_next = pnode->m_next;
		temp = temp->m_next;
		pnode->m_next = temp->m_next;
		pnode = pnode->m_next;
	}
	return pt;
}

//搜索二叉树转化为双向链表
template<typename T>
void ConvertList(BinaryNode<T>*pnode, BinaryNode<T>*&plastnode)
{
	if (NULL == pnode)
		return;
	BinaryNode<T>*pcur = pnode;
	if (pcur->m_left)
		ConvertList(pnode->m_left, plastnode);
	pcur->m_left = plastnode;
	if (plastnode)
		plastnode->m_right = pcur;
	plastnode = pcur;
	if (pcur->m_right)
		ConvertList(pcur->m_right, plastnode);
}

template<typename T>
BinaryNode<T>*Convert(BinaryNode<T>*root)
{
	BinaryNode<T>*plastnode = NULL;
	ConvertList(root, plastnode);
	BinaryNode<T>*pheadnode = plastnode;
	while (pheadnode->m_left)
		pheadnode = pheadnode->m_left;
	return pheadnode;
}

//字符串的全排列
void SortAll(char*arr, char*begin)
{
	if (NULL == arr)
		return;
	if (*begin == '\0')
		cout << arr << endl;
	for (char*pt = begin; *pt != '\0'; pt++)
	{
		swap(*pt, *begin);
		SortAll(arr, 1+begin);
		swap(*pt, *begin);
	}
}

//数组中出现次数超过一半长度的数
bool CheakIsMoreHalf(int*arr, int num, int len)
{
	int count = 0;
	for (int i = 0; i<len; i++)
	{
		if (arr[i] == num)
			count++;
		if (count>(len >> 1))
			return true;
	}
	return false;
}

//方法1
int MoreHalfLen(int*arr, int len)
{
	assert(arr&&len > 0);
	int result = 0;
	int count = 0;
	int prenum = 0;
	for (int i = 0; i < len; i++)
	{
		if (count == 0)
		{
			result = arr[i];
			count = 1;
		}
		else
		{
			if (prenum == arr[i])
				count++;
			else
				count--;
		}
		prenum = arr[i];
	}
	if (CheakIsMoreHalf(arr, result, len))
		return result;
	return 0;
}
//方法2

int Rand(int start, int end)
{
	assert(start <= end);
	int num = 0;
	while (1)
	{
		num = rand() % (end + 1);
		if (num >= start)
			return num;
	}
	return -1;
}

int Partion(int*arr, int len, int start, int end)
{
	assert(end >= start);
	int index = Rand(start, end);
	swap(arr[end], arr[index]);
	int small = start - 1;
	for (int i = start; i<end + 1; ++i)
	{
		if (arr[i] > arr[end])
		{
			small++;
			if (i != small)
				swap(arr[i], arr[small]);
		}
	}
	small++;
	swap(arr[small], arr[end]);
	return small;
}

int MoreHalf(int*arr, int len)
{
	assert(arr&&len > 0);
	int start = 0;
	int end = len - 1;
	int index = Partion(arr, len, 0, len - 1);
	int mid = (len - 1) >> 1;
	while (index != mid)
	{
		if (index > mid)
		{
			end = index-1;
			index = Partion(arr, len, start, end);
		}
		if (index < mid)
		{
			start = index+1;
			index = Partion(arr, len, start, end);
		}
	}
	if (CheakIsMoreHalf(arr, arr[mid], len))
		return arr[mid];
	return 0;
}

//求最小的k个数(适合处理海量的数据)
#include<set>
#include<vector>
#include<functional>
typedef multiset<int,greater<int> > IntSet;
typedef multiset<int>::iterator IntSetitor;
void LeastKNum(vector<int>&v, IntSet&LeastNum, int k)
{
	assert(k > 0);
	LeastNum.clear();
	vector<int>::iterator itor = v.begin();
	for (; itor != v.end(); ++itor)
	{
		if (LeastNum.size() < k)
			LeastNum.insert(*itor);
		else
		{
			IntSetitor Greatest = LeastNum.begin();
			if (*itor<*Greatest)
			{
				LeastNum.erase(*Greatest);
				LeastNum.insert(*itor);
			}
		}
	}
}

//求连续子数组的最大和
int SumOfLastArr(int*arr, int len)
{
	assert(arr&&len > 0);
	int curnum = 0;
	int GreatNum = 0x80000000;
	for (int i = 0; i < len; i++)
	{
		if (curnum <= 0)
			curnum = arr[i];
		else
			curnum += arr[i];
		if (curnum>GreatNum)
			GreatNum = curnum;
	}
	return GreatNum;
}


//把数组排成最大的数
#include<stdio.h>
const int g_MaxNumLen = 10;
char* g_Combinleft =new char [2 * g_MaxNumLen + 1];
char* g_Combinright = new char[2 * g_MaxNumLen + 1];

int compare(const void*elem1, const void*elem2)
{
	strcpy(g_Combinleft, *(char**)elem1);
	strcat(g_Combinleft, *(char**)elem2);
	strcpy(g_Combinright, *(char**)elem2);
	strcat(g_Combinright, *(char**)elem1);
	return strcmp(g_Combinleft, g_Combinright);

}
void PrintMInNum(int*arr, int len)
{
	assert(arr&&len > 0);
	char**strnums =(char**)(new int[len]);
	for (int i = 0; i < len; ++i)
	{
		strnums[i] = new char[g_MaxNumLen + 1];
		sprintf(strnums[i], "%d", arr[i]);
	}
	qsort(strnums, len, sizeof(char*), compare);
	for (int i = 0; i < len; i++)
		cout << strnums[i];
	for (int i = 0; i < len; i++)
		delete[]strnums[i];
	delete[]strnums;
}

//丑数
int Min(int num1, int num2, int num3)
{
	int num = num1>num2 ? num2 : num1;
	return num > num3 ? num3 : num;
}

int Ugly(int index)
{
	assert(index > 0);
	int*uglynum = new int[index];
	uglynum[0] = 1;
	int indexugly = 1;
	int*uglynum2 = uglynum;
	int*uglynum3 = uglynum;
	int*uglynum5 = uglynum;
	while (index > indexugly)
	{
		uglynum[indexugly] = Min(*uglynum2 * 2, *uglynum3 * 3, *uglynum5 * 5);
		while (*uglynum2 < uglynum[indexugly])
			++uglynum2;
		while (*uglynum3 < uglynum[indexugly])
			++uglynum3;
		while (*uglynum5 < uglynum[indexugly])
			++uglynum5;
		indexugly++;
	}
	int ugly = uglynum[index - 1];
	delete[]uglynum;
	return ugly;
}


//删除第一个中所有的第二个字符串内容
void DelAllSecArr(char*arr1, int len1, char*arr2, int len2)
{
	assert(arr1&&arr2&&len1 > 0 && len2 > 0);
	int sign[256] = { 0 };
	for (int i = 0; i < len2; i++)
	{
		sign[arr2[i]]++;
	}
	int index = 0;
	for (int i = 0; i < len1; i++)
	{
		if (sign[arr1[i]]==0)
			arr1[index++] = arr1[i];
	}
	arr1[index] = '\0';
}

//删除字符串后重复的部分
void DelArrRepeat(char*arr, int len)
{
	assert(arr&&len > 0);
	int sign[256] = { 0 };
	for (int i = 0; i < len; i++)
	{
		sign[arr[i]]++;
	}
	int index = 0;
	for (int i = 0; i < len; i++)
	{
		if (sign[arr[i]])
		{
			arr[index++] = arr[i];
			sign[arr[i]] = 0;
		}
	}
	arr[index] = '\0';
}


//变为词
bool IsChangePosWord(char*arr1, int len1, char*arr2, int len2)
{
	assert(arr1&&arr2&&len1 > 0 && len2 > 0);
	if (len1 != len2)
		return false;
	int sign[256] = { 0 };
	for (int i = 0; i < len1; i++)
	{
		sign[arr1[i]]++;
		sign[arr2[i]]--;
	}
	for (int i = 0; i < 256; i++)
	{
		if (sign[i] != 0)
			return false;
	}
	return true;
}

//排序数组中k出现的次数
int StartK(int*arr, int len, int k, int start, int end)
{
	assert(end>=start);
	int mid = start + (end - start) / 2;
	if (k == arr[mid])
	{
		if (0 == mid || arr[mid - 1] != k)
			return mid;
		else
			end = mid - 1;
	}
	else if (arr[mid] > k)
	{
		end = mid - 1;
	}
	else
		start = mid + 1;
	return StartK(arr, len, k, start, end);
}

int EndK(int*arr, int len, int k, int start, int end)
{
	assert( end >= start);
	int mid = start + (end - start) / 2;
	if (k == arr[mid])
	{
		if (end == mid || arr[mid + 1] != k)
			return mid;
		else
			start = mid + 1;
	}
	else if (arr[mid] > k)
	{
		end = mid - 1;
	}
	else
		start = mid + 1;
	return EndK(arr, len, k, start, end);
}

int NumOfKInOrder(int*arr, int len,int k)
{
	assert(arr&&len > 0);
	int start = 0;
	int end = len - 1;
	int left = StartK(arr, len, k, start, end);
	int right = EndK(arr, len, k, start, end);
	int num = right - left + 1;
	if (num > 0)
		return num;
	return 0;
}

//判断一棵树是不是平衡树
template<typename T>
int Height(BinaryNode<T>*root)
{
	assert(root);
	if (root->m_left == NULL&&root->m_right == NULL)
		return 1;
	int left = Height(root->m_left);
	int right = Height(root->m_right);
	return left > right:(left + 1) : (right + 1);
}

template<typename T>
bool IsBalance(BinaryNode<T>*root)
{
	if (NULL == root)
		return true;
	int left = Height(root->m_left);
	int right = Height(root->m_right);
	int diff = left - right;
	if (diff >= -1 && diff <= 1)
		return IsBalance(root->m_left) && IsBalance(root->m_right);
	return false;
}
//方法二
template<typename T>
bool IsBalance3(BinaryNode<T>*root, int&deepth)
{
	if (root == NULL)
	{
		deepth = 0;
		return true;
	}
	int left = 0, right = 0;
	if (IsBalance3(root->m_left, left) && IsBalance3(root->m_right, right))
	{
		int diff = left - right;
		if (diff >= -1 && diff <= 1)
		{
			deepth = left > right ? (left + 1) : (right + 1);
			return true;
		}
	}
	return false;
}

template<typename T>
bool IsBalance2(BinaryNode<T>*root)
{
	int deepth = 0;
	IsBalance3(root,deepth);
}


//输出数组中和为一定数的一对数
void FindNumsWithSum(int *arr,int sum, int len)
{
	assert(arr&&len > 0);
	int start = 0;
	int end = len - 1;
	while (start < end)
	{
		if (arr[start] + arr[end] < sum)
			start++;
		else if (arr[start] + arr[end]>sum)
			end--;
		else
		{
			cout << arr[start] << " " << arr[end] << endl;
			return;
		}
	}
}

//输出和为一定值的连续数字
void PrintList(int *arr, int start, int end)
{
	assert(arr&&end >= start);
	for (int i = start; i<end + 1; ++i)
		cout << arr[i] << " ";
	cout << endl;
}
void PrintLastNumWithSum(int*arr,int len, int num)
{
	assert(arr&&len>0);
	int fast = 0;
	int slow = 0;
	int sum = arr[0];
	while (fast < len - 1 && slow < len - 1)
	{
		if (sum < num)
		{
			fast++;
			sum += arr[fast];
		}
		else if (sum>num)
		{
			sum -=arr[slow];
			slow++;
		}
		else
		{
			PrintList(arr, slow, fast);
			fast++;
			sum += arr[fast];
		}
	}
}

//判断五张扑克牌是否连续
int compareIsLast(const void*elem1, const void*elem2)
{
	return *(int*)elem1 - *(int*)elem2;
}

bool IsLast(int*arr, int len)
{
	assert(arr&&len > 0);
	qsort(arr, len, sizeof(int), compareIsLast);
	int numspace = 0;
	int numking = 0;
	int i = 0;
	for (i = 0; i < len&&arr[i] == 0; i++)
		numking++;
	for (int j = i + 1; j < len-1; j++)
	{
		if (arr[j + 1] == arr[j])
			return false;
		if (arr[j + 1] - arr[j] != 1)
			numspace += arr[j + 1] - arr[j] + 1;
	}
	return numking - numspace;
}

//约瑟夫环
//模板实现
#include<list>
int josefu(int n, int count)
{
	assert(n > count&&n>0&&count>0);
	list<int>coll;
	for (int i = 0; i < n; i++)
		coll.push_back(i);
	list<int>::iterator itor = coll.begin();
	while (coll.size()>1)
	{
		for (int i = 0; i < count; i++)
		{
			++itor;
			if (itor == coll.end())
				itor = coll.begin();
		}
		list<int>::iterator pt = itor;
		list<int>::iterator next = ++pt;
		if (next == coll.end())
			next = coll.begin();
		coll.erase(itor);
		itor = next;
	}
	return *itor;
}
//有规律的快速解法
int jo(int n, int m)
{
	assert(n > 0 && m > 0);
	int last = 0;
	for (int i = 2; i <= n; i++)
		last = (last + m) % 2;
	return last;
}

//实现1到n的加法
//构造函数
class SUM
{
public:
	SUM()
	{
		N++;
		M += N;
	}
	static void reset()
	{
		M = 0;
		N = 0;
	}
	static int result()
	{
		return M;
	}
private:
	static int N;
	static int M;
};
int SUM::N = 0;
int SUM::M = 0;
int test(int x)
{
	SUM::reset();
	SUM*a=new SUM[x];
	return SUM::result();
}

//2虚函数
class AAA;
AAA*Array[2];
class AAA
{
public:
	virtual unsigned int sum(int n)
	{
		return 0;
	}
};

class BBB:public AAA
{
public:
	virtual unsigned int sum(int n)
	{
		return Array[!!n]->sum(n - 1)+n;
	}
};
void testArray()
{
	AAA a;
	BBB b;
	Array[0] = &a;
	Array[1] = &b;
	cout<<Array[1]->sum(5);
}

//函数指针
typedef unsigned int(*FUN)(unsigned int);
unsigned int fun3(unsigned int n)
{
	return 0;
}
unsigned int funsum3(unsigned int n)
{
	FUN fun[2] = { fun3, funsum3 };
	return fun[!!n](n-1) + n;
}

//完成俩数相加
int ADD(int num1, int num2)
{
	int sum = 0;
	int step = 0;
	do 
	{
		sum = num1^num2;
		step = (num1&num2) << 1;
		num1 = sum;
		num2 = step;
	} while (num2);
	return sum;
}

//设计一个不能被继承的类
class sealed1
{
public:
	static sealed1*create()
	{
		return new sealed1();
	}
	static void Free(sealed1*pointer)
	{
		delete pointer;
	}
private:
	sealed1(){};
	~sealed1(){};
};

//利用虚继承
template<typename T>
class Fa
{
public:
	friend T;
private:
	Fa(){};
	~Fa(){};
};
class Son :virtual public Fa<Son>
{
public:
	Son()
	{
		a = new int[10];
		for (int i = 0; i < 10; i++)
			a[i] = i;
	};
	void test()
	{
		for (int i = 0; i < 10; i++)
			cout<<a[i];
	}
	~Son()
	{
		delete[]a;
	};
private:
	int*a;
};

void testFa()
{
	Son s;
	s.test();
}

int main()
{
	testFa();
	return 0;
}