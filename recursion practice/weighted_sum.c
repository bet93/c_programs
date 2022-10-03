#include <stdio.h>
#include <stdlib.h>

int weightedSum(int numbers[], int n)
{

    if (n == 1)
    {
        return numbers[0];
    }

    return  n * numbers[n-1] + weightedSum(numbers, n - 1);
}

int main(void)
{
    int array[] = {7, 5, 8};

    printf("weighted sum = %d\n", weightedSum(array, 3));

    return 0;
}