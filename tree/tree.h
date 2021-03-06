#ifndef tree
#define tree

#include"queue.h"
#include"stack.h"

#define null NULL

typedef struct node{
		int num;
		struct node *right,*left;
} node;

node* get_new_node(int num)
{
	node *ret = (node*) malloc(sizeof(node));

	ret->num = num;
	ret->right = ret->left = NULL;

	return ret;
}

void BuildTree(node **root,int num)
{

	node *new_node = get_new_node(num);

	if(*root)
	{
		node *cur = *root;
		node *pre = cur;

		while(cur)
		{
			pre = cur;

			if(cur->num >= num)
				cur = cur->left;

			else
				cur = cur->right;
		}

		if(pre->num >= num)
			pre->left = new_node;

		else
			pre->right = new_node;
	}

	else{

		*root = new_node;
	}
}

void insertInTree(node **root)
{
int num;

	printf("Enter number in new node.\n");
	scanf("%d",&num);

	BuildTree(root,num);
}

node* getTree()
{
node *root = null;
char ch;

	do{
		insertInTree(&root);
		printf("Do you want to continue?(y/Y)\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	return root;
}

node* getReadyTree(void)
{
node *root = null;
int arr[12] = {10,7,3,1,6,4,18,15,14,25,22,28}, i;

	for(i = 0 ; i < 12 ; ++i)
		BuildTree(&root,arr[i]);

	return root;
}

void printInorderRecursive(node *root)
{
	if(root)
	{
		printInorderRecursive(root->left);
		printf("%d ",root->num);
		printInorderRecursive(root->right);
	}
}

void printPostorderRecursive(node *root)
{
	if(root)
	{
		printPostorderRecursive(root->left);
		printPostorderRecursive(root->right);
		printf("%d ",root->num);
	}
}

void printPreorderRecursive(node *root)
{
	if(root)
	{
		printf("%d ",root->num);
		printPreorderRecursive(root->left);
		printPreorderRecursive(root->right);
	}
}

void printInorderIterative(node *root) // Morris Traversaal
{
	if(root == NULL)
		return;		//Base Case

	while(root != NULL)
	{
		if(root->left == NULL)
		{
			printf("%d ",root->num);
			root = root->right;
		}

		else{
			node *pre = root->left;

			while(pre->right != NULL && pre->right != root)
				pre = pre->right;

			if(pre->right ==  NULL)
			{
				pre->right = root;
				root = root->left;
			}

			else if(pre->right == root)
			{
				pre->right = NULL;
				printf("%d ",root->num);
				root = root->right;
			}
		}
	}

	printf("\n");
}

void printInorderStack(node *root)
{
Stack *s = create_stack(15);

	while(1)
	{
		if(root)
		{
			push(s,root);
			root = root->left;
		}

		else
		{
			if(isEmpty(s))
				break;

			root = pop(s);
			printf("%d ",root->num);
			root = root->right;
		}
	}

	printf("\n");
}

void printPreorderIterative(node *root)
{
	if(root == NULL)
		return;

Stack *s = create_stack(20);		//assume that tree element size is les than 20 // if size is more than 20 replace 20 ..

	push(s,root);

	while(!isEmpty(s))
	{
		root = pop(s);
		printf("%d ",root->num);
		
		if(root->right)
			push(s,root->right);

		if(root->left)
			push(s,root->left);
	}

	printf("\n");
}

void printPostorderIterative(node *root)
{

	if(root == NULL)
		return;

Stack *s = create_stack(20);
Stack *storeTraversal = create_stack(20);

	push(s,root);

	while(!isEmpty(s))
	{
		root = pop(s);
		push(storeTraversal,root);

		if(root->left)
			push(s,root->left);

		if(root->right)
			push(s,root->right);
	}

	while(!isEmpty(storeTraversal))
	{
		root = pop(storeTraversal);

		printf("%d ",root->num);
	}

	printf("\n");
}

#endif
