#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <limits.h>

#define EMPTY_STACK_ERR INT_MIN
typedef struct Stack
{
    int *array;
    int capacity;
    int size;
} Stack;

Stack *create_stack(int capacity)
{
    Stack *temp = malloc(sizeof(Stack));

    temp->array = malloc(sizeof(int) * capacity);
    temp->capacity = capacity;
    temp->size = 0;

    return temp;
}

Stack *destroy_stack(Stack *s)
{
    if (s == NULL)
        return NULL;

    free(s->array);
    free(s);

    return NULL;
}

int isEmpty(Stack *s)
{
    return (s == NULL || s->size == 0);
}

int isFull(Stack *s)
{
    return (s == NULL || s->size == s->capacity);
}

void push(Stack *s, int data)
{
    if (isFull(s))
    {
        printf("Error: Stack is  full in push()\n");
        return;
    }

    // pushes data into stack and increases size
    s->array[s->size++] = data;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Error: Stack is empty in pop()\n");
        return EMPTY_STACK_ERR;
    }

    return s->array[--s->size];
}

int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Error: Stack is empty in pop()\n");
        return EMPTY_STACK_ERR;
    }

    return s->array[s->size - 1];
}
// function that prints stack
void printStack(Stack *s)
{
    int i;
    char str[32];

    printf("\n");

    if (s == NULL)
    {
        printf("   (no stack)\n");
        return;
    }

    if (s->size == 0)
    {
        printf("   (stack is empty)\n");
        return;
    }

    for (i = s->size - 1; i >= 0; i--)
    {
        printf("   |  %-4d  |%s\n", s->array[i], (i == s->size - 1) ? " <-- top" : "");
        printf("   +--------+\n");
    }
}

// print list of commands for menu-driven interface.
void printMenu(void)
{
    printf("\n");
    printf("Stack ops:\n");
    printf("\n");
    printf("  new <n>    -- create a new stack with capacity set to <n>\n");
    printf("  destroy    -- completely destroy the current stack\n");
    printf("  push <n>   -- push <n> onto the stack\n");
    printf("  pop        -- pops the top element off the stack\n");
    printf("  peek       -- prints the stack's top element without removing it\n");
    printf("  empty      -- indicates whether the stack is empty\n");
    printf("  full       -- indicates whether the stack is full\n");
}

int main(void)
{
    char buffer[128];
    int n;
    Stack *s = NULL;

    printMenu();
    printf("\n");

    do
    {
        printf("Enter a command ('?' for help, or 'exit' to quit).\n");
        printf("%% ");

        scanf("%s", buffer);

        if (strcmp(buffer, "?") == 0)
            printMenu();
        
        else if (strcmp(buffer, "new") == 0)
        {
            if (s != NULL)
                destroy_stack(s);
            
            scanf("%d", &n);
            s = create_stack(n);
        }
        else if (strcmp(buffer, "destroy") == 0)
        {
            if (s != NULL)
                s = destroy_stack(s);
        }
        else if (strcmp(buffer, "push") == 0)
        {
            scanf("%d", &n);
            push(s, n);
        }
        else if (strcmp(buffer, "pop") == 0)
        {
            n = pop(s);

            if (n != EMPTY_STACK_ERR)
                printf("\n   -> popped %d\n", n);
        }
        else if (strcmp(buffer, "peek") == 0 || strcmp(buffer, "top") == 0)
        {
            n = peek(s);

            if (n != EMPTY_STACK_ERR)
                printf("\n   -> peek: %d\n", n);
        }
        else if (strcmp(buffer, "empty") == 0)
        {
            if (isEmpty(s))
                printf("\n   -> stack is empty\n");
            else
                printf("\n   -> stack is not empty\n");
        }
        else if (strcmp(buffer, "full") == 0)
        {
            if (isFull(s))
                printf("\n   -> stack is full\n");
            else
                printf("\n   -> stack is not full\n");
        }
        else if (strcmp(buffer, "exit") == 0)
            break;
        
        // prints the stack after each command
        printStack(s);
        printf("\n");

    } while (1);

    s = destroy_stack(s);

    return 0;
}