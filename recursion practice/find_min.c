#include <stdio.h>
#include <stdlib.h>

// recursive function that finds the min element in a n array of
// n integers. Assuming the array is non-empty.
int find_min(int *array, int n)
{
    int min;

    // base case
    if (n == 1)
        return array[0];

    // returns minimum of array[0] through array[n - 2]
    min = find_min(array, n - 1);

    // final comparison, returns minimum of entire array
    return ((array[n - 1] < min) ? array[n - 1] : min);
    
}

int main(void)
{
    int array[] = {22, 19,  4, 3, -1, 67, 25};

    printf("%d\n", find_min(array, 7));

    return 0;
}