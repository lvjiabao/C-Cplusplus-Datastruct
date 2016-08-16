//#include<iostream>
//using namespace std;
//
////
//void fun()
//{
//	char arr1[] = "123456";
//	char arr2[] = "123456";
//	if (arr1 == arr2)
//		cout << "111\n";
//	else
//		cout << "222\n";
//	char*arr3 = "456789";//
//	char*arr4 = "456789";
//	if (arr3 == arr4)
//		cout << "333\n";
//	else
//		cout << "444\n";
//}
//
//
////替换空格we are happy
//#include<assert.h>
//void replace_space(char*arr, int len)
//{
//	assert(arr);
//	char*ptmp = arr;
//	int count_space = 0;
//	while (*ptmp)
//	{
//		if (*ptmp == ' ')
//			count_space++;
//		ptmp++;
//	}
//	int len_add = len + 2 * count_space;
//	if (len_add == len)
//		return;
//	while (len>=0&&len_add>len)
//	{
//		if (arr[len - 1] == ' ')
//		{
//			arr[--len_add] = '0';
//			arr[--len_add] = '2';
//			arr[--len_add] = '%';
//		}
//		else
//			arr[--len_add] = arr[len-1];
//		len--;
//	}
//}
//
////相关题目
//void insert_sort(char*A1, int lena, char*A2, int lenb)
//{
//	assert(A1);
//	assert(A2);
//	int len_add = lena + lenb;
//	if (lena<1 || lenb<1)
//		return;
//	while (len_add)
//	{
//		if (A1[lena - 1] > A2[lenb - 1])
//		{
//			A1[--len_add] = A1[--lena];
//		}
//		else
//		{
//			A1[--len_add] = A2[--lenb];
//		}
//	}
//}
//
//
////面试题7,两个栈实现队列
//#include<deque>
//#include<stack>
//template<typename T>
//class cDeque
//{
//public:
//	cDeque()
//	{}
//	~cDeque()
//	{}
//	void append_tail(const T&node);
//	T delete_head();
//	friend ostream&operator<<(ostream&os, const cDeque<T>&sta);
//private:
//	stack<T>stack1;
//	stack<T>stack2;
//};
//
//template<typename T>
//void cDeque<T>::append_tail(const T&node)
//{
//	stack1.push(node);
//}
//
//template<typename T>
//T cDeque<T>::delete_head()
//{
//	if (stack2.size() <= 0)
//	{
//		int count = stack1.size();
//		while (count)
//		{
//			T tmp = stack1[--count];
//			stack1.pop();
//			stack2.push(tmp);
//		}
//	}
//	if (stack2.size() == 0)
//		throw new expection("deque is full\n");
//	T head = stack2.top();
//	stack2.pop();
//	return head;
//}
//
//
//
//
//#include<assert.h>
////二分查找
//int BinarySort(int*arr, int num, int length)
//{
//	assert(arr&&length > 0);
//	int start = 0;
//	int end = length - 1;
//	while (start <= end)
//	{
//		int mid = start + (end - start) / 2;
//		if (arr[mid] > num)
//			end = mid - 1;
//		else if (arr[mid] < num)
//			start = mid + 1;
//		else
//			return mid;
//	}
//	return -1;
//}
//
//
////哈希表排序
//void sort_hash(int *arr, int len)
//{
//	assert(arr);
//	if (len <= 0)
//		return;
//	const int maxage = 99;
//	int countage[maxage] = { 0 };
//	for (int i = 0; i < len; i++)
//	{
//		int age = arr[i];
//		++countage[age];
//	}
//	int index = 0;
//	for (int i = 0; i < maxage; i++)
//	{
//		for (int j = 0; j < countage[i]; j++)
//		{
//			arr[index++] = i;
//		}
//	}
//}
//
//
////题8，旋转数组的最小数字,递增
//int Min(int*arr, int len)
//{
//	if (NULL == arr || len <= 0)
//		throw new std::exception("Invalid parameters");
//	int lenleft = 0;
//	int lenright = len - 1;
//	int lenmin = lenleft;
//	while (arr[lenleft]>=arr[lenright])//还有一种没有旋转的情况
//	{
//		if (lenright - lenleft != 1)
//		{
//			lenmin = lenright;
//			break;
//		}
//		lenmin = lenleft + (lenright - lenleft) / 2;
//		if (arr[lenmin] > arr[lenleft])
//			lenleft = lenmin ;
//		else if (arr[lenmin] < arr[lenright])
//			lenright=lenmin;
//	}
//	return arr[lenmin];
//}
//
//
//int MINpos(int*arr, int indexleft, int indexright)
//{
//	int min = arr[indexleft];
//	for (int i = indexleft + 1; i < indexright; i++)
//	{
//		if (arr[i] < min)
//			min = arr[i];
//	}
//	return min;
//}
//int MIN(int*arr, int len)//完善版{1，1，1，0，1，1}
//{
//	if (arr == NULL || len <= 0)
//		throw new std::exception("Invalid Parameters");
//	int indexleft = 0, indexright = len - 1;
//	int indexmid = indexleft;
//	while (arr[indexleft] >= arr[indexright])
//	{
//		if (indexright - indexleft == 1)
//		{
//			indexmid = indexright;
//			break;
//		}
//		indexmid = indexleft + (indexright - indexleft) / 2;
//		if (arr[indexmid] == arr[indexleft] &&
//			arr[indexleft] == arr[indexright])
//			return MINpos(arr, indexleft, indexright);
//		else if (arr[indexmid] > arr[indexleft])
//			indexleft = indexmid;
//		else if (arr[indexmid] < arr[indexright])
//			indexright = indexmid;
//	}
//	return arr[indexmid];
//}
//
//
//
////面试题9   feibonaqi递归（递归和循环比较，尽量使用递归）
////具体的例子，青蛙啊=跳台阶（第一步一级:feibonaqi(n-1)   +    第二步二级：feibnaqi(n-2)，依次类推）
//int feibonaqi(int n)
//{
//	if (n < 3)
//		return 1;
//	else
//		return feibonaqi(n - 1) + feibonaqi(n - 2);
//}
//
//int fe(int first,int second,int n)
//{
//	if (n < 3)
//		return 1;
//	else if (n == 3)
//		return first + second;
//	else
//		return fe(second, first + second, n - 1);
//}
//
////面试题11，模拟实现pow
//bool InvaildInput = false;
//bool Equal(double num1,double num2)
//{
//	if (num1-num2 >= -0.0000001&&num1-num2 <= 0.0000001)
//		return true;
//	return false;
//}
//double Power(double base, int enponent)
//{
//	if (enponent == 1)
//		return base;
//	if (enponent == 0)
//		return 1;
//	double ret = Power(base, enponent >> 1);
//	ret *= ret;
//	if ((enponent & 1) == 1)
//		ret *= base;
//	return ret;
//}
//double Pow(double base, int enponent)
//{
//	if (Equal(base, 0.0)&&enponent<0)
//	{
//		InvaildInput = false;
//		return 1;
//	}
//	unsigned int absenponent = (unsigned int)enponent;
//	if (enponent < 0)
//		absenponent = (unsigned int)(-enponent);
//	double ret = Power(base, enponent);
//	if (enponent < 0)
//		ret = 1.0 / ret;
//	return ret;
//}
//
//
//
////面试题12，打印1到n位的最大数之间的数（大数）
////实现1
//bool Increase(char*arr)
//{
//	int lenarr = strlen(arr);
//	int step = 0;
//	bool isoverflow = false;
//	for (int i = lenarr - 1; i >= 0; i--)
//	{
//		int	num = arr[i] - '0' + step;
//		step = 0;
//		if (i == lenarr - 1)
//			num++;
//		if (num >= 10)
//		{
//			if (i == 0)
//				isoverflow = true;
//			else
//			{
//				step = 1;
//				num -= 10;
//				arr[i] = num + '0';
//			}
//		}
//		else
//		{
//			arr[i] = num + '0';
//			break;
//		}
//	}
//	return isoverflow;
//}
//
//void printarr(char*arr)
//{
//	int posbegin = 0;
//	int len = strlen(arr);
//	int flag = 0;
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i] != '0')
//		{
//			posbegin = i;
//			flag = 1;
//			break;
//		}
//	}
//	if (flag==1)
//		cout << arr + posbegin<<" ";
//}
//
//
//void Print1ToMaxn(int n)
//{
//	if (n <= 0)
//		return;
//	char*arr = new char[n + 1];
//	memset(arr, '0', sizeof(char)*n);
//	arr[n] = '\0';
//
//	while (!Increase(arr))
//	{
//		printarr(arr);
//	}
//
//}
//
////实现2
//
//void GetNextGigits(char*num, int size, int index)
//{
//	if (index == size)
//	{
//		printarr(num);//上一种实现方法中的打印方式
//		return;
//	}
//	else
//	{
//		for (int i = 0; i < 10; i++)
//		{
//			num[index] = i + '0';
//			GetNextGigits(num, size, index + 1);
//		}
//	}
//}
//
//void Print1ToMaxOfNDigits(int n)
//{
//	if (n <= 0)
//		return;
//	char*num = new char[n + 1];
//	num[n] = '\0';
//	for (int i = 0; i < 10; i++)
//	{
//		num[0] = i + '0';
//		GetNextGigits(num, n, 1);
//	}
//	delete[]num;
//}
//
//
////面试题14
////调整数组顺序，使奇数在前，偶数在后
//void ReorderOddEven(int*arr, int length)
//{
//	if (NULL == arr || length <= 0)
//		return;
//	int *pstart = arr;
//	int *pend = arr + length - 1;
//	while (pstart < pend)
//	{
//		while (pstart < pend&&((*pstart & 0x1) == 1))
//			pstart++;
//		while (pstart < pend&&((*pend & 0x1) != 1))
//			pend--;
//		if (pstart < pend)
//		{
//			int temp = *pstart;
//			*pstart = *pend;
//			*pend = temp;
//		}
//	}
//}
//
////适用多种情况，如奇偶数，正负数
//void Reorder(int*arr,unsigned int length,bool (*func)(int))
//{
//	if (NULL == arr || length <= 0)
//		return;
//	int *pstart = arr;
//	int *pend = arr + length - 1;
//	while (pstart < pend)
//	{
//		while (pstart < pend && (func(*pstart)))
//			pstart++;
//		while (pstart < pend && (!func(*pend)))
//			pend--;
//		if (pstart < pend)
//		{
//			int temp = *pstart;
//			*pstart = *pend;
//			*pend = temp;
//		}
//	}
//}
//
//bool IsEven(int n)
//{
//	return (n & 0x1) == 0;
//}
//
//void ReorderOddEven2(int *arr, unsigned int length)
//{
//	Reorder(arr, length, IsEven);
//}
//
////面试题18
////判断树的子结构,树A中是否有树B
//
//struct BinaryTreeNode
//{
//	BinaryTreeNode(int data)
//	:value(data)
//	, pleft(NULL)
//	, pright(NULL)
//	{}
//	int value;
//	BinaryTreeNode*pleft;
//	BinaryTreeNode*pright;
//};
//
//bool DoesTree2HasTree1(BinaryTreeNode*pnode1, BinaryTreeNode*pnode2)
//{
//	if (pnode2 == NULL)
//		return true;
//	if (pnode1 == NULL)
//		return false;
//	if (pnode1->value != pnode2->value)
//		return false;
//	return DoesTree2HasTree1(pnode1->pleft, pnode2->pleft) && DoesTree2HasTree1(pnode1->pright, pnode2->pright);
//}
//
//bool HasSubTree(BinaryTreeNode*pnode1, BinaryTreeNode*pnode2)
//{
//	bool result = false;
//	if (pnode1 != NULL&&pnode2 != NULL)
//	{
//		if (pnode1->value == pnode2->value)
//			result = DoesTree2HasTree1(pnode1, pnode2);
//		if (!result)
//		{
//			result = HasSubTree(pnode1->pright, pnode2);
//		}
//		if (!result)
//		{
//			result = HasSubTree(pnode1->pleft, pnode2);
//		}
//	}
//	return result;
//}
//
////面试题19
////得到二叉树的镜像
////借用上面的二叉树节点
//void MirrorRecursively(BinaryTreeNode*pNode)
//{
//	if (NULL == pNode || NULL == pNode->pright || NULL == pNode->pright)
//		return;
//	BinaryTreeNode*ptemp = pNode->pright;
//	pNode->pright = pNode->pright;
//	pNode->pright = ptemp;
//	MirrorRecursively(pNode->pright);
//	MirrorRecursively(pNode->pright);
//}
//
////面试题20
////顺时针打印矩阵
//void PrintNum(int**p)
//{
//
//}
//
//void PrintMatrixIncricle(int **num, int col, int row, int start)
//{
//	int endx = col - start - 1;//横向长度
//	int endy = row - start - 1;//纵向长度
//	for (int i = start; i <= endx; i++)
//		cout << num[start][i] << " ";
//
//	if (start < endy)
//	{
//		for (int i = start + 1; i <= endy; i++)
//			cout << num[i][endx] << " ";
//	}
//
//	if (endy>start&&endx>start)
//	{
//		for (int i = endx - 1; i >= start; i--)
//			cout << num[endy][i] << " ";
//	}
//	if (endx > start&&start<endy - 1)
//	{
//		for (int i = endy - 1; i > start; i--)
//			cout << num[i][start] << " ";
//	}
//}
//
//void PrintMatrixClockwisely(int **num, int col, int row)
//{
//	if (col <= 0 || row <= 0 || num == NULL)
//		return;
//	int start = 0;
//	while (col>2*start&&row>2*start)
//	{
//		PrintMatrixIncricle(num, col, row,start);
//		++start;
//	}
//}
//
//
//
////面试题21
////包含MIN函数的栈(维护一个辅助栈)
//
////实现1，手动实现，不调用栈
//template<typename T>
//class StackWithMin
//{
//public:
//	StackWithMin():
//		norsize(0),
//		spesize(0),
//		capacity(10),
//		_norpData(new T[capacity]),
//		_spepData(new T[capacity])
//	{}
//	~StackWithMin()
//	{
//		delete[]_norpData;
//		delete[]_spepData;
//	}
//	void Push(const T&data);
//	void Pop();
//	const T& Min();
//private:
//	size_t norsize;
//	size_t spesize;
//	size_t capacity;
//	T*_norpData;
//	T*_spepData;
//};
//
//template<typename T>
//void StackWithMin<T>::Push(const T&data)
//{
//	if (norsize == capacity)
//	{
//		T*temp = new T[2 * capacity];
//		for (int i = 0; i < capacity; i++)
//		{
//			temp[i] = _norpData[i];
//		}
//		delete[]_norpData;
//		_norpData = temp;
//	}
//	if (spesize == capacity)
//	{
//		T*temp = new T[2 * capacity];
//		for (int i = 0; i < capacity; i++)
//		{
//			temp[i] = _spepData[i];
//		}
//		delete[]_spepData;
//		_spepData = temp;
//	}
//
//	_norpData[norsize++] = data;
//	if (spesize == 0 || (spesize != 0 && data < _spepData[spesize - 1]))
//		_spepData[spesize++] = data;
//	else
//		_spepData[spesize++] = _spepData[spesize - 1];
//}
//
//template<typename T>
//void StackWithMin<T>::Pop()
//{
//	if (norsize>0 && spesize > 0)
//	{
//		norsize--;
//		spesize--;
//	}
//}
//
//
//template<typename T>
//const T& StackWithMin<T>::Min()
//{
//	assert(norsize > 0 && spesize > 0)
//		return _spepData[spesize - 1];
//}
//
////实现2 调用栈
//#include<stack>
//template<typename T>
//class StackWithMin2
//{
//public:
//	StackWithMin2()
//	{
//
//	}
//	void Push(const T&data);
//	void Pop();
//	const T&Min();
//private:
//	stack<T>m_data;
//	stack<T>m_min;
//};
//
//template<typename T>
//void StackWithMin2<T>::Push(const T&data)
//{
//	m_data.push(data);
//	if (m_min.size() == 0 || data < m_min.top())
//		m_min.push(data);
//	else
//		m_min.push(m_min.top());
//}
//
//template<typename T>
//void StackWithMin2<T>::Pop()
//{
//	if (m_data.size()>0 & m_min.size() > 0)
//	{
//		m_min.pop();
//		m_data.pop();
//	}
//}
//
//template<typename T>
//const T& StackWithMin2<T>::Min()
//{
//	assert(m_data.size() && m_min.size());
//	return m_min.top();
//}
//
//
////面试题22
////栈的亚茹弹出序列
//bool IsPopOrder(const int*pPush, const int*pPop, int length)
//{
//	bool ret = false;
//	if (NULL == pPush || NULL == pPop || length <= 0)
//		return ret;
//	const int*pNextPush = pPush;
//	const int*pNextPop = pPop;
//	stack<int>s;
//	while (pNextPop-pPop<length)
//	{
//		while (s.size() == 0 || *pNextPop != s.top())
//		{
//			if (pNextPush - pPush == length)
//				break;
//
//			s.push(*pNextPush);
//			pNextPush++;
//		}
//		if (s.top() != *pNextPop)
//			break;
//		s.pop();
//		pNextPop++;
//	}
//	if (s.empty() && pNextPop - pPop == length)
//		ret = true;
//	return ret;
//}
//
//
////面试题23
////从上往下打印二叉树,借用上面的 二叉树节点
//#include<deque>
//void PrintFromTopToButtom(BinaryTreeNode*pNode)
//{
//	if (pNode == NULL)
//		return;
//	deque<BinaryTreeNode*>s;
//	s.push_back(pNode);
//	while (s.size())
//	{
//		BinaryTreeNode*pt = s.front();
//		s.pop_front();
//		cout << pt->value << " ";
//		if (pt->pleft)
//			s.push_back(pt->pleft);
//		if (pt->pright)
//			s.push_back(pt->pright);
//	}
//}
//
//
////面试题24
////搜索二叉树的后续遍历序列
//bool VerifySquenceOfBST(int*arr, int length)
//{
//	if (NULL == arr || length <= 0)
//		return false;
//	int ileft = 0;
//	int root = arr[length - 1];
//	for (; ileft < length - 1; ileft++)
//	{
//		if (arr[ileft]>root)
//			break;
//	}
//	int iright = ileft;
//	for (; iright < length - 1;iright++)
//	if (arr[iright] < root)
//		return false;
//	bool left = true;
//	if (ileft>0)
//		left = VerifySquenceOfBST(arr, ileft);
//	bool right = true;
//	if (ileft<length-1)
//		right = VerifySquenceOfBST(arr + ileft, length - ileft - 1);
//	return left&&right;
//}
//
//
////面试题25
////打印和为给定数的路径
//#include<vector>
//void FindPath(BinaryTreeNode*root, vector<int>&Path, int ExpectNum, int &CurNum)
//{
//	CurNum += root->value;
//	Path.push_back(root->value);
//	bool IsLeaf = NULL == root->pleft&&NULL == root->pright;
//	if (ExpectNum == CurNum&&IsLeaf)
//	{
//		vector<int> ::iterator itor = Path.begin();
//		for (; itor != Path.end(); ++itor)
//			cout << *itor << " ";
//	}
//	if (NULL != root->pleft)
//		FindPath(root->pleft, Path, ExpectNum, CurNum);
//	if (NULL!=root->pright)
//		FindPath(root->pright, Path, ExpectNum, CurNum);
//	CurNum -= root->value;
//	Path.pop_back();
//}
//
//void FindPath(BinaryTreeNode*pNode, int ExpectNum)
//{
//	if (pNode == NULL)
//		return;
//	vector<int>Path;
//	int CurNum = 0;
//	FindPath(pNode, Path, ExpectNum, CurNum);
//}
//
////面试题26
////复杂链表的赋值
//struct ListNode
//{
//	ListNode()
//	:value(0)
//	, pnext(NULL)
//	, sibling(NULL)
//	{}
//	int value;
//	ListNode*pnext;
//	ListNode*sibling;
//};
//void CreateList(ListNode*&phead)
//{
//	ListNode*pnode = phead;
//	while (pnode)
//	{
//		ListNode*pclone = new ListNode;
//		pclone->value = pnode->value;
//		pclone->pnext = pnode->pnext;
//		pnode->pnext = pclone;
//		pnode = pclone->pnext;
//	}
//}
//
//void Sibling(ListNode*&phead)
//{
//	ListNode*node = phead;
//	while (node)
//	{
//		ListNode*pclone = node->pnext;
//		if (node->pnext)////////////////////////
//			pclone->sibling = node->sibling->pnext;
//		node = pclone->pnext;
//	}
//}
//
//ListNode* detach(ListNode*&phead)
//{
//	ListNode*node = phead;
//	ListNode*pclonehead = NULL;
//	ListNode*pclone = NULL;
//	if (node)
//	{
//		pclone = pclonehead = node->pnext;
//		node->pnext = pclone->pnext;
//		node = node->pnext;
//	}
//
//	while (node)
//	{
//		pclone->pnext = node->pnext;
//		pclone = pclone->pnext;
//		node->pnext = pclone->pnext;
//		node = node->pnext;
//	}
//	return pclonehead;
//}
//
//ListNode*CopyList(ListNode*&phead)
//{
//	CreateList(phead);
//	Sibling(phead);
//	return detach(phead);
//}
//
//
//
////面试题27
////双向链表和二叉搜索树
//
//void ConvertNode(BinaryTreeNode*pNode, BinaryTreeNode*&pLastNode)
//{
//	if (NULL == pNode)
//		return;
//	BinaryTreeNode*pCurNode = pNode;
//	if (NULL != pCurNode->pleft)
//		ConvertNode(pCurNode->pleft, pLastNode);
//
//	pCurNode->pleft = pLastNode;
//
//	if (NULL != pLastNode)
//		pLastNode->pright = pCurNode;
//
//	pLastNode=pCurNode;
//
//	if (NULL != pCurNode->pright)
//		ConvertNode(pCurNode->pright, pLastNode);
//	
//}
//
////求字符串的全排列
////立方体的八个点
////八个皇后
//void Sortall(char*str,int n,int size)
//{
//	if (NULL == str)
//		return;
//	if (n == size)
//	{
//		cout <<str<<endl;
//		return;
//	}
//	for (int i = n; i < size; i++)
//	{
//		swap(str[n], str[i]);
//		Sortall(str, n + 1, size);
//		swap(str[n], str[i]);
//	}
//}
//
////快速排序的模拟实现
//int RandInRange(int start, int end)
//{
//	if (start == end)
//		return end;
//	int num = 0;
//	while (1)
//	{
//		num = rand() % end;
//		if (num >= start)
//			return num;
//	}
//	return start;
//}
//
//void Swap(int*left, int*right)
//{
//	int temp = *left;
//	*left = *right;
//	*right = temp;
//}
//
//int Partition(int*arr, int start, int end, int length)
//{
//	if (NULL == arr || start<0 || end>length - 1 || length <= 0)
//	{
//		cout << "cuo la!!!\n";
//		exit(1);
//	}
//	int index = RandInRange(start, end);
//	Swap(&arr[index], &arr[end]);
//	int small = start - 1;
//	for (int index = start; index < end; ++index)
//	{
//		if (arr[index] < arr[end])
//		{
//			++small;
//			if (index != small)
//				Swap(&arr[index], &arr[small]);
//		}
//	}
//	++small;
//	Swap(&arr[small], &arr[end]);
//	return small;
//}
//
//void Quicksort(int*arr, int start, int end, int length)
//{
//	if (start == end)
//		return;
//	int index = Partition(arr, start, end, length);
//	if (index > start)
//		Quicksort(arr, start, index - 1, length);
//	if (index < end)
//		Quicksort(arr, index + 1, end, length);
//}
//
//
////面试题29
//#include<stdlib.h>
////数组中出现次数超过一半的数字
//
//bool IsCountEnough(int*arr, int mid, int len)
//{
//	int num = arr[mid];
//	int CountNum = 0;
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i] == num)
//			CountNum++;
//		if (CountNum * 2>len)
//			return true;
//	}
//	return false;
//}
//int MoreThanHalfNum(int*arr,const int len)
//{
//	if (NULL == arr || len <= 0)
//		return -1;
//	int start = 0;
//	int end = len - 1;
//	int mid = len >> 1;
//	int index = Partition(arr, start, end, len);
//	while (mid != index)
//	{
//		if (index > mid)
//		{
//			end = index - 1;
//			index = Partition(arr, start, end, len);
//		}
//		else
//		{
//			start = index + 1;
//			index = Partition(arr, start, end, len);
//		}
//	}
//	if (!IsCountEnough(arr, mid, len))
//		return -1;
//	return mid;
//}
//
//
////解法2
//int MoreThanHalfNum2(int*arr, int length)
//{
//	if (NULL == arr || length <= 0)
//		return -1;
//	int result = arr[0];
//	int times = 1;
//	for (int i = 1; i < length; ++i)
//	{
//		if (0 == times)
//		{
//			times = 1;
//			result = arr[i];
//		}
//		else if (arr[i] == result)
//			times++;
//		else
//			times--;
//	}
//	if (!IsCountEnough(arr, length>>2, length))
//		return -1;
//	return result;
//}
//
////面试题30
////最小的K个数
//void GetLeastNums(int*arr, int len,int k)
//{
//	if (NULL == arr || len < k || len <= 0 || k <= 1)
//		return;
//	int start = 0;
//	int end = len - 1;
//	int index = Partition(arr, start, end, len);
//	while (index != k - 1)
//	{
//		if (index<k-1)
//		{
//			start = index + 1;
//			index = Partition(arr, start, end, len);
//		}
//		else
//		{
//			end = index - 1;
//			index = Partition(arr, start, end, len);
//		}
//	}
//	for (int i = 0; i < k; ++i)
//		cout << arr[i] << endl;
//}
//
//
////解法二，适合处理海量数据
//#include<set>
//#include<functional>
//typedef multiset<int, greater<int> > intSet;
//typedef multiset<int, greater<int> >::iterator SetIterator;
//void GetLeastNums2(const vector<int>&data, intSet&LeastNums, int k)
//{
//	LeastNums.clear();
//	if (k < 1 || k < data.size())
//		return;
//	vector<int>::const_iterator itor= data.begin();
//	for (; itor != data.end(); ++itor)
//	{
//		if (LeastNums.size() < k)
//			LeastNums.insert(*itor);
//		else
//		{
//			SetIterator setitor = LeastNums.begin();
//			if (*setitor>*itor)
//			{
//				LeastNums.erase(*setitor);
//				LeastNums.insert(*itor);
//			}
//		}
//	}
//}
//
////面试题30
////连续子数组的最大和
//int MaxNumOfSonArray(int*arr, int length)
//{
//	if (NULL == arr || length <= 0)
//		exit(1);
//	int nCurNum = 0;
//	int GreatstSum = 0x80000000;
//	for (int i = 0; i < length; ++i)
//	{
//		if (nCurNum <= 0)
//			nCurNum = arr[i];
//		else
//			nCurNum += arr[i];
//		if (nCurNum>GreatstSum)
//			GreatstSum = nCurNum;
//	}
//	return GreatstSum;
//}
//
////面试题31
////从1到N整数中1出现的次数
////int CountOf1Arise(int n)
////{
////	if (n <= 0)
////		return 0;
////
////}
//
//
////面试题32
////把数组排成最小的数
//#include<stdio.h>
//#include<string.h>
//const int MaxOneNumLen = 10;
//char*g_Combine1 = new char[2 * MaxOneNumLen + 1];
//char*g_Combine2 = new char[2 * MaxOneNumLen + 1];
//
//int compare(const void*Arrnumleft, const void*Arrnumright)
//{
//	strcpy(g_Combine1, *(const char**)Arrnumleft);
//	strcat(g_Combine1, *(const char**)Arrnumright);
//	strcpy(g_Combine2, *(const char**)Arrnumright);
//	strcat(g_Combine2, *(const char**)Arrnumleft);
//	return strcmp(g_Combine1, g_Combine2);
//}
//
//void PrintMinNum(int*arr, int length)
//{
//	if (NULL == arr || length <= 0)
//		exit(1);
//	char**ArrNumbers = (char**)(new int[length]);
//	for (int i = 0; i < length; ++i)
//	{
//		ArrNumbers[i] = new char[MaxOneNumLen + 1];
//		sprintf(ArrNumbers[i], "%d", arr[i]);
//	}
//	qsort(ArrNumbers, length, sizeof(char*), compare);
//	for (int i = 0; i < length; ++i)
//		cout << ArrNumbers[i];
//	for (int i = 0; i < length; ++i)
//		delete[]ArrNumbers[i];
//	delete[]ArrNumbers;
//}
//
////面试题33
////丑数
//int MIN(int num1, int num2, int num3)
//{
//	int min = num1>num2 ? num2 : num1;
//	return min > num3 ? num3 : min;
//}
//int GetUglyNum(int index)
//{
//	assert(index > 0);
//	int*UglyNum = new int[index];
//	int*Multiplay2 = UglyNum;
//	int*Multiplay3 = UglyNum;
//	int*Multiplay5 = UglyNum;
//	int NextUglyNum = 1;
//	UglyNum[0] = 1;
//	while (NextUglyNum < index)
//	{
//		UglyNum[NextUglyNum] = MIN(*Multiplay2 * 2, *Multiplay3 * 3, *Multiplay5 * 5);
//		while (*Multiplay2 * 2 <= UglyNum[NextUglyNum])
//			++Multiplay2;
//		while (*Multiplay3 * 3 <= UglyNum[NextUglyNum])
//			++Multiplay3;
//		while (*Multiplay5 * 5 <= UglyNum[NextUglyNum])
//			++Multiplay5;
//		++NextUglyNum;
//	}
//	int ret = UglyNum[NextUglyNum - 1];
//	delete[]UglyNum;
//	return ret;
//}
//
////面试题34
////第一个只出现一次的字符abaccdeff
//char FirstOncerise(char*arr, int length)
//{
//	assert(arr&&length > 0);
//	char AriseTimes[256] = { 0 };
//	for (int i = 0; i < length; ++i)
//	{
//		AriseTimes[arr[i]]++;
//	}
//	for (int i = 0; i < 256; ++i)
//	{
//		if (AriseTimes[i] == 1)
//			return i;
//	}
//	return '\0';
//}
//
//char FirstOncerise2(char*arr, int length)
//{
//	assert(arr&&length > 0);
//	char AriseTimes[2][256] = { 0 };
//	int OrderArise = 1;
//	for (int i = 0; i < length; ++i)
//	{
//		AriseTimes[0][arr[i]]++;
//		AriseTimes[1][arr[i]] = OrderArise++;
//	}
//	char ret = 0;
//	int MinOrdertime = 0;
//	int flag = 0;
//	for (int i = 0; i < 256; ++i)
//	{
//		if (AriseTimes[0][i] == 1&&flag==0)
//		{
//			flag = 1;
//			MinOrdertime = AriseTimes[1][i];
//		}
//		if (AriseTimes[0][i] == 1 && AriseTimes[1][i] < MinOrdertime&&flag == 1)
//		{
//			MinOrdertime = AriseTimes[1][i];
//			ret = i;
//		}
//	}
//	return ret;
//}
//
////从第一个字符串中删除第二个字符串中出现过得所有字符
//void DelAllSecArr(char*arr1, int len1, char*arr2, int len2)
//{
//	assert(arr1&&arr2&&len1 > 0 && len2 > 0);
//	int sign[256] = { 0 };
//	for (int i = 0; i < len2; i++)
//	{
//		sign[arr2[i]]++;
//	}
//	int index = 0;
//	for (int i = 0; i < len1; i++)
//	{
//		if (sign[arr1[i]] == 0)
//			arr1[index++] = arr1[i];
//	}
//	arr1[index] = '\0';
//}
//
////删除字符串后部重复的字符
//void DeleteAllRepeat(char*arr, int length)
//{
//	assert(arr&&length > 0);
//	int NumTimes[256] = { 0 };
//	for (int i = 0; i < length; ++i)
//	{
//		NumTimes[arr[i]]++;
//	}
//	int CurIndex = 0;
//	for (int i = 0; i < length; ++i)
//	{
//		if (NumTimes[arr[i]]==1)
//			arr[CurIndex++] = arr[i];
//		else if (NumTimes[arr[i]] > 1)
//		{
//			arr[CurIndex++] = arr[i];
//			NumTimes[arr[i]] = 0;
//		}
//	}
//	arr[CurIndex] = '\0';
//}
//
////俩单词是否为变位词
//bool IsChangePosWord(const char*dst, int lendst,const char*src,int lensrc)
//{
//	assert(dst&&src&&lendst==lensrc&&lendst>0);
//	int NumTimes[256] = { 0 };
//	for (int i = 0; i < lensrc; ++i)
//	{
//		NumTimes[dst[i]]++;
//		NumTimes[src[i]]--;
//	}
//	for (int i = 0; i < 256; i++)
//	{
//		if (NumTimes[i] != 0)
//			return false;
//	}
//	return true;
//}
//
////数组中逆序对的总数//
////有更优的算法O（nlogn）
//int NumOfReserveCouple(int*arr, int length)
//{
//	assert(arr&&length > 0);
//	int num = 0;
//	for (int i = 0; i<length; ++i)
//	{
//		if (arr[0]>arr[i])
//			num++;
//	}
//	if (length > 2)
//		return num+NumOfReserveCouple(arr + 1, length - 1);
//	return num;
//}
//
////面试题38
////计算数组中k 出现的次数，时间效率O(log n)
//int PosOfFirstK(int*arr, int k, int start, int end)
//{
//	if (start > end)
//		return -1;
//	int MidPos = start + (end - start) / 2;
//	int MidNum = arr[MidPos];
//
//	if (MidNum == k)
//	{
//		if (MidPos > 0 && arr[MidPos - 1] == k)
//			end = MidPos - 1;
//		else
//			return MidPos;
//	}
//	else if (MidNum < k)
//	{
//		start = MidPos + 1;
//	}
//	else
//		end = MidPos - 1;
//	return PosOfFirstK(arr, k, start, end);
//}
//
//int PosOfLastK(int*arr, int k, int start, int end)
//{
//	if (start > end)
//		return -1;
//	int MidPos = start + (end - start) / 2;
//	int MidNum = arr[MidPos];
//
//	if (MidNum == k)
//	{
//		if (MidPos <end && arr[MidPos +1] == k)
//			start = MidPos + 1;
//		else
//			return MidPos;
//	}
//	else if (MidNum < k)
//		start = MidPos + 1;
//	else
//		end = MidPos - 1;
//	return PosOfLastK(arr, k, start, end);
//}
//
//int NumOfK(int *arr, int k,int length, int start, int end)
//{
//	assert(arr&&length>0&&start >= 0 && end>0);
//	int firstpos = PosOfFirstK(arr, k, start, end);
//	int lastpos = PosOfLastK(arr, k, start, end);
//	if (length >= lastpos - firstpos)
//		return lastpos - firstpos + 1;
//	return 0;
//}
//
//
////面试题39
////求树的深度
//int TreeDepth(BinaryTreeNode*root)
//{
//	if (NULL == root)
//		return 0;
//	int lenleft = TreeDepth(root->pleft);
//	int lenright = TreeDepth(root->pright);
//	return (lenleft > lenright) ? (lenleft + 1) : (lenright + 1);
//}
//
////题二（基于上题），判断是否为平衡二叉树
////思路简单，但是重复遍历太多了
//bool IsBalance(BinaryTreeNode*root)
//{
//	if (root == NULL)
//		return true;
//	int dleft = TreeDepth(root->pleft);
//	int dright = TreeDepth(root->pright);
//	int diff = dleft - dright;
//	if (diff >= -1 && diff <= 1)
//		return IsBalance(root->pleft) && IsBalance(root->pright);
//	return false;
//}
//
////题二（解法二）
//bool IsBalance(BinaryTreeNode*root, int*deepth)
//{
//	if (NULL == root)
//	{
//		*deepth = 0;
//		return true;
//	}
//	int left, right;
//	if (IsBalance(root->pleft, &left) && IsBalance(root->pright, &right))
//	{
//		int diff = right - left;
//		if (diff >= -1 && diff <= 1)
//		{
//			*deepth = left > right ? (left + 1) : (right + 1);		
//			return true;
//		}
//	}
//	return false;
//}
//
//bool IsBalance2(BinaryTreeNode*root)
//{
//	int deepth = 0;
//	return IsBalance(root, 0);
//}
//
//
////面试题40
////数组中只出现一次的俩数字
//void TwoNumAriseOnce(int*arr, int length, int*num1, int*num2)
//{
//	assert(arr&&length >= 2);
//	int Xor = 0;
//	for (int i = 0; i < length; ++i)
//	{
//		Xor ^= arr[i];
//	}
//	int PosOne = 0;
//	for (int i = 0; i < 32; ++i)
//	{
//		if (((Xor >> i) & 1) == 1)
//		{
//			PosOne = i;
//			break;
//		}
//	}
//	for (int i = 0; i < length; ++i)
//	{
//		if (((arr[i] >> PosOne) & 1) == 1)
//			*num1 ^= arr[i];
//	}
//	*num2 = *num1^Xor;
//}
//
////面试题41
////找出数组中和为一定数的俩数
//bool FindNumWithSum(int*arr, int num, int length, int*num1, int*num2)
//{
//	if (NULL == arr || length < 2 || NULL == num1 || NULL == num2)
//		return false;
//	int front = 0;
//	int back = length - 1;
//	while (front < back)
//	{
//		int numfront = arr[front];
//		int numback = arr[back];
//		int curnum = numback + numfront;
//		if (curnum == num)
//		{
//			*num1 = numfront;
//			*num2 = numback;
//			return true;
//		}
//		else if (curnum > num)
//			back--;
//		else
//			front++;
//	}
//	return false;
//}
//
//
////题二
////打印和为k的所有连续输
//int Sum(int slow, int fast)
//{
//	int sum = 0;
//	for (int i = slow; i <= fast; i++)
//		sum += i;
//	return sum;
//}
//void FindContinueSequence(int num)
//{
//	if (num < 3)
//		return;
//	int fast = 2;
//	int slow = 1;
//	while (fast>slow)
//	{
//		int curnum = Sum(slow,fast);
//		if (curnum == num)
//		{
//			for (int i = slow; i <= fast; ++i)
//				cout << i << " ";
//			cout << endl;
//			slow++;
//		}
//		else if (curnum > num)
//		{
//			slow++;
//		}
//		else
//		{
//			fast++;
//		}
//	}
//}
//
////面试题42
////翻转字符串和左旋
//void reverse(char*arr,int len)
//{
//	assert(arr&&len>=0);
//	if (len == 1)
//		return;
//	for (int i = 0; i < len/2; ++i)
//	{
//		char temp = arr[i];
//		arr[i] = arr[len - i - 1];
//		arr[len - i - 1] = temp;
//	}
//}
////we are student->student are we
//void reversearr(char*arr)
//{
//	assert(arr);
//	int len = strlen(arr);
//	reverse(arr,len);
//	char*start = arr;
//	char*end = arr;
//	while (*end!='\0')
//	{
//		while (*end != ' '&&*end!='\0')
//			++end;
//		reverse(start, end - start);
//		if (*end == '\0')
//			break;
//		start = ++end;
//	}
//}
//
//void reversearr2(char*arr)
//{
//	assert(arr);
//	char*start = arr;
//	char*end = arr;
//	reverse(arr,strlen(arr));
//	while (*start!='\0')
//	{
//		if (' ' == *start)
//		{
//			start++;
//			end++;
//		}
//		else if (*end == '\0' || *end == ' ')
//		{
//			reverse(start, end);
//			start = ++end;
//		}
//		else
//			end++;
//	}
//}
//
////左旋
//
//void reverseleft(char*arr,int k)
//{
//	assert(arr&&k>=0);
//	int len = strlen(arr);
//	if (k > len)
//		k -= len;
//	reverse(arr, strlen(arr));
//	reverse(arr, k);
//	reverse(arr + k, strlen(arr) - k);
//
//}
//
//
//
////面试题44
////判断五张扑克牌是否连续
//int compare2(const void*elem1, const void*elem2)
//{
//	return *(int*)elem1 - *(int*)elem2;
//}
//
//bool IsContinues(int*arr, int length)
//{
//	assert(arr&&length > 0);
//	int NumOfZero = 0;
//	int NumOfGrp = 0;
//	
//	qsort(arr, length, sizeof(int), compare2);
//
//	for (int i = 0; i < length&&arr[i] == 0; ++i)
//		NumOfZero++;
//
//	int small = NumOfZero;
//	int big = small + 1;
//	while (big < length)
//	{
//		if (arr[small] == arr[big])
//			return false;
//		NumOfGrp += arr[big] - arr[small] + 1;
//		small = big;
//		++big;
//	}
//	return NumOfGrp>NumOfZero ? false : true;
//}
//
//
////面试题45
////约瑟夫,模板实现
//#include<list>
//int josephuse(int n, int m)
//{
//	assert(n > 0 && m > 0);
//	list<int>ll;
//	for (int i = 0; i < n; i++)
//		ll.push_back(i);
//	list<int>::iterator cur = ll.begin();
//	while (ll.size()>1)
//	{
//		for (int i = 1; i < m; i++)
//		{
//			++cur;
//			if (cur == ll.end())
//				cur = ll.begin();
//		}
//		list<int>::iterator next = ++cur;
//		if (next == ll.end())
//			next = ll.begin();
//		--cur;
//		ll.erase(cur);//删除的是下一个元素
//		cur = next;
//	}
//	return *cur;
//}
//
////最牛逼的解法
//int LastRemaining(int n, int m)
//{
//	assert(n > 0 && m > 0);
//	int last = 0;
//	for (int i = 2; i <= n; ++i)
//		last = (last + m) % i;
//	return last;
//}
//
////面试题46
////求1到N的和
//
////解法1：利用构造函数
////class Sum
////{
////public:
////	Sum()
////	{
////		++N;
////		M += N;
////	}
////	static void reset()
////	{
////		N = 0;
////		M = 0;
////	}
////	static int ret()
////	{
////		return M;
////	}
////private:
////	static int N;
////	static int M;
////};
////
////int Sum::M = 0;
////int Sum::N = 0;
////
////
////int fun(int x)
////{
////	Sum::reset();
////	Sum*p = new Sum[x];
////	return Sum::ret();
////}
//
////解法二:虚函数
////class A;
////A*Array[2];
////class A
////{
////public:
////	virtual unsigned int sum(int n)
////	{
////		return 0;
////	}
////private:
////
////};
////
////class B:public A
////{
////public:
////	virtual unsigned int sum(int n)
////	{
////		return Array[!!n]->sum(n - 1)+n;
////	}
////private:
////
////};
////int main()
////{
////	A a;
////	B b;
////	////////////
////	Array[0] = &a;
////	Array[1] = &b;
////	cout<<Array[1]->sum(5);
////	return 0;
////}
//
////解法三：函数指针
//typedef unsigned int (*Fun)(unsigned int);
//unsigned int Solution3(unsigned int n)
//{
//	return 0;
//}
//
//unsigned int Solution3Sum(unsigned int n)
//{
//	static Fun f[2] = { Solution3, Solution3Sum};
//	return n + f[!!n](n - 1);
//}
//
//
////面试题47
////不同四则完成俩数相加
//int Add(int num1, int num2)
//{
//	int sum = 0;
//	int step = 0;
//	do 
//	{
//		sum = num1^num2;
//		step = (num1&num2) << 1;
//		num1 = sum;
//		num2 = step;
//	} while (num2!=0);
//	return num1;
//}
//
//
////面试题48
////创建一个不能被继承的类
////方法1：将构造析构设为私有
////缺点，只能创建堆上的对象
//class AA
//{
//public:
//	static AA*setclass()
//	{
//		return new AA;
//	}
//	static void freeclass(AA*aa)
//	{
//		delete aa;
//	}
//private:
//	AA(){};
//	~AA(){};
//};
//
////方法二“利用虚拟继承
//template<typename T>
//class AAA
//{
//public:
//	friend T;
//private:
//	AAA(){};
//	~AAA(){};
//};
//
//class BBB :virtual public AAA<BBB>
//{
//public:
//	BBB(){};
//	~BBB(){};
//};
//
//class CCC :public BBB
//{
//	//CCC无法继承BBB的构造函数
//};
//
////面试题49
////atoi
//
////面试题50
////找到树中俩节点的最近公共祖先
////二叉搜索树
//BinaryTreeNode* GetLastCommentFather(BinaryTreeNode*root,BinaryTreeNode*node1,BinaryTreeNode*node2)
//{
//	assert(node1&&node2);
//	if (root->value > node1->value&&root->value > node2->value)
//		GetLastCommentFather(root->pleft,node1,node2);
//	else if (root->value < node1->value&&root->value < node2->value)
//		GetLastCommentFather(root->pright, node1, node2);
//	else if ((root->value>node1->value&&root->value < node2->value) ||
//		(root->value<node1->value&&root->value>node2->value))
//		return root;
//	return NULL;
//}
//
////普通的二叉树，有指向父节点的指针（可简化为求链表的第一个节点）
//
////普通二叉树，没有指针（为避免重复遍历可借助辅助空间）
////BinaryTreeNode*GetLastFather(BinaryTreeNode*root, BinaryTreeNode*son1, BinaryTreeNode*son2)
////{
////	assert(son1&&son2);
////
////}
//
//
//
//
