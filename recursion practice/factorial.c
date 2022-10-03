#include <stdio.h>
#include <stdlib.h>

// recursive function that takes a non-negative int n,
// and returns n!
int factorial(unsigned int n)
{
    //base case
    if (n == 0)
        return 1;

    return n * factorial(n - 1);

}

int main(void)
{
    printf("%d! = %d\n", 0, factorial(0));
    printf("%d! = %d\n", 1, factorial(1));
    printf("%d! = %d\n", 2, factorial(2));
    printf("%d! = %d\n", 6, factorial(6));
    return 0;
}