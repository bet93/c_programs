#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct LinkedList
{
    struct node *head;
    struct node *tail;
} LinkedList;

node *create_node(int data)
{
    node *temp = malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    return temp;
}

node *destroy_node(node *head)
{
    if (head == NULL)
        return NULL;
    
    destroy_node(head->next);
    free(head);

    return NULL;
}

LinkedList *create_list(void)
{
    return calloc(1, sizeof(LinkedList));
}

LinkedList *destroy_list(LinkedList *list)
{
    if (list == NULL)
        return NULL;
    
    list->head = list->tail = destroy_node(list->head);
    free(list);

    return NULL;
}

// O(1) runtime since we have a tail pointer
node *tail_insert_helper(node *tail, int data)
{
    if (tail == NULL)
        return create_node(data);
    
    tail->next = create_node(data);

    return tail->next;
}

void tail_insert(LinkedList *list, int data)
{
    list->tail = tail_insert_helper(list->tail, data);

    if (list->head == NULL)
        list->head = list->tail;
}

node *head_insert_helper(node *head, int data)
{
    node *temp = NULL;

    if (head == NULL)
    {
        return create_node(data);
    }

    temp = create_node(data);
    temp->next = head;

    return temp;
}

void head_insert(LinkedList *list, int data)
{
    list->head = head_insert_helper(list->head, data);

    if (list->tail == NULL)
        list->tail = list->head;

}

void print_list_helper(node *head)
{
    int i;
    node *temp = NULL;

    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d%c", temp->data, temp->next != NULL ? ' ' : '\n');

}

void print_list(LinkedList *list)
{
    if (list == NULL || list->head == NULL)
    {
        printf("(Empty List)\n");
        return;
    }

    print_list_helper(list->head);
}

node *make_circle(node *head)
{
    int i;

    if (head == NULL)
    {
        return NULL;
    }

    node *temp = NULL;

    for (temp = head; temp->next != NULL; temp = temp->next)
        ;
    
    temp->next = head;

    return head;
}

int main(int argc, char **argv)
{
    int i;
    LinkedList *list = NULL;

    if (argc < 5)
    {
        printf("Proper Syntax: %s <n> <n> <n> <n>", argv[0]);
        exit(1);
    }

    list = create_list();

    for (i = 1; i < argc; i++)
    {
        printf("Inserting %d...\n", atoi(argv[i]));
        head_insert(list, atoi(argv[i]));
    }

    print_list(list);
    list = destroy_list(list);

    return 0;
}