#include "bloom.h"

void test()
{
	Bloom<>coll(1000);
	char*arr1 = "iofawioaifbiaeygrapqopwougfraifsabgafsa";
	char*arr2 = "ibfawioaifbiaeygrapqopwougfraifsabgafsa";
	char*arr3 = "icfawioaifbiaeygrapqopwougfraifsabgafsa";
	char*arr4 = "ÍõĞ¡½¹";
	char*arr5 = "ÂÀĞ¡½¹";
	coll.Set(arr1);
	coll.Set(arr2);
	coll.Set(arr4);
	coll.Set(arr5);
	cout << "arr1:" << coll.Test(arr1) << endl;
	cout << "arr2:" << coll.Test(arr2) << endl;
	cout << "arr3:" << coll.Test(arr3) << endl;
	cout << "arr4:" << coll.Test(arr4) << endl;
	cout << "arr5:" << coll.Test(arr5) << endl;

}

int main()
{
	test();
	system("pause");
	return 0;
}