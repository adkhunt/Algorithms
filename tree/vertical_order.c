#include"header.h"

///////////////////////////////////////////////////
//						 //
// Program to print tree in vertical level order //
//						 //
///////////////////////////////////////////////////

void getMinMax(struct node *root,int *min,int *max,int level)
{
	if(root == null)
		return;

	if(level < *min)
		*min = level;

	else if(level > *max)
		*max = level;

	getMinMax(root->left,min,max,level-1);
	getMinMax(root->right,min,max,level+1);
}

void printVertical(struct node *root,int level,int cur_level)
{
	if(root == null)
		return;

	if(level == cur_level)
		printf("%d ",root->num);

	printVertical(root->left,level,cur_level-1);
	printVertical(root->right,level,cur_level+1);
}

void printVerticalOrder(struct node *root)
{
int min = 0,max = 0,i;

	getMinMax(root,&min,&max,0);

	for(i = min ; i <= max ; ++i)
	{
		printVertical(root,i,0);
		printf("\n");
	}
}

int main()
{
struct node *root = getTree();

	printInorderIterative(root);
	printf("\n======= Vertical Order ========\n");
	printVerticalOrder(root);

	return exit;
}
