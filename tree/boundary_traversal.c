#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

///////////////////////////////////////
//				     //
// Program to print Boundary of tree //
//  				     //
///////////////////////////////////////

void printLeftBoundary(struct node *root) //print left side boundary
{
	if(root == null)
		return;

	printf("%d ",root->num);
	printLeftBoundary(root->left);
}

void printBottom(struct node *root)	//print bottom of the tree
{
	if(root == null)
		return;

	printBottom(root->left);
	
	if(root->right == null && root->left == null)
		printf("%d ",root->num);

	printBottom(root->right);
}

void printRightBoundary(struct node *root)	//print right side of boundary
{
	if(root == null)
		return;

	printRightBoundary(root->right);
	printf("%d ",root->num);
}

void print_boundary(struct node *root)
{

	printf("%d ",root->num);

	printLeftBoundary(root->left);
	printBottom(root);
	printRightBoundary(root->right);
	printf("\n");
}

int main()
{
struct node *root = getTree();

	print_boundary(root);

	return EXIT_SUCCESS;
}
