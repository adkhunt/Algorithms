#include"header.h"

////////////////////////////////////////////////
//					      //
// Program to convert tree to double linklist //
// Inplace				      //
//					      //
////////////////////////////////////////////////

void getDll(struct node *root,struct node **head,struct node **tail)
{
	if(root == null)
		return;

	getDll(root->left,head,tail);

	if(*head)
	{
		(*tail)->right = root;
		root->left = *tail;
	}

	else
		*head = root;

	*tail = root;

	getDll(root->right,head,tail);
}

void convert_dll(struct node **root)
{
struct node *head = null;
struct node *last = null;

	getDll(*root,&head,&last);
	*root = head;
}

void printDll(struct node *root)
{
	while(root)
	{
		printf("%d ",root->num);
		root=root->right;
	}

	printf("\n");
}

int main()
{
struct node *root = getTree();

	printInorderRecursive(root);
	printf("\n");

	convert_dll(&root);

	printDll(root);

	return exit;
}
