#include<stdio.h>

#define SUCCESS 0
#define SIZE 8

int getSubArray(int size, int array[size])
{
   int i;
   int maxSum = array[0];
   int curMaxSum = 0;

   for (i = 0 ; i < size ; ++i)
   {
      curMaxSum += array[i];

      if (curMaxSum > maxSum)
         maxSum = curMaxSum;

      if (curMaxSum < 0)
         curMaxSum = 0;
   }

   return maxSum;
}

int main()
{
int array[] = {-2, -3, 4, -1, -2, 1, 5, -3};

   int maxSum = getSubArray(SIZE, array);

   printf("Maximum sum from array = %d\n", maxSum);

   return SUCCESS;
}
