




/*
	Function: pi()

	It returns the approximate
	number of primes up to the 
	paramter x. 
	(To be used to estimate the size of the array to store primes.)
*/
size_t pi(int x)
{
	return (size_t) (x / (log((double) x) - 1));
}

//-----------------------------------------------------------

/*
	Function: arraySize()

	It returns the size of the 
	array that will hold primes.

	x/logx always > prime number density pi(x)/x.
*/
size_t arraySize(int x)
{
	return (size_t) (x / log((double) x));
}
//-----------------------------------------------------------

/*
	initArray();

*/
void initArray(int* primes, size_t size, int initValue)
{
	unsigned int i;
	for (i = 0; i < size; ++i)
	{
		primes[i] = initValue;	
	}
}
//-----------------------------------------------------------

/*
	Function: printArray();

*/
void printArray(int* primes, size_t size)
{
	unsigned int i;
	int* ptrToArray = primes;
	int fieldWidth = (int) (1 + log10((double)MAX));

	printf("{");
	for (i = 0; i < size; ++i)
	{
		printf("%*d", fieldWidth, ptrToArray[i]);

		if (i < size - 1)
		{
			// exclude unassigned values at the end
			if (ptrToArray[i+1] == 0)
			{
				break;
			}

			printf(", ");
		}

		if (i % 20 == 0 && i != 0)
		{
			printf("\n");
		}
	}
	printf(" }\n");
}
//-----------------------------------------------------------

/*
	Function: binarySearch()

	It returns true if targer is 
	found in the array named primes. 
	Otherwise returns false.
*/
char binarySearch(unsigned int target, int* primes, size_t size)
{
	int* ptrToArray = primes;
	int first = 0;
	int last = size;
	
	while (first <= last)
	{
		unsigned int middle = first + (last - first) / 2;

		if (ptrToArray[middle] == target)
		{
			return 1;
		}

		if (ptrToArray[middle] < target)
		{
			first = middle + 1;
		}
		else 
		{
			last =  middle - 1;
		}
	}
	return 0;
}
//-----------------------------------------------------------

/*
	Function: sumArrayElements()

	It returns the sum of the first
	"size" elements of the array "arr".
*/
unsigned long long int sumArrayElements(int* arr, size_t size)
{
	size_t i;
	unsigned long long int sum = 0;
	
	for (i = 0 ; i < size; ++i)
	{
		sum += arr[i];
	}

	return sum;
}