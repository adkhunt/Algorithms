#include<stdio.h>
#include<stdlib.h>
#include"stackInt.h"

////////////////////////////////////////////////////////
//						      //
// Program to reverse stack without using extra space //
//						      //
////////////////////////////////////////////////////////

void insertStack(stack *s,int num)
{
	if(isEmpty(s))
	{
		push(s,num);
	}

	else
	{
		int temp = pop(s);
		insertStack(s,num);
		push(s,temp);
	}
	
}

void reverseStack(stack *s)
{

	if(isEmpty(s))
		return;

	int temp = pop(s);
	reverseStack(s);
	insertStack(s,temp);
}

int main()
{
stack *s = create_stack(6);

	push(s,1);
	push(s,2);
	push(s,3);
	push(s,4);
	printStack(s);
	reverseStack(s);
	printStack(s);

	return EXIT_SUCCESS;
}
