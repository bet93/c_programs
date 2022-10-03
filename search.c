#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct bstNode
{
    struct bstNode *left, *right;
    char str[100];
} bstNode;

int search(bstNode *root, char *target)
{
    if (root == NULL)
    {
        return 0;
    }

    int compare = strcmp(target, root->str); 
    
    if (compare < 0)
    {
        return search(root->left, target);
    }
    else if (compare > 0)
    {
        return search(root->right, target);
    }

    return 1;
}