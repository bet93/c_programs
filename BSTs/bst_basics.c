#include <stdio.h>
#include <stdlib.h>

// node struct used for BST
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

// creates new node
node *create_node(int data)
{
    node *newNode = calloc(1, sizeof(node));
    newNode->data = data;

    return newNode;
}

// recursive function that inserts a new node into BST
node *insert(node *root, int data)
{
    // base case
    if (root == NULL)
        return create_node(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        ; // excludes duplicate values

    return root;
}

// recursive function that prints out BST using in-order traversal
void inorder_traversal(node *root)
{
    // base case
    if (root == NULL)
        return;
    
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

// recursive function that prints out BST using pre-order traversal
void preorder_traversal(node *root)
{
    // base case
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

// recursive function that prints out BST using post-order traversal
void postorder_traversal(node *root)
{
    // base case
    if (root == NULL)
        return;
    
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}

// recursive function that takes a root of a binary tree
// and returns the number of nodes in that tree.
int count_nodes(node *root)
{
    if (root == NULL)
        return 0;
    
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int count_even_values(node *root)
{
    // base case
    if (root == NULL)
        return 0;

    return (root->data % 2 == 0) + count_even_values(root->left) + count_even_values(root->right);

}

// recursively deallocates memory for all nodes in BST
node *destroy_nodes(node *root)
{
    // base case
    if (root == NULL)
        return NULL;

    destroy_nodes(root->left);
    destroy_nodes(root->right);
    free(root);

    return NULL;
}

int main(void)
{
    // int i, n = 6, array[] = {46, 39, 109, 42, 40, 43};
    // int i, n = 5, array[] = {46, 39, 109, 40, 43};
    int i, n = 10, array[] = {22, 2, 80, 82, 50, 29, 13, 27, 17, 4};
    node *root = NULL;

    for (i = 0; i < n; i++)
    {
        printf("Inserting %d...\n", array[i]);
        root = insert(root, array[i]);
    }

    printf("\n\nin-order traversal:\n");
    inorder_traversal(root);
    
    printf("\n\npre-order traversal:\n");
    preorder_traversal(root);

    printf("\n\npost-order traversal:\n");
    postorder_traversal(root);

    printf("\n\nThere are %d nodes in this BST.\n", count_nodes(root));

    printf("\nThere are %d even values in this BST.\n", count_even_values(root));

    root = destroy_nodes(root);

    return 0;
}