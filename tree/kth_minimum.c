#include"header.h"

//////////////////////////////////////////
//					//
// Program to find the kth minimum from //
// Tree					//
//					//
//////////////////////////////////////////

void getNumber(struct node *root,int k,int *count,int *res)
{
	if(root == null)
		return;

	getNumber(root->left,k,count,res);
	++(*count);

	if(*count == k)
	{
		*res = root->num;
		return;
	}

	getNumber(root->right,k,count,res);
}

void kthNumber(struct node *root,int k)
{
int count = 0,res = 0;

	getNumber(root,k,&count,&res);

	printf("%d \n",res);
}

int main()
{
struct node *root = getTree();
int k;

	printInorderRecursive(root);
	printf("\n");

	printf("Enter k value to find minimum.\n");
	scanf("%d",&k);

	kthNumber(root,k);

	return exit;
}
