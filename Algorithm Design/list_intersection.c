#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// creates random but sorted array
int *create_array(int n)
{
    int *temp;

    if (n < 0)
    {
        printf("<n> must be greater than 0\n");
        exit(1);
    }

    temp = malloc(sizeof(int) * n);

    if (temp == NULL)
    {
        printf("Could not dynamically allocate integer array");
        exit(1);
    }

    // sets index 0 with first random value
    temp[0] = rand() % 10 + 1;

    // adds previous random value to the next
    for (int i = 1; i < n; i++)
        temp[i] += (rand() % 10 + 1) + temp[i-1];

    return temp;
}

void print_array(int *array, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d%c", array[i], (i < n - 1) ? ' ' : '\n');
}

// worst-case runtime: O(logn)
// best-case runtime: O(1)
int binary_search(int *array, int n, int key)
{
    int lo = 0;
    int hi = n - 1;
    int mid;

    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;

        if (array[mid] < key)
        {
            lo = mid + 1;
        }
        else if (array[mid] > key)
        {
            hi = mid - 1;
        }
        else
        {
            return 1;
        }
    }

    return 0;
}

// O(n^2), uses brute force to compare elements 
void slow_list_intersection(int *array1, int *array2, int n)
{
    int i, j;

    // checks which elements are the same between two arrays
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (array1[i] == array2[j])
                printf("%d%c", array1[i], (i < n - 1) ? ' ' : '\n');
}

// O(nlogn), uses binary search function to compare elements
void list_intersection(int *array1, int *array2, int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        if (binary_search(array2, n, array1[i]))
        {
            printf("%d%c", array1[i], i < n - 1 ? ' ' : '\n');
        }
    }
}

// O(n), capatilizes on both lists being sorted 
void fancy_list_intersection(int *array1, int *array2, int n)
{
    int i = 0, j = 0;

    while (i < n && j < n)
    {
        if (array1[i] < array2[j])
        {
            i++;
        }
        else if (array1[i] > array2[j])
        {
            j++;
        }
        else
        {
            printf("%d ", array1[i]);
            i++;
            j++;
        }
    }

    printf("\n");

}



int main(int argc, char **argv)
{
    int n, *array1, *array2;

    if (argc < 2)
    {
        printf("Proper syntax: %s <n>\n", argv[0]);
        return 1;
    }

    n = atoi(argv[1]);

    // seeds random number generator
    srand(time(NULL));

    // create arrays
    array1 = create_array(n);
    array2 = create_array(n);

    // prints sorted arrays
    printf("Array 1:\n");
    print_array(array1, n);

    printf("Array 2:\n");
    print_array(array2, n);

    // O(n^2)
    // slow_list_intersection(array1, array2, n);

    // O(nlogn)
    // list_intersection(array1, array2, n);

    // O(n)
    fancy_list_intersection(array1, array2, n);

    // free array
    free(array1);
    free(array2);


    return 0;
}