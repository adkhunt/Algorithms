#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
#define null NULL

struct node* minRight(struct node *root)
{
struct node *min = root->right;

	while(min->left)
	{
		min = min->left;
	}

	return min;
}

struct node* get_successor(struct node *root,int num)
{
	if(root == null)
		return root;

struct node *ret = root;

	if(root->num == num)
		return minRight(root);

	while(root)
	{
		if(root->num > num)
		{
			ret = root;
			root = root->left;
		}

		else if(root->num < num)
			root = root->right;

		else 
			break;
	}

	return ret;
}

int main()
{
struct node *root = null;
char ch;
int succ;

	do{
		insertInTree(&root);
		printf("Do you want to continue?(y/n)\n");
		scanf(" %c",&ch);
	}while(ch=='y' || ch == 'Y');

	printInorderRecursive(root);
	printf("\n");

	printf("Enter the successor you want to find..\n");
	scanf("%d",&succ);
	struct node *successor = get_successor(root,succ);

	printf("Inorder successor of %d is %d\n",succ,successor->num);

	return EXIT_SUCCESS;
}
