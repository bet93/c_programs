#include <stdio.h>
#include <stdlib.h>

int num;

void printArray(int *array, int num, int n)
{
    if (n < num)
    {
        printf("%d ", array[n]);
        printArray(array, num, n+1);
    }
}

int main(void)
{
    int num, element;

    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &num);

    int *array = malloc(sizeof(int) * num);

    printf("Input 6 elements in the array:\n");
    for (int i = 0; i < num; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &element);
        array[i] = element;
    }

    printArray(array, num, 0);
    free(array);

    return 0;
}