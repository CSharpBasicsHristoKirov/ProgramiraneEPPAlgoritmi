/*
	TITLE          Wilson Theorem	Chapter1PrimeWilson.c 
	COMMENT
		Objective: Write a code that finds prime number
				   using Wilson's Theorem.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
		     Date: 02.09.2016

*/
#define MAX 1000

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t
#include "Chapter1HelperCombinatorics.h"

char isPrimeUsingWilson(uint64_t p);
void theoremOFWilson();

//----------------------------------------------------
int main()
{
	printf("The prime numbers up to %d are: \n", MAX);
	theoremOFWilson();
	printf("\n");
}
//----------------------------------------------------

/*
	Function: primesUsingWilson();
*/
char isPrimeUsingWilson(uint64_t p)
{
	if (p < 2)
	{
		return 0;
	}

	return modeFactorial(p - 1, p) + 1 == p;	 
}
//----------------------------------------------------

/*
	Function: theoremOFWilson();

*/
void theoremOFWilson()
{
	unsigned int i;
	unsigned int upperBound = MAX;

	for (i = 2; i < upperBound; ++i)
	{
		if (isPrimeUsingWilson(i))
		{
			printf(" %d", i);
		}
	}
}