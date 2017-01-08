#include<stdio.h>
#include<string.h>
#define EXIT_SUCCESS 0

void sortStringArray(char stringArray[26][5],int size)
{
int i;
int data[26] = {0}; 						 //store the starting character index

	for(i = 0 ; i < 26 ; ++i)
	{
		int temp = stringArray[i][0]-97;
		data[temp] = i;					// build look up table for accessing the character using index
	}

	for(i = 0 ; i < 26 ; ++i)
		printf("%d ",data[i]);
	printf("\n");

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
char stringArray[26][5] = {"pefb","gnms","flmr","cfgo","tmnf","vqrh","xuvj","zyzl",
			    "jstv","dhip","bden","ejkq","myzy","nabz","kuvw","iqru",
		  	    "hopt","abcm","qghc","lwxx","ywxk","wsti","uopg","rijd","ocda","skle"};

	sortStringArray(stringArray,26);

	return EXIT_SUCCESS;
}
