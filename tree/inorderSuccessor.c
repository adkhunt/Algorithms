#include"header.h"

////////////////////////////////////////////////////
//						  //
// Get Inorder predecessor and successor of given //
// Number					  //
//						  //
////////////////////////////////////////////////////

int getMin(struct node *root)
{
	while(root->right)
		root = root->right;

	return root->num;	
}

int getMinLeft(struct node *root)
{
	while(root->left)
		root = root->left;

	return root->num;
}

int getSuccessor(struct node *root,int num)
{
	if(root == null)
		return;

	if(root->num == num)
	{
		return getMinLeft(root->right);
	}

struct node *pre = null;

	while(root)
	{
		if(root->num > num)
		{
			pre = root;
			root = root->left;
		}

		else if(root->num < num)
			root = root->right;

		else break;
	}

	if(root->right)
		return getMinLeft(root->right);

	if(pre)
		return pre->num;

	else
		printf("No such number present in tree.\n");
		return 0;
}

int getPredecessor(struct node *root,int num)
{
	if(root == null)
	{
		printf("Root is null.\n");
		return 0;
	}

	if(root->num == num)
	{
		int min = getMin(root->left);
		return min;
	}

struct node *pre = null;

	while(root)
	{
		if(root->num > num)
			root = root->left;

		else if(root->num < num)
		{
			pre = root;
			root = root->right;
		}

		else 
			break;
	}

	if(root == null)
	{
		printf("No such number found.\n");
		return 0;
	}

	if(root->left)
		return getMin(root->left);

	else if(pre)
		return pre->num;

	else
		return root->num;

}

int main()
{
struct node *root = getTree();
int num;

	printInorderIterative(root);
	
	printf("Enter number to get Inorder successor and predecessor.\n");
	scanf("%d",&num);

	int predecessor = getPredecessor(root,num);
	int successor = getSuccessor(root,num);

	printf("Predecessor = %d\n",predecessor);
	printf("Successor = %d\n",successor);

	return EXIT_SUCCESS;
}
