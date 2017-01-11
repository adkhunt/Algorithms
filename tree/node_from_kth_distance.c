#include"header.h"

void printKthDistance(struct node *root,int distance)
{
	if(root == null)
		return;

	if(distance == 0)
		printf("%d ",root->num);

	printKthDistance(root->left,distance-1);
	printKthDistance(root->right,distance-1);
}

int main()
{
struct node *root = null;
char ch;
int distance;

	do{
		insertInTree(&root);
		printf("Do you want to continue??\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	printf("Enter distance to print nodes from root.\n");
	scanf("%d",&distance);

	printKthDistance(root,distance);
	printf("\n");

	return EXIT_SUCCESS;
}
