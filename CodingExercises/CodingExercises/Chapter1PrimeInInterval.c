/*
	TITLE          Find primes in interval Chapter1PrimeInInterval.c 
	COMMENT
		Objective: Implement an algorithm for finding primes in 
				   interval [a, b] 
				   Hint: considering the first 3 primes a natural
				   number could be expressed as:
				   n = 2 x 3 x 5 x q + r = 30q + r, 
				   or r[0, +/-1, 2, ...,14, 15]

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
	int n = 500;
	unsigned int lower = 100;
	unsigned int upper = 200;

	findPrimesMemoization(n);

	printf("\n\n");
	// primesInInterval not implemented
	primesInInterval(lower, upper);
}