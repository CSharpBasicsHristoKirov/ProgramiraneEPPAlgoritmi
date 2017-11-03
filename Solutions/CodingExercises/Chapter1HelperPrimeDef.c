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

/*
	Function: round();

*/
double round(double val)
{    
    return floor(val + 0.5);
}
//-----------------------------------------------------------

/*
	Function isPrime();

	It returns true if the argument
	is prime, otherwise returns false.
*/
char isPrime(int n)
{
	unsigned int denom = 2;
	unsigned int limit;

	if (n < 2)
	{
		return 0;
	}

	if (n == 2)
	{
		return 1;
	}

	limit = (unsigned) round(sqrt((double) n));

	while (denom <= limit)
	{
		if (n % denom == 0)
		{
			return 0;
		}
		++denom;
	}
	return 1;
}
//-----------------------------------------------------------

/*
	Function: isPrimeOptimized(int n);

*/
char isPrimeOptimized(int n)
{
	 unsigned int increment, upperBound, factorCandidate;

	 if (n < 2)
	 {
		return 0;	 
	 }

	 if (n == 2 || n == 3)
	 {
		return 1;
	 }

	 if (n % 2 == 0 || n % 3 == 0)
	 {
		return 0;
	 }

	 increment = 4;
	 upperBound = (unsigned int) sqrt((double) n);
	 for (factorCandidate = 5; factorCandidate < upperBound; factorCandidate += increment)
	 {
		if (n % factorCandidate == 0) 
		{
            return 0;
        }

		// alternating incrementation, skips multiples of 2, 3, 4
        increment = 6 - increment;
	 }
	 return 1;
}
//-----------------------------------------------------------

/*
	Function: isPrimePrevious()
*/
char isPrimePrevious(int n, int* arr, size_t size)
{
	// algorithm starts here
	size_t i = 0;
	while (primes[i] * primes[i] <= n)
	{
		if (n % primes[i] == 0)
		{
			return 0;
		}
		++i;
	}
	return 1;
}
//-----------------------------------------------------------

/*
	Function: sieveOfEratosthenes();

	Assumes array initialized with 0
	and size >= n. The variable limit
	determined the last number being
	checked. All elements marked with 0 
	are considered prime, all 1-compound.
*/
void sieveOfEratosthenes(int limit, int* sieve, size_t size)
{
	unsigned int i, j;

	i = 2;
	while (i <= limit)
	{
		if (sieve[i] == 0)
		{
			// mark all multiples of i as compound
			j = i * i;
			while (j <= limit)
			{
				sieve[j] = 1;
				j += i;
			}
		}
		++i;
	}
}
//-----------------------------------------------------------

/*
	Function: printSieve()

*/
void printSieve(int* arr, size_t size)
{
	unsigned int i;
	int* ptrToArray = arr;
	int fieldWidth = (int) (1 + log10((double)MAX));

	printf("{");
	for (i = 2; i < size; ++i)
	{
		// print unmarked, prime numbers
		if (ptrToArray[i] == 0)
		{
			printf(" %*u", fieldWidth, i);
		}
	}
	printf(" }\n");
}
//-----------------------------------------------------------

/*
	Function: isPrimeMemoization()

	Every time it finds a prime it stores
	it in an array (primesMemoization[]) and then uses them as 
	primality test.
*/
char isPrimeMemoization(unsigned int candidate)
{
	unsigned int i = 0;
	
	// test candidate agains all the existend primes
	while (i < index && primesMemoization[i] * primesMemoization[i] <= candidate)
	{
		if (candidate % primesMemoization[i] == 0)
		{
			return 0;
		}
		i++;
	}
	return 1;
}
//-----------------------------------------------------------

/*
	Function findPrimesMemoization()

	Find primes up to: limit.
*/
void findPrimesMemoization(unsigned int limit)
{
	unsigned int i = 2;

	while (i < limit)
	{
		if (isPrimeMemoization(i))
		{
			// if i prime store it and print it
			primesMemoization[index] = i;
			index++;
			printf("%d ", i);
		}
		++i;
	}
}
//-----------------------------------------------------------

/*
	Function: primesInInterval();

	Uses the fact that: every natural number could be expressed
	as:
	n = 2 x 3 x 5 x q + r = 30q + r, or r[0, +/-1, 2, ...,14, 15]
*/
void primesInInterval(unsigned int lower, unsigned int upper)
{
	size_t i;
	int fieldWidth = (int) (1 + log10((double)MAX));

	int sieve[MAX];
	initArray(sieve, MAX, 0);
	
	sieveOfEratosthenes(upper, sieve, MAX);

	// print result
	printf("{");
	for (i = lower; i <= upper; ++i)
	{
		if(sieve[i] == 0)
		{
			printf(" %*u", fieldWidth, i);
		}
	}
	printf("}\n");
}
//-----------------------------------------------------------

/*
	Function: findPrimesTill()

	Finds all primes up to given number, n,
	and returns them collected in array.
*/
void findPrimesTill(int* primes,unsigned int size, unsigned int upperBound)
{
	unsigned int index = 0;
	int* ptrToArray = primes;

	unsigned int i = 0;
	for (i = 2; i < upperBound; ++i)
	{
		if (isPrime(i))
		{
			ptrToArray[index++] = i;

			if (index >= size)
			{
				 printf("realloc on i = %d.\n", i);
				 break;
			}
		}
	}
}
//-----------------------------------------------------------

/*
	Function: isSumOfTwoPrimes()

	Checks if argument is a sum of two prime.
*/
char isSumOfTwoPrimes(unsigned int target, int* primes, unsigned int size)
{
	unsigned int i;
	unsigned int remainder;
	int* ptrToArray = primes;

	for (i = 0; i < size; ++i)
	{
		if (ptrToArray[i] < target)
		{
			remainder = target - ptrToArray[i];
		}
		else
		{
			break;
		}

		if (binarySearch(remainder, primes, size))
		{
			printf("%d = %d + %d", target, ptrToArray[i], remainder);
			return 1;
		}
	}
	return 0;
}
//-----------------------------------------------------------

/*
	isSumOfUniqueThreePrimes();

*/
char isSumOfUniqueThreePrimes(unsigned int target, int* primes, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int remainder;
	int* ptrToArray = primes;

	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
		{
			if (ptrToArray[i] + ptrToArray[j] < target)
			{
				remainder = target - ptrToArray[i] - ptrToArray[j];
			}
			else
			{
				break;
			}
			// check uniqueness 
			if (ptrToArray[i] != ptrToArray[j] && ptrToArray[j] != remainder && ptrToArray[i] != remainder)
			{
				if (binarySearch(remainder, primes, size))
				{
					printf("%d = %d + %d + %d", target, ptrToArray[i], ptrToArray[j], remainder);
					return 1;
				}
			}
		}
	}
	return 0;
}
//-----------------------------------------------------------

/*
	isSumOfThreePrimes();

*/
char isSumOfThreePrimes(unsigned int target, int* primes, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int remainder;
	int* ptrToArray = primes;

	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
		{
			if (ptrToArray[i] + ptrToArray[j] < target)
			{
				remainder = target - ptrToArray[i] - ptrToArray[j];
			}
			else
			{
				break;
			}
			 
			if (binarySearch(remainder, primes, size))
			{
				printf("%d = %d + %d + %d", target, ptrToArray[i], ptrToArray[j], remainder);
				return 1;
			}
		}
	}
	return 0;
}
//-----------------------------------------------------------

/*
	Functiop: isSumOfTheMostSixPrimes();

	It could probably be a recursive function.

	Complexity: O(n^6)
*/
char isSumOfTheMostSixPrimes(unsigned int target, int* primes, unsigned int size)
{
	int* ptrToArray = primes;
	unsigned int i, j, k , l ,m ,n;

	for (i = 0; i < size; ++i)
	{
		unsigned int currentSum = ptrToArray[i];
		if (currentSum == target) return 1;
		else if (currentSum > target) break;
		for (j = 0; j < size; ++j)
		{
			currentSum = ptrToArray[i] + ptrToArray[j];
			if (currentSum == target) return 1;
			else if (currentSum > target) break;
			for (k = 0; k < size; ++k)
			{
				currentSum = ptrToArray[i] + ptrToArray[j] + ptrToArray[k];
				if (currentSum == target) return 1;
				else if (currentSum > target) break;
				for (l = 0; l < size; ++l)
				{
					currentSum = ptrToArray[i] + ptrToArray[j] + ptrToArray[k] + ptrToArray[l];
					if (currentSum == target) return 1;
					else if (currentSum > target) break;
					for (m = 0; m < size; ++m)
					{
						currentSum = ptrToArray[i] + ptrToArray[j] + ptrToArray[k] + ptrToArray[l] + ptrToArray[m];
						if (currentSum == target) return 1;
						else if (currentSum > target) break;
						for (n = 0; n < size; ++n)
						{
							currentSum = ptrToArray[i] + ptrToArray[j] + ptrToArray[k] + ptrToArray[l] + ptrToArray[m] +  + ptrToArray[n];
							if (currentSum == target) return 1;
							else if (currentSum > target) break;
						}
					}
				}
			}
		}
	}
	return 0;
}
//-----------------------------------------------------------

/*
	Function: isDifferenceOfPrimes();

*/
char isDifferenceOfPrimes(unsigned int target, int* primes, unsigned int size)
{
	int* ptrToArray = primes;
	unsigned int i, j;

	for (i = 0; i < size - 1; ++i)
	{
		for (j = i + 1; j < size; ++j)
		{
			if (target == ptrToArray[j] - ptrToArray[i])
			{
				printf("%d = %d - %d", target, ptrToArray[j], ptrToArray[i]);
				return 1;
			}
		}
	}
	return 0;
}