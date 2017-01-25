#include<stdio.h>
#include<stdlib.h>

#define null NULL
#define exit 0

///////////////////////////////////////////
//					 //
// Program to convert DLL to Bst inplace //
//					 //
///////////////////////////////////////////

struct node{
		int num;
		struct node *next;
		struct node *pre;
};

struct node* getNode(int num)
{
	struct node *ret = (struct node*)
				malloc(sizeof(struct node));

	ret->num = num;	
	ret->next = null;
	ret->pre = null;

	return ret;
}

void addAtEnd(struct node **hptr)
{
int num;

	printf("Enter number in new node.\n");
	scanf("%d",&num);

	if(*hptr == null || (*hptr)->num > num)
	{
		if(*hptr)
		{
			struct node *temp = getNode(num);
			temp->next = *hptr;
			(*hptr)->pre = temp;
			*hptr = temp;
		}

		else
			*hptr = getNode(num);
	}

	else
	{
		struct node *cur = *hptr;
		struct node *temp = getNode(num);

		while(cur)
		{
			if(cur->num > num)
			{
				temp->next = cur;
				cur->pre->next = temp;
				temp->pre = cur->pre;
				cur->pre = temp;
				break;
			}

			else if(cur->next == null)
			{
				temp->pre = cur;
				cur->next = temp;
				break;
			}
		
			cur = cur->next;
		}
	}
}

void printDll(struct node *hptr)
{
	while(hptr)
	{
		printf("%d ",hptr->num);
		hptr = hptr->next;
	}

	printf("\n");
}

int countNode(struct node *hptr)
{
int i = 0;

	while(hptr)
	{
		++i;
		hptr = hptr->next;
	}

	return i;
}

struct node* getBst(struct node **hptr,int n)
{
	if(n <= 0)
		return null;

	struct node *left = getBst(hptr,n/2);

	struct node *root = *hptr;
	root->pre = left;

	*hptr = (*hptr)->next;

	root->next = getBst(hptr,n-n/2-1);

	return root;
}

struct node* convertBst(struct node **hptr)
{
	int count = countNode(*hptr);

	return getBst(hptr,count);
	
}

void printTree(struct node *root)
{
	if(root == null)
		return;

	printTree(root->pre);
	printf("%d ",root->num);
	printTree(root->next);
}

int main()
{
struct node *hptr = null;
char ch;

	do{
		addAtEnd(&hptr);
		printf("Do you want to continue.\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	printDll(hptr);

	hptr = convertBst(&hptr);

	printTree(hptr);
	printf("\n");

	return exit;
}
