#ifndef __QUEUE_H
#define __QUEUE_H

typedef struct Queue
{
	struct node *head;
	struct node *tail;
} Queue;

Queue *initQueue(void);

int enqueue(Queue *p, int data);

int dequeue(Queue *p);

int isEmpty(Queue *p);

#endif
