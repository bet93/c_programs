#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *create_random_array(int n)
{
    int *array = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        array[i] = rand() % 100 + 1;
    
    return array;
}

void print_array(int *array, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d%c", array[i], i == n - 1 ? '\n' : ' ');
}

// recursive function that sorts an array
void merge_sort(int *array, int lo, int hi)
{
    int mid = lo + (hi - lo) / 2;
    int *aux;

    // base case
    if (lo >= hi)
        return;

    merge_sort(array, lo, mid);
    merge_sort(array, mid + 1, hi);


    aux = malloc(sizeof(int) * ((hi - lo) + 1));
    int k = 0, i = lo, j = mid + 1;

    // merge
    while (i <= mid || j <= hi)
    {
        if ((j > hi) || (i <= mid && array[i] < array[j]))
            aux[k++] = array[i++];
        else
            aux[k++] = array[j++];
    }

    // place elements back to array
    for (i = lo; i <= hi; i++)
        array[i] = aux[i - lo];

    // free aux array
    free(aux);
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

    // creates array
    array = create_random_array(n);

    // print unsorted array
    printf("Unsorted array: ");
    print_array(array, n);

    // sorts array
    printf("Merge Sorted array: ");
    merge_sort(array, 0, n - 1);

    // print sorted array
    print_array(array, n);

    // destroys array
    free(array);


    return 0;
}