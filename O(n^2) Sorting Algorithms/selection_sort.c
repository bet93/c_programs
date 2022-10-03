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

void swap_elements(int *array, int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

// worst case: O(n^2)
// best case: O(n^2)
void selection_sort(int *array, int n)
{
    int min_index, pass;

    for (pass = 0; pass < n - 1; pass++)
    {
        min_index = pass;

        // single pass of selection sort
        for (int i = pass + 1; i < n; i++)
            if (array[i] < array[min_index])
                min_index = i;

        swap_elements(array, pass, min_index);

        // uncomment to print single pass of selection sort
        printf("pass %d: ", pass + 1);
        print_array(array, n);
    }
}

// ./a.out 10 <--- will create array of length 10
int main(int argc, char **argv)
{
    int n, *array;

    if (argc < 2)
    {
        printf("Proper syntax: %s <n>\n", argv[0]);
        exit(1);
    }

    n = atoi(argv[1]);
    
    // seeds random number generator
    srand(time(NULL));

    array = create_random_array(n);

    printf("Unsorted array:\n");
    print_array(array, n);

    selection_sort(array, n);

    printf("Selection sorted array:\n");
    print_array(array, n);

    free(array);

    return 0;
}