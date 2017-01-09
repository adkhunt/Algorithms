#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

void tree_bfs(struct node *root)
{
	if(root == NULL)
		return;

	
}

int main()
{
struct node *root = NULL;
char ch;

	do{
		insertInTree(&root);
		printf("Do you want to continue?(Y/n)\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');


	return EXIT_SUCCESS;
}
