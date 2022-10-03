// Sean Szumlanski
// COP 3502, Fall 2020

// LinkedLists.c
// =============
// Linked lists. Supports head removal and tail insertion. Maintains head and
// tail pointers within a LinkedList struct. Comments are sparse because we've
// covered these functions in class.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "LinkedLists.h"


node *create_node(int data)
{
	node *n = malloc(sizeof(node));
	n->data = data;
	n->next = NULL;
	return n;
}

LinkedList *create_list(void)
{
	return calloc(1, sizeof(LinkedList));
}

node *recursive_destroyer(node *head)
{
	if (head == NULL)
		return NULL;

	recursive_destroyer(head->next);
	free(head);

	return NULL;
}

LinkedList *destroy_list(LinkedList *list)
{
	if (list == NULL)
		return NULL;

	recursive_destroyer(list->head);
	free(list);

	return NULL;
}

void tail_insert(LinkedList *list, int data)
{
	if (list == NULL)
		return;

	if (list->tail == NULL)
	{
		list->head = list->tail = create_node(data);
		return;
	}

	list->tail->next = create_node(data);
	list->tail = list->tail->next;
}

int head_delete(LinkedList *list)
{
	int retval;
	node *temp;

	if (list == NULL || list->head == NULL)
		return EMPTY_LIST_ERR;

	retval = list->head->data;

	temp = list->head->next;

	free (list->head);

	list->head = temp;

	if (list->head == NULL)
		list->tail = NULL;

	return retval;
}
