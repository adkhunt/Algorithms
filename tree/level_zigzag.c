#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
#include"stack.h"
#include"queue.h"
#define exit 0

/////////////////////////////////////////////
//					   //
// Program to print levels in zigzag order //
//					   //
/////////////////////////////////////////////

void countNode(struct node *root,int *count)
{
	if(root == null)
		return;

	++(*count);

	countNode(root->left,count);
	countNode(root->right,count);
}

void printTreeZigzag(struct node *root)
{
int count = 0;

	countNode(root,&count);

Stack *s = create_stack(count);
Stack *s1 = create_stack(count);

	push(s,root);

	while(!isEmpty(s) || !isEmpty(s1))
	{
		while(!isEmpty(s))
		{
			root = pop(s);
			printf("%d ",root->num);

			if(root->left)
				push(s1,root->left);

			if(root->right)
				push(s1,root->right);
		}

		while(!isEmpty(s1))
		{
			root = pop(s1);

			printf("%d ",root->num);

			if(root->right)
				push(s,root->right);
			if(root->left)
				push(s,root->left);
		}
	}

	printf("\n");
}

int getHeight(struct node *root)
{
	if(root == null)
		return 0;

	int lh = getHeight(root->left) + 1;
	int rh = getHeight(root->right) + 1;

	return (lh >rh) ? lh : rh;
}

void printFromLeft(struct node *root,int level,int cur_level)
{
	if(root == null)
		return;

	if(level == cur_level)
		printf("%d ",root->num);

	printFromLeft(root->left,level,cur_level+1);
	printFromLeft(root->right,level,cur_level+1);
}

void printFromRight(struct node *root,int level,int cur_level)
{
	if(root == null)
		return;

	if(level == cur_level)
		printf("%d ",root->num);

	printFromRight(root->right,level,cur_level+1);
	printFromRight(root->left,level,cur_level+1);
}

void printTreeZigZagRecursion(struct node *root)
{
int height = getHeight(root);
int i;
bool var = true;

	for(i = 0 ; i < height ; ++i)
	{
		if(var)
		{
			printFromLeft(root,i,0);
		}

		else
		{
			printFromRight(root,i,0);
		}

		printf("\n");

		var = !var;
	}
}

int main()
{
struct node *root = getTree();

	printInorderIterative(root);
	printTreeZigzag(root);		// Print tree in O(n) time
	printTreeZigZagRecursion(root);	// Print levels in zigzag fashion in O(n2) time

	return exit;
}
