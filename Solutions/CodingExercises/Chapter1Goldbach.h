/*
	TITLE          Goldback's hypothesis	Chapter1Goldbach.h 
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
#ifndef CHAPTER1_GOLDBACH_H
#define CHAPTER1_GOLDBACH_H

void First(int* primes, unsigned int size, unsigned int upperBound);
void Second(int* primes, unsigned int size, unsigned int upperBound);
void Third(int* primes, unsigned int size, unsigned int upperBound);
void Fourth(int* primes, unsigned int size, unsigned int upperBound);
void Fifth(int* primes, unsigned int size, unsigned int upperBound);
void testGoldbackHypothesis(void);

#include "Chapter1GoldbachDef.c"
#endif 