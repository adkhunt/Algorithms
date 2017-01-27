#include<stdio.h>

///////////////////////////////////////////
//					 //
// Program to check if entered number is //
// Pelindrome or not			 //
//					 //
///////////////////////////////////////////

int checkPelindrom(int num)
{
int rem,sum = 0,temp = num;

	while(temp)
	{
		rem = temp%10;
		sum = (sum*10) + rem;
		temp /= 10;
	}

	return sum == num;
}

int main()
{
int num;

	printf("Enter number to check pelindrom.\n");
	scanf("%d",&num);

	if(checkPelindrom(num))
		printf("%d is pelindrome number.\n",num);
	
	else
		printf("%d is not pelindrom number.\n",num);

	return 0;
}
