#include<stdio.h>

//////////////////////////////////////////////////
//						//
// Program to check if number is perfect or not //
//						//
//////////////////////////////////////////////////

int isPerfect(int num)
{
int rem,sum = 0,i;

	for(i = 1 ; i < num ; ++i)
	{
		if(num%i == 0)
			sum += i;
	}

	return sum == num;
}

int main()
{
int num;

	printf("Enter number to check if its perfect or not.\n");
	scanf("%d",&num);

	if(isPerfect(num))
		printf("%d is perfect number.\n",num);

	else
		printf("%d is not perfect number.\n",num);

	return 0;
}
