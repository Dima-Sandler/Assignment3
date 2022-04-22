#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

#define stringLEN 100

/***************** Auxiliary Functions *****************/

void deleteList(charNode*);
charNode* createNode(char), * insertNode(charNode*, charNode*);

void main()
{
	puts("\tTest unit for function: <flipBetweenHashes>\n");

	char test_string[stringLEN];

	while (1)
	{	
		printf("Enter a sentense: ");
		fseek(stdin, 0, SEEK_END);
		gets_s(test_string, stringLEN);
		
		flipBetweenHashes(test_string);
		printf("\n");
	}
}