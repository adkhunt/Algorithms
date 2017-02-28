#include<stdio.h>
#include<stdlib.h>

////////////////////////////////////////////////
//					      //
// Program to swap adjucent nodes in linklist //
//					      //
////////////////////////////////////////////////

struct node{
		int num;
		struct node *next;
};

struct node* get_new_node(int num)
{
	struct node *temp = (struct node*)
				malloc(sizeof(struct node));

	temp->num = num;
	temp->next = NULL;

	return temp;
}

void add_node_to_list(struct node **hptr,int num)
{
static struct node *pre = NULL;

	if(*hptr)
	{
		pre->next = get_new_node(num);
		pre = pre->next;
	}

	else{
		*hptr = get_new_node(num);
		pre = *hptr;
	}
}

void print_list(struct node *hptr)
{
	while(hptr)
	{	
		printf("%d ",hptr->num);
		hptr = hptr->next;
	}

	printf("\n");
}

void swap_adjcent_node(struct node **hptr)
{
	if(*hptr == NULL || (*hptr)->next == NULL)
		return ;

	struct node *cur = *hptr;
	*hptr = (*hptr)->next;
	cur->next = (*hptr)->next;
	(*hptr)->next = cur;

struct node *pre = cur->next;
struct node *nxt = pre->next;

	while(nxt)
	{
		pre->next = nxt->next;
		nxt->next = cur->next;
		cur->next = nxt;

		cur = pre;

		if(pre == NULL || pre->next == NULL)
			break;

		pre = pre->next;
		nxt = pre->next;
	}
}

int main()
{
struct node *hptr = NULL;
char ch;
int num;

	do{
		printf("Enter number to new node.\n");
		scanf("%d",&num);
		add_node_to_list(&hptr,num);
		printf("Do you want to continue?(Y/y)\n");
		scanf(" %c",&ch);
	}while(ch == 'Y' || ch == 'y');

	print_list(hptr);
	swap_adjcent_node(&hptr);
	print_list(hptr);

	return EXIT_SUCCESS;
}
