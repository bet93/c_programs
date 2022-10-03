#include <stdio.h>
#include <stdlib.h>

// recursive function that returns the product of two non-negative ints,
// a and b, using only addition and subtraction operators
int mult(unsigned int a, unsigned int b)
{
    if (a == 1)
        return b;

    return a + mult(a - 1, b); 
}

int main(void)
{
    printf("%d x %d = %d\n", 5, 10, mult(5, 10));
    return 0;
}