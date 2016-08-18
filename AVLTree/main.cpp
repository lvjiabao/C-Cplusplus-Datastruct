#include "AVLTree.h"

void test()
{
	AVLTree<int, int>tree;
	int arr[] = { 16, 3, 7, 11, 9, 2, 6, 18, 14, 15 };
	for (int i = 0; i < 10; i++)
		tree.Insert(arr[i], i);
	tree.InOrder();
	cout << endl;
	cout << "是否为平衡树：" << tree.Isbalance() << endl;


	AVLTree<int, int>tree1;
	int arr1[] = { 4,2,6,1,3,5 ,15,7,16,14};
	for (int i = 0; i < 9; i++)
		tree1.Insert(arr1[i], i);
	tree1.InOrder();
	cout << endl;
	cout << "是否为平衡树：" << tree1.Isbalance() << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}