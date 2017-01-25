#include"header.h"

//////////////////////////////////////////////////
//						//
// Program to recorrect the binary search tree  //
// Whose two nodes are swapped each-other	//
//						//
//////////////////////////////////////////////////

void correctTree(struct node *root,struct node **first,struct node **second)
{
	if(root == null || root->right == null || root->left == null)
		return ;

	if(root->left->num > root->num)
		*first = root;

	if(root->right->num < root->num)
		*second = root;

	correctTree(root->left,first,second);
	correctTree(root->right,first,second);
}

void rearrangeTree(struct node *root)
{
struct node *first = null;
struct node *second = null;

	correctTree(root,&first,&second);

	if(first && second)
	{
		int temp = first->num;
		first->num = second->num;
		second->num = temp;
	}
}

int main()
{
struct node *root = get_new_node(6);
    root->left        = get_new_node(10);
    root->right       = get_new_node(2);
    root->left->left  = get_new_node(1);
    root->left->right = get_new_node(3);
    root->right->right = get_new_node(12);
    root->right->left = get_new_node(7);

	printInorderRecursive(root);
	printf("\n");
	rearrangeTree(root);
	printInorderRecursive(root);
	printf("\n");

	return EXIT_SUCCESS;
}
