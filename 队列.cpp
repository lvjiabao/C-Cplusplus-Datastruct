#include<iostream>
using namespace std;


//queue队列，是一个适配器,通过容器deque实现
template<typename T>
class Queue
{
public:
	Queue(size_t capacity = 10)
		:m_front(0)
		, m_back(0)
		, m_tag(0)
		, m_count(0)
		, m_capacity(10)
	{
		m_capacity = m_capacity > capacity ? m_capacity : capacity;
		m_pData = new T[m_capacity];
	}
	~Queue()
	{
		if (NULL != m_pData)
		{
			delete[]m_pData;
		}
	}
	size_t Size();
	T&Top();
	const T&Top()const;
	bool Empty();
	void Push(const T&data);
	void Pop();
private:
	size_t m_capacity;
	size_t m_tag;
	size_t m_count;
	int m_front;//库中back（）返回的是最后一个元素
	int m_back;//front（）返回第一个元素
	T*m_pData;
};

//用循环对列来实现,循环队列判断空满的3中方式
//最后一块空间不使用m_front==m_back
//设置一个计数器count==m_capacity
//设置一个标志位

template<typename T>
void Queue<T>::Push(const T&data)
{
	//第一种判断方式
	if ((m_back + 1) % capacity == m_front)
		return;
	m_pData[m_back] = data;
	m_back = (m_back + 1) % m_capacity;
	//第二种判断方式
	if (m_count == m_capacity)
		return;
	m_count++;
	m_pData[m_back] = data;
	m_back = (m_back + 1) % m_capacity;
	//第三种判断方式
	if (m_front == m_back&&m_tag == 1)
		return;
	m_tag = 1;
	m_pData[m_back] = data;
	m_back = (m_back + 1) % m_capacity;
}


template<typename T>
void Queue<T>::Pop()
{
	//第一种判断情况
	if (m_back==m_front)
		return;
	m_front = (m_front + 1) % m_capacity;
	//第二种判断情况
	if (m_count == 0)
		return;
	m_count--;
	m_front = (m_front + 1) % m_capacity;
	//第三种判断方式
	if (m_front == m_back&&m_tag == 0)
		return;
	m_tag = 0;
	m_front = (m_front + 1) % m_capacity;
}

template<typename T>
size_t Queue<T>::Size()//////
{
	return (m_front==m_back&&m_tag==1)?m_capacity:((m_back - m_front + m_capacity) % m_capacity);
}


template<typename T>
T& Queue<T>::Top()
{
	//第一种判断情况
	if (m_back == m_front)
		return;
	return m_pData[m_front];
	//第二种判断情况
	if (m_count == 0)
		return;
	return m_pData[m_front];
	//第三种判断方式
	if (m_front == m_back&&m_tag == 0)
		return;
	return m_pData[m_front];
}

template<typename T>
const T&Queue<T>::Top()const
{
	//第一种判断情况
	if (m_back == m_front)
		return;
	return m_pData[m_front];
	//第二种情况
	if (m_count == 0)
		return;
	return m_pData[m_front];
	//第三种判断方式
	if (m_front == m_back&&m_tag == 0)
		return;
	return m_pData[m_front];
}

template<typename T>
bool Queue<T>::Empty()
{
	//第一种判断情况
	if (m_back == m_front)
		return true;
	return false;
	//第二种判断情况
	if (m_count == 0)
		return true;
	return false;
	//第三种判断方式
	if (m_front == m_back&&m_tag == 0)
		return true;
	return false;
}


//拿出栈上的最小值,时间复杂度为O(1)
#include<stack>
template<typename T>
class StackMin
{
public:
	void Push(const T&data);
	void Pop();
	T Min();
private:
	stack<T>st1;
	stack<T>st2;
};

template<typename T>
void StackMin<T>::Push(const T&data)
{
	st1.push(data);
	if (st2.size() == 0 || st2.top() > data)
		st2.push(data);
	else
		st2.push(st2.top());
}

template<typename T>
void StackMin<T>::Pop()
{
	if (st1.size() == 0)
		return;
	st1.pop();
	st2.pop();
}

template<typename T>
T StackMin<T>::Min()
{
	return st2.top();
}

void teststackmin()
{
	StackMin<int>sta;
	sta.Push(2);
	sta.Push(1);
	sta.Push(4);
	sta.Push(5);
	sta.Push(0);
	cout << sta.Min()<<endl;
	sta.Pop();
	cout << sta.Min() << endl;
	sta.Pop();
	cout << sta.Min() << endl;
	sta.Pop();
	cout << sta.Min() << endl;
	sta.Pop();
}

//用俩栈实现队列
//栈：先进后出
//队列：先进先出
template<typename T>
class QueueOfTwoStack
{
public:
	void Push(const T&data);
	void Pop();
	T&Front()////可以合并
	{
		if (st2.empty())
		{
			while (!st1.empty())
			{
				st2.push(st1.top());
				st1.pop();
			}
		}
	return st2.top();
	}
	T&Back()
	{
		if (st1.empty())
		{
			while (!st2.empty())
			{
				st1.push(st2.top());
				st2.pop();
			}
		}
		return st1.top();
	}
private:
	stack<T>st1;
	stack<T>st2;
};

template<typename T>
void QueueOfTwoStack<T>::Push(const T&data)
{
	st1.push(data);
}

template<typename T>
void QueueOfTwoStack<T>::Pop()
{
	if (st2.size() == 0)
	{
		int count = st1.size();
		for (size_t i = 0; i < count; i++)
		{
			st2.push(st1.top());
			st1.pop();
		}
		st2.pop();
	}
	else
		st2.pop();
}

void testQueueOfTwoStack()
{
	QueueOfTwoStack<int>q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	cout<<q.Back()<<endl;
	cout<<q.Front()<<endl;
	q.Pop();
	cout << q.Back() << endl;
	cout << q.Front() << endl;
}


/////////////////////
//用俩队列实现栈
#include<queue>
template<typename T>
class StackWithTwoQueue
{
public:
	void Push(const T&data);
	void Pop();
	T&Top()
	{
		assert(!qu1.empty());
		return qu1.back();
	}
private:
	queue<T>qu1;
	queue<T>qu2;
};


template<typename T>
void StackWithTwoQueue<T>::Push(const T&data)
{
	qu1.push(data);
}

template<typename T>
void StackWithTwoQueue<T>::Pop()
{
	if (0 == qu1.size())
		return;
	int count = qu1.size();
	for (int i = 0; i < count - 1; i++)
	{
	qu2.push(qu1.front());
	qu1.pop();
	}
	qu1.pop();
	swap(qu1, qu2);//交换
}

void testStackWithTwoQueue()
{
	StackWithTwoQueue<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Pop();
	s.Pop();
	s.Push(4);
	s.Pop();
}

//判断是否为出栈顺序
bool IsPopOrder(const int*pPush, const int*pPop, int length)
{
	bool ret = false;
	if (NULL == pPush || NULL == pPop || length <= 0)
		return ret;
	const int*pNextPush = pPush;
	const int*pNextPop = pPop;
	stack<int>s;
	while (pNextPop - pPop < length)
	{
		while (s.size() == 0 || *pNextPop != s.top())
		{
			if (pNextPush - pPush == length)
				break;
			s.push(*pNextPush);
			pNextPush++;
		}
		if (s.top() != *pNextPop)
			break;
		s.pop();
		pNextPop++;
	}
	if (s.empty() && pNextPop - pPop == length)
		ret = true;
	return ret;
}


bool IsPopOrder2(const vector<int>pPush, const vector<int>pPop)
{
	if (pPush.size() != pPop.size()||pPush.size()==0||pPop.size()==0)
		return false;
	stack<int>s;
	bool ret = false;
	int indexpush = 0;
	int indexpop = 0;
	while (indexpop < pPop.size())
	{
		while (s.size() == 0 || s.top() != pPop[indexpop])
		{
			if (indexpush == pPush.size())
				break;
			s.push(pPush[indexpush]);
			indexpush++;
		}
		if (indexpop == pPop.size())
			break;
		indexpop++;
	}
	if (indexpush == pPush.size() && indexpop == pPop.size())
		ret = true;
	return ret;
}


//共享栈
template<typename T,int MAX_LEN=10>
class DoubleStack
{
public:
	DoubleStack() :index1(0), index2(1)
	{}
	void Push(const T&data,bool choice)
	{
		if (choice)
		{
			assert(index1 < MAX_LEN);
			arr[index1] = data;
			index1 += 2;
		}
		else
		{
			assert(index2 < MAX_LEN);
			arr[index2] = data;
			index2 += 2;
		}
	}

	void Pop(bool choice)
	{
		if (choice)
		{
			assert(index1>0);
			index1 -= 2;
		}
		else
		{
			assert(index2 > 1);
			index2 -= 2;
		}
	}
	T&Top(bool choice)
	{
		if (choice)
		{
			assert(index1 > 0);
			return arr[index1 - 2];
		}
		else
		{
			assert(index2 > 1);
			return arr[index2 - 2];
		}
	}
private:
	int index1;
	int index2;
	int arr[MAX_LEN];
};


//用俩数组实现共享栈
//push pop empty size top
template<class T>
class ShareStack
{
public:
	ShareStack() :
		_sizel(0),
		_sizer(0),
		capacity(10),
		_pData(new T[capacity])
	{}
	~ShareStack()
	{
		delete[]_pData;
	}
	void Push(const T&data, bool leftorright);
	void Pop(bool leftorright);
private:
	size_t _sizel;
	size_t _sizer;
	size_t capacity;
	T*_pData;
};

template<typename T>
void ShareStack<T>::Push(const T&data, bool leftorright)
{
	if (leftorright)
	{
		if (_sizer + _sizel < capacity)
			_pData[_sizel++] = data;
		else
		{
			cout << "空间已满\n";
			return;
		}
	}
	else
	{
		if (_sizer + _sizel < capacity)
			_pData[_sizer++] = data;
		else
		{
			cout << "空间已满\n";
			return;
		}
	}
}

template<typename T>
void ShareStack<T>::Pop(bool leftorright)
{
	if (leftorright)
	{
		if (_sizel > 0)
			--_sizel;
		else
		{
			cout << "列表为空\n";
			return;
		}
	}
	else
	{
		if (_sizer > 0)
			--_sizer;
		else
		{
			cout << "列表为空\n";
			return;
		}
	}
}

//背包问题
void Print(int*arr,stack<int>s)
{
	cout << "( ";
	while (!s.empty())
	{
		cout << arr[s.top()]<<" ";
		s.pop();
	}
	cout << " )"<<endl;
}
#include<assert.h>
void backpack(int *arr, int size, int weight)
{
	assert(arr);
	int begin = 0;
	int sum = 0;
	stack<int> s;
	int pos = 0;
	while (begin < size)
	{
		if (pos < size)
		{
			s.push(pos);
			sum += arr[pos];
			if (sum == weight)
			{
				Print(arr, s);

			}
			if (sum > weight)
			{
				sum -= arr[s.top()];
				s.pop();
			}
			pos++;
		}
		else
		{
			sum -= arr[s.top()];
			pos = s.top() + 1;
			s.pop();
		}

		if (s.empty())
		{
			begin++;
			pos = begin;
			sum = 0;
		}
	}
}

void Pack(int*arr, int size, int weight)
{
	assert(arr&&size > 0);
	stack<int>s;
	int begin = 0;
	int pos = 0;
	int TotalNum = 0;
	while (begin < size)
	{
		if (pos < size)
		{
			s.push(pos);
			TotalNum += arr[s.top()];
			if (TotalNum>weight)
			{
				TotalNum -= arr[s.top()];
				s.pop();
			}
			else if (TotalNum == weight)
			{
				Print(arr, s);
			}
			pos++;
		}
		else
		{
			TotalNum -= arr[s.top()];
			pos = s.top() + 1;
			s.pop();
		}
		if (s.empty())
		{
			TotalNum = 0;
			begin++;
			pos = begin;
		}
	}
}

int main()
{
	int arr[] = { 1, 8, 4, 3, 5, 2 };
	backpack(arr, 6, 10);

	return 0;
}