#include<stdio.h>
#include<stdlib.h>
#define exit 0
#define null NULL

////////////////////////////////////////////
//					  //
// Program to find the next grater number //
// from given digits			  //
// 					  //
////////////////////////////////////////////

int my_strlen(char *str)
{
int i;

	for(i = 0 ; str[i] ; ++i);

	return i;
}

void swap(char *a,char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void sort(char *str,int start,int end)
{
int i,j;

	for(i = start ; i <= end ; ++i)
	{
		for(j = i+1 ; j <= end ; ++j)
		{
			if(str[i] > str[j])
				swap(&str[i],&str[j]);
		}
	}
}

void getNextGreaterNumber(char *num)
{
int len = my_strlen(num)-1;
int i = len;

	while(i > 0)
	{
		if(num[i] > num[i-1])
			break;
		--i;
	}

	if(i == 0)
	{
		printf("No next number is possible.\n");
		return;
	}

	int curNum = num[i-1],index = i,j;

	for(j = i+1 ; j <= len ; ++j)
		if(curNum < num[j] && num[index] > num[j])
			index = j;

	swap(&num[index],&num[i-1]);
	sort(num,i,len);
}

char* getNumber(void)
{
int i = 0;
char ch;

	char *ret = malloc(sizeof(char));

	while((ch=fgetc(stdin)) != '\n')
	{
		ret[i] = ch;
		++i;
		ret = realloc(ret,i+1);
	}

	ret[i] = '\0';
	return ret;
}

int main()
{
char *num = getNumber();

	printf("num = %s\n",num);
	getNextGreaterNumber(num);
	printf("num = %s\n",num);

	return exit;
}
