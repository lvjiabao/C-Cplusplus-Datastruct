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
		parent->_bf = subR->_bf = 0;//ppNode��ƽ�������ǿ��Բ��ı�ģ���Ϊ��û�е��ڵ�ppNode��Ȼ������ƽ����
	}

	void RotateLR(Node*parent)
	{
		Node*subL = parent->_left;
		Node*subLR = subL->_right;
		//parent��subL��ƽ�����ӵ�ֵ��subLR����,��Ϊ������ת��ı����������ȱ�������
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
		//���subLR��Ϊ���ڵ�϶���ƽ���
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

	//ʱ�临�Ӷ�O(N^2)???????????????ÿ���ڵ㶼�ж���n*(��߶�)
	bool _Isbalance(Node*root)
	{
		if (NULL == root)
			return true;
		int left = Height(root->_left);
		int right = Height(root->_right);
		int diff = left - right;
		if (root->_bf != right - left)
			cout << "ƽ������������" << root->_value<<endl;
		return diff >= -1 && diff <= 1 && _Isbalance(root->_left) && _Isbalance(root->_right);
	}

	//o(n),ÿ���ڵ㶼�ж���
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
	//1.�ҵ������λ�ã�����
	//2.����ƽ������
	//3.�ж���������ת
	bool _Insert(Node*&root, const K&key, const V&value)
	{
		//�����һ���ڵ�
		if (NULL == root)
		{
			root = new Node(key, value);
			return true;
		}
		//Ѱ�Ҳ���λ��
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
		//����ڵ�
		pcur = new Node(key, value);
		pcur->_parent = parent;
		if (parent->_key>key)
			parent->_left = pcur;
		else
			parent->_right = pcur;
		
		//����ƽ������
		while (parent)
		{
			if (parent->_left == pcur)
				parent->_bf--;
			else
				parent->_bf++;
			//Ϊ0��˵���Ǵ�-1��1���ģ��߶�û�б仯
			if (0 == parent->_bf)
				break;
			//-1��1,˵����0�����߶ȷ����仯��Ҫ��һ���ж���һ���ڵ�
			else if (1 == parent->_bf || -1 == parent->_bf)
			{
				pcur = parent;
				parent = parent->_parent;
			}
			//Ϊ2����ת
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
				//��ת��һ��ƽ���ˣ���break
				break;
			}
		}
		return true;
	}
private:
	Node*_root;
};


