#include<stdio.h>
#include<stdbool.h>
#define EXIT_SUCCESS 0

bool isArmstrong(int num)
{
int sum = 0,temp = num,rem;

	while(temp)
	{
		rem = temp%10;
		sum+= (rem*rem*rem);
		temp/=10;
	}

	return sum == num ? true : false;
}

int main()
{
int num;

	printf("Enter number to check if its armstrong or not.\n");
	scanf("%d",&num);

	if(isArmstrong(num))
		printf("%d is armgstong number.\n",num);

	else
		printf("Not armstrong number.\n");

	return EXIT_SUCCESS;
}
