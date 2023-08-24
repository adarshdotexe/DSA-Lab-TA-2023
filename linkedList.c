#include "linkedList.h"

int main(int argc, char *argv[]) {
	// Create a linked list
	node *head;
	init(&head);
	for (int i = 0; i < 10; i++) {
		insert(&head, i, rand() % 100);
	}
	traverse(head);
	insertAfter(&head, head->next->next->data, 100);
	traverse(head);
	insertBefore(&head, 100, 200);
	traverse(head);
	node *temp = NULL;
	search(&head, 100, &temp);
	printf("%p\n", temp);
}

int init(node **head) {
	if (head == NULL) {
		return -1;
	}
	*head = NULL;
	return 0;
}

int insert(struct node **head, int position, int data) {
	if (head == NULL) {
		return -1;
	}
	if (position < 0) {
		return -1;
	}
	if (position == 0) {
		node *newNode = (node *)malloc(sizeof(node));
		newNode->data = data;
		newNode->next = *head;
		*head = newNode;
		return 0;
	}
	node *temp = *head;
	for (int i = 0; i < position - 1; i++) {
		if (temp == NULL) {
			return -1;
		}
		temp = temp->next;
	}
	node *newNode = (node *)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = temp->next;
	temp->next = newNode;
	return 0;
}

int insertAfter(struct node **head, int preData, int data) {
	if (head == NULL) {
		return -1;
	}
	node *temp = *head;
	while (temp != NULL && temp->data != preData) {
		temp = temp->next;
	}
	if (temp == NULL) {
		return -1;
	}
	node *newNode = (node *)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = temp->next;
	temp->next = newNode;
	return 0;
}

int insertBefore(struct node **head, int postData, int data) {
	if (head == NULL) {
		return -1;
	}
	if (*head == NULL) {
		return -1;
	}
	if ((*head)->data == postData) {
		node *newNode = (node *)malloc(sizeof(node));
		newNode->data = data;
		newNode->next = *head;
		*head = newNode;
		return 0;
	}
	node *temp = *head;
	while (temp->next != NULL && temp->next->data != postData) {
		temp = temp->next;
	}
	if (temp->next == NULL) {
		return -1;
	}
	node *newNode = (node *)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = temp->next;
	temp->next = newNode;
	return 0;
}

int search(struct node **head, int key, struct node **ptrToKey) {
	if (head == NULL) {
		return -1;
	}
	if (*head == NULL) {
		return -1;
	}
	node *temp = *head;
	while (temp != NULL && temp->data != key) {
		temp = temp->next;
	}
	if (temp == NULL) {
		return -1;
	}
	*ptrToKey = temp;
	return 0;
}

int traverse(struct node *head) {
	if (head == NULL) {
		return -1;
	}
	node *temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	return 0;
}

// Bonus Functions:

// Print the linked list in reverse order (recursively)
int reverseTraverse(struct node *head) {
	if (head == NULL) {
		return -1;
	}
	reverseTraverse(head->next);
	printf("%d ", head->data);
	return 0;
}

// Reverses the linked list
int reverse(struct node **head) {
	if (head == NULL) {
		return -1;
	}
	if (*head == NULL) {
		return -1;
	}
	node *prev = NULL;
	node *curr = *head;
	node *next = NULL;
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
	return 0;
}