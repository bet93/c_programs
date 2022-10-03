#include <stdio.h>
#include <stdlib.h>

// recursive function that takes a non-negative integer n
// and returns the sum of 0 through n.
int get_sum(unsigned int n)
{
    // base case
    if (n == 0)
    {
        return 0;
    }

    return (n + get_sum(n - 1));
}

int main(void)
{
    unsigned int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("\nThe sum of all non-negative integers up to %d is: %d\n", n, get_sum(n));

    return 0;
}