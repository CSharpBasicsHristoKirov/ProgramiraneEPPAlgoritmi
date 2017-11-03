/*
	TITLE          Sieve of Eratosthenes	Chapter1Eratosthenes.c 
	COMMENT
		Objective: Implement the Sieve of Eratosthenes.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
		     Date: 31.08.2016

*/
// upper bound of the interval we search for primes
#define MAX 100000

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Chapter1HelperArray.h"
#include "Chapter1HelperPrime.h"

int main()
{
	unsigned int limit;

	int sieve[MAX];
	initArray(sieve, MAX, 0);
	
	limit = MAX - 1;
	sieveOfEratosthenes(limit, sieve, MAX);

	printSieve(sieve, MAX); 
}