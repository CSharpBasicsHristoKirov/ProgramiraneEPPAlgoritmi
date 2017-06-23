/*
	TITLE          Goldback's hypothesis	Chapter1HelperArray.h
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
#ifndef CHAPTER1HELPERARRAY_H
#define CHAPTER1HELPERARRAY_H

#include <math.h>

#ifndef MAX
  #error Define `MAX` before including HelperArray.h
#endif

size_t pi(int x);
size_t arraySize(int x);
void initArray(int* primes, size_t size, int initValue);
void printArray(int* primes, size_t size);
char binarySearch(unsigned int target, int* primes, size_t size);
unsigned long long int sumArrayElements(int* arr, size_t size);

#include "Chapter1HelperArrayDef.c"
#endif