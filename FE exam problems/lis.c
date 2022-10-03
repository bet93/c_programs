#include <stdio.h>
#include <stdlib.h>

int lis(int *values, int k, int max)
{
    // base case
    if (k < 0)
        return 0;
    
    if (values[k] <= max)
        return 1 + lis(values, k - 1, values[k] - 1);
    else
        return lis(values, k - 1, max);
}

int main(void)
{
    int i, k = 8, max = 8, array[] = {2, 9, 4, 3, 7, 5, 6, 8};
    
    printf("The given sequence of integers is: ");

    for (i = 0; i < k; i++)
        printf("%d%c", array[i], i != k - 1 ? ' ' : '\n');

    printf("The longest increasing subsequence of this sequence is %d\n", lis(array, k - 1, max));

    return 0;
}