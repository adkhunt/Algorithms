#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
#include"insert.h"

int getHeight(struct node *root)
{
	if(root == null)
		return 0;

	int lh = 1 + getHeight(root->left);
	int rh = 1 + getHeight(root->right);

	return lh > rh ? lh : rh;
}

int main()
{
struct node *root = insertTree();

	int height = getHeight(root);

	printf("Height = %d\n",height);

	return EXIT_SUCCESS;
}
