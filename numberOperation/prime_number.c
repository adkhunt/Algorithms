#include<stdio.h>
#define EXIT_SUCCESS 0

int isPrime(int num)
{
int i;

	for(i = 2 ; i < num ; ++i)
	{
		if(num % i == 0)
			break;
	}

	return i == num ? 1 : 0;
}

int main()
{
int num;

	printf("Enter number to check if prime or not.\n");
	scanf("%d",&num);

	if(isPrime(num))
		printf("%d is prime number.\n",num);

	else
		printf("%d is not prime number.\n",num);
	
	return EXIT_SUCCESS;
}
