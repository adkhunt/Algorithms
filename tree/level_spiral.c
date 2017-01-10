#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

//prints two level from left to right and one level right to left

int height_tree(struct node *root)
{
	if(root == NULL)
		return 0;

	int lh = height_tree(root->left)+1;	//return the left height of sub tree
	int rh = height_tree(root->right)+1;	//return the right heigth of the sub tree

	return lh > rh ? lh : rh;		//return the max of right and left height
}

void print_spiral(struct node *root,int level_monitor,int level)
{

	if(root == NULL)
		return;

	if(level == 1)						//if level is equal to one than prints the value
		printf("%d ",root->num);

	if(level_monitor == 0 || level_monitor == 1)		//if level is zero or one than print from left to right
	{
		print_spiral(root->left,level_monitor,level-1);
		print_spiral(root->right,level_monitor,level-1);
	}

	else							//if level is two than print from right to left
	{
		print_spiral(root->right,level_monitor,level-1);
		print_spiral(root->left,level_monitor,level-1);
	}
}

void print_spiral_order(struct node *root)
{
int level_monitor = 0;
int i;

	int height = height_tree(root);			//get the height of tree
	
	for(i = 1 ; i <= height ; ++i)			//iterate through all level
	{
		print_spiral(root,level_monitor,i);
		++level_monitor;
		if(level_monitor == 3)			//if level_monitor reaches to three than we reset it
			level_monitor = 0;
	}
}

int main()					//Main driver function
{
struct node *root = NULL;
char ch;

	do{
		insertInTree(&root);
		printf("Do you want to continue?(y/n)\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	print_spiral_order(root);
	printf("\n");

	free(root);

	return EXIT_SUCCESS;
}
