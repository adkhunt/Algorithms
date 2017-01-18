#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

void findCycle(Node *hptr)
{

	if(hptr == null)
		return;

Node *slow = hptr;
Node *fast = hptr->next;

	while(fast!=null && fast!=slow)
	{
		slow = slow->next;
		fast = fast->next;
		if(fast)
			fast = fast->next;
	}

	if(fast == null)
		printf("No cycle found in linklist.\n");

	else if(fast == slow)
		printf("Cycle found at %p node.\n",fast);
}

int main()
{
Node *hptr = null;
char ch;
int num;

	do{
		printf("Enter number in node.\n");
		scanf("%d",&num);
		addAtEnd(&hptr,num);
		printf("Do you want to continue?(Y/y)\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	findCycle(hptr);

	return EXIT_SUCCESS;
}
