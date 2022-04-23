#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "Stack.h"
#include "Queue.h"

#define stringLEN 100

/***************** Auxiliary Functions *****************/

void deleteList(charNode*), test_unit1(int), test_unit2(int), test_unit3(int);
charNode* createNode(char), * insertNode(charNode*, charNode*);

void main()
{
	int c1 = 3, c2 = 3, c3 = 3;
	
	test_unit1(c1);
	test_unit2(c2);
	test_unit3(c3);
}

void test_unit1(int cnt)
{
	puts("\tTest unit for function: <flipBetweenHashes>\n");
	
	char test_string[stringLEN];

	while (cnt--)
	{	
		printf("Enter a sentense: ");
		fseek(stdin, 0, SEEK_END);
		gets_s(test_string, stringLEN);
		
		flipBetweenHashes(test_string);
		printf("\n");
	}
}
void test_unit2(int cnt)
{
	puts("\tTest unit for function: <isPalindrome>\n");

	char str[stringLEN];

	while (cnt--)
	{
		printf("Enter a string: ");
		fseek(stdin, 0, SEEK_END);
		gets_s(str, stringLEN);

		// create and initialize a test stack
		Stack test_stack;
		initStack(&test_stack);

		// insert the string to the test stack
		for (int i = 0; i < strlen(str); i++)
			push(&test_stack, str[i]);
		
		printf("Result: ");
		
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
	puts("\tTest unit for function: <rorateStack>\n");

	char str[stringLEN];
	int n;

	while (cnt--)
	{
		printf("Enter a string: ");
		fseek(stdin, 0, SEEK_END);
		gets_s(str, stringLEN);

		printf("Enter number of elements to shift: ");
		scanf("%d", &n);

		// create and initialize a test stack
		Stack test_stack;
		initStack(&test_stack);

		// insert the string to the test stack
		for (int i = 0; i < strlen(str); i++)
			push(&test_stack, str[i]);

		rotateStack(&test_stack, n);

		while (!isEmptyStack(&test_stack))
			putchar(pop(&test_stack));
	
		printf("\n");
	}
}
