#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next;
    int data;
} node;

void destroy_list(node *head)
{
    if (head == NULL)
        return;
    
    destroy_list(head->next);

    free(head);
      
}

int main(void)
{
    node *head = malloc(sizeof(node));

    head->data = 1;
    head->next = malloc(sizeof(node));

    head->next->data = 2;
    head->next->next = malloc(sizeof(node));

    head->next->next->data = 3;
    head->next->next->next = NULL;

    destroy_list(head);

    return 0;
}