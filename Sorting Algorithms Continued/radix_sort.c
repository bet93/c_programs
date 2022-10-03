#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

int *create_random_array(int *array, int n)
{
    int *temp = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        temp[i] = rand() % 100 + 1; // range 1 through 100
    
    return temp;
}

// assumes array is not empty
int find_max(int *array, int n)
{
    int i, max = array[0];

    for (i = 1; i < n; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

void print_array(int *array, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d%c", array[i], (i == n - 1) ? '\n' : ' ');
}

void radix_sort(int *array, int n)
{
    int pow = 1, i, j, d;
    int max = find_max(array, n);
    Queue *buckets[10];

    for (i = 0; i < 10; i++)
        buckets[i] = initQueue();
    
    for (pow = 1; max / pow > 0; pow *= 10)
    {
        // single pass, throws elements into queues
        for (i = 0; i < n; i++)
            enqueue(buckets[(array[i]/pow) % 10], array[i]);

        // empty out queues
        for (i = j = 0; i < 10; i++)
            while (!isEmpty(buckets[i]))
                array[j++] = dequeue(buckets[i]);

    }

    for (i = 0; i < 10; i++)
        free(buckets[i]);
}

int main(int argc, char **argv)
{
    int n, *array = NULL;

    if (argc < 2)
    {
        printf("Proper syntax: %s <n>\n", argv[0]);
        exit(1);
    }

    n = atoi(argv[1]);

    srand(time(NULL));

    // create array
    array = create_random_array(array, n);

    printf("Unsorted array: ");
    print_array(array, n);

    // sort array
    radix_sort(array, n);

    printf("Radix Sorted array: ");
    print_array(array, n);

    // destroy array
    free(array);

    return 0;
}