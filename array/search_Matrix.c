#include"header.h"

///////////////////////////////////////////////////
//						 //
// Program to find an element in strickly sorted //
// (Row & coloumn) matrix in O(n) time		 //
//						 //
///////////////////////////////////////////////////

void isPresent(int **mat,int size,int num)
{
int i = 0, j = size-1;

	while(i < size && j >= 0)
	{
		if(mat[i][j] == num)
		{
			printf("%d is found at mat[%d][%d]\n",num,i,j);
			return;
		}

		else if(mat[i][j] > num)
			--j;

		else
			++i;
	}

	printf("Number not found in matrix.\n");
}

int main()
{
int **mat = null;
int size,i,j,num;

	printf("Enter square matrix size.\n");
	scanf("%d",&size);
	
	mat = (int**) malloc(sizeof(int*)*size);
	for(i = 0 ; i < size ; ++i)
		mat[i] = (int*) malloc(sizeof(int)*size);

	printf("Enter element in row and coloum wise sorted manner.\n");
	for(i = 0 ; i < size ; ++i)
		for(j = 0 ; j < size ; ++j)
			scanf("%d",&mat[i][j]);

	printf("Enter number to search.\n");
	scanf("%d",&num);

	isPresent(mat,size,num);

	return EXIT_SUCCESS;
}
