#include"header.h"

//////////////////////////////////////////////
//					    //
// Program to get lowest common ancentor of //
// Two numbers in tree			    //
//					    //
//////////////////////////////////////////////

struct node* getLCA(struct node *root,int num1,int num2)
{

	if(root == null)
		return root;

	if(root->num == num1 || root->num == num2)
		return root;

	struct node *lr = getLCA(root->left,num1,num2);
	struct node *rr = getLCA(root->right,num1,num2);

	if(lr && rr)
		return root;

	else 
		return lr ? lr : rr;
}

int main()
{
struct node *root = getTree();
int num1,num2;

	printInorderIterative(root);
	
	printf("Enter two numbers to get its LCA.\n");
	scanf("%d%d",&num1,&num2);

	struct node *ret = getLCA(root,num1,num2);

	printf("Lowest Common Ancentor = %d\n",ret->num);

	return EXIT_SUCCESS;
}
