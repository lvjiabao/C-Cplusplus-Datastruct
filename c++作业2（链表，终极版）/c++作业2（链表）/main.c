#include "List.h"
int cmp(const void*elem1, const void*elem2)
{
	return ((pList)elem2)->data - ((pList)elem1)->data;
}

int main()
{
	pList pHead;
	init_list(&pHead);
	pList pHead2;
	init_list(&pHead2);
	Pushback(&pHead, 1);
	Pushback(&pHead, 2);
	Pushback(&pHead, 2);
	Pushback(&pHead, 2);
	Pushback(&pHead, 6);
	Pushback(&pHead, 6);
	Pushback(&pHead2, 1);
	Pushback(&pHead2, 2);
	Pushback(&pHead2, 3);
	Pushback(&pHead2, 4);
	Pushback(&pHead2, 5);
	Pushback(&pHead2, 6);
	UnionSet(&pHead, &pHead2);

	return 0;
}