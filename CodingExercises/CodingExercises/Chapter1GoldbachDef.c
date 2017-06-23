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

// probably all uppedBounds in the for loops could be doubled
/*
	Function: First();

	Test first hypothesis.
*/
void First(int* primes, unsigned int size, unsigned int upperBound)
{
	unsigned int even;

	for (even = 4; even <= upperBound; even += 2)
	{
		if (isSumOfTwoPrimes(even, primes, size))
		{
			printf("\nFirst Goldback's hypothesis not disproved!\n");
		}
		else
		{
			printf("\nYeah, right: %d\n", even);
		}
	}
}
//-----------------------------------------------------------

/*
	Function: Second();

*/
void Second(int* primes, unsigned int size, unsigned int upperBound)
{
	unsigned int natural;

	for (natural = 17; natural <= upperBound; ++natural)
	{
		if (isSumOfUniqueThreePrimes(natural, primes, size))
		{
			printf("\nSecond Goldback's hypothesis not disproved!\n");
		}
		else
		{
			printf("\nYeah, right: %d\n", natural);
		}
	}
}
//-----------------------------------------------------------

/*
	Function: Third()

*/
void Third(int* primes, unsigned int size, unsigned int upperBound)
{
	int* ptrToArray = primes;
	unsigned int integer;

	for (integer = 0; integer < upperBound; ++integer)
	{
		if (isSumOfTheMostSixPrimes(integer, primes, size))
		{
			printf("\nThird Goldback's hypothesis not disproved!\n");
		}
		else
		{
			printf("\nYeah, right: %d\n", integer);
		}
	}
}
//-----------------------------------------------------------

/*
	Function: Fourth()

*/
void Fourth(int* primes, unsigned int size, unsigned int upperBound)
{
	unsigned int odd;

	for (odd = 7; odd <= upperBound; odd += 2)
	{
		if (isSumOfThreePrimes(odd, primes, size))
		{
			printf("\nFourth Goldback's hypothesis not disproved!\n");
		}
		else
		{
			printf("\nYeah, right: %d\n", odd);
		}
	}
}
//-----------------------------------------------------------

/*
	Function: Fifth();

*/
void Fifth(int* primes, unsigned int size, unsigned int upperBound)
{
	unsigned int even;

	for (even = 2; even <= upperBound; even += 2)
	{
		if(isDifferenceOfPrimes(even, primes, size))
		{
			printf("\nFifth  Goldback's hypothesis not disproved!\n");
		}
		else
		{
			printf("\nYeah, right: %d\n", even);
		}
	}
}
//-----------------------------------------------------------

/*
	Function: testGoldbackHypothesis(void)

*/
void testGoldbackHypothesis(void)
{
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

	 // First(primes, size, MAX);
	 // Second(primes, size, MAX);
	 // Third(primes, size, MAX);
	 // Fourth(primes, size, MAX);
	 Fifth(primes, size, MAX);

	 printf("\nup to the number: %d.\n", MAX);

	 // free allocated memory
	 free(primes);
}