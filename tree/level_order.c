#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
#include"queue.h"
#define exit 0

////////////////////////////////////////////////
//					      //
// Program to print tree in level order (BFS) //
// Pattern travesal			      //
//					      //
////////////////////////////////////////////////

int getHeight(struct node *root)
{
	if(root == null)
		return 0;

	int lh = getHeight(root->left) + 1;
	int rh = getHeight(root->right) +1;

	return (lh > rh) ? lh : rh ;
}

void printLevel(struct node *root,int level,int cur_level)
{
	if(root == null)
		return;

	if(cur_level == level)
		printf("%d ",root->num);
	
	printLevel(root->left,level,cur_level+1);
	printLevel(root->right,level,cur_level+1);
}

void printLevelOrderRecursive(struct node *root)
{
int height = getHeight(root);
int i;

	for(i = 0 ; i < height ; ++i)
	{
		printLevel(root,i,0);
		printf("\n");
	}

}

void countNodes(struct node *root,int *count)
{
	if(root == null)
		return;

	++(*count);

	countNodes(root->left,count);
	countNodes(root->right,count);
}

void printLevelOrder(struct node *root)
{
int nodes = 0;

	countNodes(root,&nodes);
	Queue *q = create_queue(nodes);

	enqueue(q,root);

	while(!isQueueEmpty(q))
	{
		root = dequeue(q);
		printf("%d ",root->num);

		if(root->left)
			enqueue(q,root->left);
		if(root->right)
			enqueue(q,root->right);
	}

	printf("\n");
}

int main()
{
struct node *root = getTree();

	printInorderRecursive(root);
	printf("\n");
	printLevelOrder(root);		// Print the levels in O(n) time
	printLevelOrderRecursive(root); // Print the levels in O(n2) time

	return exit;
}
