#include <stdio.h>
#include <stdlib.h>

typedef struct bstNode
{
    struct bstNode *left, *right;
    char str[100];
} bstNode;

// recrusive function that takes in a pointer to root of bst of strings,
// root, and a string, target, and returns 1 if the string is contained in bst.
// otherwise returns 0. Runtime: O(h)
int search(bstNode *root, char *target)
{
    int cmp;

    if (root == NULL)
        return 0;
    
    // compares strings
    cmp = strcmp(target, root->str);

    if (cmp < 0)
        return search(root->left, target);
    else if (cmp > 0)
        return search(root->right, target);

    return 1;

}

int main(void)
{

    return 0;
}