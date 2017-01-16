#include<stdio.h>
#define EXIT_SUCCESS 0

int my_strlen(char *binary)
{
int i;
	for(i = 0 ; binary[i] ; ++i);

	return i;
}

int get_decimal(char *binary)
{
int buff,decimal=0,i,j=1;
int len = my_strlen(binary)-1;

	for(i = len ; i>=0 ; --i)
	{
		buff = binary[i] - 48;
		buff = j*buff;
		decimal += buff;
		j *= 2;
	}

	return decimal;
}

int main()
{
char binary[32];

	printf("Enter number in binary format.\n");
	scanf("%s",binary);
	
	int decimal = get_decimal(binary);

	printf("decimal = %d\n",decimal);	

	return EXIT_SUCCESS;
}
