#include<iostream>
#include<queue>
#include<vector>
#include<stack>

////////////////////////////////////////////////////
//1.����������Ƚڵ�����⣬������Ժ��ӽڵ��غ�
//2.main()�д��Σ�m_root��Ϊ���У�û�б�Ҫ����ͨ������Ա����������һ�����ķ�ʽʵ��
//3.�ж���ȫ���������߶ȵ�ʵ�֣�
//
using namespace std;
template<typename T>
struct BinaryNode
{
	BinaryNode(T data)
	:_data(data)
	,m_left(NULL)
	,m_right(NULL)
	
	{}
	T _data;
	BinaryNode<T>*m_left;
	BinaryNode<T>*m_right;
};

template<typename T>
class BinaryTree
{
public:
	BinaryTree()
	{
		m_root = NULL;
	}
	BinaryTree(T arr[],size_t size)
	{
		size_t index = 0;
		init(arr, m_root,size ,index);
	}
	BinaryTree(const BinaryTree<T>&t)
	{
		m_root = CreatTree(t.m_root);
	}
	BinaryTree<T>&operator=(const BinaryTree<T>&t)
	{
		if (&t != this)
		{
			if (NULL != m_root)
				Free(m_root);
			m_root=CreatTree(t.m_root);
		}
		return *this;
	}
	~BinaryTree()
	{
		if (NULL != m_root)
			Free(m_root);
	}


	//ˮƽ���
	void LevelOrder()
	{
		if (NULL == m_root)
			return;
		queue<BinaryNode<T>*>qu;
		qu.push(m_root);
		while (!qu.empty())
		{
			cout << qu.front()->_data << " ";
			BinaryNode<T>*pt = qu.front();
			qu.pop();
			if (NULL != pt->m_left)
				qu.push(pt->m_left);
			if (NULL != pt->m_right)
				qu.push(pt->m_right);
		}
	}

	//ǰ��������ݹ�ʵ��
	void FrontOrder(BinaryNode<T>*m_root)
	{
		if (NULL != m_root)
		{
			cout << m_root->_data << " ";
			FrontOrder(m_root->m_left);
			FrontOrder(m_root->m_right);
		}
	}

	



	//ǰ��������ǵݹ�ʵ��
	void Front()
	{
		if (NULL == m_root)
			return;
		stack<BinaryNode<T>*>v;
		v.push(m_root);
		while (!v.empty())
		{
			cout << v.top()->_data << " ";
			BinaryNode<T>*pt = v.top();
			v.pop();
			if (NULL != pt->m_right)
				v.push(pt->m_right);
			if (NULL != pt->m_left)
				v.push(pt->m_left);
		}
	}


	//����������ݹ�ʵ��
	void MidOrder(BinaryNode<T>*m_root)
	{
		if (NULL != m_root)
		{
			MidOrder(m_root->m_left);
			cout << m_root->_data << " ";
			MidOrder(m_root->m_right);
		}
	}

	//����������ǵݹ�ʵ��(�Լ�ʵ�ֵ�)
	void Mid()
	{
		if (NULL == m_root)
			return;
		stack<BinaryNode<T>*>s;
		s.push(m_root);
		while (!s.empty())
		{
			while (s.top()->m_left)
				s.push(s.top()->m_left);
			cout << s.top()->_data << " ";
			BinaryNode<T>*pt = s.top();
			s.pop();
			while (NULL == pt->m_right&&!s.empty())
			{
				cout << s.top()->_data<<" ";
				pt = s.top();
				s.pop();
			}
			if (pt->m_right)
				s.push(pt->m_right);
		}
	}
	//������������ô��룩
	void MidOrder2(BinaryNode<T>*root)
	{
		if (NULL == root)
			return;
		stack<BinaryNode<T>*>s;
		BinaryNode<T>*pCur = root;
		while (pCur || !s.empty())
		{
			while (pCur)
			{
				s.push(pCur);
				pCur = pCur->m_left;
			}
			BinaryNode<T>*pTop = s.top();
			cout << pTop->_data << " ";
			s.pop();
			if (pTop->m_right)
			{
				pCur = pTop->m_right;
			}
			
		}
	}

	//�����������ݹ�ʵ��
	void BackOrder(BinaryNode<T>*m_root)
	{
		if (NULL != m_root)
		{
			BackOrder(m_root->m_left);
			BackOrder(m_root->m_right);
			cout << m_root->_data << " ";
		}
	}

	//�������������ô���
	void BackOrder2(BinaryNode<T>*root)
	{
		if (NULL == root)
			return;
		stack<BinaryNode<T>*>s;
		BinaryNode<T>*pCur = root;
		BinaryNode<T>*perv = NULL;
		while (pCur || !s.empty())
		{
			while (pCur)
			{
				s.push(pCur);
				pCur = pCur->m_left;
			}
			BinaryNode<T>*pTop = s.top();
			if (NULL == pTop->m_right||pTop->m_right==perv)
			{
				cout << pTop->_data << " ";
				s.pop();
				perv = pTop;
			}
			else
				pCur = pTop->m_right;
		}
	}

	//��������ĸ߶�
	int TreeHighth(BinaryNode<T>*root)
	{
		if ( NULL == root)
			return 0;
		if (NULL == root->m_left&&NULL == root->m_right)
			return 1;
		int lefthigh = TreeHighth(root->m_left);
		int righthigh = TreeHighth(root->m_right);
		return lefthigh > righthigh ? lefthigh + 1 : righthigh + 1;
	}

	//Ҷ�ڵ����
	int NumLeaf(BinaryNode<T>*root)
	{
		if (NULL == root)
			return 0;
		if (NULL == root->m_left&&NULL == root->m_right)
			return 1;
		return NumLeaf(root->m_left) + NumLeaf(root->m_right);
	}

	//�ж������Ƿ��и�Ԫ��(����)
	bool IsInTreedata(BinaryNode<T>*root,T data)
	{
		if (NULL == root)
			return false;
		if (root->_data == data)
			return true;
		return IsInTreedata(root->m_left, data) || IsInTreedata(root->m_right, data);
	}
	//�ж������Ƿ��и�Ԫ��(ָ��)
	bool IsInTreep(BinaryNode<T>*root, BinaryNode<T>*pt)
	{
		if (NULL == root||NULL==pt)
			return false;
		if (root==pt)
			return true;
		return IsInTreep(root->m_left, pt) || IsInTreep(root->m_right, pt);
	}

	//Ѱ������Ϊdata�Ľڵ�
	BinaryNode<T>*FindData(BinaryNode<T>*root, T data)
	{
		if (NULL == root)
			return NULL;
		if (root->_data == data)
			return root;
		BinaryNode<T>*left;
		BinaryNode<T>*right;
		if (left=FindData(root->m_left, data))
			return left;
		if (right=FindData(root->m_right, data))
			return right;
		return NULL;
	}

	//Ѱ�ҵ�ַΪpt�Ľڵ�
	BinaryNode<T>*FindPos(BinaryNode<T>*root, BinaryNode<T>*pt)
	{
		if (NULL == root || NULL == pt)
			return NULL;
		if (pt == root)
			return pt;
		BinaryNode<T>*left;
		BinaryNode<T>*right;
		if (left = FindPos(root->m_left, pt))
			return left;
		if (right = FindPos(root->m_right, pt))
			return right;
		return NULL;
	}

	//Ѱ����������Ƚڵ�(�����)(������ΪB��A�ĸ��ڵ㣬B�����������游�ڵ�)
	BinaryNode<T>*GetLeastComment(BinaryNode<T>*root, BinaryNode<T>*p1, BinaryNode<T>*p2)
	{
		if (NULL == root || NULL == p1 || NULL == p2)
			return NULL;
		if (p1 == root || p2 == root)
			return NULL;
		if (root->m_left == p1 || root->m_right == p1 || root->m_right == p2 || root->m_left == p2)
			return root;
		bool l1 = IsInTreep(root->m_left, p1);
		bool r2 = IsInTreep(root->m_right, p2);
		bool l2 = IsInTreep(root->m_left, p2);
		bool r1 = IsInTreep(root->m_right, p1);
		if ((l1 && r2) || (l2 && r1))
			return root;
		if (l1&&l2)
			return GetLeastComment(root->m_left, p1, p2);
		if (r1&&r2)
			return GetLeastComment(root->m_right, p1, p2);
		return NULL;
	}

	//Ѱ����������Ƚڵ�(��·��1)
	//(������ΪB��A�ĸ��ڵ㣬B�����������游�ڵ�)
	bool GetPath2(BinaryNode<T>*root, BinaryNode<T>*node, vector<BinaryNode<T>*>&path)
	{
		if (NULL == root || NULL == node)
			return false;
		path.push_back(root);
		if (node == root)
			return true;
		if (GetPath2(root->m_left, node, path))
			return true;
		if (root->m_left)
			path.pop_back();
		if (GetPath2(root->m_right, node, path))
			return true;
		if (root->m_right)
			path.pop_back();
		return false;
	}

	BinaryNode<T>*GetCommenNode2(vector<BinaryNode<T>*>path1, vector<BinaryNode<T>*>path2)
	{
		if (path1.empty() && path2.empty())
			return NULL;
		while (!path1.empty()&&!path2.empty())
		{
			if (path1.size() > path2.size())
				path1.pop_back();
			else if (path1.size() < path2.size())
				path2.pop_back();
			else
			{
				if (path1.back() == path2.back())
					return path1.back();
				else
				{
					path1.pop_back();
					path2.pop_back();
				}
			}
		}
		return NULL;
	}

	BinaryNode<T>*GetLeastCommentNode2(BinaryNode<T>*root, BinaryNode<T>*left, BinaryNode<T>*right)
	{
		if (NULL == root || NULL == left || NULL == right)
			return NULL;
		vector<BinaryNode<T>*>path1;
		vector<BinaryNode<T>*>path2;
		GetPath2(root, left, path1);
		GetPath2(root, right, path2);
		return GetCommenNode2(path1, path2);
	}

	//Ѱ����������Ƚڵ�(��·��2)
	void GetPath(BinaryNode<T>*root, BinaryNode<T>*node, vector<BinaryNode<T>*>&path)
	{
		if (NULL == root)
			return;
		BinaryNode<T>*pCur = root;
		BinaryNode<T>*prev = NULL;
		while (!path.empty()||pCur)
		{
			while (pCur)
			{
				path.push_back(pCur);
				if (pCur == node)
					return;
				pCur = pCur->m_left;
			}
			BinaryNode<T>*pTop = path.back();
			if (NULL == pTop->m_right || prev == pTop->m_right)
			{
				path.pop_back();
				prev = pTop;
			}
			else
				pCur = pTop->m_right;
		}
	}

	BinaryNode<T>*GetCommenNode(vector<BinaryNode<T>*>path1, vector<BinaryNode<T>*>path2)
	{
		if (path1.empty() || path2.empty())
			return NULL;
		BinaryNode<T>*CommenNode = NULL;
		int len1 = path1.size()-1;
		int len2 = path2.size() - 1;
		int len = len1 > len2 ? len2 : len1;
		for (int i = 0; i < len; i++)
		{
			if (path1[i] == path2[i])
				CommenNode = path1[i];
		}
		return CommenNode;
	}
	BinaryNode<T>*GetLeastCommentNode(BinaryNode<T>*root, BinaryNode<T>*left, BinaryNode<T>*right)
	{
		if (NULL == root || NULL == left || NULL == right)
			return NULL;
		vector<BinaryNode<T>*>path1;
		vector<BinaryNode<T>*>path2;
		GetPath(root, left, path1);
		GetPath(root, right, path2);
		return GetCommenNode(path1, path2);
	}

	//��������ľ���
	void Mirror(BinaryNode<T>*root)
	{
		if (NULL == root||root->m_left==NULL||root->m_right==NULL)
			return;
		BinaryNode<T>*pt = root->m_left;
		root->m_left = root->m_right;
		root->m_right = pt;
		Mirror(root->m_left);
		Mirror(root->m_right);
	}

	//���񣨲������ʵ�֣�
	void Mirror2(BinaryNode<T>*root)
	{
		if (NULL == root || root->m_left == NULL || root->m_right == NULL)
			return;
		queue<BinaryNode<T>*>qu;
		qu.push(m_root);
		while (!qu.empty())
		{
			if (qu.front()->m_left)
				qu.push(qu.front()->m_left);
			if (qu.front()->m_right)
				qu.push(qu.front()->m_right);
			swap(qu.front()->m_left, qu.front()->m_right);
			qu.pop();
		}
	}

	//�ж��Ƿ�Ϊ��ȫ������(״̬)
	bool IsTatalTree()
	{
		if (NULL == m_root||(NULL==m_root->m_left&&NULL==m_root->m_right))
			return true;
		bool state = true;
		queue<BinaryNode<T>*>q;
		q.push(m_root);
		while (!q.empty())
		{
			if (q.front()->m_left)
			{
				q.push(q.front()->m_left);
				if (state == false)
					return false;
			}
			else
				state = false;
			if (q.front()->m_right)
			{
				q.push(q.front()->m_right);
				if (state == false)
					return false;
			}
			else
				state = false;
			q.pop();
		}
		return true;
	}

	//����ǰ�����򴴽�������
	BinaryNode<T>* CreatTreeWithPreIn(T*Pre, size_t presize, T*In, size_t insize)
	{
		size_t prestart = 0;
		size_t instart = 0;
		return _CreatTreeWithPreIn(Pre, presize, prestart, In, insize, instart);
	}

	BinaryNode<T>* _CreatTreeWithPreIn(T*Pre, size_t presize, size_t& prestart, T* In, size_t insize, size_t instart)
	{
		if (presize != insize || NULL == Pre || NULL == In )
			return NULL;
		T mid = Pre[prestart];
		size_t index = instart;
		while (index<instart+insize)
		{
			if (In[index] == mid)
				break;
			index++;
		}
		if (index >= insize+instart)
			return NULL;
		prestart++;
		BinaryNode<T>*root = new BinaryNode<T>(mid);
		
		if (index>instart)
		{
			root->m_left=_CreatTreeWithPreIn(Pre, index - instart, prestart, In, index - instart, instart);
		}
		if (index < insize+instart)
		{
			root->m_right=_CreatTreeWithPreIn(Pre, insize+instart-index-1, prestart, In, insize+instart-index-1, index + 1);
		}
		return root;
	}


private:
	void Free(BinaryNode<T>*&root)///////ע�������ã���ΪҪ�ı�ָ��
	{
		if (NULL != root)
		{
			Free(root->m_left);
			Free(root->m_right);
			delete root;
			root = NULL;
		}
	}

	BinaryNode<T>*CreatTree(BinaryNode<T>*root)
	{
		if (root != NULL)
		{
			BinaryNode<T>*NewRoot = new BinaryNode<T>(root->_data);
			NewRoot->m_left=CreatTree(root->m_left);
			NewRoot->m_right=CreatTree(root->m_right);
			return NewRoot;
		}
		return NULL;
	}

	void init(T arr[], BinaryNode<T>*&root,size_t size,size_t&index)
	{
		if (index<size&&arr[index]!='#')
		{
			root = new BinaryNode<T>(arr[index]);
			init(arr, root->m_left, size,++index);
			init(arr, root->m_right, size,++index);
		}
	}
public:
	BinaryNode<T>*m_root;
};

void test1()
{
	char arr[] = "013##4##25##6";
	BinaryTree<char> tree(arr, strlen(arr));
	BinaryTree<char> tree2(tree);
	BinaryTree<char> tree3(tree);
}
void test2()
{
	char arr[] = "013##4##25##6";
	BinaryTree<char> tree(arr, strlen(arr));
	BinaryNode<char>*p1 = tree.FindData(tree.m_root, '5');
	BinaryNode<char>*p2 = tree.FindData(tree.m_root, '2');
	BinaryNode<char>*p3 = tree.GetLeastCommentNode(tree.m_root, p1, p2);
	if (p3)
		cout << p3->_data;
}

void test3()
{
	char arr[] = "0137###4##25###";
	BinaryTree<char> tree(arr, strlen(arr));
	cout << tree.IsTatalTree();

}

void test4()
{
	char arr[] = "013##4##25##6";
	BinaryTree<char> tree(arr, strlen(arr));
	tree.Mirror2(tree.m_root);
}

void test5()
{
	char arr[] = "013##4##25##6";
	BinaryTree<char> tree(arr, strlen(arr));
	BinaryNode<char>*p1 = tree.FindData(tree.m_root, '5');
	BinaryNode<char>*p2 = tree.FindData(tree.m_root, '4');
	BinaryNode<char>*p3 = tree.GetLeastCommentNode2(tree.m_root, p1, p2);
	if (p3)
		cout << p3->_data;
}

void test6()
{
	char arr[] = "123##4##56##7##";
	BinaryTree<char> tree(arr, strlen(arr));
	char pre[] = "1234567";
	char in[] = "3241657";
	BinaryNode<char>*pt = tree.CreatTreeWithPreIn(pre, strlen(pre), in, strlen(in));
}

int main()
{
	test6();
	return 0;
}