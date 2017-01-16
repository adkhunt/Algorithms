#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

////////////////////////////////////////////////////////
//						      //
// This program will convert the original BST to it's //
// Mirror Image Tree 				      //
//						      //
////////////////////////////////////////////////////////

void makeMirrorTree(struct node *root)		//We start with post order traversal
{
	if(root == null)			//if root is null than we simply return
		return;

	makeMirrorTree(root->left);		//this two step is for post order traversal
	makeMirrorTree(root->right);

	struct node *temp = root->left;		//we swap the left and right node of current node
	root->left = root->right;
	root->right = temp;
}

int main()
{
struct node *root = null;
char ch;

	do{
		insertInTree(&root);
		printf("Do you want to continue?(y/Y)");
		scanf(" %c",&ch);
	}while(ch=='y' || ch =='Y');

	printInorderRecursive(root);
	printf("\n");
	makeMirrorTree(root);
	printf("Mirror tree is : ");
	printInorderRecursive(root);
	printf("\n");

	return EXIT_SUCCESS;
}
