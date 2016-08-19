#include "BRTree.h"

void test()
{
	BRTree<int, int>t;
	int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (int i = 0; i < 9; i++)
		t.Insert(arr[i], i);
	t.InOrder();
	cout << endl;
	cout << "ÊÇ·ñÊÇºìºÚÊ÷£º" << t.Isbalance() << endl;

}

int main()
{
	test();
	system("pause");
	return 0;
}