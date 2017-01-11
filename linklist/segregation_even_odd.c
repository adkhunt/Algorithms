#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

void segregate_even_odd(Node **hptr)
{
	if((*hptr)->next == null)
		return;

Node *even = null;
Node *cur_even = null;
Node *cur = (*hptr)->next;
Node *pre = *hptr;

	while(cur)
	{
		if((cur->num&1) == 0)
		{
			if(even != null)
			{
				cur_even->next = cur;
				cur_even = cur_even->next;
				cur = cur->next;
			}

			else
			{
				even = cur;
				cur_even = cur;
				cur = cur->next;
			}

			pre->next = cur;
			cur = pre->next;
			cur_even->next = null;
		}

		else
		{
			pre = cur;
			cur = cur->next;
		}
	}

	if(((*hptr)->num&1) == 0)
	{
		Node *temp = *hptr;
		*hptr = (*hptr)->next;
		temp->next = even;
		even = temp;
	}

	if(*hptr == null)
		*hptr = even;

	else
		pre->next = even;
}

int main()
{
Node *hptr = null;
char ch;
int num;

	do{
		printf("Enter number in new node.\n");
		scanf("%d",&num);
		addAtEnd(&hptr,num);
		printf("Do you want to continue?(y/n)\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	print_list(hptr);
	segregate_even_odd(&hptr);
	print_list(hptr);

	return EXIT_SUCCESS;
}
