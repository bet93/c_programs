#include <stdio.h>
#include <stdlib.h>

void printNaturalNums(int n)
{
    if (n <= 50)
    {
        printf("%d ", n);
        printNaturalNums(n+1);
    }
}
int main(void)
{
    printNaturalNums(1);
    return 0;
}