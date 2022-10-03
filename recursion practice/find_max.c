#include <stdio.h>
#include <stdlib.h>

// recursive function that takes an array of n ints
// and returns the largest value in the array.
// assume array contains atleast 1 int
int find_max(int *array, int n)
{
    int max;

    if (n == 1)
        return array[0];

    max = find_max(array, n - 1);

    if (array[n - 1] > max)
        return array[n - 1];

    return max;
}

int main(void)
{
    int array1[] = {-1, -5, -3, -10, 0};

    printf("The max value in the array is: %d\n", find_max(array1, 5));


    return 0;
}