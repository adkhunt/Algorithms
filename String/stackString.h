#ifndef stackString
#define stackString

#include<stdbool.h>

typedef struct Stack{
			int size,start;
			char *arr;
} stack;

stack* create_stack(int size)
{
	stack *ret = (stack*) malloc(sizeof(stack));

	ret->size = size;
	
	ret->start = -1;
	ret->arr = (char*) malloc(sizeof(char)*size);

	return ret;
}

void push(stack *s,char ch)
{
	if(s->start != s->size)
	{
		s->arr[++s->start] = ch;
	}

	else
	{
		printf("STACK IS FULL.\n");
		return;
	}
}

char pop(stack *s)
{
	if(s->start != -1)
	{
		return s->arr[s->start--];
	}

	else
	{
		printf("STACK IS EMPTY.\n");
		return 0;
	}
}

bool isEmpty(stack *s)
{
	return s->start == -1;
}

#endif
