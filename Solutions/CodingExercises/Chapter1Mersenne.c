/*
	TITLE          Find Mersenne prime    Chapter1Mersenne.c 
	COMMENT
		Objective: Find Mersenne prime numbers:
		           1. Find first n Meresenne primes without 
				      using the theorem of Lucas–Lehmer.
				   2. Find first n Meresenne numbers by
				      using the theorem of Lucas–Lehmer.
			Input: - 
		   Output: -
		   Author: Chris B. Kirov
		     Date: 07.09.2016

*/
#include <stdio.h>
#include <math.h> // pow(x, exp)
#include <limits.h> // INT_MAX
#include <time.h> // clock
#define MAX 10000
#include "Chapter1HelperPrime.h"

char isMersenneSuccessive(unsigned int candidate);
void findMersenneSuccessive(unsigned int limit);

char isMersenneLucasLehmer(unsigned int candidate);
void findMersenneLucasLehmer(unsigned int limit);

//----------------------------------------------------------
int main()
{
	// till 8, largest value that could be stored
	int number = 8;
	clock_t t1Begin, t1End, t2Begin, t2End;
	double  time1, time2;

	t1Begin = clock();
	findMersenneSuccessive(number);
	t1End = clock();

	printf("\nLucas-Lehmer\n");

	t2Begin = clock();
	findMersenneLucasLehmer(number);
	t2End = clock();

	time1 = (double) (t1End - t1Begin) / CLOCKS_PER_SEC;
	time2 = (double) (t2End - t2Begin) / CLOCKS_PER_SEC;

	printf("\nSuccessive: %f ms, Lucas-Lehmer: %f ms\n", time1, time2);

	return 0;
}
//----------------------------------------------------------

/*
	Function: isMersenneSuccessive();

	Checks if argument is Mersenne number, i.e.
	of the form 2^(p)-1, where p is prime by
	checking successively for every prime p if
	the resultant 2^(p)-1 is prime.
*/
char isMersenneSuccessive(unsigned int prime)
{
	unsigned long mersenne;
	size_t i;

	mersenne = (unsigned long) pow(2, (double)prime) - 1;

	for (i = 0; i < index; ++i)
	{
		if (primesMemoization[i] < mersenne)
		{
			if (mersenne % primesMemoization[i] == 0)
			{
				return 0;
			}
		}
		else 
		{
			break;
		}
	}
	printf("mersenne: %lu, index: %d\n", mersenne, prime);
	return 1;
}
//----------------------------------------------------------

/*
	Function: findMersenneSuccessive()

	It returns the first n Mersenne numbers.
*/
void findMersenneSuccessive(unsigned int limit)
{
	size_t i, nthMersenne = 0;
	unsigned int prime;
	unsigned int primesUpTo = 10000;
	
	// fills array primesMemoization with "index" primes
	findPrimesMemoization(primesUpTo);
	printf("\n");

	for (i = 0; i <= index; ++i)
	{
		prime = primesMemoization[i];
		if (isMersenneSuccessive(prime))
		{
			nthMersenne++;
		}

		if (nthMersenne >= limit)
		{
			break;
		}
	}
}
//----------------------------------------------------------

/*
	Function: isMersenneLucasLehmer()

	Checks if a number is Mersenne by
	verifying that the relation:
	(E_{p-1} % (2^{p} - 1)) = 0 holds.
*/
char isMersenneLucasLehmer(unsigned int prime)
{
	unsigned int i, limit, res;
	unsigned long mersenne;
	unsigned long long int termN = 4;

	mersenne = (unsigned long) pow(2, (double)prime) - 1;
	if (prime % 2 == 0)
	{
		return prime == 2;
	}
    else 
	{
		res = (unsigned int) sqrt((double) prime);
		for (i = 3; i <= res; i += 2)
		{
                if (prime % i == 0)
				{
					return 0;  
				}
		}

		limit = prime - 2;
		for (i = 1; i <= limit; ++i)
		{
			termN = (termN * termN - 2) % mersenne;
		}
	}
	return termN == 0;
}
//----------------------------------------------------------

/*
	Function: findMersenneLucasLehmer()

*/
void findMersenneLucasLehmer(unsigned int limit)
{
	
	unsigned int i, current = 0;
	unsigned long mersenne, bitsInLong = 64;

	for (i = 2; i <= bitsInLong; i++)
	{
		if (current >= limit)
		{
			break;
		}

		if (isMersenneLucasLehmer(i))	
		{
			mersenne = (unsigned long) pow(2, (double)i) - 1;
			printf("current = %u, mersenne = %lu, index = %u\n", current, mersenne, i);
			++current;
		}
	}
}