#include<stdio.h>

#define SIZE 9

int find_missing(int size, int array[size])
{
   int total_sum = (size + 1) * (size + 2) / 2;
   int i;

   for(i = 0 ; i < size ; ++i){

      total_sum -= array[i];
   }

   return total_sum;
}

int main()
{
int array[] = {1, 9, 2, 7, 8, 4, 5, 3, 10};

   int array_size = sizeof(array)/sizeof(array[0]);

   int missing_number = find_missing(SIZE, array);

   printf("Missing number in array = %d\n",missing_number);

   return 0;
}
