#include<stdio.h>
#include<stdlib.h>
#include"string.h"
#include"stackString.h"

int my_strlen(char *str)
{
int i = 0;

	while(str[i])
		++i;

	return i;
}

bool checkSame(char a,char b)
{
	if(a == ')' && b == '(')
		return true;

	else if(a == '}' && b == '{')
		return true;

	else if(a == ']' && b == '[')
		return true;

	return false;
}

void checkParanthesis(char *str)
{
int i;
stack *s = create_stack(my_strlen(str));

	for(i = 0 ; str[i] ; ++i)
	{
		if(str[i] == '(' || str[i] == '{' || str[i] == '[')
			push(s,str[i]);

		else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			if(!checkSame(str[i],pop(s)))
			{
				printf("Unbalance Paranthesis found.\n");
				return;
			}
		}
	}

	if(isEmpty(s))
		printf("Balanced paranthesis string.\n");

	else 
		printf("Unbalanced Paranthesis found.\n");
}

int main()
{
char *str = getString();

	printf("String = %s\n",str);

	checkParanthesis(str);

	return EXIT_SUCCESS;
}
