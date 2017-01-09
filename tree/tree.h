#ifndef tree
#define tree

#include"stack.h"
#include"queue.h"

struct node{
		int num;
		struct node *right,*left;
};

struct node* get_new_node(int num)
{
	struct node *ret = (struct node*) malloc(sizeof(struct node));

	ret->num = num;
	ret->right = ret->left = NULL;

	return ret;
}

void insertInTree(struct node **root)
{
int num;

	printf("Enter number in new node..\n");
	scanf("%d",&num);

	struct node *new_node = get_new_node(num);

	if(*root)
	{
		struct node *cur = *root;
		struct node *pre = cur;

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

void printInorderRecursive(struct node *root)
{
	if(root)
	{
		printInorderRecursive(root->left);
		printf("%d ",root->num);
		printInorderRecursive(root->right);
	}
}

void printPostorderRecursive(struct node *root)
{
	if(root)
	{
		printPostorderRecursive(root->left);
		printPostorderRecursive(root->right);
		printf("%d ",root->num);
	}
}

void printPreorderRecursive(struct node *root)
{
	if(root)
	{
		printf("%d ",root->num);
		printPreorderRecursive(root->left);
		printPreorderRecursive(root->right);
	}
}

void printInorderIterative(struct node *root) // Morris Traversaal
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
			struct node *pre = root->left;

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

void printPreorderIterative(struct node *root)
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

void printPostorderIterative(struct node *root)
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
