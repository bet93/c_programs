// Sean Szumlanski
// COP 3502, Fall 2020

// ===========
// make-list.c
// ===========
// This is the program I used in class today to demonstrate the basic anatomy of
// linked lists.
//
// The values to be placed in each node are given at the command line. This is
// quite limited and is currently designed to work with two-digit integers only.
//
// This is just a little program for printing out linked list diagrams.
// The main thing to notice is how the address of each node is stored in
// the previous node's 'next' field in the linked list.
//
// This won't look so hot if you print a lot of nodes and exceed the print
// width of your screen / terminal window.
//
// Example usage and output:
//
//
//    ./a.out 14 58 37
//
//
//    addr:   (0x1dd6)        (0x181a)        (0x0061)       
//
//           +--------+      +--------+      +--------+      
//    data:  |   14   |      |   58   |      |   37   |      
//           +--------+ ---> +--------+ ---> +--------+ --->  X
//    next:  | 0x181a |      | 0x0061 |      | (NULL) |      
//           +--------+      +--------+      +--------+      
//               ^
//               head = 0x1dd6


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants based on output format for diagram shown above.
#define NUM_LINES 7
#define NODE_WIDTH 16

// Concatenate diagram for a single node to our current lines of output.
void listCat(char **output, int data, int *addy, int i)
{
	// each node is 16 spaces wide (and we include space for '\0')
	char buffer[NODE_WIDTH + 1];

	sprintf(buffer, " (0x%04x)       ", addy[i]);
	strcat(output[0], buffer);

	sprintf(buffer, "+--------+      ");
	strcat(output[2], buffer);

	// Shamelessly alter the data to ensure it has exactly two digits. This
	// keeps all the node output nicely aligned.
	if (data < 0) data *= -1;
	if (data > 99) data %= 100;
	if (data < 10) data += 10;

	sprintf(buffer, "|   %2d   |      ", data);
	strcat(output[3], buffer);

	sprintf(buffer, "+--------+ ---> ");
	strcat(output[4], buffer);

	if (addy[i + 1] == 0)
		sprintf(buffer, "| (NULL) |      ");
	else
		sprintf(buffer, "| 0x%04x |      ", addy[i + 1]);
	strcat(output[5], buffer);

	sprintf(buffer, "+--------+      ");
	strcat(output[6], buffer);
}

// Construct a linked list diagram with n nodes.
void makeList(char **values, int n)
{
	int i, *addy;
	char **output;

	// If we don't have any nodes to print, just output an empty list and return.
	if (n <= 0)
	{
		printf("\n");
		printf("   head = NULL  (empty list)\n");
		printf("\n");
		return;
	}

	// A place to hold (n + 1) memory addresses. The last will always be NULL.
	addy = malloc(sizeof(int) * (n + 1));

	// We have NUM_LINES lines of output to print.
	output = malloc(sizeof(char *) * NUM_LINES);

	// Each node we print is 16 spaces wide, plus we have 7 characters of lead-in
	// text at the beginning of each line, and 3 characters leading out at the
	// end of our linked list (space, 'X', and '\0'). malloc() space accordingly.
	for (i = 0; i < NUM_LINES; i++)
		output[i] = malloc(sizeof(char) * (n * NODE_WIDTH + 7 + 3));

	// Generate some random "addresses" to print for our nodes.
	for (i = 0; i < n; i++)
		addy[i] = rand() % 9999 + 1;
	addy[n] = 0;

	// Add leading text to beginning of each output line.
	strcpy(output[0], "addr:  ");
	strcpy(output[1], "");
	strcpy(output[2], "       ");
	strcpy(output[3], "data:  ");
	strcpy(output[4], "       ");
	strcpy(output[5], "next:  ");
	strcpy(output[6], "       ");

	// Concatenate node diagrams to the output lines -- one node for each call to
	// listCat().
	for (i = 0; i < n; i++)
		listCat(output, atoi(values[i]), addy, i);

	// Cancatenate our final pointer (X) to the end of the diagram(s).
	strcat(output[4], " X");

	// Output the lines we've constructed.
	printf("\n");
	for (i = 0; i < NUM_LINES; i++)
		printf("%s\n", output[i]);
	printf("           ^\n");
	printf("           head = 0x%04x\n", addy[0]);
	printf("\n");

	// Avoid memory leaks
	for (i = 0; i < NUM_LINES; i++)
		free(output[i]);
	free(output);
}

int main(int argc, char **argv)
{
	srand(time(NULL));

	// Print linked list diagram with <n> nodes.
	makeList(argv + 1, argc - 1);
	
	return 0;
}
