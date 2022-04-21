#include <stdlib.h>
#include "Stack.h"

/***************** Auxiliary Functions *****************/

void deleteList(charNode*);
charNode* createNode(char), *insertNode(charNode*, charNode*);

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	s->head = NULL;
}

void destroyStack(Stack* s) 
{
	if (!s->head) // empty stack
		return;

	deleteList(s->head);
	s->head = NULL;
}

void push(Stack* s, char data)
{	
	s->head = insertNode(s->head, createNode(data));
}

char pop(Stack* s)
{	// save the current list head and the data of the first node
	charNode* head = s->head;
	char data = head->data;
	
	// update the list head to the next node
	s->head = head->next;
	
	// delete the previous node
	free(head);
	head = NULL;

	return data; // return the saved data
}


int isEmptyStack(const Stack* s)
{
	return !s->head;
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	// add your code here
}

int isPalindrome(Stack* s)
{
	// add your code here
}

void rotateStack(Stack* s, int n)
{
	// add your code here
}

void deleteList(charNode* head) {
	charNode* node = head;

	while (head) {
		head = head->next;
		free(node);
		node = head;
	}
}
charNode* createNode(char data) {
	charNode* node = (charNode*)malloc(sizeof(charNode));

	// malloc check
	if (node) {
		node->data = data;
		node->next = NULL;
	}
	else // malloc faild
		puts("Memory allocation error");

	return node;
}
charNode* insertNode(charNode* head, charNode* node) {
	if (!node) // edge case
		return head;

	node->next = head;
	return node;
}
