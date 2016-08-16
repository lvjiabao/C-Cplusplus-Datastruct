#include<iostream>
#include<bitset>
using namespace std;

enum PointTag
{
	Link,
	Thread
};

template<typename T>
struct TBTreeNode
{
	TBTreeNode(const T&data)
	:value(data)
	,leftchild(NULL)
	, rightchild(NULL)
	, parent(NULL)
	, leftpoint(Link)
	, rightpoint(Link)
	{}
	T value;
	TBTreeNode<T>*leftchild;
	TBTreeNode<T>*rightchild;
	TBTreeNode<T>*parent;
	int leftpoint;
	int rightpoint;
};

template<typename T>
class TBTree
{
public:
	TBTree()
	{
		m_root = NULL;
	}
	TBTree(const T*arr,size_t size)
	{
		size_t index = 0;
		init(m_root, arr, index, size);
	}
	~TBTree()
	{
		Free(m_root);
	}
	
	//构造前序线索树
	void CreatPreBt()
	{
		TBTreeNode<T>*prev = NULL;
		_CreatPreBt(m_root, prev);
	}
	//打印前序线索树
	void PrintPre()
	{
		_PrintPre(m_root);
	}

	//构造中序线索二叉树
	void CreatMidBt()
	{
		TBTreeNode<T>*prev = NULL;
		_CreatMidBt(m_root, prev);
	}

	//打印中序线索二叉树
	void PrintMid()
	{
		_PrintMid(m_root);
	}
	//构造后续线索二叉树
	void CreatBackBt()
	{
		TBTreeNode<T>*prev = NULL;
		_CreatBackBt(m_root, prev);
	}

	//打印后序线索二叉树
	void PrintBack()
	{
		_PrintBack(m_root);
	}
	
private:
	void _PrintBack(TBTreeNode<T>*root)
	{
		if (NULL == root)
			return;
		TBTreeNode<T>*pCur = root;
		TBTreeNode<T>*prev = NULL;
		while (pCur)
		{
			if (pCur->leftchild != prev)
			{
				while (pCur->leftpoint == Link)
				{
					pCur = pCur->leftchild;
				}
			}
			while (pCur&&pCur->rightpoint == Thread)
			{
				cout << pCur->value << " ";
				prev = pCur;
				pCur = pCur->rightchild;
			}
			if (root == pCur&&pCur->rightchild==prev)
			{
				cout << root->value << " ";
				return;
			}
			while (pCur&&pCur->rightchild == prev)
			{
				cout << pCur->value << " ";
				prev = pCur;
				pCur = pCur->parent;
			}
			if (pCur&&pCur->rightpoint==Link)
			{
				pCur = pCur->rightchild;
			}
		}
	}
	void _CreatBackBt(TBTreeNode<T>*root, TBTreeNode<T>*&prev)
	{
		if (NULL == root)
			return;
		if (Link == root->leftpoint)
			_CreatBackBt(root->leftchild, prev);
		if (Link == root->rightpoint)
			_CreatBackBt(root->rightchild, prev);
		if (NULL == root->leftchild)
		{
			root->leftpoint = Thread;
			root->leftchild = prev;
		}
		if (prev&&prev->rightchild == NULL)
		{
			prev->rightpoint = Thread;
			prev->rightchild = root;
		}
		prev = root;
	}

	void _PrintMid(TBTreeNode<T>*root)
	{
		if (NULL == root)
			return;
		TBTreeNode<T>*pCur = root;
		while (pCur)
		{
			while (pCur->leftpoint != Thread)
			{
				pCur = pCur->leftchild;
			}
			cout << pCur->value << " ";
			while (pCur&&pCur->rightpoint == Thread)
			{
				pCur = pCur->rightchild;
				cout << pCur->value << " ";
			}
			if (pCur)
				pCur = pCur->rightchild;
		}
	}

	void _CreatMidBt(TBTreeNode<T>*root, TBTreeNode<T>*&prev)
	{
		if (NULL == root)
			return;
		if (Link == root->leftpoint)
			_CreatMidBt(root->leftchild, prev);
		if (NULL == root->leftchild)
		{
			root->leftpoint = Thread;
			root->leftchild = prev;
		}
		if (prev&&prev->rightchild == NULL)
		{
			prev->rightpoint = Thread;
			prev->rightchild = root;
		}
		prev = root;
		if (Link == root->rightpoint)
			_CreatMidBt(root->rightchild, prev);
	}

	void Free(TBTreeNode<T>*root)//////注意是引用
	{
		if (NULL == root)
			return;
		if (root->leftpoint==Link)
			Free(root->leftchild);
		if (root->rightpoint == Link)
			Free(root->rightchild);      
		delete[]root;
		root = NULL;
	}

	//建立前序线索二叉树
	void _CreatPreBt(TBTreeNode<T>*root, TBTreeNode<T>*&prev)
	{
		if (NULL == root)
			return;
		if (NULL == root->leftchild)
		{
			root->leftpoint = Thread;
			root->leftchild = prev;
		}
		//如果这一层判断放在上一判断里面（NULL == root->leftchild）会影响判断，使4的右连不上5
		if (prev&&NULL == prev->rightchild)
		{
			prev->rightpoint = Thread;
			prev->rightchild = root;
		}
		prev = root;              
		if (Link == root->leftpoint)
		{
			_CreatPreBt(root->leftchild, prev);
		}

		if (Link == root->rightpoint)
		{
			_CreatPreBt(root->rightchild, prev);
		}
	}
	void _PrintPre(TBTreeNode<T>*root)
	{
		if (NULL == root)
			return;
		TBTreeNode<T>*pCur = root;
		while (pCur)
		{
			while (pCur->leftchild)
			{
				cout << pCur->value << " ";
				if (pCur->leftpoint != Link)
					break;
				pCur = pCur->leftchild;
			}
			pCur = pCur->rightchild;
		}
	}
	void init(TBTreeNode<T>*&root, const T*arr, size_t&index, size_t size)
	{
		if (index < size&&arr[index] != '#')
		{
			root = new TBTreeNode<T>(arr[index]);
			init(root->leftchild, arr, ++index, size);
			if (root->leftchild)
				root->leftchild->parent = root;
			init(root->rightchild, arr, ++index, size);
			if (root->rightchild)
				root->rightchild->parent = root;
		}
	}
private:
	TBTreeNode<T>*m_root;
};

int main()
{
	char arr[] = "123##4##56##7##";
	TBTree<char>t(arr,strlen(arr));
	return 0;
}