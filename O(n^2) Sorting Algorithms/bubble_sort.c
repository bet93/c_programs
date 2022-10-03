#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *create_array(int n)
{
    int i, *temp = malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        // rand() % 100 = [0 - 99]
        // rand() % 100 + 1 = [1 - 100]
        temp[i] = rand() % 100 + 1;
    }

    return temp;
}

void print_array(int *array, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d%c", array[i], (i == (n - 1)) ? '\n' : ' ');
    }
}

void swap_elements(int *array, int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

// worst case: O(n^2)
// best case: O(n)
void bubble_sort(int *array, int n)
{
    int i, pass, swap_flag;

    for (pass = 1; pass <= n - 1; pass++)
    {
        swap_flag = 0;

        // single pass of bubble sort
        // n - pass, prevents going out of bounds
        for (i = 0; i < n - pass; i++)
        {
            if(array[i] > array[i + 1])
            {
                swap_elements(array, i, i + 1);
                swap_flag = 1;
            }
        }

        // uncomment code below to see each pass:
        // printf("pass %d: ", pass); // n - 1 passes
        // print_array(array, n);

        // early termination
        if (swap_flag == 0)
        {
            break;
        }
    }


    // do
    // {
    //     swap_flag = 0;

    //     // single pass of bubble sort
    //     // n - pass, prevents going out of bounds
    //     for (i = 0; i < n - pass; i++)
    //     {
    //         if (array[i] > array[i + 1])
    //         {
    //             swap_elements(array, i, i + 1);
    //             swap_flag = 1;
    //         }
    //     }

    //     printf("pass %d\n", pass); // n passes
    //     // pass continues to increase, causing the amount of elements -
    //     // in the array that need to be compared - to decrease
    //     pass++;

    // } while (swap_flag == 1);
}

// ./a.out 10 <--- will create array of length 10
int main(int argc, char **argv)
{
    int n, *array;

    if (argc < 2)
    {
        printf("Proper syntax: %s <n>\n", argv[0]);
        return 1; // indicates error
    }

    n = atoi(argv[1]); // captures number

    // seeds random number generator
    srand(time(NULL));

    array = create_array(n);

    printf("Unsorted Array:\n");
    print_array(array, n);

    bubble_sort(array, n);

    printf("Bubble Sorted Array:\n");
    print_array(array, n);

    free(array);

    return 0;
}