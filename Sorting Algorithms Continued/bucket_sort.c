#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *create_random_array(int *array, int n)
{
    int *temp = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        temp[i] = rand() % 100 + 1; // range 1 through 100
    
    return temp;
}

void print_array(int *array, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d%c", array[i], (i == n - 1) ? '\n' : ' ');
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

// runtime: O(m + n)
void bucket_sort(int *array, int n)
{
    
    int i, j;
    int max = find_max(array, n);
    int *buckets = calloc((max + 1), sizeof(int));

    // place elements into buckets
    for (i = 0; i < n; i++)
        buckets[array[i]]++;

    for (i = j = 0; j <= max; j++)
    {
        // early termination
        if (i >= n)
            break;

        while (buckets[j] > 0)
        {
            array[i++] = j;
            buckets[j]--;
        }
    }

    free(buckets);

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
    bucket_sort(array, n);

    printf("Bucket Sorted array: ");
    print_array(array, n);

    // destroy array
    free(array);

    return 0;
}