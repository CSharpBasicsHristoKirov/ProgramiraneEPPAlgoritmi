/*
	TITLE          Combinatorics Formulae Chapter1HelperCombinatorics.h 
	COMMENT
		Objective: Contains code implementing combinatorics formulae.
			Input: -
		   Output: -
		   Author: Chris B. Kirov
		     Date: 02.09.2016

*/
#ifndef CHAPTER1_HELPER_COMBINATORICS_H
#define CHAPTER1_HELPER_COMBINATORICS_H

/*
	Function: factorial()

	It returns the factorial of the argument n.
*/
unsigned long long int factorial (unsigned int n)
{
	unsigned long long int fact = 1;
	unsigned int i;

	for (i = 1; i <= n; ++i)
	{
		fact *= i;
	}

	return fact;
}
//---------------------------------------------

/*
	Function: modeFactorial();

	It calculates (n!) mod m.

	Used in Wilson primality test.
*/
uint64_t modeFactorial(uint64_t n, uint64_t m)
{
	uint64_t f = 1;

	for (; n > 1; --n)
	{
		f = (n * f) % m;
	}
	return f;
}

#endif
