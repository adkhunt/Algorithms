#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

////////////////////////////////////////////////////
//						  //
// Program to for i=1 to n/2, subtract (n-i)th 	  //
// number from ith number in O(n) time complexity //
// Note : Only works for even numbers of nodes    //
//						  //
////////////////////////////////////////////////////

Node* substractList(Node *hptr,Node *last)
{
struct node *ret = null;
static int i = 1;

	if(last == null)
		return hptr;

	ret = substractList(hptr,last->next);

	if((ret != last) && i)
	{
		ret->num = ret->num - last->num;
		return ret->next;
	}

	else
		i = 0;
}

int main()
{
Node *hptr = get_list();

	print_list(hptr);
	substractList(hptr,hptr);

	print_list(hptr);

	return EXIT_SUCCESS;
}
