#include <stdio.h>
#include <string.h>

#include "Stack.h"
#include "Queue.h"

#define stringLEN 100

/***************** Auxiliary Functions *****************/

void deleteList(charNode*), test_unit1(int), test_unit2(int);
charNode* createNode(char), * insertNode(charNode*, charNode*);

void main()
{
	int c1 = 3, c2 = 3;
	
	test_unit1(c1);
	test_unit1(c2);
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