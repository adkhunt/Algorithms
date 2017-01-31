#include"header.h"

//////////////////////////////////////////
//					//
// Program to find distance between two	//
// Nodes in tree			//
//					//
//////////////////////////////////////////

void distance(struct node *root,int num1,int num2,int *d1,int*d2,int level)	// get the distance of nodes from root
{
	if(root == null)
		return;

	if(root->num == num1)
		*d1 = level;

	if(root->num == num2)
		*d2 = level;

	distance(root->left,num1,num2,d1,d2,level+1);
	distance(root->right,num1,num2,d1,d2,level+1);
}

struct node* lca(struct node *root,int num1,int num2)	// Return the lowest common ancentor
{
	if(root == null)
		return root;

	if(root->num == num1 || root->num == num2)
		return root;

	struct node *lr = lca(root->left,num1,num2);
	struct node *rr = lca(root->right,num1,num2);

	if(lr&&rr)
		return root;

	return lr ? lr : rr;
}

int findLevel(struct node *root,int num,int level)	// get the level of given node from the root
{
	if(root == null)
		return 0;

	if(root->num == num)
		return level;

	int lh = findLevel(root->left,num,level+1);
	int rh = findLevel(root->right,num,level+1);

	return lh ? lh : rh;
}

int getDistance(struct node *root,int num1,int num2) //Util function get the distance between two nodes
{
int d1 = 0 , d2 = 0;

	distance(root,num1,num2,&d1,&d2,0);
	struct node *ret = lca(root,num1,num2);

	int level = findLevel(root,ret->num,0);

	return (d1+d2)-(2*level);
}

int main()
{
struct node *root = getTree();
int num1,num2;

	printInorderRecursive(root);
	printf("\n");

	printf("Enter two numbers to get distance.\n");
	scanf("%d%d",&num1,&num2);

	int distance = getDistance(root,num1,num2);

	printf("Total Distance = %d\n",distance);

	return exit;
}
