#include<stdio.h>
#include<stdbool.h>

#define EXIT_SUCCESS 0
#define N 4

/*
 * Program to solve the n queen problem
 * using backtracking
 */

/*
 * This function will print the matrix
 */

void print_matrix(int mat[N][N])
{
int i,j;

	for(i = 0 ; i < N ; ++i)
	{
		for(j = 0 ; j < N ; ++j)
			printf("%d ",mat[i][j]);

		printf("\n");
	}
}

/*
 * This function will check the row and 
 * coloumn to place the queen at the safe 
 * position
 */

bool check_row_col(int mat[N][N],int row,int col)
{
int i;

	for(i = 0 ; i < N ; ++i)
	{
		if(mat[row][i] == 1 || mat[i][col] == 1)
			return false;
	}

	return true;
}

/*
 * This funtion will check the all four 
 * diagonal if any one of them occupied by
 * any queen than it will return false
 */

bool check_diagonal(int mat[N][N],int row,int col)
{
int i,j;

	for(i = row,j = col ; i >= 0 && j >= 0 ; --i,--j)
		if(mat[i][j] == 1)
			return false;

	for(i = row,j = col ; i < N && j < N ; ++i,++j)
		if(mat[i][j] == 1)
			return false;

	for(i = row,j=col ; i >= 0 && j < N ; --i,++j)
		if(mat[i][j] == 1)
			return false;

	for(i = row,j = col ; i < N && j >= 0 ; ++i,--j)
		if(mat[i][j] == 1)
			return false;

	return true;
}

/* 
 * This function is responsible to check 
 * row and coloumn and return flase if 
 * no safe place found
 */

bool isSafe(int mat[N][N],int row,int col)
{

	if(!check_row_col(mat,row,col))
		return false;

	if(!check_diagonal(mat,row,col))
		return false;

	return true;
}

/*
 * This is the function which will check 
 * and place quuens in right place and solve 
 * the n-queen problem using backtracking
 */

bool solve_n_queen(int mat[N][N],int row)
{
	if(row >= N)
		return true;

int i;

	for(i = 0 ; i < N ; ++i)
	{
		if(isSafe(mat,row,i))
		{
			mat[row][i] = 1;

			if(solve_n_queen(mat,row+1))
				return true;

			mat[row][i] = 0;
		}
	}

	return false;
}

int main()
{
int mat[N][N] = {0};

	if(solve_n_queen(mat,0))
		print_matrix(mat);

	else
		printf("No solution possible for this config.\n");

	return EXIT_SUCCESS;
}
