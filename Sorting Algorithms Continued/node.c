#include <stdlib.h>
#include "node.h"

node *createNode(int data)
{
	node *n = malloc(sizeof(node));
	
	n->data = data;
	n->next = NULL;
	
	return n;
}
