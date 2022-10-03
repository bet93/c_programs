// Sean Szumlanski
// COP 3502, Fall 2020

// LinkedLists.h
// =============
// Header file for linked lists code. Includes struct definitions and functional
// prototypes. This library supports head removal and tail insertion. Maintains
// head and tail pointers within a LinkedList struct.


#ifndef __LINKEDLISTS_H  // This is an include guard. It's fantastic!
#define __LINKEDLISTS_H


#define EMPTY_LIST_ERR INT_MIN

typedef struct node
{
	int data;
	struct node *next;
} node;

typedef struct LinkedList
{
	node *head;
	node *tail;
} LinkedList;


// Functional prototypes. Notice that I only included functional prototypes for
// functions that we'd want to call from outside of this "library."

LinkedList *create_list(void);

LinkedList *destroy_list(LinkedList *list);

void tail_insert(LinkedList *list, int data);

int head_delete(LinkedList *list);


#endif
