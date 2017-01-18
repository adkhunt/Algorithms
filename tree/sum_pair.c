#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

////////////////////////////////////////////////////
//						  //
// Program to get the sum of pair of given number //
//						  //
////////////////////////////////////////////////////

void getSum(struct node *cur,struct node *root,int res)
{
	if(root == null)
		return;

	if(root->num + cur->num == res)
	{
		printf("%d and %d is pair.\n",root->num,cur->num);
	}

	getSum(cur,root->left,res);
	getSum(cur,root->right,res);
}

void getPair_On2(struct node *cur,struct node *root,int num) //this function will give pair of sum in O(n2) time
{
	if(cur == null)
		return;

	getSum(cur,root,num);
	getPair_On2(cur->left,root,num);
	getPair_On2(cur->right,root,num);
}

void convert_dll(struct node *root,struct node **tail,struct node **head)	//convert tree to double linklist
{
	if(root == null)
		return;

	convert_dll(root->left,tail,head);

	root->left = null;

	if(*tail)
	{
		root->left = *tail;
		(*tail)->right = root;
	}

	else
		*head = root;

	*tail = root;

	convert_dll(root->right,tail,head);
}

void getPair_On(struct node *root,int num)	//this function will give the pair of sum in O(n) time
{
	if(root == null)
		return;

struct node *tail = null;
struct node *head = null;

	convert_dll(root,&tail,&head);		

	tail = head;

	while(tail->right)
		tail = tail->right;

	while(head != tail)
	{
		if(head->num + tail -> num == num)
		{
			printf("%d + %d = %d\n",head->num,tail->num,num);
			tail = tail -> left;
			head = head->right;
		}

		else if(head->num + tail->num > num)
			tail = tail -> left;

		else
			head = head->right;
	}
}

int main()
{
struct node *root = getTree();
int num;

	printInorderRecursive(root);
	printf("\n");

	printf("Enter number to get sum pair.\n");
	scanf("%d",&num);

	getPair_On2(root,root,num);
	printf("\n==========\n");
	getPair_On(root,num);
	printf("\n");

	return EXIT_SUCCESS;
}
