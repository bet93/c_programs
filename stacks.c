#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct stack
{
    int *array;
    int size;
    int capacity;
}

int main(int argc, char **argv)
{
    int i, n, r;
    if (argc < 2)
    {
        printf("The proper syntax for running this program is: %s <n>\n", argv[0]);
        exit(1);
    }

    n = atoi(argv[1]);

    for (i = 0; i < n; i++)
    {
        printf("Pushing %d onto top of the stack...\n", r = random() % 100 + 1);
        push(list, r);
    }


    return 0;
}