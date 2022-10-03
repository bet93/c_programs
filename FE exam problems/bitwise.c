#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 182, i = 0;

    while (n > 0)
    {
        if ((n & (1 << i)) > 0)
        {
            printf("%d\n", (1 << i));
            n ^= (1 << i);
        }
        i++;
    }

    return 0;
}