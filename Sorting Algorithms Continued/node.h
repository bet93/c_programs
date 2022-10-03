#ifndef __NODE_H
#define __NODE_H

typedef struct node
{
	int data;
	struct node *next;
} node;

node *createNode(int data);

#endif
