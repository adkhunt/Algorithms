#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

Node* getMiddle(Node *hptr)
{
	if(hptr == null)
		return;

	Node *slow = hptr;
	Node *fast = hptr->next;

	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next;
		if(fast)
			fast = fast->next;
	}

	return slow;
}

int main()
{
Node *hptr = null;
char ch;
int num;

	do{
		printf("Enter number in node\n");
		scanf("%d",&num);
		addAtEnd(&hptr,num);
		printf("Do you want to continue?\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	print_list(hptr);
	Node *ret = getMiddle(hptr);

	printf("Midlle = %d\n",ret->num);

	return EXIT_SUCCESS;
}
