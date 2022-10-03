#include <stdio.h>
#include <stdlib.h>

// recursive implementation of LIS problem
int lis(int *values, int k, int max)
{
    // base case
    if (k == 0)
    {
        return values[0] <= max;
    }

    int notake = lis(values, k-1, max);

    int take = 0;

    if (values[k] <= max)
    {
        take = 1 + lis(values, k-1, values[k]-1);
    }

    if (take > notake)
    {
        return take;
    }
    
    return notake;
}

int main(void)
{
    int array = {2, 9, 4, 3, 7, 5, 6, 8};


    return 0;
}