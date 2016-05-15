#include "List.h"


int main()
{
	pList pHead;
	init_list(&pHead);

	/*pushfront(&pHead, 2);
	print_list(pHead);

	Pushback(&pHead, 2);
	Pushback(&pHead, 3);
	print_list(pHead);

	Pushback(&pHead, 4);
	print_list(pHead);

	popback(&pHead);
	popback(&pHead);
	popback(&pHead);
	print_list(pHead);

	popback(&pHead);
	print_list(pHead);

	pushfront(&pHead, 1);
	pushfront(&pHead, 2);
	pushfront(&pHead, 3);
	pushfront(&pHead, 4);
	print_list(pHead);

	popfront(&pHead);
	popfront(&pHead);
	popfront(&pHead);
	print_list(pHead);

	popfront(&pHead);
	print_list(pHead);

	pushfront(&pHead, 1);
	pushfront(&pHead, 2);
	pushfront(&pHead, 3);
	pushfront(&pHead, 4);
	insert(&pHead,search(&pHead, 1),18);
	print_list(pHead);


	deletepos(&pHead, search(&pHead,4));
	print_list(pHead);

	deletedata(&pHead,7);
	print_list(pHead);

	pushfront(&pHead, 2);
	pushfront(&pHead, 2);
	pushfront(&pHead, 2);
	pushfront(&pHead, 2);
	print_list(pHead);
	deletealldata(&pHead, 6);
	print_list(pHead);


	pushfront(&pHead, 1);
	pushfront(&pHead, 2);
	pushfront(&pHead, 3);
	pushfront(&pHead, 4);
	Printbth(pHead);*/

	/*pushfront(&pHead, 1);
	pushfront(&pHead, 2);
	pushfront(&pHead, 3);
	pushfront(&pHead, 4);
	deletedata(&pHead, search(&pHead, 1));
	print_list(pHead);*/

	/*pushfront(&pHead, 2);
	pushfront(&pHead, 3);
	pushfront(&pHead, 4);
	pushfront(&pHead, 5);
	pushfront(&pHead, 6);
	pushfront(&pHead, 7);
	deletenotendnode(search(&pHead, 5));
	print_list(pHead);*/

	/*pushfront(&pHead, 3);
	pushfront(&pHead, 4);
	pushfront(&pHead, 5);
	pushfront(&pHead, 6);
	pushfront(&pHead, 7);
	print_list(pHead);
	insertnotfirstnode(search(&pHead,4), 18);
	print_list(pHead);*/

	/*pushfront(&pHead, 3);
	pushfront(&pHead, 4);
	pushfront(&pHead, 5);
	pushfront(&pHead, 6);
	pushfront(&pHead, 7);
	pushfront(&pHead, 8);
	pushfront(&pHead, 9);
	pushfront(&pHead, 10);
	pushfront(&pHead, 11);
	pushfront(&pHead, 12);
	printf("%d", midnode(&pHead));*/

	pushfront(&pHead, 4);
	pushfront(&pHead, 5);
	pushfront(&pHead, 4);
	pushfront(&pHead, 4);
	pushfront(&pHead, 8);
	deletedata(&pHead, 8);
	print_list(pHead);





	return 0;
}