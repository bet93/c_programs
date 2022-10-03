#include <stdio.h>
#include <stdlib.h>

int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n + sum(n-1);
}

int main(void)
{
    int val = sum(5);
    printf("the sum of numbers 1 to 5: %d", val);

    return 0;
}