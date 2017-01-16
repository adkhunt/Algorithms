#include<stdio.h>
#include<stdbool.h>
#define EXIT_SUCCESS 0

//////////////////////////////////////////
//					//
// Program to check if given number is  //
// armstrong number or not		//
//					//
//////////////////////////////////////////

bool isArmstrong(int num)
{
int sum = 0,temp = num,rem;

	while(temp)
	{
		rem = temp%10;		//take single digit from number
		sum+= (rem*rem*rem);	//make cube of that number and add to sum
		temp/=10;		//remove element which already counted
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
