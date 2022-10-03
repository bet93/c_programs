#include <stdio.h>
#include <stdlib.h>


// recursive function that returns the sum of all digits in a number.
// if number is negative, simply ignore the - sign.
// Big-oh runtime is O(l), where l is the length of the number
int digit_sum(int n)
{
    int sum;

    if (n == 0)
        return 0;
    
    if (n < 0)
    {
        n *= -1;
    }

    return n % 10 + digit_sum((n / 10));
}

int main(void)
{
    
    printf("1 + 5 + 9 = %d\n", digit_sum(-133));

    return 0;
}