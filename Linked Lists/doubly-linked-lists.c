#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

typedef struct LinkedList
{
    struct node *head;
    struct node *tail;
} LinkedList;

LinkedList *create_list(void)
{
    return calloc(1, sizeof(LinkedList));
}

node *create_node(int data)
{
    node *temp = malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;

    return temp;
}

node *tail_insert(node *tail, int data)
{
    if (tail == NULL)
        return create_node(data);

    node *temp = create_node(data);
    tail->next = temp;
    temp->prev = tail;

    return temp;
}

void tail_insert_helper(LinkedList *list, int data)
{
    list->tail = tail_insert(list->tail, data);

    if (list->head == NULL)
        list->head = list->tail;
}

node *head_insert(node *head, int data)
{
    if (head == NULL)
        return create_node(data);

    node *temp = create_node(data);
    temp->next = head;
    head->prev = temp;

    return temp;
}

void head_insert_helper(LinkedList *list, int data)
{
    list->head = head_insert(list->head, data);

    if (list->tail == NULL)
        list->tail = list->head;
}

void print_list(node *head)
{
    if (head == NULL)
    {
        printf("(empty list)\n");
        return;
    }

    node *temp = NULL;

    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d%c", temp->data, temp->next != NULL ? ' ' : '\n');
}

node *destroy_node(node *head)
{
    if (head == NULL)
        return NULL;
    
    destroy_node(head->next);
    free(head);

    return NULL;
}

LinkedList *destroy_list(LinkedList *list)
{
    if (list == NULL || list->head == NULL)
    {
        printf("(empty list)\n");
        return NULL;
    }

    list->head = destroy_node(list->head);
    free(list);

    return NULL;

}

int main(int argc, char **argv)
{
    LinkedList *list = NULL;

    if (argc < 5)
    {
        printf("Proper syntax: %s <n> <n> <n> <n>\n", argv[0]);
    }

    list = create_list();

    for (int i = 1; i < argc; i++)
    {
        printf("Inserting %d...\n", atoi(argv[i]));
        tail_insert_helper(list, atoi(argv[i]));
    }

    print_list(list->head);

    printf("node(35)->prev = node(%d)\nnode(35)->next = node(%d)", list->head->next->prev->data, list->head->next->next->data);

    list = destroy_list(list);

    return 0;
}