#include"header.h"

////////////////////////////////////////////////
//					      //
// Program to get minimum from the given tree //
//					      //
////////////////////////////////////////////////

int getMin(struct node *root)
{
	if(root == null)
		return;

	while(root->left)
		root = root->left;

	return root->num;
}

int main()
{
struct node *root = getTree();

	printInorderRecursive(root);
	printf("\n");
	
	int min = getMin(root);

	printf("Minimum in tree = %d\n",min);

	return EXIT_SUCCESS;
}
