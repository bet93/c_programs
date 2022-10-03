#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *create_random_array(int n)
{
    int *temp = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        temp[i] = rand() % 100 + 1;
    
    return temp;
}

void print_array(int *array, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d%c", array[i], (i < n - 1) ? ' ' : '\n');
}

void insertion_sort(int *array, int n)
{
    int start, val, gap;

    for (start = 1; start < n; start++)
    {
        val = array[start];

        // single pass of insertion sort
        for (gap = start; gap > 0 && array[gap-1] > val; gap--)
            array[gap] = array[gap-1];

        array[gap] = val;

        // uncomment to print single pass of insertion sort
        // printf("pass %d: ", start);
        // print_array(array, n);
    }
}

int main(int argc, char **argv)
{
    int n, *array;

    if (argc < 2)
    {
        printf("Proper syntax: %s <n>", argv[0]);
        exit(1);
    }

    n = atoi(argv[1]);

    srand(time(NULL));

    array = create_random_array(n);

    printf("Unsorted array:\n");
    print_array(array, n);

    insertion_sort(array, n);

    printf("Insertion sorted array:\n");
    print_array(array, n);

    free(array);

    return 0;
}