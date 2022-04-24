#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Stack.h"

/***************** Auxiliary Functions *****************/

void deleteList(charNode*);
int COUNTERSTACK(const Stack);
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
	if (!sentence || !*sentence) { // edge case or empty string
		putchar('\n');
		return;
	}
	
	while (*sentence) // main loop - iterate over the string
		if (*sentence == '#')
		{
			// create and initialize a helper stack
			Stack stack;
			initStack(&stack);

			// skip the detected hash
			// iterate over the string until the next hash
			// store the string characters in the helper stack
			for (sentence++; *sentence != '#'; sentence++)
			{
				if (!*sentence) // edge case
				{
					destroyStack(&stack);
					putchar('\n');
					
					return;
				}

				push(&stack, *sentence);
			}

			sentence++; // skip the second hash

			// print the characters stored in the stack
			while (!isEmptyStack(&stack))
				putchar(pop(&stack));
		}
		else // hash not detected
		{
			putchar(*sentence);
			sentence++;
		}

	putchar('\n');
}

int isPalindrome(Stack* s)
{
	if (!s) // edge case
		return -1;

	if (isEmptyStack(s))
		return 1;

	int size = 0;
	// create and initialize a helper stack
	Stack t; 
	initStack(&t);

	// loop 1 - get the stack size
	while (!isEmptyStack(s))
	{
		push(&t, pop(s));
		size++;
	}

	if (size == 1)
	{   // 1 element in the stack
		destroyStack(&t);
		return 1;
	}

	// loop 2 - bisect the stack
	for (int i = 0; i < size / 2; i++)
		push(s, pop(&t));
	
	// remove excess element if any
	if (size % 2)
		pop(&t); 

	// loop 3 - compare half stacks
	while (!isEmptyStack(s))
		if (pop(s) != pop(&t))
		{ // not equel
			destroyStack(&t);
			return 0;
		}	
	
	return 1;
}

void rotateStack(Stack* s, int n)
{
	if (isEmptyStack(s))
		return;

	if (s->head->next == NULL)
	{
		return;
	}
	int sum = COUNTERSTACK(*s);
	if (n > sum)
		return;

	if (n == sum)
	{
		return;
	}
	Stack last, first;
	last.head = NULL, first.head = NULL;
	for (int i = 0; i < n; i++)
	{
		push(&last, pop(s));
	}
	while (!isEmptyStack(s))
	{
		push(&first, pop(s));
	}
	s->head = NULL;
	for (int i = 0; i < n; i++)
	{
		char c = pop(&last);
		push(s, c);
	}
	while (!isEmptyStack(&first))
	{
		push(s, pop(&first));
	}
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
int COUNTERSTACK(const Stack s)
{
	if (isEmptyStack(&s))
	{
		printf("Empty Stack");
		return 0;
	}
	int counter = 0;
	charNode* head = s.head;
	while (head != NULL)
	{
		counter++;
		head = head->next;
	}
	return counter;
}

