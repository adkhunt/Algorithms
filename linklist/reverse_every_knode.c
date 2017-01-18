#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

Node* swapNodes(Node *hptr,int k)
{
int i = 0;

Node *cur = hptr;
Node *pre = null;
Node *nxt = hptr->next;

	while(i<k && cur)
	{
		nxt = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nxt;
		++i;
	}

	if(nxt!=null)
		hptr->next = swapNodes(nxt,k);
	return pre;
}

int main()
{
Node *hptr = get_list();
int k;

	print_list(hptr);
	printf("Enter k value to swap nodes.\n");
	scanf("%d",&k);

	hptr = swapNodes(hptr,k);
	print_list(hptr);	

	return EXIT_SUCCESS;
}
