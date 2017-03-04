#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////
//							//
// Program to count the minimum change to convert first //
// String to second string				//
//							//
//////////////////////////////////////////////////////////

int min(int a,int b,int c)
{
	return (a < b) ? (a < c) ? a : c : (b < c) ? b : c;
}

int my_strlen(char *str)
{
int i;

	for(i = 0 ; str[i] ; ++i);

	return i;
}

int minimum_edit_distance(char *str1,char *str2)
{
int len1 = my_strlen(str1);
int len2 = my_strlen(str2);
int mat[len1+1][len2+1],i,j;

	for(i = 0 ; i <= len1 ; ++i)
		mat[i][0] = i;

	for(i = 0 ; i <= len2 ; ++i)
		mat[0][i] = i;

	for(i = 1 ; i<=len1 ; ++i)
	{
		for(j = 1 ; j<=len2 ; ++j)
		{
			if(str1[i-1] != str2[j-1])
				mat[i][j] = min(mat[i-1][j-1],mat[i-1][j],mat[i][j-1]) + 1;

			else
				mat[i][j] = mat[i-1][j-1];
		}
	}

	return mat[len1][len2];
}

char* get_string(void)
{
int i = 0;
char *str = NULL,ch;

	str = (char*) malloc(sizeof(char));

	while((ch = fgetc(stdin)) != '\n')
	{
		str[i] = ch;
		++i;
		str = (char*) realloc(str,i+1);
	}

	str[i] = '\0';

	return str;
}

int main()
{
char *str1 = NULL,*str2 = NULL;

	printf("Enter two string to find minimum edit distance\n");
	str1 = get_string();
	str2 = get_string();

	printf("String1 = %s\n",str1);
	printf("String2 = %s\n",str2);

	int minimum_edit = minimum_edit_distance(str1,str2);

	printf("Minimum Edit = %d\n",minimum_edit);

	return EXIT_SUCCESS;
}
