#include<stdio.h>
#define exit 0

///////////////////////////////////////
//				     //
// Program to print fibonacci series //
//				     //
///////////////////////////////////////

int printFibonacciRecursive(int num) // Recursice way to print fibonacci series
{
	if(num <= 1)
		return num;

	return printFibonacciRecursive(num-1)+printFibonacciRecursive(num-2);
}

void printFibonacci(int num) //Iterative way to print fibonacci series
{
int pre = 0,cur = 1,next = 1;
int i;

	printf("%d ",pre);
	printf("%d ",cur);

	for(i = 0 ; i < num ; ++i)
	{
		printf("%d ",pre+cur);
		pre = cur;
		cur = next;
		next = pre+cur;
	}

	printf("\n");
}

int main()
{
	printFibonacci(12);
int i;

	for(i = 0 ; i < 12 ; ++i)
		printf("%d ",printFibonacciRecursive(i));
	printf("\n");

	return exit;
}
