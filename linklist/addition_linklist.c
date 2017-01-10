#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"
#define null NULL

Node* make_link(char *str)		//this function convert character array to linklist
{
int i = 0,temp;
Node *ret = null;

	while(str[i])
	{
		temp = str[i]-48;	//convert character to integer
		addAtEnd(&ret,temp);	//add that number to link
		++i;
	}

	return ret;			//return generater linklist head pointer
}

Node* ReverseList(Node *list)		//recursive function to reverse linklist
{
	if(list == null || list->next == null)
		return list;

	Node *temp = ReverseList(list->next);

	list->next->next = list;
	list->next = null;

	return temp;
}

Node* add(Node *link1,Node *link2)	//add function to add two linklist
{
Node *result = null;
int sum,carry = 0;

	link1 = ReverseList(link1);	//reverse both linklist b'cause we'r starting adding them from end
	link2 = ReverseList(link2);

	while(link1 && link2)		//if any one of them list reaches to null we came out from loop
	{
		sum = link1->num + link2->num + carry;		//take sum of both number and carry
		carry = sum>9 ? 1 : 0;				//if number is greater than 9 than we take carry as 1
		sum = sum>9 ? sum%10 : sum;			//and make number as module

		addAtEnd(&result , sum);
		link1 = link1->next;
		link2 = link2->next;
	}

	while(link1)		//if link2 reaches to null than we continue with link1
	{
		sum = link1->num + carry;
		carry = sum > 9 ? 1 : 0;
		sum = sum>9 ? sum%10 : sum;

		addAtEnd(&result , sum);
		link1 = link1 ->next;
	}

	while(link2)		//if link1 reaches to null than we coninue with link2
	{
		sum = link2->num + carry;
		carry = sum > 9 ? 1 : 0;
		sum = sum>9 ? sum%10 : sum;

		addAtEnd(&result,sum);
		link2 = link2->next;
	}

	if(carry == 1)
	{
		addAtEnd(&result,carry);
	}

	result = ReverseList(result);	//reverse the resultant link 

	return result;
}

int main()
{
char *num1 = NULL,*num2 = NULL,ch;
int i = 0;
	
	num1 = (char*) malloc(sizeof(char));
	num2 = (char*) malloc(sizeof(char));

	printf("Enter first very long number.\n");

	while((ch = getc(stdin))!= '\n')		// store the number as string form
	{
		num1[i] = ch;
		++i;
		num1 = (char*) realloc(num1,sizeof(char)*(i+1));
	}

	printf("Enter second number..\n");
	i = 0;

	while((ch = getc(stdin))!= '\n')
	{
		num2[i] = ch;
		++i;
		num2 = (char*) realloc(num2,sizeof(char)*(i+1));
	}
	
	Node *link1 = make_link(num1);	//make link of string
	Node *link2 = make_link(num2);

	Node *result = add(link1,link2);

	print_list(result);	//printing the linklist

	free(num1);
	free(num2);
	free(link1);
	free(link2);
	free(result);

	return EXIT_SUCCESS;
}
