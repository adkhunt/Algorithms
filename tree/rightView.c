#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

/////////////////////////////////////
//				   //
// Print right view of binary tree //
//				   //
/////////////////////////////////////

void printView(struct node *root,int cur_level,int *level)
{
	if(root == null)
		return;

	if(cur_level > *level)
	{
		*level = cur_level;
		printf("%d ",root->num);
	}

	printView(root->right,cur_level+1,level);
	printView(root->left,cur_level+1,level);
}

void printRightView(struct node *root)
{
int level = 0;

	printf("%d ",root->num);
	printView(root,0,&level);
	printf("\n");
}

int main()
{
struct node *root = getTree();

	printRightView(root);

	return EXIT_SUCCESS;
}
