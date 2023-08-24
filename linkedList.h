#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} node;

// Initializes the head of the linked list
int init(struct node **head);

// Inserts a node with the given data at the position specified
int insert(struct node **head, int position, int data);

// Inserts a node with the given data immediately after the node containing preData
int insertAfter(struct node **head, int preData, int data);

// Inserts a node with the given data immediately before the node containing postData
int insertBefore(struct node **head, int postData, int data);

// Searches for the key in the list and returns a pointer to the key (if found) in ptrToKey
int search(struct node **head, int key, struct node **ptrToKey);

// Prints the linked list
int traverse(struct node *head);

// Bonus Functions:

// Print the linked list in reverse order (recursively)
int reverseTraverse(struct node *head);

// Reverses the linked list
int reverse(struct node **head);
