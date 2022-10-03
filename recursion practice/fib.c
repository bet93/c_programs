#include <stdio.h>
#include <stdlib.h>

// recursive implementation of fibonacci function
int fib(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    return fib(n-1) + fib(n-2);
}

int main(void)
{
    int n;

    printf("Input number of terms for the Series (<20): ");
    scanf("%d", & n);

    // prints fibonacci numbers from 0 to n
    for (int i = 0; i < n; i++)
    {
        int value = fib(i);
        printf("%d ", value);
    }

    return 0;
}