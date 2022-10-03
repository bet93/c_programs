#include <stdio.h>
#include <stdlib.h>

// node struct
typedef struct node
{
    int data;
    struct node *next;

} node;

// creates new node
node *create_node(int data)
{
    node *temp = malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    return temp;
}

// inserts node at the tail of the linked list
node *tail_insert(node *head, int data)
{
    node *temp = NULL;

    if (head == NULL)
        return create_node(data);
    
    for (temp = head; temp->next != NULL; temp = temp->next)
        ;
    
    temp->next = create_node(data);

    return head;
}

// recursive tail insert function
void tail_insert_recursive_helper(node *head, int data)
{
    node *temp = head;

    if (temp->next == NULL)
    {
        temp->next = create_node(data);
        return;
    }
    
    tail_insert_recursive_helper(temp->next, data);
}

// gateway function for tail_insert_recursive
node *tail_insert_recursive(node *head, int data)
{
    if (head == NULL)
        return create_node(data);
    
    tail_insert_recursive_helper(head, data);

    return head;

}

// iterative print list function
void print_list(node *head)
{
    node *temp = NULL;

    if (head == NULL)
    {
        printf("(empty list)\n");
        return;
    }

    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d%c", temp->data, temp->next != NULL ? ' ' : '\n');
}

// recursive print function
void print_list_recursive_helper(node *head)
{
    node *temp = head;

    // base case
    if (temp == NULL)
        return;
    
    printf("%d%c", temp->data, temp->next != NULL ? ' ' : '\n');
    print_list_recursive_helper(temp->next);
}

// recursive print function that prints linked list in reverse
void print_list_reverse(node *head)
{
    node *temp = head;

    //base case
    if (temp == NULL)
        return;
    
    print_list_reverse(head->next);
    printf("%d ", temp->data);
}

// gatekeeper function for recursive print list
void print_list_recursive(node *head)
{
    if (head == NULL)
    {
        printf("(empty list)\n");
        return;
    }
    //print_list_recursive_helper(head);
    print_list_reverse(head);
}

// recursive function that frees the dynamically allocated linked list
node *destroy_list(node *head)
{
    if (head == NULL)
        return NULL;
    
    destroy_list(head->next);
    free(head);

    return NULL;

}


int main(int argc, char **argv)
{
    int i;
    node *head = NULL;

    if (argc < 5)
    {
        printf("Proper Syntax: %s <n> <n> <n> <n>\n", argv[0]);
        exit(1);
    }

    for (i = 1; i < argc; i++)
    {
        printf("Inserting %d...\n", atoi(argv[i]));
        head = tail_insert_recursive(head, atoi(argv[i]));
    }

    print_list_reverse(head);

    head = destroy_list(head);
    
    return 0;
}