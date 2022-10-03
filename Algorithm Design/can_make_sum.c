// Sara Betancourth
// 20JUL2021

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 1

// this function takes a sorted array of n integers and determines
// whether two distinct elements of the array add up to a key.
int can_make_sum(int *array, int n, int key)
{

}

int *create_random_array(int n)
{
    int i, *temp = malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
        temp[i] = rand() % 100 + 1;

    return temp;
}

void print_array(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", array[i], (i < n - 1) ? ' ' : '\n');
    }
}

void swap_elements(int *array, int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void bubble_sort(int *array, int n)
{
    int i, pass, swap_flag;

    for (pass = 1; pass <= n - 1; pass++)
    {
        // resets swap flag for each pass
        swap_flag = 0;

        // single pass of bubble sort
        for (i = 0; i < n - pass; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap_elements(array, i, i + 1);
                swap_flag = 1;
            }
        }

        if (DEBUG)
        {
            // uncomment code below to see each pass:
            printf("pass %d: ", pass); // n - 1 passes
            print_array(array, n);
        }

        // if no swaps detected, exit out of loop
        if (swap_flag == 0)
        {
            break;
        }
    }
}

// at the command line type:
// ./a.out <n> , where n is the length of the array of integers
int main(int argc, char **argv)
{
    int n, *array;

    if (argc < 2)
    {
        printf("Proper syntax: %s <n>\n", argv[0]);
        exit(1);
    }

    // captures number
    n = atoi(argv[1]);

    // seeds random number generator
    srand(time(NULL));

    array = create_random_array(n);

    if (DEBUG)
    {
        // print unsorted array
        print_array(array, n);
    }

    // use bubble sort to sort array
    bubble_sort(array, n);

    if (DEBUG)
    {
        // print sorted array
        print_array(array, n);
    }

    if (can_make_sum(array, n, 50))
    {
        printf("two elements in array add up to: %d\n", 50);
    }

    free(array);

    return 0;
}