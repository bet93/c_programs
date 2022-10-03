#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *left;
    struct node *right;
} node;

typedef struct stack
{
    struct node *head;
} stack;

node *create_node(int data)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = newNode->left = newNode->right = NULL;

    return newNode;
}

stack *create_stack()
{
    stack *newStack = malloc(sizeof(stack));
    newStack->head = NULL;

    return newStack;
}

void destroy_nodes(node *head)
{
    if (head == NULL)
        return;
    
    destroy_nodes(head->next);
    free(head);
}

stack *destroy_stack(stack *s)
{
    if (s == NULL)
        return NULL;
    
    destroy_nodes(s->head);
    free(s);

    return NULL;
}

node *bst_insertion(node *root, int data)
{
    // base case
    if (root == NULL)
        return create_node(data);
    
    if (data < root->data)
        root->left = bst_insertion(root->left, data);
    else if (data > root->data)
        root->right = bst_insertion(root->right, data);
    else
        ;
    
    return root;
}

int is_empty(stack *s)
{
    return (s == NULL || s->head == NULL);
}

void push(stack *s, node *root)
{
    if (s->head == NULL)
    {
        s->head = create_node(root->data);
        return;
    }

    node *temp = create_node(root->data);
    temp->next = s->head;
    s->head = temp; 
}

node *pop(stack *s)
{
    if (is_empty(s))
    {
        printf("Stack is empty at pop()\n");
        return NULL;
    }

    node *temp = s->head;
    s->head = temp->next;
    
    return temp;
}

int tree_sum(node *root)
{
    stack *s = create_stack();
    int sum = 0, data;

    push(s, root);

    while(!is_empty(s))
    {
        root = pop(s);

        if (root == NULL)
            continue;
        sum += root->data;

        push(s, root->right);
        push(s, root->left);
    }

    s = destroy_stack(s);

    return sum;
    
}

int main(void)
{
    int n = 4, array[] = {32, 5, 8, 1};

    node *root = NULL;

    for (int i = 0; i < n; i++)
        root = bst_insertion(root, array[i]);

    printf("The tree sum is: %d\n", tree_sum(root));

    // root = forest_fire(root);

    return 0;
}