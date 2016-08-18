#pragma once
#include<iostream>
using namespace std;

template<class K,class V>
struct AVLTreeNode
{
	K _key;
	V _value;
	AVLTreeNode<K, V>*_left;
	AVLTreeNode<K, V>*_right;
	AVLTreeNode<K, V>*_parent;
	int _bf;

	AVLTreeNode(const K&key, const V&value)
		:_key(key)
		, _value(value)
		, _left(NULL)
		, _right(NULL)
		, _parent(NULL)
		, _bf(0)
	{}
};

template<class K,class V>
class AVLTree
{
public:
	typedef AVLTreeNode<K, V> Node;
	AVLTree()
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

	void _InOrder(Node*root)
	{
		if (NULL == root)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	void RotateR(Node*node)
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

		subL->_parent = ppNode;
		if (NULL == ppNode)
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
		}
		subL->_bf = parent->_bf = 0;
	}

	void RotateL(Node*node)
	{
		Node*parent = node;
		Node*subR = parent->_right;
		Node*subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		Node*ppNode = parent->_parent;
		subR->_left = parent;
		parent->_parent = subR;
		if (NULL == ppNode)
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
		}
		parent->_bf = subR->_bf = 0;//ppNode的平衡因子是可以不改变的，因为还没有调节到ppNode，然后树就平衡了
	}

	void RotateLR(Node*parent)
	{
		Node*subL = parent->_left;
		Node*subLR = subL->_right;
		//parent和subL的平衡因子的值由subLR决定,因为以下旋转会改变它，所以先保存下来
		int bf = subLR->_bf;
		RotateL(parent->_left);
		RotateR(parent);

		if (bf == 1)
		{
			subL->_bf = -1;
			parent->_bf = 0;
		}
		else if (bf == -1)
		{
			subL->_bf = 0;
			parent->_bf = 1;
		}
		else
		{
			subL->_bf = parent->_bf = 0;
		}
		//最后subLR作为根节点肯定是平衡的
		subLR = 0;
	}

	void RotateRL(Node*parent)
	{
		Node*subR = parent->_right;
		Node*subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		if (1 == bf)
		{
			subR->_bf = 0;
			parent->_bf = -1;
		}
		else if (-1 == bf)
		{
			subR->_bf = 1;
			parent->_bf = 0;
		}
		else
		{
			subR->_bf = parent->_bf = 0;
		}
		subRL->_bf = 0;
	}

	bool Isbalance()
	{
		return _Isbalance(_root);
	}

	int Height(Node*root)
	{
		if (NULL == root)
			return 0;
		int left = Height(root->_left);
		int right = Height(root->_right);
		return left > right?(left + 1) : (right + 1);
	}

	//时间复杂度O(N^2)???????????????每个节点都判断了n*(求高度)
	bool _Isbalance(Node*root)
	{
		if (NULL == root)
			return true;
		int left = Height(root->_left);
		int right = Height(root->_right);
		int diff = left - right;
		if (root->_bf != right - left)
			cout << "平衡因子有问题" << root->_value<<endl;
		return diff >= -1 && diff <= 1 && _Isbalance(root->_left) && _Isbalance(root->_right);
	}

	//o(n),每个节点都判断了
	bool _Isbalance(Node*root, int&height)
	{
		if (root == NULL)
		{
			height = 0;
			return true;
		}
		int left, right;
		if (false == _Isbalance(root->_left, left))
			return false;
		if (false == _Isbalance(root->_right, right))
			return false;
		if (right - left > 1 || right - left < -1)
			return false;
		height = right>left ? (right + 1) : (left + 1);
		return true;
	}

private:
	//1.找到插入的位置，插入
	//2.更新平衡因子
	//3.判断是哪种旋转
	bool _Insert(Node*&root, const K&key, const V&value)
	{
		//插入第一个节点
		if (NULL == root)
		{
			root = new Node(key, value);
			return true;
		}
		//寻找插入位置
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
		//插入节点
		pcur = new Node(key, value);
		pcur->_parent = parent;
		if (parent->_key>key)
			parent->_left = pcur;
		else
			parent->_right = pcur;
		
		//调节平衡因子
		while (parent)
		{
			if (parent->_left == pcur)
				parent->_bf--;
			else
				parent->_bf++;
			//为0，说明是从-1或1来的，高度没有变化
			if (0 == parent->_bf)
				break;
			//-1或1,说明由0来，高度发生变化，要进一步判断上一个节点
			else if (1 == parent->_bf || -1 == parent->_bf)
			{
				pcur = parent;
				parent = parent->_parent;
			}
			//为2，旋转
			else
			{
				if (-2 == parent->_bf)
				{
					if (-1 == pcur->_bf)
						RotateR(parent);
					else
						RotateLR(parent);
				}
				if (2==parent->_bf)
				{
					if (1 == pcur->_bf)
						RotateL(parent);
					else
						RotateRL(parent);
				}
				//旋转后一定平衡了，就break
				break;
			}
		}
		return true;
	}
private:
	Node*_root;
};


