/*
	TITLE          Goldback's hypothesis	Chapter1Goldbach.c 
	COMMENT
		Objective: Write a code that checks the Goldback's 
				   conjecture hypothesis.
				   1. Every even integer > 2 could be represented as a sum of two prime numbers.
				   2. Every integer > 17 could be represented as a sum of three unique prime numbers.
				   3. Every integer could be represented as a sum consisted of maximally six prime numbers.
				   4. Every odd integer > 5 could be represented as a sum of three prime numbers.
				   5. Every even integer could be represented as a difference between two prime numbers.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
		     Date: 31.08.2016

*/

// upper bound of the interval we search for primes
#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include "Chapter1HelperArray.h"
#include "Chapter1HelperPrime.h"
#include "Chapter1Goldbach.h"

int main()
{
	 testGoldbackHypothesis();

	 return 0;
}

