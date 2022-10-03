// Sean Szumlanski
// COP 3502, Fall 2020

// Queue.c
// =======
// Linked list-based implementation of queues.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedLists.h"  // Functional prototypes & struct definitions for linked lists
#include "Queue.h"        // Functional prototypes & struct definitions for queues


// Create the queue. Initialize its internal linked list.
Queue *create_queue(void)
{
	Queue *q = malloc(sizeof(Queue));
	q->list = create_list();
	q->size = 0;
	return q;
}

int isEmpty(Queue *q)
{
	return (q == NULL || q->size == 0);
}

// When using linked lists, we might (naively?) assume there is always room for more.
int isFull(Queue *q)
{
	return 0;
}

// Insert element at back of queue (using tail insertion).
void enqueue(Queue *q, int data)
{
	if (q == NULL || q->list == NULL)
		return;

	q->size++;
	tail_insert(q->list, data);
}

// Remove front of queue (using head removal).
int dequeue(Queue *q)
{
	if (isEmpty(q))
		return EMPTY_QUEUE_ERR;

	q->size--;
	return head_delete(q->list);
}

// Peek at the front of the queue without dequeueing.
int peek(Queue *q)
{
	if (isEmpty(q))
		return EMPTY_QUEUE_ERR;

	return q->list->head->data;
}

// This is acting as an alias for peek(). This is slightly slower than just
// having all of peek's code in this function, but it frees us from having to
// maintain and update two different copies of the exact same code.
int front(Queue *q)
{
	return peek(q);
}

Queue *destroy_queue(Queue *q)
{
	if (q == NULL)
		return NULL;
	
	destroy_list(q->list);
	free(q);

	return NULL;
}

// Just a trivial test of the queue's functionality.
int main(void)
{
	int i, r, n = 5;
	Queue *q = create_queue();

	srand(time(NULL));

	// Enqueue a few elements.
	for (i = 0; i < n; i++)
	{
		printf("Enqueueing %d...\n", r = rand() % 100 + 1);
		enqueue(q, r);
	}

	// Empty out the queue.
	while (!isEmpty(q))
		printf("%d\n", dequeue(q));

	// Exercise: Write this function yourself.
	destroy_queue(q);

	return 0;
}
