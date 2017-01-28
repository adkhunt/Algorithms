#include<stdio.h>
#include<stdlib.h>
#define exit 0
#define null NULL

////////////////////////////////////////////////
//					      //
// Double link-list using single next pointer //
// Using XOR operation			      //
//					      //
////////////////////////////////////////////////

struct node{
		int num;
		struct node *xor;
};

struct node* getNewNode(int num)
{
	struct node *temp = (struct node*)
				malloc(sizeof(struct node));

	temp->num = num;
	temp->xor = null;

	return temp;
}

struct node* getNextNode(struct node *cur, struct node *pre)
{
	return (struct node*) ((unsigned int) (cur) ^ (unsigned int) (pre));
}

void addNode(struct node **root)
{
int num;

	printf("Enter numebr in new node.\n");
	scanf("%d",&num);

	struct node *newNode = getNewNode(num);
	newNode->xor = getNextNode(*root,null);

	if(*root)
	{
		struct node* next = getNextNode((*root)->xor,  NULL);
	        (*root)->xor = getNextNode(newNode, next);	
	}

	*root = newNode;
}

void print_list(struct node *hptr)
{
struct node *cur = hptr;
struct node *pre = null;
struct node *nxt = null;

	while(cur)
	{
		nxt = getNextNode(cur->xor,pre);
		printf("%d ",cur->num);
		pre = cur;
		cur = nxt;
	}

	printf("\n");
}

int main()
{
struct node *hptr = null;
char ch;

	do{
		addNode(&hptr);
		printf("Do you want to continue?\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');	

	print_list(hptr);

	return exit;
}
