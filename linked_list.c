#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

// this linked list struct contains both a head and tail pointer.
typedef struct LinkedList
{
    node *head;
    node *tail;
} LinkedList;

// creates a linked list
LinkedList *create_list()
{
    return calloc(1, sizeof(LinkedList));
}

// creates new node
node *create_node(int data)
{
    node *temp = malloc(sizeof(node));

    if (temp == NULL)
    {
        printf("Failed to allocate memory for new node\n");
        exit(1);
    }

    temp->data = data;
    temp->next = NULL;

    return temp;
}

// this function inserts new node at end of linked list
void tail_insert(LinkedList *list, int data)
{
    // if list does not exist
    if (list == NULL)
    {
        printf("List does not exist\n");
        exit(1);
    }

    // if empty list create new node
    if (list->tail == NULL)
    {
        // set both head and tail pointers to this node
        list->head = list->tail = create_node(data);
    }

    // if list is not empty add new node to end of list
    else
    {
        list->tail->next = create_node(data);
        list->tail = list->tail->next;
    }
}

void print_list(node *head)
{
    if (head == NULL)
    {
        return;
    }

    printf("%d%c", head->data, (head->next == NULL) ? '\n' : ' ');
    print_list(head->next);
}

void print_list_helper(LinkedList *list)
{
    if (list == NULL || list->head == NULL)
    {
        printf("(empty list)\n");
        exit(1);
    }

    print_list(list->head);
}

node *destroy_list(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    destroy_list(head->next);
    free(head);

    return NULL;
}

LinkedList *destroy_list_helper(LinkedList *list)
{
    if (list == NULL)
    {
        return NULL;
    }

    // free all nodes in list
    destroy_list(list->head);

    // free list struct
    free(list);

    return NULL;
}

int main(int argc, char **argv)
{
    int i, n, r;
    LinkedList *list = create_list();

    if (argc < 2)
    {
        free(list);
        printf("The proper syntax for running this program is: %s <n>\n", argv[0]);
        return 1;
    }

    n = atoi(argv[1]);

    srand(time(NULL));

    for (i = 0; i < n; i++)
    {
        printf("Inserting %d...\n", r = rand() % 100 + 1);
        tail_insert(list, r);
    }

    // print list
    print_list_helper(list);

    // free memory
    list = destroy_list_helper(list);

    return 0;
}