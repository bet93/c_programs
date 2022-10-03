// Sean Szumlanski
// COP 3502, Fall 2020

// avl.c
// =====
// My implementation of AVL trees in C.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// print notifications when we insert, delete, or perform rotations?
#define VERBOSE 1

typedef struct node
{
	int data;
	int height;
	struct node *left;
	struct node *right;
} node;

int max(int a, int b)
{
	return (a > b) ? a : b;
}

// create node; initialize height to 0 and left and right children to NULL
node *create_node(int data)
{
	node *n = malloc(sizeof(node));

	n->data   = data;
	n->left   = n->right = NULL;
	n->height = 0;

	if (VERBOSE)
		printf("    Inserted %d\n", data);

	return n;
}

// returns height of the subtree rooted at 'root' (-1 if root is NULL)
int H(node *root)
{
	return (root == NULL) ? -1 : root->height;
}

// returns balance factor of current node (assuming tree heights are properly
// maintained during insertion and deletion)
int BF(node *root)
{
	return H(root->left) - H(root->right);
}

// perform single left rotation at specified node
node *SingleLeft(node *root)
{
	// Hold onto the root's right child. It's going to become the new root.
	node *temp = root->right;

	// Root is moving down to the left and losing its right child. It can take
	// the new root's orphaned left child as its own right child.
	root->right = temp->left;

	// Right child now moves up to take the place of the root.
	temp->left = root;

	// Update tree heights.
	root->height = 1 + max(H(root->left), H(root->right));
	temp->height = 1 + max(H(temp->left), H(temp->right));

	if (VERBOSE)
		printf("    (Performed single left rotation at node %d)\n", root->data);

	return temp;
}

// perform single right rotation at specified node
node *SingleRight(node *root)
{
	// Hold onto the root's left child. It's going to become the new root.
	node *temp = root->left;

	// Root is moving down to the right and losing its left child. It can take
	// the new root's orphaned right child as its own left child.
	root->left = temp->right;

	// Left child now moves up to take the place of the root.
	temp->right = root;

	// Update tree heights.
	root->height = 1 + max(H(root->left), H(root->right));
	temp->height = 1 + max(H(temp->left), H(temp->right));

	if (VERBOSE)
		printf("    (Performed single right rotation at node %d)\n", root->data);

	return temp;
}

// check balance factor at this node; if it's out of whack, perform rotations
node *AVL_balance(node *root)
{
	// calculate balance factor
	int bf = BF(root);

	// AVL trees are unhappy when they have balance factors of -2
	if (bf == -2)
	{
		// The AVL tree is right-heavy. If the right child is left-heavy, we need
		// to perform a double rotation. This is the first step (a single right
		// rotation about the right child).
		//if (BF(root->right) == 1)
		if (BF(root->right) > 0)
			root->right = SingleRight(root->right);

		// This is the second step of the double rotation, which is also the
		// single rotation we have to perform when the AVL tree and the right
		// child are both right-heavy.
		root = SingleLeft(root);
	}
	// AVL trees are unhappy when they have balance factors of +2
	else if (bf == 2)
	{
		// The AVL tree is left-heavy. If the left child is right-heavy, we need
		// to perform a double rotation. This is the first step (a single left
		// rotation about the left child).
		//if (BF(root->left) == -1)
		if (BF(root->left) < 0)
			root->left = SingleLeft(root->left);

		// This is the second step of the double rotation, which is also the
		// single rotation we have to perform when the AVL tree and the left
		// child are both left-heavy.
		root = SingleRight(root);
	}

	return root;
}

// AVL insertion is much like BST insertion, but we balance the tree as needed.
// This function updates all (sub)tree heights affected by insertion, as well.
node *AVL_insert(node *root, int data)
{
	if (root == NULL)
		return create_node(data);

	// left subtree insertion
	else if (data < root->data)
		root->left = AVL_insert(root->left, data);

	// right subtree insertion
	else if (data > root->data)
		root->right = AVL_insert(root->right, data);

	// disallow insertion of duplicates
	else
		return root;

	// update height of the subtree rooted here
	root->height = 1 + max(H(root->left), H(root->right));

	// restore the balance if necessary
	root = AVL_balance(root);

	return root;
}

// returns max value in subtree (recursive version)
int findMax(node *root)
{
	if (root == NULL)
		return -1;

	if (root->right == NULL)
		return root->data;
	else
		return findMax(root->right);
}

// delete an element from a binary search tree
node *AVL_delete(node *root, int data)
{
	node *temp = NULL;

	if (root == NULL)
		return NULL;

	// if we've found the data
	if (root->data == data)
	{
		if (VERBOSE)
			printf("    Deleted %d\n", data);

		// if no children, get rid of node
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return NULL;
		}
		// if only right child exists, move that child up
		else if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return temp;
		}
		// if only left child exists, move that child up
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return temp;
		}
		else
		{
			// move max data from left subtree up here
			root->data = findMax(root->left);

			// now delete that node from the left subtree
			root->left = AVL_delete(root->left, root->data);
		}
	}
	// delete from left subtree if data < root->data
	else if (data < root->data)
	{
		root->left = AVL_delete(root->left, data);
	}
	// delete from right subtree if data > root->data
	else
	{
		root->right = AVL_delete(root->right, data);
	}

	// update height of the subtree rooted here
	root->height = 1 + max(H(root->left), H(root->right));

	// restore the balance if necessary
	root = AVL_balance(root);

	return root;
}

// print inorder traversal of tree with balance factors in parentheses
void inorder_BF(node *root)
{
	if (root == NULL)
		return;

	inorder_BF(root->left);
	printf("%d(%d)  ", root->data, BF(root));
	inorder_BF(root->right);
}

// print inorder traversal of tree with subtree heights in parentheses
void inorder_H(node *root)
{
	if (root == NULL)
		return;

	inorder_H(root->left);
	printf("%d(%d)  ", root->data, H(root));
	inorder_H(root->right);
}

// prints main menu; returns integer value of "quit" selection
int printMenu(void)
{
	int i = 0;

	printf("\n");
	printf("[%d] Insert Node (by Key)\n", ++i);
	printf("[%d] Delete Node (by Key)\n", ++i);
	printf("[%d] Insert <N> Random Keys\n", ++i);
	printf("[%d] Print Inorder Traversal (with balance factors)\n", ++i);
	printf("[%d] Print Inorder Traversal (with subtree heights)\n", ++i);
	printf("[%d] Quit\n\n", ++i);

	printf("Make your selection: ");
	return i;
}

// destroy the AVL tree; this is left as an exercise for the class
node *AVL_destroy(node *root)
{
	// ...

	return NULL;
}

// Is 'key' in the tree? Returns 1 if so, 0 otherwise.
int findKey(node *root, int key)
{
	if (root == NULL)
		return 0;
	else if (key < root->data)
		return findKey(root->left, key);
	else if (key > root->data)
		return findKey(root->right, key);
	else
		return 1;	
}

int main(void)
{
	int i, n, cmd, quit, key;
	node *root = NULL;

	srand(time(NULL));

	do
	{
		// print menu; 'quit' stores the integer value of the quit command for
		// comparison at the end of the do-while loop
		quit = printMenu();

		// get user input
		scanf("%d", &cmd);

		switch (cmd)
		{
			case 1:
				// specify a key to insert into the AVL tree
				printf("\n -> Key to insert: ");
				scanf("%d", &key);

				if (VERBOSE)
					printf("\n");

				// NOTE: Calling findKey() here is inefficient because it
				// duplicates the search effort before we perform insertion, but
				// it allows us to keep the output nicely formatted.
				if (findKey(root, key))
				{
					if (VERBOSE)
						printf("    %d is already in the tree...\n", key);
				}
				else
				{
					root = AVL_insert(root, key);
				}
				break;

			case 2:
				// specify a key to delete from the AVL tree (if present)
				printf("\n -> Value of key to delete: ");
				scanf("%d", &key);

				if (VERBOSE)
					printf("\n");

				if (!findKey(root, key))
				{
					if (VERBOSE)
						printf("    %d is not in the tree...\n", key);
				}
				else
				{
					root = AVL_delete(root, key);
				}
				break;

			case 3:
				// NOTE: Sometimes it will look like this option attempts to
				// insert fewer than 'n' nodes, because there is no output when
				// it tries to insert a node that is already in the AVL tree.
				// (The insertion code does not allow duplicates.)
				printf("\n -> Number of keys to insert: ");
				scanf("%d", &n);

				if (VERBOSE)
					printf("\n");

				for (i = 0; i < n; i++)
				{
					key = rand() % 200 + 1;
					if (findKey(root, key))
					{
						if (VERBOSE)
							printf("    %d is already in the tree...\n", key);
					}
					else
					{
						root = AVL_insert(root, key);
					}
				}
				break;

			case 4:
				// print inorder traversal; also prints balance factors
				printf("\n    ");

				if (root == NULL)
					printf("AVL tree is empty.");
				else
					inorder_BF(root);

				printf("\n");
				break;

			case 5:
				// print inorder traversal; also prints (sub)tree heights
				printf("\n    ");

				if (root == NULL)
					printf("AVL tree is empty.");
				else
					inorder_H(root);

				printf("\n");
				break;

			case 6:
				break;

			default:
				printf("\nCommand not recognized.\n");
		}
	} while (cmd != quit);

	// clean up after yourself
	root = AVL_destroy(root);

	return 0;
}
