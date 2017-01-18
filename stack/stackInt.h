#ifndef stackInt
#define stackInt

#include<stdbool.h>

typedef struct Stack{
			int start,limit;
			int *data;
} stack;

stack* create_stack(int size)
{
stack *ret = NULL;

	ret = (stack*) malloc(sizeof(stack));

	ret->limit = size;
	ret->start = -1;
	ret->data = (int*) calloc(size,sizeof(int));

	return ret;
}

void push(stack *s,int num)
{
	if(s->start < s->limit-1)
		s->data[++s->start] = num;

	else
		printf("Stack is full.\n");
}

int pop(stack *s)
{
	if(s->start >= 0)
	{
		return s->data[s->start--];
	}

	else
		printf("Stack is empty.\n");
}

int top(stack *s)
{
	if(s->start >= 0)
		return s->data[s->start];

	else
		printf("stack is empty.\n");
}

bool isEmpty(stack *s)
{
	return s->start == -1;
}

void printStack(stack *s)
{
int i;

	if(s->start != -1)
	{
		for(i = 0 ; i <= s->start ; ++i)
			printf("%d ",s->data[i]);
		printf("\n");
	}

	else
	{
		printf("Nothing to print.\n");
	} 
}

#endif
