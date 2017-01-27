#include<stdio.h>
#include<stdlib.h>
#define null NULL

///////////////////////////////////
//				 //
// Program to insert in AVL tree //
//				 //
///////////////////////////////////

struct node{
		int num,height;		//Height will store the current height at node
		struct node *right;
		struct node *left;
};

struct node* getNewNode(int num)
{
	struct node *ret = (struct node*)
				malloc(sizeof(struct node));
	ret->height = 0;
	ret->num = num;
	ret->right = null;
	ret->left = null;

	return ret;
}

int max(int a,int b)			// return maximum of two integer
{
	return a > b ? a : b;			
}

int Height(struct node *root)		// return the current height of node
{
	if(root == null)
		return 0;

	return root->height;
}

int getHeight(struct node *root) 	// get height max of left or right height
{	
	return max(Height(root->left),Height(root->right))+1;
}

int balance(struct node *root)		// return difference of left and right height
{
	return Height(root->left) - Height(root->right);
}

struct node* rotateRight(struct node *root)	// perform right rotation on node
{
	struct node *newRoot = root->left;
	root->left = newRoot->right;
	newRoot->right = root;

	newRoot->height = getHeight(newRoot);
	root->height = getHeight(root);

	return newRoot;
}

struct node* rotateLeft(struct node *root)	// perform left rotation on sub-tree
{
	struct node *newRoot = root->right;
	root->right = newRoot->left;
	newRoot->left = root;

	newRoot->height = getHeight(newRoot);
	root->height = getHeight(root);

	return newRoot;
}

struct node* addTree(struct node *root,int num)	//this function to insert node in tree
{
	if(root == null)
		return getNewNode(num);

	else if(root->num > num)
		root->left = addTree(root->left,num);

	else if(root->num < num)
		root->right = addTree(root->right,num);

	else
		return root;

	root->height = getHeight(root);

	int bal = balance(root);

	//left left case
	if(bal > 1 && root->left->num > num)
		return rotateRight(root);

	//Right Right case
	else if(bal < -1 && root->right->num < num)
		return rotateLeft(root);

	//left Right case
	else if(bal > 1 && root->left->num < num)
	{
		root->left = rotateLeft(root->left);
		return rotateRight(root);
	}

	//right left case
	else if(bal < -1 && root->right->num > num)
	{
		root->right = rotateRight(root->right);
		return rotateLeft(root);
	}

	return root;
}

int heightTree(struct node *root)		// return height of whole tree
{
	if(root ==  null)
		return 0;

	int lh = heightTree(root->left) + 1;
	int rh = heightTree(root->right) + 1;

	return max(lh,rh);
}

void print(struct node *root,int level,int cur_level)
{
	if(root == null)
		return;

	if(level == cur_level)
		printf("%d ",root->num);

	print(root->left,level,cur_level+1);
	print(root->right,level,cur_level+1);
}

void printLevel(struct node *root)		// print level order traversal
{
int i,height = heightTree(root);

	for(i = 0 ; i < height ; ++i)
	{
		print(root,i,0);
		printf("\n");
	}
}

int main()
{
struct node *root = null;
int numToInsert;
char ch;

	do{
		printf("Enter number in node.\n");
		scanf("%d",&numToInsert);
		root = addTree(root,numToInsert);
		printf("Do you want to continue?\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	printLevel(root);

	return EXIT_SUCCESS;
}
