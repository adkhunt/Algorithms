#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

//Program to modify the binary tree node with the sum of its greater node

///////////////////////////////////////////////////////////////////
//								 //
/* Below function will modify the tree in O(n) time Complexity   */
//								 //
///////////////////////////////////////////////////////////////////

void replaceWithSum(struct node *root,int *sum)		//this function will take advantage of inorder traversal in reverse order
{
	if(root == null)
		return;

	replaceWithSum(root->right,sum);		// we start from right side of tree
	*sum = *sum+root->num;
	root->num = *sum;
	replaceWithSum(root->left,sum);
}

void Modify_tree_in_on(struct node *root)
{
	if(root == null)
		return;

int sum = 0;

	replaceWithSum(root,&sum);
}

////////////////////////////////////////////////////////////////////////
//						      		      //
/* Below two function will modify the tree in O(n2) time Complexity   */
//								      //
////////////////////////////////////////////////////////////////////////

void getGreaterValueSum(struct node *root,int num,int *sum)
{
	if(root == NULL)
		return;

	if(root->num > num)
		*sum = *sum+root->num;

	getGreaterValueSum(root->left,num,sum);
	getGreaterValueSum(root->right,num,sum);
}

void Modify_tree_in_on2(struct node *root,struct node *cur)		//Here We traverse in order whole tree
{
	if(cur == NULL)
		return;
int sum = 0;
	
	Modify_tree_in_on2(root,cur->left);
	getGreaterValueSum(root,cur->num,&sum);
	printf("%d ",sum+cur->num);
	Modify_tree_in_on2(root,cur->right);
}

int main()
{
struct node *root = null;
char ch;
int num;

	do{
		insertInTree(&root);
		printf("Do you want to continue?(y/n)\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	printInorderRecursive(root);
	printf("\n");

	Modify_tree_in_on2(root,root);
	printf("\n");

	Modify_tree_in_on(root);
	printInorderRecursive(root);
	printf("\n");

	return EXIT_SUCCESS;
}
