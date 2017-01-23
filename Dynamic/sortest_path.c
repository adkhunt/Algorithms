#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////
//						//
// Program to find the minimum path cost to re- //
// ach at the last index of matrix in O(n2) 	//
//						//
//////////////////////////////////////////////////

void printMatrix(int **mat,int size)		// Print the matrix
{
int i,j;

	for(i = 0 ; i < size ; ++i)
	{
		for(j = 0 ; j < size ; ++j)
			printf("%d ",mat[i][j]);
		
		printf("\n");
	}
}

int min(int a,int b,int c)			// Return minimum of three number
{
	return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}

int countMinimumPath(int **mat,int size)
{
int temp[size][size],i,j;

	temp[0][0] = mat[0][0];

	for(i = 1 ; i < size ; ++i)
	{
		temp[0][i] = mat[0][i]+temp[0][i-1];
		temp[i][0] = mat[i][0]+temp[i-1][0];
	}

	for(i = 1 ; i < size ; ++i)
	{
		for(j = 1 ; j < size ; ++j)
		{
			temp[i][j] = min(temp[i][j-1],temp[i-1][j],temp[i-1][j-1])+mat[i][j];
		}
	}

	return temp[size-1][size-1];
}

int main()
{
int **mat = NULL;
int size,i,j;

	printf("Enter size of square matrix.\n");
	scanf("%d",&size);

	mat = (int**) malloc(sizeof(int*)*size);
	for(i = 0 ; i < size ; ++i)
		mat[i] = (int*) malloc(sizeof(int)*size);

	printf("Enter element in array. : ");
	for(i = 0 ; i < size ; ++i)
		for(j = 0 ; j < size ; ++j)
			scanf("%d",&mat[i][j]);

	printMatrix(mat,size);
	int res = countMinimumPath(mat,size);

	printf("minimum path-cost to reach at end = %d\n",res);

	return EXIT_SUCCESS;
}
