#include <stdio.h>
#include <stdlib.h>

typedef struct bstNode
{
    struct bstNode *left, *right;
    int data;
} bstNode;

bstNode *create_node(int data)
{
    bstNode *newNode = malloc(sizeof(bstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

bstNode *bst_insert(bstNode *root, int data)
{
    if (root == NULL)
        return create_node(data);

    if (data < root->data)
        root->left = bst_insert(root->left, data);

    else if (data > root->data)
        root->right = bst_insert(root->right, data);
    
    else
        ;

    return root;
}

int count_div(bstNode *root, int value)
{
    if (root == NULL)
        return 0;
    
    return (root->data % value == 0) + count_div(root->left, value) + count_div(root->right, value);
}

int main(void)
{
    int k = 7, n = 6, array[] = {4, 2, 6, 3, 7, 8};
    bstNode *root = NULL;

    for (int i =0; i < n; i++)
        root = bst_insert(root, array[i]);

    
    printf("There are %d nodes that are divisible by %d", count_div(root, k), k);
     
    return 0;
}