#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

void deleteList(intNode*), flipflop(Queue*);
int numofNodes(Queue*), sumofNodes(Queue*);

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{
	q->head = NULL;
	q->tail = NULL;
}

void destroyQueue(Queue* q)
{
	if (q->head == NULL && q->tail == NULL) // empty queue
		return;
	
	deleteList(q->head);
	q->head = NULL;
}

void enqueue(Queue* q, unsigned int data)
{
	{
		intNode* newnode = (intNode*)calloc(1, sizeof(intNode));
		
		if (!newnode)
		{
			puts("Memory allocation error");
			return;
		}
		
		newnode->data = data;
		if (isEmptyQueue(q))
		{
			q->head = q->tail = newnode;
			return;
		}
		q->tail->next = newnode;
		q->tail = newnode;
	}
}

unsigned int dequeue(Queue* q)
{
	{
		if (isEmptyQueue(q))
		{
			printf("it is empty\n");
			return -1;//  -1 is flag that is empty
		}
		intNode* pointer = q->head;
		q->head = q->head->next;
		if (q->head == NULL)
		{
			q->tail = NULL;
		}
		int data = pointer->data;
		free(pointer);
		return data;
	}
}

int isEmptyQueue(const Queue* q)
{
	if (q->head == NULL)
	{
		return 1;
	}
	return 0;
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	if (isEmptyQueue(q))
	{
		printf("it is empty\n");
		return;
	}
	Queue tmp;
	initQueue(&tmp);
	int numend, counter = -1;
	while (!isEmptyQueue(q))
	{
		numend = dequeue(q);
		enqueue(&tmp, numend);
		counter++;
	}
	enqueue(q, numend);
	printf("after rotate\n %d \t", numend);
	for (int i = 0; i < counter; i++)
	{
		numend = dequeue(&tmp);
		printf("%d \t", numend);
		enqueue(q, numend);
	}
}

void cutAndReplace(Queue* q)
{
	int numof = numofNodes(q);
	if (numof == 0)
		return;
	Queue tmp;
	initQueue(&tmp);
	if (numof % 2 != 0)
	{
		enqueue(q, sumofNodes(q) / numofNodes(q));
		numof++;
	}

	for (int i = 0; i < numof / 2; i++)
	{
		enqueue(&tmp, dequeue(q));
	}
	flipflop(q);
	while (!isEmptyQueue(&tmp))
	{
		enqueue(q, dequeue(&tmp));
	}
}

void sortKidsFirst(Queue* q)
{
	if (isEmptyQueue(q))
		return;
	int last, current, output;
	last = dequeue(q);
	Queue tmp1, tmp2;
	initQueue(&tmp1); initQueue(&tmp2);
	enqueue(&tmp1, last);
	while (!isEmptyQueue(q))
	{
		current = dequeue(q);
		if (current > last)
		{
			enqueue(&tmp1, current);
			last = current;
		}
		else
		{
			output = dequeue(&tmp1);
			while (current > output)
			{
				enqueue(&tmp2, output);
				output = dequeue(&tmp1);
			}
			enqueue(&tmp2, current);
			enqueue(&tmp2, output);
			while (!isEmptyQueue(&tmp1))
				enqueue(&tmp2, dequeue(&tmp1));
			while (!isEmptyQueue(&tmp2))
				enqueue(&tmp1, dequeue(&tmp2));
		}
	}
	printf("after sorting\n");
	while (!isEmptyQueue(&tmp1))
	{
		current = dequeue(&tmp1);
		printf("%d \t", current);
		enqueue(q, current);

	}
}

void deleteList(intNode* head) {
	intNode* node = head;

	while (head) {
		head = head->next;
		free(node);
		node = head;
	}
}

void flipflop(Queue* q)
{
	if (isEmptyQueue(q))
		return;
	Queue tmp, tmp2;
	initQueue(&tmp);
	initQueue(&tmp2);
	int sum = numofNodes(q);
	if (sum == 1)
	{
		return;
	}
	while (numofNodes(&tmp2) != sum)
	{

		while (numofNodes(q) != 1 && numofNodes(q) != 0)
		{
			enqueue(&tmp, dequeue(q));
		}
		enqueue(&tmp2, dequeue(q));

		while (numofNodes(&tmp) != 1 && numofNodes(&tmp) != 0)
		{

			enqueue(q, dequeue(&tmp));
		}
		if (!isEmptyQueue(&tmp))
		{
			enqueue(&tmp2, dequeue(&tmp));
		}

	}
	while (!isEmptyQueue(&tmp2))
	{
		enqueue(q, dequeue(&tmp2));
	}
}

int numofNodes(Queue* q)
{
	if (isEmptyQueue(q))
		return 0;
	Queue tmp;
	initQueue(&tmp);
	int counter = 0;
	while (!isEmptyQueue(q))
	{
		counter++;
		enqueue(&tmp, dequeue(q));
	}
	while (!isEmptyQueue(&tmp))
	{
		enqueue(q, dequeue(&tmp));
	}
	return counter;
}

int sumofNodes(Queue* q)
{
	if (isEmptyQueue(q))
		return 0;
	Queue tmp;
	initQueue(&tmp);
	int sum = 0, data;
	while (!isEmptyQueue(q))
	{
		sum += data = dequeue(q);
		enqueue(&tmp, data);
	}
	while (!isEmptyQueue(&tmp))
	{
		enqueue(q, dequeue(&tmp));
	}
	return sum;
}