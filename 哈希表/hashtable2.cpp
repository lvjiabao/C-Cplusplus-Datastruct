#include<iostream>
#include<vector>
using namespace std;


template<class K,class V>
struct HashTableNode
{
	K _key;
	V _value;
	HashTableNode<K, V>*_next;
	HashTableNode(const K&key, const V&value)
		:_key(key)
		, _value(value)
		, _next(NULL)
	{}
};

template<class K, class V>
class HashTable
{
	typedef HashTableNode<K, V> Node;
public:
	HashTable()
		:_size(0)
	{}
	HashTable(size_t size)
		:_size(0)
		, table(GetNextPrime(size))
	{}

	bool Insert(const K&key, const V&value)
	{
		Capacity();
		if (Find(key))
			return false;
		int index = HashFunc(key, table.size());
		Node*tmp = new Node(key, value);
		tmp->_next = table[index];
		table[index] = tmp;
		_size++;
		return true;
	}

	bool Remove(const K&key)
	{
		int index = HashFunc(key, table.size());
		Node*pcur = table[index];
		if (pcur&&pcur->_key == key)
		{
			table[index] = pcur->_next;
			delete pcur;
			pcur = NULL;
			return true;
		}
		Node*prev = pcur;
		while (pcur)
		{
			if (pcur->_key == key)
			{
				prev->_next = pcur->_next;
				delete pcur;
				return true;
			}
			prev = pcur;
			pcur = pcur->_next;
		}
		return false;
	}

	bool Remove1(const K&key)
	{
		Node*pt = Find(key);
		if (pt == NULL)
			return false;
		Node*pnext = pt->_next;
		swap(pnext, pt);
		delete pnext;
	}

	size_t GetNextPrime(size_t size)
	{
		const int _PrimeSize = 28;
		static const unsigned long _PrimeList[_PrimeSize] =
		{
			53ul, 97ul, 193ul, 389ul, 769ul,
			1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
			49157ul, 98317ul, 196613ul, 393241ul,
			786433ul,
			1572869ul, 3145739ul, 6291469ul, 12582917ul,
			25165843ul,
			50331653ul, 100663319ul, 201326611ul, 402653189ul,
			805306457ul,
			1610612741ul, 3221225473ul, 4294967291ul
		};
		int i = 0;
		for (i = 0; i < 28; i++)
		{
			if (_PrimeList[i]>size)
				return _PrimeList[i];
		}
		return _PrimeList[i - 1];
	}
	void Capacity()
	{
		//两种方法，一种和开发一样
		if (_size == table.size())
		{
			vector<Node*>newTables;
			newTables.resize(GetNextPrime(_size));//resize同时改变size和capacity
			for (int i = 0; i < table.size(); i++)
			{
				Node*pcur = table[i];
				while (pcur)
				{
					Node*next = pcur->_next;
					int index = HashFunc(pcur->_key, newTables.size());
					pcur->_next = newTables[index];
					newTables[index] = pcur;
					pcur = next;
				}
				table[i] = NULL;
			}
			table.swap(newTables);
		}
	}

	Node* Find(const K&key)
	{
		int index = HashFunc(key, table.size());
		Node*pcur = table[index];
		while (pcur)
		{
			if(pcur->_key == key)
				return pcur;
			pcur = pcur->_next;
		}
		return NULL;
	}

	int HashFunc(K key, size_t size)
	{
		return key%size;
	}

	void Print()
	{
		for (int i = 0; i < table.size(); i++)
		{
			Node*pcur = table[i];
			printf("table[%d]:", i);
			while (pcur)
			{
				cout << pcur->_key << " ";
				pcur = pcur->_next;
			}
			cout << endl;
		}
	}
	

protected:
	size_t _size;
	vector<Node*>table;
};


//哈希表的容量最好是素数，可以减少冲突


int main()
{
	int arr[] = { 51, 105, 52, 3, 55, 2, 106, 53, 0 };
	HashTable<int, int>ht;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		ht.Insert(arr[i],i);
	ht.Print();
	ht.Remove1(53);
	ht.Print();
	ht.Remove1(0);
	ht.Print();
	ht.Remove1(106);
	ht.Print();
	//HashTable<int, int>tt;
	//for (int i = 0; i < 60; i++)
	//	tt.Insert(i, i);
	//tt.Print();
	system("pause");
	return 0;
}