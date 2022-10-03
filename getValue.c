#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

// recursive function that takes a linked list with value 5 9 2
// and returns the value 295
int getValue(node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    return (head->data + 10 * getValue(head->next));
}

// iterative function that takes a linked list with values 5 2 9
// and returns the value 592 using horner's rule
int getValueIterative(node *head)
{
    if (head == NULL)
    {
        printf("No linked-list exists\n");
        exit(1);
    }

    node *temp = NULL;
    int value = head->data;

    // using horner's rule
    for (temp = head->next; temp != NULL; temp = temp->next)
    {
        value *= 10;
        value += temp->data;
    }

    return value;
}

node *createNode(int data)
{
    node *temp = malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    return temp;
}

node *insertNode(node *head, int data)
{
    node *temp = head;
    if (head == NULL)
    {
        temp = head = createNode(data);
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = createNode(data);
    temp = temp->next;

    return head;
}

void printList(node *head)
{
    if (head == NULL)
    {
        return;
    }

    printf("%d ", head->data);
    printList(head->next);
}

int main(void)
{
    node *head = createNode(5);
    head = insertNode(head, 9);
    head = insertNode(head, 2);

    printList(head);
    
    printf("\nGet Value recursively: ");
    printf("%d", getValue(head));

    printf("\nGet Value iteratively: ");
    printf("%d", getValueIterative(head));

    return 0;
}