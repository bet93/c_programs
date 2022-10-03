#include <stdlib.h>
#include "queue.h"
#include "node.h"

Queue *initQueue(void)
{
	Queue *p = malloc(sizeof(Queue));
	
	p->head = NULL;
	p->tail = NULL;
	
	return p;
}

// Insert a new node at the back of the queue (i.e., the tail of the list).
// Return -1 if insertion fails, or 'data' if insertion succeeds. You might
// want to call the createNode() function defined in node.c.
int enqueue(Queue *p, int data)
{
	if (p->head == NULL || p->tail == NULL)
	{
		p->head = p->tail = createNode(data);
		return (p->head == NULL || p->tail == NULL) ? -1 : data;
	}

	node *temp = p->tail;
	temp->next = createNode(data);
	p->tail = temp->next;

	return (p->tail == NULL) ? -1 : data;
}

// Remove the element at the front of the list (i.e., the head of the list).
// Return the 'data' stored in the dequeued node, or -1 if the queue is empty.
// Keep in mind that you need to free() the node being removed to avoid memory
// leaks.
int dequeue(Queue *p)
{
	if (p == NULL || isEmpty(p))
		return -1;
	
	int retval = p->head->data;
	node *temp = p->head;
	p->head = temp->next;
	free(temp);

	return retval;
}

int isEmpty(Queue *p)
{
	return (p->head == NULL);
}
