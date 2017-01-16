#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"tree.h"
#include"insert.h"

//////////////////////////////////////////////////////////
//							//
// Program to check if the given binary search tree is  //
// binary tree or not					//
//							//
//////////////////////////////////////////////////////////

int isValidateBst(struct node *root,int min,int max)		//min and max is limit for node data
{
	if(root == null)
		return 1;

	else if(root->num < min || root->num > max)		// if current number is less than min or greater than max than return 0
		return 0;

	int retl = isValidateBst(root->left,min,root->num);	//get left side value
	int retr = isValidateBst(root->right,root->num,max);	//get right side value

	return retl && retr;
}

int main()
{
struct node *root = null;

	root = insertTree();

	printInorderRecursive(root);
	printf("\n");
	
	if(isValidateBst(root,INT_MIN,INT_MAX))
		printf("Given tree is Binary search tree\n");

	else
		printf("Given tree is not Binary search tree\n");

	return EXIT_SUCCESS;
}
