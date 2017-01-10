#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void sortStringArray(char **stringArray,int size)
{
int i;
int data[26] = {0}; 						 //store the starting character index

	for(i = 0 ; i < 26 ; ++i)
	{
		int temp = stringArray[i][0]-97;
		data[temp] = i;					// build look up table for accessing the character using index
	}

	i = 0;
	int j = 0;

	while(i<26)						//iterate through whole array
	{
		printf("%s\n",stringArray[data[j]]);		//print the current string
		int len = strlen(stringArray[data[j]])-1;	//get last character of current string
		j = (int) stringArray[data[j]][len]-97;		//get index of string array from look up table
		++i;						//increment variable
	}
}

int main()
{
char **stringArray = NULL,ch;
int i,j=0;

	stringArray = (char**) malloc(sizeof(char*)*26);
		
	for(i = 0 ; i < 26 ; ++i)
	{
		printf("Enter %d Stirng..\n",i+1);
		j = 0;
		stringArray[i] = (char*) malloc(sizeof(char)*1);

		while((ch=getc(stdin))!='\n'){
			++j;
			stringArray[i][j-1] = ch;
			stringArray[i] = realloc(stringArray[i],j);
		}			
	}

	sortStringArray(stringArray,26);

	for(i =0 ;i < 26; ++i)
		free(stringArray[i]);

	free(stringArray);

	return EXIT_SUCCESS;
}
