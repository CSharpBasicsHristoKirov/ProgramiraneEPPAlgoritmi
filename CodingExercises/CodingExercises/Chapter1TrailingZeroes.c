/*
	TITLE          Find trailing zeroes   Chapter1TrailingZeroes.c 
	COMMENT
		Objective: Find trailing zeroes of n!, using factorization
				   to number 2 and 5.
			Input: 4200000
		   Output: There are 5 trailing zeroes 4200000 
		   Author: Chris B. Kirov
		     Date: 07.09.2016

*/
#include <stdio.h>

int unsigned findNumberOfTrailingZeroesInFactorial(int fact);
//--------------------------------------------------------------

int main()
{
	int factorial =  4200000;

	unsigned int zeroes = findNumberOfTrailingZeroesInFactorial(factorial);

	printf("There are %d trailing zeroes in %d\n", zeroes, factorial);

	return 0;
}
//--------------------------------------------------------------

/*
	Function: findNumberOfZeroesInFactorial();

	Finds number of trailing zeroes in factorial
	of the argument by factorizing it to 2 and 5
	and returning the minimum between the number 
	of 2 and 5.
*/
int unsigned findNumberOfTrailingZeroesInFactorial(int fact)
{
	unsigned int numberOfTwos = 0;
	unsigned int numberOfFives = 0;

	while (fact > 0)
	{
		if (fact % 5 == 0)
		{	
			fact /= 5;
			numberOfFives++;
		}

		if (fact % 2 == 0)
		{	
			fact /= 2;
			numberOfTwos++;
		}

		if (fact % 5 != 0 &&  fact % 2 != 0)
		{
			break;
		}
	}
	return (numberOfTwos < numberOfFives) ? numberOfTwos : numberOfFives;
}
