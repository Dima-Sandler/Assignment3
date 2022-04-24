#define _CRT_SECURE_NO_WARNINGS
#define stringLEN 100

#include <stdio.h>
#include <string.h>
#include "Stack.h"
#include "Queue.h"

void test_unit1(int), test_unit2(int), test_unit3(int);

void main()
{
	/***************** Test of Part A - Stack ADT *****************/
	
	test_unit1(1);
	test_unit2(1);
	test_unit3(2);

	/***************** Test of Part B - Queue ADT *****************/

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

void test_unit1(int cnt)
{
	puts("\t\tTest unit for function: <flipBetweenHashes>\n");
	
	char test_string[stringLEN];

	for (int i = 1; i <= cnt; i++)
	{	
		printf("Attemp %d:\n", i);
		printf("\tEnter a sentense: ");
		fseek(stdin, 0, SEEK_END);
		gets_s(test_string, stringLEN);
		printf("\tResult: ");
		flipBetweenHashes(test_string);
		printf("\n");
	}
}
void test_unit2(int cnt)
{
	puts("\t\tTest unit for function: <isPalindrome>\n");

	char str[stringLEN];

	for (int i = 1; i <= cnt; i++)
	{
		printf("Attemp %d:\n", i);
		printf("\tEnter a string: ");
		fseek(stdin, 0, SEEK_END);
		gets_s(str, stringLEN);

		// create and initialize a test stack
		Stack test_stack;
		initStack(&test_stack);

		// build the test stack from string input
		for (int i = 0; i < strlen(str); i++)
			push(&test_stack, str[i]);
		
		printf("\tResult: ");
		
		if (isPalindrome(&test_stack))
			puts("Palindrome");
		else
			puts("Not Palindrome");

		printf("\n");
		destroyStack(&test_stack);
	}
}
void test_unit3(int cnt)
{
	puts("\t\tTest unit for function: <rorateStack>\n");

	char str[stringLEN];
	int k, n;

	for (int i = 1; i <= cnt; i++)
	{
		
		printf("Attemp %d:\n", i);
		printf("\tEnter a string: ");
		fseek(stdin, 0, SEEK_END);
		gets_s(str, stringLEN);

		printf("\tEnter number of elements to shift: ");
		scanf("%d", &n);

		// create and initialize a test stack
		Stack test_stack;
		initStack(&test_stack);

		// build the test stack from the string input
		for (k = 0; k < strlen(str); k++)
			push(&test_stack, str[k]);

		rotateStack(&test_stack, n);

		// build a string from the result		
		while(!isEmptyStack(&test_stack))
			str[--k] = pop(&test_stack);
		
		// print the result string
		printf("\n\tResult: %s\n\n", str);
	}
}
