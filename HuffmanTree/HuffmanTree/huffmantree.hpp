#pragma once
#include<iostream>
#include<assert.h>
#include<queue>
#include<vector>
using namespace std;





template<typename T>
struct HuffmanTreeNode
{
	T _weight;
	HuffmanTreeNode<T>*_pleft;
	HuffmanTreeNode<T>*_pright;
	HuffmanTreeNode<T>*_parent;
	HuffmanTreeNode(const T&weight)
		:_weight(weight)
		, _pleft(NULL)
		, _pright(NULL)
		, _parent(NULL)
	{}
};

template<typename T>
class Compare_less
{
public:
	bool operator()(HuffmanTreeNode<T>*left, HuffmanTreeNode<T>*right)
	{
		return left->_weight < right->_weight;
	}
};

template<typename T>
class Compare_more
{
public:
	bool operator()(HuffmanTreeNode<T>*left, HuffmanTreeNode<T>*right)
	{
		return left->_weight > right->_weight;
	}
};

template<typename T>
class HuffmanTree
{
public:
	HuffmanTree() :_root(NULL){}
	HuffmanTree(const T*weight, int size)
	{
		CreateTree(weight, size);
	}
	void PrintLevel()
	{
		_PrintLevel(_root);
	}
	~HuffmanTree()
	{
		Destroy(_root);
	}
private:
	void CreateTree(const T*weight, int size)
	{
		assert(weight);
		if (size == 0)
			return;
		if (size == 1)
		{
			_root = new HuffmanTreeNode<T>(weight[0]);
			return;
		}
		heap<HuffmanTreeNode<T>*,Compare_less<T> >coll;
		for (int i = 0; i < size; ++i)
			coll.Insert(new HuffmanTreeNode<T>(weight[i]));
		HuffmanTreeNode<T>*parent = NULL;
		while (coll.Size()>1)
		{
			HuffmanTreeNode<T>*left = coll.Top();
			coll.Remove();
			HuffmanTreeNode<T>*right = coll.Top();
			coll.Remove();
			parent = new HuffmanTreeNode<T>(left->_weight + right->_weight);
			parent->_pleft = left;
			parent->_pright = right;
			left->_parent = parent;
			right->_parent = parent;
			coll.Insert(parent);
		}
		_root = parent;
	}

	void _PrintLevel(HuffmanTreeNode<T>*root)
	{
		if (NULL == root)
			return;
		queue<HuffmanTreeNode<T>*>coll;
		coll.push(root);
		while (!coll.empty())
		{
			HuffmanTreeNode<T>*tmp = coll.front();
			cout << tmp->_weight << " ";
			if (tmp->_pleft)
				coll.push(tmp->_pleft);
			if (tmp->_pright)
				coll.push(tmp->_pright);
			coll.pop();
		}
	}

	void Destroy(HuffmanTreeNode<T>*root)
	{
		if (root)
		{
			Destroy(root->_pleft);
			Destroy(root->_pright);
			delete[]root;
			root = NULL;
		}
	}
private:
	HuffmanTreeNode<T>*_root;
};



template<typename T>
struct HuffmanTreeNode_A
{
	T _weight;
	int _leftchildidx;
	int _rightchildidx;
	int _parentidx;
	int _idx;
	HuffmanTreeNode_A(const T&weight)
		:_weight(weight)
		, _leftchildidx(-1)
		, _rightchildidx(-1)
		, _parentidx(-1)
		, _idx(0)
	{}
};

template<typename T>
class Compare_less_A
{
public:
	bool operator()(HuffmanTreeNode_A<T>*left, HuffmanTreeNode_A<T>*right)
	{
		return left->_weight < right->_weight;
	}
};

template<typename T>
class Compare_more_A
{
public:
	bool operator()(HuffmanTreeNode_A<T>*left, HuffmanTreeNode_A<T>*right)
	{
		return left->_weight > right->_weight;
	}
};

template<typename T>
class HuffmanTree_A
{
public:
	HuffmanTree_A(const T*weight, size_t size)
	{
		if (size == 0)
			return;
		if (size == 1)
		{
			_node.push_back(new HuffmanTreeNode_A(weight[0]));
			return;
		}
		int index = 0;
		_node.reserve(2 * size - 1);
		heap<HuffmanTreeNode_A<T>*,Compare_less_A<T> >hp;
		for (int i = 0; i < size; i++)
		{
			_node.push_back(new HuffmanTreeNode_A<T>(weight[i]));
			HuffmanTreeNode_A<T>*&node = _node.back();
			node->_idx = index++;
			hp.Insert(node);
		}
		HuffmanTreeNode_A<T>*parent = NULL;
		while (hp.Size()>1)
		{
			HuffmanTreeNode_A<T>*left = hp.Top();
			hp.Remove();
			HuffmanTreeNode_A<T>*right = hp.Top();
			hp.Remove();

			parent = new HuffmanTreeNode_A<T>(left->_weight + right->_weight);
			parent->_idx = index++;
			left->_parentidx = parent->_idx;
			right->_parentidx = parent->_idx;
			parent->_leftchildidx = left->_idx;
			parent->_rightchildidx = right->_idx;
			_node.push_back(parent);
			hp.Insert(parent);
		}
	}

private:
	vector<HuffmanTreeNode_A<T>*>_node;
};
