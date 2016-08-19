#pragma once
#include<iostream>

using namespace std;

enum Colour
{
	Red,
	Black
};
template<class K,class V>
struct BRTreeNode
{
	BRTreeNode<K, V>*_left;
	BRTreeNode<K, V>*_right;
	BRTreeNode<K, V>*_parent;
	K _key;
	V _value;
	Colour _col;
	BRTreeNode(const K&key, const V&value)
		:_left(NULL)
		, _right(NULL)
		, _parent(NULL)
		, _key(key)
		, _value(value)
		, _col(Red)
	{}
};

template<class K,class V>
class BRTree
{
public:
	typedef BRTreeNode<K, V> Node;
	BRTree()
		:_root(NULL)
	{}

	bool Insert(const K&key, const V&value)
	{
		return _Insert(_root, key, value);
	}

	void InOrder()
	{
		_InOrder(_root);
	}
	
	//判断平衡需满足俩规则：没有连续的红，各路上黑节点个数相同
	bool Isbalance()
	{
		int count = 0;
		Node*pcur = _root;
		while (pcur)
		{
			if (pcur->_col == Black)
				count++;
			pcur = pcur->_left;
		}
		int k = 0;
		return _Isbalance(_root, count, k);
	}

private:
	bool _Isbalance(Node*root, const int count, int k)
	{
		if (NULL == root)
			return true;
		if (root->_col == Red&&root->_parent->_col == Red)
		{
			cout << "俩连续红节点:" << root->_key << endl;
			return false;
		}

		if (root->_col == Black)
			k++;
		if (root->_left == NULL&&root->_right == NULL&&k != count)
		{
			cout << "黑节点个数不等：" << root->_key << endl;
			return false;
		}

		return _Isbalance(root->_left, count, k) && _Isbalance(root->_right, count, k);
	}

	void _InOrder(Node*root)
	{
		if (NULL == root)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
	bool _Insert(Node*root, const K&key, const V&value)
	{
		if (NULL == root)
		{
			_root = new Node(key, value);
			_root->_col = Black;
			return true;
		}
		Node*parent = NULL;
		Node*pcur = root;
		while (pcur)
		{
			if (pcur->_key > key)
			{
				parent = pcur;
				pcur = pcur->_left;
			}
			else if (pcur->_key < key)
			{
				parent = pcur;
				pcur = pcur->_right;
			}
			else
				return false;
		}

		pcur = new Node(key, value);
		if (parent->_key>key)
			parent->_left = pcur;
		else
			parent->_right = pcur;
		pcur->_parent = parent;

		while (pcur!=root&&parent->_col==Red)
		{
			Node*grandfather = parent->_parent;
			if (grandfather->_left == parent)
			{
				Node*uncle = grandfather->_right;
				if (uncle&&uncle->_col == Red)
				{
					parent->_col = uncle->_col = Black;
					grandfather->_col = Red;
					pcur = grandfather;
					parent = pcur->_parent;
				}
				else if (pcur == parent->_right)
				{
					RoateL(parent);
					RoateR(grandfather);
					swap(parent, pcur);
					parent->_col = Black;
					grandfather->_col = Red;
					break;
				}
				else
				{
					RoateR(grandfather);
					parent->_col = Black;
					grandfather->_col = Red;
					break;
				}
			}
			else
			{
				Node*uncle = grandfather->_left;
				if (uncle&&uncle->_col == Red)
				{
					parent->_col = uncle->_col = Black;
					grandfather->_col = Red;
					pcur = grandfather;
					parent = pcur->_parent;
				}
				else if (parent->_left == pcur)
				{
					RoateR(parent);
					RoateL(grandfather);
					swap(parent, pcur);
					parent->_col = Black;
					grandfather->_col = Red;
					break;
				}
				else
				{
					RoateL(grandfather);
					parent->_col = Black;
					grandfather->_col = Red;
					break;
				}
			}
		}
		_root->_col = Black;
		return true;
	}

	void RoateL(Node*node)
	{
		Node*parent = node;
		Node*subR = parent->_right;
		Node*subRL = subR->_left;
		Node*ppNode = parent->_parent;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (ppNode == NULL)
		{
			_root = subR;
			subR->_parent = NULL;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subR;
			else
				ppNode->_right = subR;
			subR->_parent = ppNode;
		}
	}

	void RoateR(Node*node)
	{
		Node*parent = node;
		Node*subL = parent->_left;
		Node*subLR = subL->_right;
		Node*ppNode = parent->_parent;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (ppNode == NULL)
		{
			_root = subL;
			subL->_parent = NULL;
		}
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = subL;
			else
				ppNode->_right = subL;
			subL->_parent = ppNode;
		}
	}
private:
	Node*_root;
};