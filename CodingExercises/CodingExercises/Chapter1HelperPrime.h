/*
	TITLE          Goldback's hypothesis	Chapter1HelperPrime.c 
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
#ifndef CHAPTER1HELPERPRIME_H
#define CHAPTER1HELPERPRIME_H
 
// binarySearch dependence
#ifndef CHAPTER1HELPERARRAY_H
#include "Chapter1HelperArray.h"
#endif

char isPrimeOpt2(int n);

double round(double val);
char isPrime(int n);
char isPrimeOptimized(int n);

#define N 25
int primes[N] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 }; 
char isPrimePrevious(int n, int* arr, size_t size);

void sieveOfEratosthenes(int n, int* arr, size_t size);
void printSieve(int* arr, size_t size);

#define MAXN 10000
unsigned int primesMemoization[MAXN], index = 0;
char isPrimeMemoization(unsigned int candidate);
void findPrimesMemoization(unsigned int limit);

void primesInInterval(unsigned int lower, unsigned int upper);

void findPrimesTill(int* primes,unsigned int size, unsigned int upperBound);

char isSumOfTwoPrimes(unsigned int target, int* primes, unsigned int size);
char isSumOfUniqueThreePrimes(unsigned int target, int* primes, unsigned int size);
char isSumOfThreePrimes(unsigned int target, int* primes, unsigned int size);
char isSumOfTheMostSixPrimes(unsigned int target, int* primes, unsigned int size);
char isDifferenceOfPrimes(unsigned int target, int* primes, unsigned int size);

#include "Chapter1HelperPrimeDef.c"
#endif