/*
	TITLE          Operations with Matrices		Chapter1Matrices.c 
	COMMENT
		Objective: Fill a matrix in the formats:

					0 20 19 17 14
					1 0  18 16 13
					2 5  0  15 12
					3 6  8  0  11
					4 7  9  10  0

					1 16 15 14 13
					2 17 24 23 12
					3 18 25 22 11
					4 19 20 21 10
					5 6  7  8  9
			Input: -
		   Output: -
		   Author: Chris B. Kirov
		     Date: 31.08.2016

*/ 
#include <stdio.h>
#define MAX 5 
void fillMatrix (unsigned int a [MAX][MAX], unsigned int n);
void fillMatrixSpiral (unsigned int a [MAX][MAX], unsigned int n);
void printMatrix (unsigned int a [MAX][MAX], unsigned int n);

//-----------------------------------------------------------------
int main()
{
	unsigned int a[MAX][MAX];

	fillMatrix(a, MAX);
	printMatrix(a, MAX);

	printf("\n");

	fillMatrixSpiral(a, MAX);
	printMatrix(a, MAX);

	return 0;
}
//-----------------------------------------------------------------

/*
	Function: fillMatrix()

	It fills the elements of the 2D matrix: a
	in the followint format:

	0 20 19 17 14
	1 0  18 16 13
	2 5  0  15 12
	3 6  8  0  11
	4 7  9  10  0
*/
void fillMatrix (unsigned int a [MAX][MAX], unsigned int n)
{
	int val = 1;

	unsigned int startCol = 0;
	unsigned int endCol = n - 1;

	unsigned int startRow = 1;
	unsigned int endRow = n;

	unsigned int i = 0;
	unsigned int j = 0;
	 
	// fill lower left triangle matrix
	for (i = startCol; i < endCol; ++i)
	{
		for (j = startRow; j < endRow; ++j)
		{
			a[j][i] = val++;
		}
		++startRow;
	}

	// fill diagonal
	for (i = 0; i < MAX; ++i)
	{
		a[i][i] = 0;
	}

	// fill upper right triangle matrix
	startCol = n - 1;
	endCol = 1;

	startRow = n - 1;
	endRow = 0;

	for (i = startCol; i >= endCol; --i)
	{
		for (j = startRow; j-- > endRow;)
		{
			a[j][i] = val++;
		}
		--startRow;
	}
}
//-----------------------------------------------------------------

/*
	Function:fillMatrixSpiral()

	It fills the elements of the 2D matrix: a
	in the followint format:
*/
void fillMatrixSpiral (unsigned int a [MAX][MAX], unsigned int n)
{
	int val = 1;

	unsigned int startCol = 0;
	unsigned int endCol = n - 1;

	unsigned int startRow = 0;
	unsigned int endRow = n - 1;

	unsigned int row = 0;
	unsigned int col = 0;

	while (val <= MAX * MAX)
	{
		for (row = startRow; row <= endRow; ++row)
		{
			a[row][startCol] = val++;
		}
		++startCol;

		for (col = startCol; col <= endCol; ++col)
		{
			a[endRow][col] = val++;
		}
		--endRow;

		for (row = endRow + 1; row-- > startRow;)
		{
			a[row][endCol] = val++;
		}
		--endCol;

		for (col = endCol + 1; col-- > startCol;)
		{
			a[startRow][col] = val++;
		}
		++startRow;
	}
}
//-----------------------------------------------------------------

/*
	Function: printMatrix()

*/
void printMatrix(unsigned int a [MAX][MAX], unsigned int n)
{
	unsigned int i = 0;
	unsigned int j = 0;
	int fieldWidth = 3;

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			printf("%*d", fieldWidth, a[i][j]);
		}
		printf("\n");
	}
}

