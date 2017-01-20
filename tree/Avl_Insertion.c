#include<stdio.h>
#include<stdlib.h>
#define null NULL

struct node{
		int num;
		struct node *right;
		struct node *left;
		int height;
};

int max(int a,int b)
{
	return (a>b) ? a : b;
}

int Height(struct node *root)
{
	if(root == null)
		return 0;

	return root->height;
}

int getHeight(struct node *root)
{
	return max(Height(root->left),Height(root->right))+1;
}

int getBalance(struct node *root)
{
	if(root == null)
		return 0;

	return (Height(root->left)-Height(root->right));
}

struct node* rightRotate(struct node *root)
{
	struct node *newRoot = root->left;
	root->left = newRoot->right;
	newRoot->right = root;

	root->height = getHeight(root);
	newRoot->height = getHeight(newRoot);

	return newRoot;
}

struct node* leftRotate(struct node *root)
{
	struct node *newRoot = root->right;
	root->right = newRoot->left;
	newRoot->left = root;

	root->height = getHeight(root);
	newRoot->height = getHeight(newRoot);

	return newRoot;
}

struct node* getNewNode(int num)
{
	struct node *ret = (struct node*) malloc(sizeof(struct node));

	ret->num = num;
	ret->right = null;
	ret->left = null;
	ret->height = 0;

	return ret;
}

struct node* insertNode(struct node *root,int num)
{
	if(root == null)
		return (getNewNode(num));

	if(root->num > num)
		root->left = insertNode(root->left,num);

	else if(root->num < num)
		root->right = insertNode(root->right,num);

	else
		return root;

	root->height = getHeight(root);

	int bal = getBalance(root);

	if(bal > 1 && num < root->left->num)
		return rightRotate(root);
	
	if(bal < -1 && num > root->right->num)
		return leftRotate(root);
	
	if(bal > 1 && num > root->left->num)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if(bal < -1 && num < root->right->num)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void printInorder(struct node *root)
{
	if(root == null)
		return;

	printInorder(root->left);
	printf("%d ",root->num);
	printInorder(root->right);
}

void printPostorder(struct node *root)
{
	if(root == null)
		return;

	printPostorder(root->left);
	printPostorder(root->right);
	printf("%d ",root->num);
}

void printPreorder(struct node *root)
{
	if(root == null)
		return;

	printf("%d ",root->num);
	printPreorder(root->left);
	printPreorder(root->right);
}

int main()
{
struct node *root = null;
char ch;
int num;

	do{
		printf("Enter data in new node.\n");
		scanf("%d",&num);
		root = insertNode(root,num);
		printf("Do you want to continue?(Y/y)");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	printf("\n");
	printPreorder(root);
	printf("\n=================\n");
	printInorder(root);
	printf("\n=================\n");
	printPostorder(root);
	printf("\n");

	return EXIT_SUCCESS;
}
