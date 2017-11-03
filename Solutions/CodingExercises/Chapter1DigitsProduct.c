/*
	TITLE          Digits in product	Chapter1DigitsProduct.c 
	COMMENT
		Objective: Find the number of digits in a product (factoriel).
			Input: -
		   Output: -
		   Author: Chris B. Kirov
		     Date: 31.08.2016

*/ 
#include <stdio.h>
#include <math.h>
const unsigned long n = 123; 

int main()
{
	 double digits = 0;   
	 unsigned i;   
	 for (i = 1; i <= n; i++)
	 {
		 digits += log10((double) i);  
	 }

	 /* factoriel of 123, i.e. 123! has digits: digits + 1 */  
     printf("Number of digits in %lu! is %lu.\n", n, (unsigned long)digits + 1);  
	 return 0; 
}