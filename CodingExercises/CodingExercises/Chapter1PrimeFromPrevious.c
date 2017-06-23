/*
	TITLE          Primality test	Chapter1PrimeFromPrevious.c 
	COMMENT
		Objective: Write a code that checks for prime numbers
				   by using a set of already found primes.

				   Taking advantage of the statement:
				   To proof that p is prime it is enough
				   to shot that it is not divisible by
				   another prime within [2, sqrt(p)].
			Input: -
		   Output: -
		   Author: Chris B. Kirov
		     Date: 31.08.2016

*/
// upper bound of the interval we search for primes
#define MAX 1000 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> // measure run time
#include "Chapter1HelperArray.h"
#include "Chapter1HelperPrime.h"
//-----------------------------------------------------------

int main()
{
	size_t i;
	clock_t t1Begin, t1End, t2Begin, t2End, t3Begin, t3End;
	double time1, time2, time3;

	printf("The primes up to %d are:\n", MAX);

	t1Begin = clock();
	for (i = 2; i < MAX; ++i)
	{
		if (isPrime(i))
		{
			printf(" %d", i);
		}
	}
	t1End = clock();
	
	printf("\n");

	t2Begin = clock();
	for (i = 2; i < MAX; ++i)
	{
		// TO BE CHECKED AS IT PRODUCES WRONG RESULTS
		if (isPrimeOptimized(i))
		{
			printf(" %d", i);
		}
	}
	t2End = clock();

	printf("\n");

	t3Begin = clock();
	for (i = 2; i < MAX; ++i)
	{
		if (isPrimePrevious(i, primes, N))
		{
			printf(" %d", i);
		}
	}
	t3End = clock();

	time1 = (double) (t1End - t1Begin) / CLOCKS_PER_SEC;
	time2 = (double) (t2End - t2Begin) / CLOCKS_PER_SEC;
	time3 = (double) (t3End - t3Begin) / CLOCKS_PER_SEC;

	printf("\nTimes: time1: %f, time2: %f, time3: %f \n", time1, time2, time3);
}