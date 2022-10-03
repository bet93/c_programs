#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(void)
{
    char str[] = {'c', 'u', 'p', 'c', 'a', 'k', 'e', '\0'};

    printf("strlen(str) = %d\n", strlen(str));
    return 0;
}