/*
	TITLE          Operman's hypothesis	Chapter1Operman.c 
	COMMENT
		Objective: Write a code that checks the Operman's 
				   conjecture hypothesis.
				   A prime number always exist inbetween n^2 and (n + 1)^2.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
		     Date: 02.09.2016

*/

// upper bound of the interval we search for primes
#define MAX 100 

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Chapter1HelperArray.h"
#include "Chapter1HelperPrime.h"

char isPrimeWithin(int* primes, unsigned int size, int lowerBound, int upperBound);
void testOpermanHypothesis();

//---------------------------------------------------------------------------
int main()
{
	testOpermanHypothesis();
	return 0;
}
//---------------------------------------------------------------------------

/*
	Function: testOpermanHypothesis()

*/
void testOpermanHypothesis()
{
	 int upTo = sqrt((double) MAX);
	 int testNumber;

	 // calculate size of array
	 int error = MAX / 10; // uses adding of error rather than memory reallocation 
	 int size = arraySize(MAX) + error;

	 // allocate memory for the array storing the primes
	 int* primes = 0;
	 primes = (int*)malloc(sizeof(int) * size);

	 // check allocation
	 if (!primes)
	 {
		printf("Failed to allocate memory for array!\n");
	 }
	 initArray(primes, size, 0);

	 findPrimesTill(primes, size, MAX);

	 printArray(primes, size);

	 for (testNumber = 2; testNumber < upTo; ++testNumber)
	 {
		int lower = testNumber * testNumber;
		int upper = (testNumber + 1) * (testNumber + 1);

		 if (isPrimeWithin(primes, size,  lower, upper))	 
		 {
			printf("Operman's conjecture holds!\n");
		 }
		 else
		 {
			printf("?Exception!\n");
		 }
	 
	 }

	 // free allocated memory
	 free(primes);
}
//---------------------------------------------------------------------------

/*
	Function: isPrimeWithin();

*/
char isPrimeWithin(int* primes, unsigned int size, int lowerBound, int upperBound)
{
	int* ptrToArray = primes;
	unsigned int i;

	for (i = 0; i < size; ++i)
	{
		if (ptrToArray[i] > lowerBound && ptrToArray[i] < upperBound)
		{
			printf("A prime within [ %d, %d ] is: %d.\n", lowerBound, upperBound, ptrToArray[i]);
			return 1;
		}
	}
	return 0;
}