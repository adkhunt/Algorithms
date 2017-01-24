#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

////////////////////////////////////
//				  //
// Program to free whole linklist //
//				  //
////////////////////////////////////

void free_list(Node **list)
{
struct node *temp = null;
struct node *cur = *list;

	while(cur)
	{
		temp = cur->next;
		free(cur);
		cur = null;
		cur = temp;
	}

	free(*list);
	*list = null;
}

int main()
{
Node *list = get_list();

	print_list(list);
	free_list(&list);
	printf("list = %p\n",list);

	return EXIT_SUCCESS;
}
