#include<iostream>
#include "bitmap.h"
using namespace std;

struct HashFunc1
{
	static size_t BKDRHash(const char *str)
	{
		unsigned int seed = 131;
		unsigned int hash = 1;
		while (*str)
		{
			hash = hash * seed + (*str++);
		}

		return (hash & 0x7fffffff);
	}

	size_t operator()(const std::string &str)
	{
		return BKDRHash(str.c_str());
	}
};
struct HashFunc2
{
	static size_t BKDRHash(const char *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}

	size_t operator()(const std::string &str)
	{
		return BKDRHash(str.c_str());
	}
};
struct HashFunc3
{
	static size_t BKDRHash(const char *str)
	{
		if (!*str)        // 这是由本人添加，以保证空字符串返回哈希值0  
			return 0;
		register size_t hash = 1315423911;
		while (size_t ch = (size_t)*str++)
		{
			hash ^= ((hash << 5) + ch + (hash >> 2));
		}
		return hash;
	}

	size_t operator()(const std::string &str)
	{
		return BKDRHash(str.c_str());
	}
};
struct HashFunc4
{
	static size_t BKDRHash(const char *str)
	{
		register size_t hash = 0;
		size_t magic = 63689;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * magic + ch;
			magic *= 378551;
		}
		return hash;
	}

	size_t operator()(const std::string &str)
	{
		return BKDRHash(str.c_str());
	}
};
struct HashFunc5
{
	static size_t BKDRHash(const char *str)
	{
		register size_t hash = 0;
		size_t ch;
		for (long i = 0; ch = (size_t)*str++; i++)
		{
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
			}
		}
		return hash;
	}
	size_t operator()(const std::string &str)
	{
		return BKDRHash(str.c_str());
	}
};
template<class K=string,
class Hash1 = HashFunc1,
class Hash2 = HashFunc2,
class Hash3 = HashFunc3,
class Hash4 = HashFunc4,
class Hash5 = HashFunc5>
class Bloom
{
public:
	Bloom(size_t size)
		:_map(size)
	{}
	void Set(string str1)
	{
		size_t hash1 = HashFunc1()(str1);
		_map.Set(hash1%_map.Size());
		size_t hash2 = HashFunc2()(str1);
		_map.Set(hash2%_map.Size());
		size_t hash3 = HashFunc3()(str1);
		_map.Set(hash3%_map.Size());
		size_t hash4 = HashFunc4()(str1);
		_map.Set(hash4%_map.Size());
		size_t hash5 = HashFunc5()(str1);
		_map.Set(hash5%_map.Size());
	}

	void Unset()
	{

	}

	bool Test(string str1)
	{
		size_t hash1 = HashFunc1()(str1);
		if (false == _map.test(hash1%_map.Size()))
			return false;
		size_t hash2 = HashFunc2()(str1);
		if (false == _map.test(hash2%_map.Size()))
			return false;
		size_t hash3 = HashFunc3()(str1);
		if (false == _map.test(hash3%_map.Size()))
			return false;
		size_t hash4 = HashFunc4()(str1);
		if (false == _map.test(hash4%_map.Size()))
			return false;
		size_t hash5 = HashFunc5()(str1);
		if (false == _map.test(hash5%_map.Size()))
			return false;
		return true;
	}

private:
	bitmap _map;
};

//可以用来处理大多数类型，但是主要用来处理string，所以这里给了缺省的string
//也可以用来判断结构体，选择结构体中不容易冲突的因素来比较
//