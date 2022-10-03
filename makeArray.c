#include <stdio.h>
#include <stdlib.h>

int **makeArray(int *lengths, int numarrays) 
{
    int i;
    int **temp = malloc(sizeof(int*) * numarrays);

    for (i = 0; i < numarrays; i++)
    {
        temp[i] = calloc(lengths[i], sizeof(int));
    }

    return temp;
}

int main(void)
{
    int lengths[] = {5, 10, 15, 20, 25};

    int **arrays = makeArray(lengths, 5);

    return 0;
}