#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int *array;
    int top;
    int capacity;
};

void grow_stack(struct Stack *s, int increase)
{
    int *temp = s->array;

    s->array = malloc(sizeof(int*) * (s->capacity + increase));

    for (int i = 0; i < s->top; i++)
    {
        s->array[i] = temp[i];
    }

    s->capacity += increase;

    free(temp);
}

int main(void)
{
    struct Stack *s = malloc(sizeof(struct Stack));
    int *array = malloc(sizeof(int *) * 5);
    s->top = 3;
    s->capacity = 5;

    int i;
    for (i = 0; i < 3; i++)
    {
        array[i] = 1;
    }

    s->array = array;

    for (int i = 0; i < s->capacity; i++)
    {
        printf("%d ", s->array[i]);
    }

    grow_stack(s, 3);

    printf("\nAfter growing stack:\n");
    
    for (int i = 0; i < s->capacity; i++)
    {
        printf("%d ", s->array[i]);
    }

    return 0;
}
