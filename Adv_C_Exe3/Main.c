#include <stdio.h>

#include "Stack.h"
#include "Queue.h"

void main()
{
	Queue tmp;
	initQueue(&tmp);
	enqueue(&tmp, 8); // head
	enqueue(&tmp, 11); 
	enqueue(&tmp, 5); 
	enqueue(&tmp, 3); 
	enqueue(&tmp, 1); 
	enqueue(&tmp, 4); // tail
	rotateQueue(&tmp);
	cutAndReplace(&tmp);
	sortKidsFirst(&tmp);
	destroyQueue(&tmp);
}