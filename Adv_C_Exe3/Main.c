#include <stdio.h>
#include "Stack.h"

#include "Queue.h"

void main()
{
	Queue tmp;
	initQueue(&tmp);
	enqueue(&tmp, 6);
	enqueue(&tmp, 1);
	enqueue(&tmp, 5);
	enqueue(&tmp, 2);
	enqueue(&tmp, 3);
	enqueue(&tmp, 1);
	enqueue(&tmp, 9);
	//rotateQueue(&tmp);
	//cutAndReplace(&tmp);
	sortKidsFirst(&tmp);
	destroyQueue(&tmp);
}