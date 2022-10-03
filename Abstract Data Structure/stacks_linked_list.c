#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define STACK_ERROR INT_MIN

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct Stack
{
    struct node *head;
    int capacity;
    int size;

} Stack;

node *create_node(int data)
{
    node *temp = malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    return temp;
}

Stack *create_stack(int capacity)
{
    Stack *s = malloc(sizeof(Stack));
    s->head = NULL;
    s->capacity = capacity;
    s->size = 0;

    return s;
}

node *destroy_node(node *head)
{
    if (head == NULL)
        return NULL;
    
    destroy_node(head->next);
    free(head);

    return NULL;
}

Stack *destroy_stack(Stack *s)
{
    if (s == NULL)
        return NULL;
    
    s->head = destroy_node(s->head);
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
        printf("Error: stack is full in push()\n");
        return;
    }

    if (s->head == NULL)
        s->head = create_node(data);

    else
    {
        node *temp = create_node(data);
        temp->next = s->head;
        s->head = temp;
    }

    s->size++;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Error: stack is empty in pop()\n");
        return STACK_ERROR;
    }


    int retval = s->head->data;
    node *temp = s->head->next;
    free(s->head);
    s->head = temp;
    s->size--;

    return retval;
}

int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Error: stack is empty in pop()\n");
        return STACK_ERROR;
    }

    return s->head->data;
}


int main(void)
{
    Stack *s = create_stack(5);

    printf("push(%d)...\n", 25);
    push(s, 25);

    printf("push(%d)...\n", 36);
    push(s, 36);

    printf("push(%d)...\n", 57);
    push(s, 57);

    printf("push(%d)...\n", 90);
    push(s, 90);

    printf("push(%d)...\n", 74);
    push(s, 74);

    printf("push(%d)...\n", 101);
    push(s, 101);

    printf("top of the stack --> %d\n", peek(s));

    printf("pop(%d)...\n", pop(s));
    printf("pop(%d)...\n", pop(s));
    printf("pop(%d)...\n", pop(s));
    printf("pop(%d)...\n", pop(s));
    printf("pop(%d)...\n", pop(s));
    printf("pop(%d)...\n", pop(s));

    s = destroy_stack(s);

    return 0;
}