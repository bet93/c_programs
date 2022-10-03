#include <stdio.h>
#include <stdlib.h>

void stack_trace(int n)
{
    printf("We just called stack_trace(%d)\n", n);

    // base case
    if (n == 0)
    {
        printf("\nWe hit a base case, and we're about to return!\n\n");
        return;
    }

    printf("\nWe're about to call stack_trace(%d)\n", n - 1);
    stack_trace(n - 1);
    printf("We just returned from stack_trace(%d)\n", n - 1);
}

int main(void)
{
    stack_trace(3);

    return 0;
}