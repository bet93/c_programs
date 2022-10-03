#include <stdio.h>
#include <stdlib.h>

// iterative and faster fibonacci solution
// O(n) runtime
int fib(int n)
{
    int i, retval, *array;

    if (n < 2)
        return n;
    
    array = malloc(sizeof(int) * (n + 1));

    array[0] = 0;
    array[1] = 1;

    for (i = 2; i <= n; i++)
        array[i] = array[i-1] + array[i-2];

    retval = array[n];
    free(array);

    return retval;
}

// takes up O(1) space without changing run time
int fib_2(int n)
{
    int i, retval, *array;

    if (n < 2)
    {
        return n;
    }

    array = malloc(sizeof(int) * 2);

    array[0] = 0;
    array[1] = 1;

    for (i = 2; i <= n; i++)
    {
        array[i%2] = array[0] + array[1];
        
    }

    retval = (n % 2 == 0) ? array[0] : array[1];
    free(array);

    return retval;
}

int main(int argc, char **argv)
{
    int n;

    if (argc < 2)
    {
        printf("Proper syntax: %s <n>\n", argv[0]);
        return 0;
    }

    n = atoi(argv[1]);

    printf("fib(%d) = %d\n", n, fib_2(n));

    return 0;
}