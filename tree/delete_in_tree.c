#include"header.h"

////////////////////////////////////////
//				      //
// Program to delete number from tree //
//				      //
////////////////////////////////////////

struct node* getMin(struct node *root)
{

	while(root->left)
		root = root->left;

	return root;
}

struct node* deleteNode(struct node *root,int numToDelete)
{

	if(root == null)
		return root;

	if(root->num > numToDelete)
		root->left = deleteNode(root->left,numToDelete);

	else if(root->num < numToDelete)
		root->right = deleteNode(root->right,numToDelete);

	else{

		if(root->left == null)
		{
			struct node *temp = root->right;
			free(root);
			root = null;
			return temp;
		}

		else if(root->right == null)
		{
			struct node *temp = root->left;
			free(root);
			root = null;
			return temp;
		}

		else
		{
			struct node *temp = getMin(root->right);
			root->num = temp->num;
			root->right = deleteNode(root->right,temp->num);
		}
	}

	return root;
}

int main()
{
struct node *root = getTree();
int numToDelete;

	printInorderRecursive(root);
	printf("\n");
	printf("Enter number to delete.\n");
	scanf("%d",&numToDelete);

	root = deleteNode(root,numToDelete);
	printInorderRecursive(root);
	printf("\n");

	return EXIT_SUCCESS;
}
