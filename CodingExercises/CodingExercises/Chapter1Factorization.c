/*
	TITLE          Sum of reciprocal factors  Chapter1Factorization.c 
	COMMENT
		Objective: Write a program that finds all the numbers
				   whose sum of reciprocal factors 
				   (including 1 and the number itself)
				   equals to 
				   
				   2. Are these perfect numbers? : Not all of them.

				   3. Write a code to find perfect number:
				      number equals the sum of its factors (without itself).
			Input: - 
		   Output: - 
		   Author: Chris B. Kirov
		     Date: 08.09.2016

*/
#include <stdio.h>
#define MAX 100
#include "Chapter1HelperArray.h"

#define CAPACITY 100
int factors[CAPACITY]; // all elements initialized to 0 by default (side effect of global declaration?)

size_t findAllFactors(unsigned int n, int* arr, size_t size);
char isSumOfReciprocalFactorsEqTwo(unsigned int n);
void findNumbersWithSumTwo(void);

void printPerfectNumbers(unsigned long long int limit);

//----------------------------------------------------------------

int main()
{
	findNumbersWithSumTwo();
	// printPerfectNumbers(100000000);
	return 0;
}
//----------------------------------------------------------------

/*
	Function: findAllFactors();

	Stores the factors of number n
	in arr and returns the number
	of found factors.
*/
size_t findAllFactors(unsigned int n, int* arr, size_t size)
{
	size_t i, index = 0;

	for (i = 1; i <= n; ++i)
	{
		if (n % i == 0)
		{
			arr[index] = i;
			++index;
		}

		// number of factors < CAPACITY
		if (index >= CAPACITY)
		{
			break;
		}
	}
	return index;
}

//----------------------------------------------------------------

/*
	Function: isSumOfReciprocalFactorsEqTwo();

	Finds whether the sum of reciprocal
	factors of number n sum up to 2.
*/
char isSumOfReciprocalFactorsEqTwo(unsigned int n)
{
	size_t i, numberOfFoundFactos = 0;
	unsigned int denom = 1, sum = 0, targetSum = 2;

	numberOfFoundFactos = findAllFactors(n, factors, CAPACITY);

	for (i = 0; i < numberOfFoundFactos; ++i)
	{
		sum += factors[i];
	}
	denom = factors[numberOfFoundFactos - 1];

	// release resources
	initArray(factors, numberOfFoundFactos, 0);

	return sum / denom == targetSum;
}

//----------------------------------------------------------------

/*
	Function: findNumbersWithSumTwo();

*/
void findNumbersWithSumTwo(void)
{
	unsigned int number;

	for (number = 1; number  < 1000; ++number)
	{
		if (isSumOfReciprocalFactorsEqTwo(number))
		{
			printf("\nThe sum of reciprocal factors of number %d equals 2.", number);
		}
	}
}
//----------------------------------------------------------------

/*
	Function: printPerfectNumbers();

	Finds and prints all perfect numbers
	till limit.
*/
void printPerfectNumbers(unsigned long long int limit)
{
	unsigned long long int i, sum = 0;
	size_t numberOfFactors = 0;

	for (i = 2; i <= limit; ++i)
	{
		numberOfFactors = findAllFactors(i, factors, CAPACITY);

		// sum all the factors without the number itself
		sum = sumArrayElements(factors, numberOfFactors - 1);

		if (i == sum)
		{
			printf("\n%I64u is a perfect number.\n", i);
			getchar();
		}

		printf("\ni = %I64u", i);
		// free resources
		initArray(factors, numberOfFactors, 0);
	}
}