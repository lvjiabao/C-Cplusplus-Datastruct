#pragma once
#include<iostream>
#include <vector>
using namespace std;

class bitmap
{
public:
	bitmap(size_t size)
	{
		map = new int[(size >> 5) + 1];
		memset(map, 0, sizeof(map));
	}
	~bitmap()
	{
		delete[]map;
	}
	void Set(size_t num)
	{
		int index = num >> 5;
		int pos = num % 32;
		map[index] |= (1 << (pos-1));
	}
	void Unset(size_t num)
	{
		int index = num >> 5;
		int pos = num % 32;
		map[index] &= ~(1 << (pos-1));
	}

	bool test(size_t num)
	{
		int index = num >> 5;
		int pos = num % 32;
		if (((map[index]>>(pos-1))&1)==1)
			return true;
		return false;
	}
private:
	int*map;
};

int main()
{
	bitmap ll(-1);
	ll.Set(10);
	ll.Set(1000);
	ll.Set(1024);
	cout << "100:" << ll.test(10) << endl;
	cout << "1000:" << ll.test(1000) << endl;
	cout << "1024:" << ll.test(1024) << endl;
	ll.Unset(1000);
	cout << "100:" << ll.test(10) << endl;
	cout << "1000:" << ll.test(1000) << endl;
	cout << "1024:" << ll.test(1024) << endl;
	system("pause");
	return 0;
}