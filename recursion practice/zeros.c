#include <stdio.h>
#include <stdlib.h>



int zeros_recursively(int n)
{
    int res;

    if (n == 0)
    {
        return 0;
    }
    
    res = n + zeros_recursively(n/5);

    res /= 5;

    return res;
}

int zeros(int n)
{
    int res = 0;

    while (n != 0)
    {
        res += n/5;
        printf("res = %d\n", res);
        n /= 5;
        printf("n = %d\n", n);
    }

    return res;
}

int main(void)
{
    int n, res1, res2;

    printf("Enter a number: ");
    scanf("%d", &n);

    res1 = zeros(n);

    printf("\nThe number of zeros at the end of %d! = %d\n", n, res1);

    res2 = zeros_recursively(n);
    printf("\nThe number of zeros at the end of %d! = %d\n", n, res2);
    
    return 0;
}