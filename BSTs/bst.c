#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <limits.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

// creates new node
node *create_node(int data)
{
    node *temp = calloc(1, sizeof(node));
    temp->data = data;

    return temp;
}

// recursively inserts nodes into BST
node *bst_insert(node *root, int data)
{
    // base case
    if (root == NULL)
        return create_node(data);
    
    if (data < root->data)
        root->left = bst_insert(root->left, data);
    else if (data > root->data)
        root->right = bst_insert(root->right, data);
    else
        ; // no duplicate values

    return root;
}

// iterative function that finds max of left subtree
// assumes root is not NULL
int bst_find_max(node *root)
{
    node *temp = NULL;

    for (temp = root; temp->right != NULL; temp = temp->right)
        ;
    
    return temp->data;
}

// assumes root is not NULL
int bst_find_max_recursive(node *root)
{
    // base case
    if (root->right == NULL)
        return root->data;
    
    return bst_find_max_recursive(root->right);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

// recursive function that finds max value of a regular binary tree
int find_max(node *root)
{
    int lmax, rmax;
    // base case
    if (root == NULL)
        return INT_MIN;

    lmax = find_max(root->left);
    rmax = find_max(root->right);

    return max(root->data, max(lmax, rmax));

}

node *bst_delete(node *root, int data)
{
    node *new_root = NULL;

    // base case
    if (root == NULL)
        return NULL;
    
    if (data < root->data)
    {
        root->left = bst_delete(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = bst_delete(root->right, data);
    }
    else
    {
        // no children
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL; 
        }
        // left child
        else if (root->right == NULL)
        {
            new_root = root->left;
            free(root);
            return new_root;
        }
        // right child
        else if (root->left == NULL)
        {
            new_root = root->right;
            free(root);
            return new_root;
        }
        // two children
        else
        {
            root->data = find_max(root->left);
            root->left = bst_delete(root->left, root->data);
            return root;
        }
    }

    return root;
}

void inorder_traversal(node *root)
{
    if (root == NULL)
        return;

    inorder_traversal(root->left);  
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

void inorder(node *root)
{
    if (root == NULL)
    {
        printf("(empty tree)\n");
        return;
    }

    printf("\n\nin-order traversal:\n");

    inorder_traversal(root);
    printf("\n");
}

void preorder_traversal(node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void preorder(node *root)
{
    if (root == NULL)
    {
        printf("(empty tree)\n");
        return;
    }

    printf("\n\npre-order traversal:\n");

    preorder_traversal(root);
    printf("\n");
}

void postorder_traversal(node *root)
{
    if (root == NULL)
        return;

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}

void postorder(node *root)
{
    if (root == NULL)
    {
        printf("(empty tree)\n");
        return;
    }

    printf("\n\npost-order traversal:\n");

    postorder_traversal(root);
    printf("\n");
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

int height(node *root)
{
    // base case
    if (root == NULL)
        return -1;

    return max(height(root->left), height(root->right)) + 1;
}

int has_negatives(node *root)
{
    if (root == NULL)
        return 0;
    
    if (root->data < 0)
        return 1;
    
    return has_negatives(root->left);
}

// recursively deallocates memory for all nodes in BST
node *destroy_nodes(node *root)
{
    // base case
    if (root == NULL)
        return NULL;

    root->left = destroy_nodes(root->left);
    root->right = destroy_nodes(root->right);
    free(root);

    return NULL;
}


int main(void)
{
    // int i, n = 6, array[] = {46, 39, 109, 42, 40, 43};
    int i, r, n = 6, array[] = {46, 39, 109, 40, 43, -21};
    // int i, r, n = 8, array[] = {40, 32, 11, 38, 79, 65, 51, 64};
    // int i, r, n = 10, array[] = {22, 2, 80, 82, 50, 29, 13, 27, 17, 4};
    node *root = NULL;

    // Creates BST
    for (i = 0; i < n; i++)
    {
        printf("Inserting %d...\n", array[i]);
        root = bst_insert(root, array[i]);
    }

    // BST Traversals
    inorder(root);
    preorder(root);
    postorder(root);

    printf("\n\nThere are %d nodes in this BST.\n", count_nodes(root));
    printf("\nThere are %d even values in this BST.\n", count_even_values(root));
    printf("\n Height = %d\n", height(root));

    // root = bst_delete(root, 22);
    // root = bst_delete(root, 65);

    printf("\n\nChoose a value to delete:\n");
    scanf("%d", &r);
    root = bst_delete(root, r);
    
    inorder(root);
    preorder(root);
    postorder(root);

    printf("\n\nThere are %d nodes in this BST.\n", count_nodes(root));
    printf("\nThere are %d even values in this BST.\n", count_even_values(root));
    printf("\n Height = %d\n", height(root));
   
    if (has_negatives(root))
        printf("This BST has negative(s).\n");

    // Destroys BST
    root = destroy_nodes(root);

    return 0;

}